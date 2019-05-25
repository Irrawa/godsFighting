//
// Created by 梦芙兰 on 2019/5/16.
//

#include "actural_moves.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "field_status.h"
#include "character.h"
#include "note_page.h"
#include "status.h"
#include "actural_statuses.h"

using namespace std;

vector <cmove> AllMoveList;   //全游戏技能表，已设为全局变量
vector <cmove> IrrawaMoveList;  //伊洛瓦的技能表，已设为全局变量
vector <cmove> MewMoveList;  //妙的技能表，已设为全局变量
vector <cmove> RosieMoveList;  //露丝的技能表，已设为全局变量
vector <cmove> AsibiMoveList;  //Asibi的技能表，已设为全局变量

cmove AquaBall(character * owner, character * taker, field * place){
    cmove aquaBall;
    aquaBall.mName = "Aqua Ball";
    aquaBall.slf_dm = -100;
    aquaBall.mv_atk = 20;
    cout << "AquaBall established!" << endl;
    aquaBall.opo_adStat.push_back(&(taker->CharChoke));
    return aquaBall;
}

cmove AquaBall(){
    cmove aquaBall;
    aquaBall.mName = "Aqua Ball";
    aquaBall.slf_dm = -100;
    aquaBall.mv_atk = 20;
    cout << "AquaBall established!" << endl;
    AllMoveList.push_back(aquaBall);
    IrrawaMoveList.push_back(aquaBall);
    return aquaBall;
}

cmove WindSlash(character * owner, character * taker, field * place){
    cmove windSlash;
    windSlash.mName = "Wind Slash";
    windSlash.slf_dm = -80;
    windSlash.mv_atk = 65;
    cout << "WindSlash established!" << endl;
    return windSlash;
}

cmove WindSlash(){
    cmove windSlash;
    windSlash.mName = "Wind Slash";
    windSlash.slf_dm = -80;
    windSlash.mv_atk = 65;
    cout << "WindSlash established!" << endl;
    AllMoveList.push_back(windSlash);
    IrrawaMoveList.push_back(windSlash);
    return windSlash;
}

cmove PsychoBoost(character * owner, character * taker, field * place){
    cmove psychoBoost;
    psychoBoost.mName = "Psycho Boost";
    psychoBoost.slf_dm = -25;
    psychoBoost.slf_da = 15;
    psychoBoost.selfTarget = true;
    cout << "PsychoBoost established!" << endl;
    return psychoBoost;
}

cmove PsychoBoost(){
    cmove psychoBoost;
    psychoBoost.mName = "Psycho Boost";
    psychoBoost.slf_dm = -25;
    psychoBoost.slf_da = 15;
    psychoBoost.selfTarget = true;
    cout << "PsychoBoost established!" << endl;
    AllMoveList.push_back(psychoBoost);
    MewMoveList.push_back(psychoBoost);
    return psychoBoost;
}

cmove Tsunami(character * owner, character * taker, field * place){
    cmove tsunami;
    tsunami.mName = "Tsunami";
    tsunami.slf_dm = -150;
    tsunami.mv_atk = 30;
    tsunami.opo_adStat.push_back(&(taker->CharAquaBlast));
    return tsunami;
}

cmove Tsunami(){
    cmove tsunami;
    tsunami.mName = "Tsunami";
    tsunami.slf_dm = -150;
    tsunami.mv_atk = 30;
    AllMoveList.push_back(tsunami);
    IrrawaMoveList.push_back(tsunami);
    return tsunami;
}

cmove RainOfNayad(character * owner, character * taker, field * place){
    cmove rainOfNayad;
    rainOfNayad.mName = "Rain Of Nayad";
    rainOfNayad.field_adStat.push_back(&(place->RainOfNayad));
    return rainOfNayad;
}

cmove RainOfNayad(){
    cmove rainOfNayad;
    rainOfNayad.mName = "Aqua Ball";
    cout << "Rain of Nayad established!" << endl;
    AllMoveList.push_back(rainOfNayad);
    IrrawaMoveList.push_back(rainOfNayad);
    return rainOfNayad;
}

cmove Tailwind(character * owner, character * taker, field * place){
    cmove tailwind;
    tailwind.mName = "Tailwind";
    int NumStatus = owner->statL.size();
    if(NumStatus > 0) {
        int deleteNum = rand() % NumStatus;
        cout << "deleteNum = " << deleteNum << endl;
        owner->statL[deleteNum]->StatusLoss(owner, taker, place);
        (owner->statL).erase(owner->statL.begin() + deleteNum);
    }
    return tailwind;
}

cmove Tailwind(){
    cmove tailwind;
    tailwind.mName = "Tailwind";
    cout << "Tailwind established!" << endl;
    AllMoveList.push_back(tailwind);
    IrrawaMoveList.push_back(tailwind);
    return tailwind;
}