//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "status.h"
#include "cmove.h"

using namespace std;



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
    nT -= 1;
}

void status::SetupStatus(){
}

void status::RefStatus(){}


void status::StatusLoss(){}

string status::get_information(){
    string output = "【" + sta_name + "】" + ":\n" + sta_info + "\n目前剩余" + to_string(nT) + "回合。";
    return output;
}