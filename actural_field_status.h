//
// Created by 梦芙兰 on 2019/5/24.
//

#ifndef GODS_ACTURAL_FIELD_STATUS_H
#define GODS_ACTURAL_FIELD_STATUS_H

#include "actural_characters.h"
#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "note_page.h"
#include "field_status.h"

using namespace std;

class character;
class cmove;

class nayadBreeze : public field_status{
public:
    nayadBreeze(){
        sta_name = "NAYAD BREEZE";
        sta_info = "Increase speed each turn, the longer the status last, the more the speed increases.\nStill helps recover some HP.";
        iniT = 5;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }

    int totalBuffCount = 0; //用此参数计算增加的速度总量，以便状态消失时减去。

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



#endif //GODS_ACTURAL_FIELD_STATUS_H
