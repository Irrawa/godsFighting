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

    string sta_name, sta_info, sta_logo;
    //      状态名    状态介绍
    int sta_dh = 0, sta_dm = 0, sta_da = 0, sta_dd= 0, sta_ds= 0,
    //状态对造成的生命值、魔法值、攻击、防御、速度 的变化
        sta_Odh= 0, sta_Odm= 0, sta_Oda= 0, sta_Odd= 0, sta_Ods= 0,
            iniT= 0, nT= 0, sta_id;
    //初始持续时间 目前持续时间 状态id
    vector <status> sta_rmStat;

    character* owner;
    character* non_owner;


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
