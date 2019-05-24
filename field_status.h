//
// Created by 梦芙兰 on 2019/5/15.
//

#ifndef GODS_FIELD_STATUS_H
#define GODS_FIELD_STATUS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class character;
class status;
class field;

class field_status{
    //场地状态
public:

    string sta_name, sta_info;
    //      状态名    状态介绍
    int sta_dh, sta_dm, sta_da, sta_dd, sta_ds,
    //状态对造成的生命值、魔法值、攻击、防御、速度 的变化
        sta_Odh, sta_Odm, sta_Oda, sta_Odd, sta_Ods,
            iniT, nT, sta_id;
    //初始持续时间 目前持续时间 状态id
    vector <status> sta_rmStat;


    bool sta_pos, sta_neg;

    virtual void SetupStatus(character* maker, character* other, field* currentField);
    //状态被施加时，使用此函数初始化
    virtual void RefStatus(character* maker, character* other, field* currentField);
    //每经过一回合，所有生效的status需要使用此函数刷新。
    virtual void StatusTakeEffect(character* maker, character* other, field* currentField);
    //效果产生影响
    virtual void StatusLoss(character* maker, character* other, field* currentField);
    //状态消失时调用的函数，主要功能为将一些状态造成的改变复原（如攻击力降低等）
    string get_information();

};

#endif //GODS_FIELD_STATUS_H
