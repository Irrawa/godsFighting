//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "character.h"

using namespace std;

class cmove;
class field;
class character;
class field_status;

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

void status::SetupStatus(){}

void status::RefStatus(){}


void status::StatusLoss(){}