//
// Created by 梦芙兰 on 2019/5/20.
//

#include <iostream>
#include <vector>
#include <string>
#include "actural_statuses.h"
#include "character.h"
#include "actural_moves.h"
using namespace std;

//*****************************CHOKE*******************************
void choke::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 3;
    nT = iniT;
    sta_ds = -15;
    cout << "Choke status setup..." << endl;
}

void choke::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
//    cout << "Choke status refreshed..." << endl;
    if (nT > 0 && nT < iniT) {
        sta_ds = 0;
    }
}

void choke::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Choke status lost" << endl;
    (*selfCharacter).ctr_spd += 15;
}

//choke oriChoke;
//choke *ChokePtr = &oriChoke;
//*****************************AQUA BLAST********************************
void aquaBlast::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
    cout << "AquaBlast status setup..." << endl;
}

void aquaBlast::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
    if (nT > 0 && nT < iniT) {
        sta_ds = 0;
    }
}

void aquaBlast::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField) {
    cout << "AquaBlast status lost" << endl;
}

void aquaBlast::StatusTakeEffect(character* self, character* oppo, field* currentField){
    if(nT <= 0) {
        (*self).HP -= 300;
        cout << "爆炸！💥" << endl;
    }
    nT -= 1;
}

//*****************************NETHER CIRCUIT********************************待完成
void netherCircuit::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
    sta_da = 20;
    sta_dd = 20;
    cout << "Nether Circuit status setup..." << endl;
}

void netherCircuit::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
//    cout << "Choke status refreshed..." << endl;
    vector <status*> targetSList = selfCharacter->statL;
    int Length = targetSList.size();
    for(int i = 0; i < Length; i++){
        if(targetSList[i]->sta_name == "TOXIC" or targetSList[i]->sta_name == "POISONED"){
            if(targetSList[i]->sta_dh < 0) {
                targetSList[i]->sta_dh *= -1;
            }
        }
    }
}

void netherCircuit::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Nether Circuit status lost" << endl;
    (*selfCharacter).ctr_atk -= 20;
    (*selfCharacter).ctr_def -= 20;
    vector <status*> targetSList = selfCharacter->statL;
    int Length = targetSList.size();
    for(int i = 0; i < Length; i++){
        if(targetSList[i]->sta_name == "TOXIC" or targetSList[i]->sta_name == "POISONED"){
            if(targetSList[i]->sta_dh > 0) {
                targetSList[i]->sta_dh *= -1;
            }
        }
    }
}

//*****************************TOXIC*******************************
void toxic::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 3;
    nT = iniT;
    sta_dh = -10;
    toxicEnhancer = 1;
    cout << "Toxic status setup..." << endl;
}

void toxic::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
//    cout << "Choke status refreshed..." << endl;
    sta_dh *= 1.3;
    toxicEnhancer *= 1.3;
    if(sta_dh < -200){
        sta_dh = -200;
    }
}

void toxic::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Toxic status lost" << endl;
}

//*****************************POISONED*******************************
void poisoned::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 5;
    nT = iniT;
    sta_dh = -30;
    cout << "Poisoned status setup..." << endl;
}

void poisoned::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
}

void poisoned::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Poisoned status lost" << endl;
}

//*****************************STATIC OVERLOAD*******************************

void staticOverload::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 5;
    nT = iniT;
    cout << "Static Overload status setup..." << endl;
}

void staticOverload::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    int dHP = 0;
    string selfCharName = selfCharacter->cName;
    note_page currentPage = currentField->GetCurrentPage();
    string FasterName = currentPage.C00.cName;
    string SlowerName = currentPage.C01.cName;
    if(selfCharName == FasterName){
        dHP = 0.5 * (currentPage.C04.HP - currentPage.C02.HP);
    }
    else if(selfCharName == SlowerName){
        dHP = 0.5 * (currentPage.C03.HP - currentPage.C01.HP);
    }
    if(dHP > 0){
        dHP = 0;
    }
    sta_Odh = dHP;
}

//void staticOverload::StatusTakeEffect(character* selfCharacter, character* oppoCharacter, field* currentField){
//
//}

//void staticOverload::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){}