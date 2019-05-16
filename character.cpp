//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "status.h"
#include "character.h"
#include "cmove.h"
#include "field.h"
#include "field_status.h"

using namespace std;


void character::add_status(status S){
    statL.push_back(S);
};

void character::Initialize(string name, vector <cmove> cmoveList, int hp, int mp, int atk, int def, int spd){
    cName = name;
    moveL = cmoveList;
    maxHP = hp;
    maxMP = mp;
    HP = hp;
    mp = mp;
    ctr_atk = atk;
    ctr_def = def;
    ctr_spd = spd;
    cout << "Character " << cName << " created!" << endl;
}

void character::TakeTurn(character oppoCharacter, cmove chosenMove,field currentField){
    cout << cName << " casted move <" << chosenMove.mName << "> to " << oppoCharacter.cName << endl;
    chosenMove.SpellMove(*this, oppoCharacter, currentField.FStatusL);
    chosenMove.LaunchMove(*this, oppoCharacter, currentField.FStatusL);
    cout << oppoCharacter.HP << endl;

}

//string cName; //角色名
//int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
////最大生命值       最大魔法值     攻击力       防御力       速度      生命值  魔法值
//vector <status> statL;
////     状态列表
//vector <cmove> moveL;
////     技能列表
//vector <status> statM;