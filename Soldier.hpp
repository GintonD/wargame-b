#include <vector>
#include <cmath>
#pragma once

namespace WarGame
{
    class Soldier
            {
        public:
        int player;
        int hp; //current hp
        int dmg;
        int max_hp; //maximum abillity of hp

        virtual ~Soldier() {}



        Soldier(int hp, int p,int dmg,int max_hp): hp(hp), player(p) , dmg(dmg) , max_hp(max_hp) {}

        virtual void fire (std::pair<int,int> source, std::vector<std::vector<Soldier*>>& board) = 0; //abstract function

        //naive search for closest player
        std::pair<int,int> closest_target(std::pair<int,int> source, const std::vector<std::vector<Soldier*>>& board)
        {
            std::pair<int,int> target = {-1,-1};

            double dist;
            double min=999;
            int p; //enemy player
            board[source.first][source.second]->player == 1 ? p=2 : p=1;

            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    if(board[i][j]!=nullptr && board[i][j]->player==p) //find enemy solider
                    {
                        dist=sqrt(pow(source.first-i,2)+pow(source.second-j,2)); // distant formula : sqrt(a^2+b^2)
                        if(dist<min)
                        {
                            min=dist;
                            target = {i,j};
                        }
                    }
                }
        
            } 
            return target;  
            
        }

        //naive search for player with highest HP.
        std::pair<int,int> highest_hp(std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board)
        {
            std::pair<int,int> target = {-1,-1};
            double hp;
            double max=0;
            int p; //enemy player
            board[source.first][source.second]->player == 1 ? p=2 : p=1;

            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    if(board[i][j]!=nullptr && board[i][j]->player==p)
                    {
                        hp=board[i][j]->hp;
                        if(hp>max)  // highest hp
                        {
                            max=hp;
                            target = {i,j};
                        }
                    }
                }
        
            } 
            return target;  
            
        }        
    };
}
