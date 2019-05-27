//
// Created by 梦芙兰 on 2019/5/15.
//
#include <iostream>
#include <vector>
#include <string>
#include "status.h"
#include "actural_statuses.h"
using namespace std;

#ifndef GODS_CHARACTER_H
#define GODS_CHARACTER_H

class cmove;
class field;
class character;
class field_status;
class status;

class character{
public:
    string cName; //角色名
    string cInfo;
    int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
    //最大生命值       最大魔法值     攻击力       防御力       速度      生命值  魔法值
    vector <status*> statL;
    //     状态列表
    vector <cmove> moveL;
    //     技能列表
    vector <status> statM;

    void Initialize(string name, vector <cmove> cmoveList, int hp, int mp, int atk, int def, int spd);
    //初始化角色，用于创建角色

    void TakeTurn(character* oppoCharacter, cmove* chosenMove, field* currentField);
    //玩家针对对手玩家行动

    void add_status(status* S, character* creator, field* thisField);

    void SufferStatus(character* oppoCharacter, field* currentField);

    bool IsAlive();

    string print();

    vector <status*> noteStatL = {&CharChoke, &CharAquaBlast, &CharToxic, &NetherCircuit, &Poisoned};

    void SetMove(character* opponent, field* battleField);

    choke CharChoke;
    aquaBlast CharAquaBlast;
    toxic CharToxic;
    netherCircuit NetherCircuit;
    poisoned Poisoned;
    staticOverload StaticOverload;
    spiritified Spiritified;
};

#endif //GODS_CHARACTER_H
