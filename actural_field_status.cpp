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

//*****************************Nayad Breeze*******************************
void nayadBreeze::SetupStatus(character* maker, character* other, field* currentField){
    iniT = 5;
    nT = iniT;
    sta_ds = 5;
    sta_dh = 20;
    owner = maker;
    non_owner = other;
//    cout << "Nayad Breeze status setup..." << endl;
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
//    cout << "奈亚德效果生效："<< sta_ds << endl;
    nT -= 1;
    cout << sta_da << endl;
    cout << sta_ds << endl;
    cout << sta_dh << endl;

}

void nayadBreeze::StatusLoss(character* maker, character* other, field* currentField){
    cout << "Nayad Breeze status lost" << endl;
    (*maker).ctr_spd -= totalBuffCount;
    totalBuffCount = 0;
}

//*****************************Poison Aura*******************************
void poisonAura::SetupStatus(character* maker, character* other, field* currentField){
    iniT = 5;
    nT = iniT;
    owner = maker;
    non_owner = other;
//    cout << "Poison Aura status setup..." << endl;

}


void poisonAura::StatusTakeEffect(character* maker, character* other, field* currentField){
    status* selfTempStatus = &(maker->Poisoned);
    selfTempStatus->SetupStatus(maker, other, currentField);
    (*maker).add_status(selfTempStatus, maker, currentField);

    status* otherTempStatus = &(other->Poisoned);
    otherTempStatus->SetupStatus(other, maker, currentField);
    (*other).add_status(otherTempStatus, maker, currentField);

//    cout << "毒气效果生效："<< sta_ds << endl;
    nT -= 1;
}

void poisonAura::StatusLoss(character* maker, character* other, field* currentField){
    cout << "Poison Aura status lost" << endl;
}