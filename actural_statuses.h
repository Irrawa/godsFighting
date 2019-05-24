//
// Created by 梦芙兰 on 2019/5/20.
//

#ifndef GODS_ACTURAL_STATUSES_H
#define GODS_ACTURAL_STATUSES_H
#include "actural_characters.h"
#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "note_page.h"
#include "status.h"

using namespace std;

class character;
class cmove;

class choke : public status{
public:
    choke(){
        sta_name = "CHOKE";
        sta_info = "Reduce speed by 15. Last 3 turns.";
        iniT = 3;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }

    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);
};

class aquaBlast : public status{
public:
    aquaBlast(){
        sta_name = "AQUA BLAST";
        sta_info = "Deals 300 damage after 2 turns.";
        iniT = 2;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }

    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusTakeEffect(character* self, character* oppo, field* currentField);
};

//extern choke *ChokePtr;


#endif //GODS_ACTURAL_STATUSES_H
