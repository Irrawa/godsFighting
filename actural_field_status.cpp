//
// Created by 梦芙兰 on 2019/5/24.
//

#include "actural_field_status.h"
#include <iostream>
#include <vector>
#include <string>
#include "actural_statuses.h"
#include "character.h"
#include "actural_moves.h"
using namespace std;

//*****************************CHOKE    *******************************
void nayadBreeze::SetupStatus(character* maker, character* other, field* currentField){
    iniT = 5;
    nT = iniT;
    sta_ds = 5;
    sta_dh = 20;
    cout << "Nayad Breeze status setup..." << endl;
}

void nayadBreeze::RefStatus(character* maker, character* other, field* currentField) {
    if(totalBuffCount >= 99){
        sta_ds = 0;
    }
}

void nayadBreeze::StatusTakeEffect(character* maker, character* other, field* currentField){
    (*maker).HP += sta_dh;
    (*maker).MP += sta_dm;
    (*maker).ctr_atk += sta_da;
    (*maker).ctr_def += sta_dd;
    (*maker).ctr_spd += sta_ds;
    totalBuffCount += sta_ds;
    (*other).HP += sta_Odh;
    (*other).MP += sta_Odm;
    (*other).ctr_atk += sta_Oda;
    (*other).ctr_def += sta_Odd;
    (*other).ctr_spd += sta_Ods;
    cout << "奈亚德效果生效："<< sta_ds << endl;
    nT -= 1;
}

void nayadBreeze::StatusLoss(character* maker, character* other, field* currentField){
    cout << "Nayad Breeze status lost" << endl;
    (*maker).ctr_spd -= totalBuffCount;
}