#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

namespace WarGame{

    TEST_CASE("!"){
        Paramedic* a = new Paramedic(4);
        CHECK(a->dmg==0);
        CHECK(a->hp==100);
        CHECK(a->player==4);


        ParamedicCommander* b = new ParamedicCommander(3);
        CHECK(b->dmg==0);
        CHECK(b->hp==200);
        CHECK(b->player==3);


        Sniper* x = new Sniper(3);
        CHECK(x->dmg==50);
        CHECK(x->hp==100);
        CHECK(x->player==3);

        SniperCommander* y = new SniperCommander(4);
        CHECK(y->dmg==100);
        CHECK(y->hp==120);
        CHECK(y->player==4);        
        

        FootCommander* z = new FootCommander(2);
        CHECK(z->dmg==20);
        CHECK(z->hp==150);
        CHECK(z->player==2);

        FootSoldier* w = new FootSoldier(1);
        CHECK(w->dmg==10);
        CHECK(w->hp==100);
        CHECK(w->player==1); 
    

    }

    TEST_CASE("?"){



        Board p(6,6);
        CHECK_FALSE(p.has_soldiers(1));
        CHECK_FALSE(p.has_soldiers(2));
        p[{1,0}]= new Sniper(1);
        p[{3,4}]= new FootSoldier(2);
        p[{5,5}]= new FootCommander(1);
        p[{3,5}]= new ParamedicCommander(2);
        p[{0,1}]= new FootSoldier(2);
        p[{3,3}]= new Sniper(2);
        p[{2,1}]= new Paramedic(1);
        p[{4,4}]= new SniperCommander(2);
        p[{5,4}]= new Paramedic(1);
        p[{2,3}]= new SniperCommander(2);
        p[{1,5}]= new ParamedicCommander(1);
        p[{4,1}]= new FootCommander(1);



        CHECK((p[{1,0}]->dmg) == 50);
        CHECK((p[{1,0}]->hp) == 100);
        CHECK((p[{3,4}]->hp) == 0);
        CHECK((p[{3,4}]->hp) == 0);
        CHECK((p[{3,4}]->hp) == 0);
        CHECK((p[{5,5}]->hp) == 0);
        CHECK((p[{5,5}]->hp) == 0);
        CHECK((p[{5,5}]->hp) == 0);
        CHECK((p[{0,1}]->hp) == 0);
        CHECK((p[{0,1}]->hp) == 0);
        CHECK((p[{0,1}]->hp) == 0);
        CHECK((p[{3,3}]->hp) == 0);
        CHECK((p[{3,3}]->hp) == 0);
        CHECK((p[{3,3}]->hp) == 0);
        CHECK((p[{2,1}]->hp) == 0);
        CHECK((p[{2,1}]->hp) == 0);
        CHECK((p[{2,1}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{1,5}]->hp) == 0);
        CHECK((p[{1,5}]->hp) == 0);
        CHECK((p[{1,5}]->hp) == 0);
        CHECK((p[{5,4}]->hp) == 0);
        CHECK((p[{5,4}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{1,5}]->hp) == 0);

        CHECK(p.has_soldiers(1));
        CHECK(p.has_soldiers(2));

        // p.move(1,{1,5},Board::Up);
        // CHECK(p[{2,5}]->dmg==0);
         CHECK(p[{1,5}] == nullptr);
         CHECK(typeid(p[{1,5}])==typeid(ParamedicCommander));

        // p.move(2,{1,5},Board::Down);
        // CHECK(p[{2,5}] == nullptr);
        CHECK(p[{1,5}]->dmg==0);
        CHECK(typeid(p[{1,5}])==typeid(ParamedicCommander));

        // p.move(1,{1,5},Board::Left);
        // CHECK(p[{1,4}]->dmg==0);
         CHECK(p[{1,5}] == nullptr);
         CHECK(typeid(p[{1,4}])==typeid(ParamedicCommander));

        // p.move(1,{4,4},Board::Right);
        // CHECK(p[{4,5}]->dmg==0);
        CHECK(p[{4,4}] == nullptr);
        CHECK(typeid(p[{4,4}])==typeid(ParamedicCommander));



    }


