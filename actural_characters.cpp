//
// Created by 梦芙兰 on 2019/5/16.
//

#include "actural_characters.h"
#include "actural_moves.h"
#include "actural_statuses.h"
#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "character.h"
#include "cmove.h"
#include "note_page.h"
#include "status.h"

using namespace std;

vector <character> AllCharacterList;

character IRRAWA(){
    character irrawa;
    irrawa.Initialize("Irrawa", IrrawaMoveList, 1200, 800, 125, 100, 80);
    AllCharacterList.push_back(irrawa);
    return irrawa;
}


character MEW(){
    character mew;
    mew.Initialize("Mew", MewMoveList, 1000, 1000, 100, 100, 100);
    AllCharacterList.push_back(mew);
    return mew;
}

character ROSIE(){
    character rosie;
    rosie.Initialize("Rosie", RosieMoveList, 900, 1000, 90, 90, 120);
    AllCharacterList.push_back(rosie);
    return rosie;
}

character ASIBI(){
    character asibi;
    asibi.Initialize("Asibi", AsibiMoveList, 1100, 1200, 110, 110, 100);
    AllCharacterList.push_back(asibi);
    return asibi;
}