#pragma once
#include "Soldier.hpp"
namespace WarGame
{
    class FootSoldier : public Soldier
            {
        public:
        FootSoldier(int pn):Soldier(100,pn,10,100){}

        void fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override
        {
            std::pair<int,int> target = this->closest_target(source,board); //find the enemy solider target
            if(target.first==-1 && target.second==-1) // if there is'nt such a player - return
                return;

            board[target.first][target.second]->hp-=board[source.first][source.second]->dmg; //decrease from hp
            if(board[target.first][target.second]->hp<=0) //if die, delete the solider
            {
                delete(board[target.first][target.second]);
                board[target.first][target.second]=nullptr;
            }

        }

    };

}
