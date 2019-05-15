//
// Created by 梦芙兰 on 2019/5/15.
//
#include "godFighting.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef GODS_STATUS_H
#define GODS_STATUS_H

void status::SetupStatus(){}

void status::RefStatus(){}

void status::StatusTakeEffect(character self, character oppo){
    self.HP += sta_dh;
    self.MP += sta_dm;
    self.ctr_atk += sta_da;
    self.ctr_def += sta_dd;
    self.ctr_spd += sta_ds;
    oppo.HP += sta_Odh;
    oppo.MP += sta_Odm;
    oppo.ctr_atk += sta_Oda;
    oppo.ctr_def += sta_Odd;
    oppo.ctr_spd += sta_Ods;
}

void status::StatusLoss(){}

class choke : public status{
public:
    choke(){
        sta_name = "窒息";
        sta_info = "减少目标15点速度，持续3回合。";
        iniT = 3;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }

    void SetupStatus(){
        sta_ds = -15;
    }

    void RefStatus(){
        if(nT == 0){
            sta_ds = 15;
        }
        else if(nT < iniT){
            sta_ds = 0;
        }
    }



};




#endif //GODS_STATUS_H
