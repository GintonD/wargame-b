#pragma once

#include "Soldier.hpp"
namespace WarGame
{

class ParamedicCommander : public Soldier
        {
    public:

        ParamedicCommander(int pn): Soldier(200,pn,0,200){}

        void fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override
        {
            //his fire
            for(int i = source.first-1;i<=source.first+1;i++)
            {
                for(int j = source.second-1;j<=source.second+1;j++)
                {
                    if(i>=0 && i<board.size() && j>=0 && j<board[i].size())
                    {
                        if (board[i][j]!=nullptr && i != source.first && j != source.second)
                        {
                            if(board[i][j]->player==board[source.first][source.second]->player)
                            {
                                board[i][j]->hp=max_hp;
                            }

                        }
                    }
                }
            }

            //the fires of all of his parameidc soldier's
        for(int i = 0; i<board.size(); i++)
        {
            for(int j =0; j<board[i].size() ; j++)
            {
                if(board[i][j]!=nullptr && board[i][j]->player==board[source.first][source.second]->player)
                {
                    if(board[i][j]->max_hp==100 && board[i][j]->dmg==0)
                    {
                        board[i][j]->fire({i,j},board);
                    }
                }
                    
            }
        }

        }
   
    };
}