//
// Created by 梦芙兰 on 2019/5/15.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class cmove;
class field;
class character;
class field_status;

#ifndef GODS_STATUS_H
#define GODS_STATUS_H

class status{
public:
    string sta_name, sta_info, sta_logo;
    //      状态名    状态介绍
    int sta_dh = 0, sta_dm = 0, sta_da = 0, sta_dd = 0, sta_ds = 0,
    //状态造成的生命值、魔法值、攻击、防御、速度 的变化
            sta_Odh = 0, sta_Odm = 0, sta_Oda = 0, sta_Odd = 0, sta_Ods = 0,
    //对对手造成的...变化
            iniT = 1, nT = 1;
    //初始持续时间 目前持续时间 状态id

    vector <cmove> LinkedMoves;
    //联携技能表，若此表不空，则在状态生效时自动施放技能。

    bool sta_pos, sta_neg;
    //正面状态还是负面状态？

    bool showStatus = true;
    // 该状态是否可被玩家看到;

    int ParameterDeliver = 0;

    string specialProperty;


    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);
    //状态被施加时，使用此函数初始化，并返回初始化后的状态
    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);
    //每经过一回合，所有生效的status需要使用此函数刷新。
    virtual void StatusTakeEffect(character* selfCharacter, character* oppoCharacter, field* currentField);
    //效果产生影响（如攻击力降低等）
    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);
    //状态消逝时的特殊行为，如失去状态时回血等等,状态消失时也调用此函数将一些状态造成的改变复原
    string get_information();

};


#endif //GODS_STATUS_H
