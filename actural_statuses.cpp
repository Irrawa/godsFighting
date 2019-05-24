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