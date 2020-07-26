#pragma once
#include "Soldier.hpp"

namespace WarGame
{

    class FootCommander : public Soldier
            {
        public:
        FootCommander(int pn):Soldier(150,pn,20,150){}

        // the commander's fire
        void fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override
        {
            std::pair<int,int> target = this->closest_target(source,board);
            if(target.first==-1 && target.second==-1)
                return; // if there is'nt such a player - return

            board[target.first][target.second]->hp-=board[source.first][source.second]->dmg;

            if(board[target.first][target.second]->hp<=0)
            {
                delete(board[target.first][target.second]);
                board[target.first][target.second]=nullptr;
            }

            //The fires of his soldier
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    if(board[i][j]!=nullptr && board[i][j]->player==board[source.first][source.second]->player)
                    {
                        if(board[i][j]->max_hp==100 && board[i][j]->dmg==10)
                        { // means this is a foot soldier
                            board[i][j]->fire({i,j},board);
                        }
                    }
                }
            }


        }


    };





}