    TEST_CASE("%"){

        Board p(116,116);
        CHECK_FALSE(p.has_soldiers(1));
        CHECK_FALSE(p.has_soldiers(2));
        p[{1,0}]= new Sniper(1);
        p[{3,4}]= new FootSoldier(2);
        p[{5,5}]= new FootCommander(1);
        p[{3,5}]= new ParamedicCommander(2);
        p[{0,1}]= new FootSoldier(2);
        p[{3,3}]= new Sniper(2);
        p[{2,1}]= new Paramedic(1);
        p[{4,4}]= new SniperCommander(2);
        p[{5,4}]= new Paramedic(1);
        p[{2,3}]= new SniperCommander(2);
        p[{1,5}]= new ParamedicCommander(1);
        p[{4,1}]= new FootCommander(1);

        CHECK(typeid(p[{4,4}])==typeid(SniperCommander));
        CHECK(typeid(p[{1,0}])==typeid(Sniper));
        CHECK(typeid(p[{3,4}])==typeid(FootSoldier));
        CHECK(typeid(p[{5,5}])==typeid(FootCommander));
        CHECK(typeid(p[{3,5}])==typeid(ParamedicCommander));
        CHECK(typeid(p[{0,1}])==typeid(FootSoldier));
        CHECK(typeid(p[{3,3}])==typeid(Sniper));
        CHECK(typeid(p[{5,4}])==typeid(Paramedic));



        CHECK_NOTHROW(p.move(1,{1,1},WarGame::Board::Up));
        CHECK_NOTHROW(p.move(1,{2,1},WarGame::Board::Left));
        CHECK_NOTHROW(p.move(1,{3,1},WarGame::Board::Down));
        CHECK_NOTHROW(p.move(2,{4,1},WarGame::Board::Right));
        CHECK_NOTHROW(p.move(2,{5,1},WarGame::Board::Right));
        CHECK_NOTHROW(p.move(2,{2,1},WarGame::Board::Down));
        CHECK_NOTHROW(p.move(2,{2,2},WarGame::Board::Right));
        CHECK_NOTHROW(p.move(2,{3,2},WarGame::Board::Down));
        CHECK_NOTHROW(p.move(2,{4,2},WarGame::Board::Down));
        CHECK_NOTHROW(p.move(1,{5,2},WarGame::Board::Up));
        CHECK_NOTHROW(p.move(1,{3,3},WarGame::Board::Down));
        CHECK_NOTHROW(p.move(1,{4,4},WarGame::Board::Right));
        CHECK_NOTHROW(p.move(1,{5,5},WarGame::Board::Right));
        CHECK_NOTHROW(p.move(1,{5,7},WarGame::Board::Left));
        CHECK_NOTHROW(p.move(1,{4,2},WarGame::Board::Right));
        CHECK_THROWS(p.move(1, {5, 6}, WarGame::Board::Up));
        CHECK_THROWS(p.move(1, {2, 4}, WarGame::Board::Down));
        CHECK_THROWS(p.move(2, {1, 2}, WarGame::Board::Down));
        CHECK_THROWS(p.move(1, {5, 12}, WarGame::Board::Right));
        CHECK_THROWS(p.move(1, {9, 9}, WarGame::Board::Left));
        CHECK_THROWS(p.move(2, {1, 2}, WarGame::Board::Up));
        CHECK_THROWS(p.move(2, {12, 3}, WarGame::Board::Up));
        CHECK_THROWS(p.move(2, {4, 3}, WarGame::Board::Up));
        CHECK_THROWS(p.move(2, {1, 3}, WarGame::Board::Down));
        CHECK_THROWS(p.move(1, {0, 12}, WarGame::Board::Left));
        CHECK_THROWS(p.move(1, {1, 0}, WarGame::Board::Up));
        CHECK_THROWS(p.move(1, {2, 3}, WarGame::Board::Up));
        CHECK_THROWS(p.move(1, {3, 2}, WarGame::Board::Down));
        CHECK_THROWS(p.move(2, {5, 2}, WarGame::Board::Right));
        CHECK_THROWS(p.move(2, {7, 4}, WarGame::Board::Left));
        CHECK_THROWS(p.move(1, {1, 2}, WarGame::Board::Up));
        CHECK_THROWS(p.move(1, {1, 3}, WarGame::Board::Up));
        CHECK_THROWS(p.move(1, {8, 2}, WarGame::Board::Down));
        CHECK_THROWS(p.move(2, {9, 2}, WarGame::Board::Right));
        CHECK_THROWS(p.move(2, {10, 4}, WarGame::Board::Left)); 

        
        
               
    }
}
