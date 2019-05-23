//
// Created by 梦芙兰 on 2019/5/20.
//
#include "actural_characters.h"
#include "actural_moves.h"
#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "character.h"
#include "cmove.h"
#include "note_page.h"
#include "status.h"
#include "actural_statuses.h"
using namespace std;


void choke::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
    sta_ds = -15;
    cout << sta_ds << "Choke status setup..." << endl;
}

void choke::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField) {
    if (nT > 0 && nT < iniT) {
        sta_ds = 0;
    }
}

void choke::StatusLoss(character* selfCharacter){
    (*selfCharacter).ctr_spd += 15;
}