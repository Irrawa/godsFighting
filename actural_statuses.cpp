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
//    cout << "Choke status setup..." << endl;
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
//    cout << "AquaBlast status setup..." << endl;
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
        int dh = 30000 / self->ctr_def;
        (*self).HP -= dh;
        cout << "💥The AquaBomb exploded and dealt " << dh << " damage to "<< self->cName << "!" << endl;
    }
    nT -= 1;
}

//*****************************NETHER CIRCUIT********************************待完成
void netherCircuit::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
    sta_da = 20;
    sta_dd = 20;
//    cout << "Nether Circuit status setup..." << endl;
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
    sta_dh = -10 - selfCharacter->ctr_atk / 10;
    toxicEnhancer = 1;
//    cout << "Toxic status setup..." << endl;
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
//    cout << "Poisoned status setup..." << endl;
}

void poisoned::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
}

void poisoned::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Poisoned status lost" << endl;
}

//*****************************STATIC OVERLOAD*******************************

void staticOverload::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 3;
    nT = iniT;
//    cout << "Static Overload status setup..." << endl;
}

void staticOverload::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    int dHP = 0;
    string selfCharName = selfCharacter->cName;
    note_page currentPage = currentField->GetCurrentPage();
    string FasterName = currentPage.C00.cName;
    string SlowerName = currentPage.C01.cName;
    if(selfCharName == FasterName){
        dHP = 0.3 * (currentPage.C04.HP - currentPage.C02.HP);
    }
    else if(selfCharName == SlowerName){
        dHP = 0.3 * (currentPage.C03.HP - currentPage.C01.HP);
    }
    if(dHP >= 0){
        sta_Odh = 0;
    }
    else {
        sta_Odh = dHP;
        sta_dh = -dHP;
        cout << "The Static Overload reflected " << -dHP << " damage to " << oppoCharacter->cName << "." << endl;
    }
}

void staticOverload::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Static Overload status lost" << endl;
}

//*****************************SPIRIFIED*******************************

void spiritified::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
//    cout << "SETUPED!!!" << endl;
    ParameterDeliver += (selfCharacter->ctr_def) * 3;
    (*selfCharacter).ctr_def += ParameterDeliver;
//    cout << "Spirified status setup..." << endl;
}

void spiritified::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
//    cout << "Choke status refreshed..." << endl;
//    if (nT > 0 && nT < iniT) {
//        sta_dd = 0;
//    }
}

void spiritified::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    cout << "Spirified status lost" << endl;
    (*selfCharacter).ctr_def -= ParameterDeliver;
}


//*****************************AWAKENING*******************************

void awakening::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 0;
    nT = iniT;
}

void awakening::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    note_page thePage = currentField->GetPage(currentField->battleRecord.size() - 4);
    character fasterC = thePage.C00;
    character slowerC = thePage.C01;
    fasterC.print();
    slowerC.print();
//    cout << "FasterC:";
    fasterC.print();
    if(selfCharacter->cName == fasterC.cName){
        thePage.copyCharToCurrent(selfCharacter, 0);
        thePage.copyCharToCurrent(oppoCharacter, 1);
    }
    else if(selfCharacter->cName == slowerC.cName){
        thePage.copyCharToCurrent(selfCharacter, 0);
        thePage.copyCharToCurrent(oppoCharacter, 1);
    }
    selfCharacter->MP -= 50;
    if(selfCharacter->MP < 0){
        selfCharacter->MP = 0;
    }
}

//*****************************NIGHTMARE*******************************

void nightmare::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
//    selfCharacter->HP -= 200;
}

void nightmare::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    selfCharacter->HP += 200;
}

//*****************************LOTUS*******************************

void lotus::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    iniT = 2;
    nT = iniT;
//    selfCharacter->HP -= 200;
}

void lotus::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
    selfCharacter->HP -= 200;
}










