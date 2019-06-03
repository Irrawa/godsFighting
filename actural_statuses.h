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
#include "status.h"
//#include "note_page.h"

using namespace std;

class character;
class cmove;
//💥💦💧🌊🌨🌧💨🌬🔮💗💖💞☣️☢️❌💢♥️🗯💭☠️🌪🌈🔥☄️⚡️
class choke : public status{
public:
    choke(){
        sta_name = "CHOKE";
//        sta_logo = "\uD83D\uDCA7";
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
//        sta_logo = "\uD83D\uDCA6";
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

class netherCircuit : public status{
public:
    netherCircuit(){
        sta_name = "NETHER CIRCUIT";
        sta_info = "Increase 20 ATK and DEF, heals the character while suffer poison";
//        sta_logo = "\uD83D\uDC9E"
        iniT = 2;
        nT = iniT;
        sta_pos = true;
        sta_neg = false;
    }

    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};

//*****************************TOXIC*******************************
class toxic : public status{
public:
    float toxicEnhancer = 1;
    toxic(){
        sta_name = "TOXIC";
        sta_info = "Inflict increasing damage each turn.";
//        sta_logo = "☠️";
        iniT = 3;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }

    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);
};

//*****************************POISONED*******************************

class poisoned : public status{
public:
    poisoned(){
        sta_name = "POISONED";
        sta_info = "Inflict damage each turn.";
//        sta_logo = "\uD83D\uDC80️"
        iniT = 5;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }
    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);
};

//*****************************STATIC OVERLOAD*******************************
class staticOverload : public status{
public:
    staticOverload() {
        sta_name = "STATIC OVERLOAD";
        sta_info = "Reflect half of the damage to the opponent";
//        sta_logo = "\uD83D\uDCA2"
        iniT = 3;
        nT = iniT;
        sta_pos = true;
        sta_neg = false;
    }


virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

//virtual void StatusTakeEffect(character* self, character* oppo, field* currentField);

virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};


//*****************************SPIRITIED*******************************
class spiritified : public status{
public:
    spiritified() {
        sta_name = "SPIRITIFIED";
        sta_info = "Greatly lower the move damage Rosie takes.";
//        sta_logo = "\uD83D\uDD2E"
        iniT = 2;
        nT = iniT;
        sta_pos = true;
        sta_neg = false;
    }


    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

    virtual void RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField);

//virtual void StatusTakeEffect(character* self, character* oppo, field* currentField);

    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};

//*****************************Awakening*******************************

class awakening : public status{
public:
    awakening() {
            sta_name = "AWAKENING";
            sta_info = "Time will back flow after this status takes effect";
//            sta_logo = "\uD83D\uDCAD";
            iniT = 2;
            nT = iniT;
            sta_pos = true;
            sta_neg = false;
    }


    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);


    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};

//*****************************Nightmare*******************************

class nightmare : public status{
public:
    nightmare() {
        sta_name = "NIGHTMARE";
        sta_info = "She is now suffering a nightmare, it will end sooner or later!";
//        sta_logo = "\uD83D\uDC7E";
        iniT = 1;
        nT = iniT;
        sta_pos = true;
        sta_neg = false;
    }


    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);


    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};

//*****************************Lotus*******************************

class lotus : public status{
public:
    lotus() {
        sta_name = "LOTUS";
        sta_info = "She is now dreaming sweetness, it will end sooner or later!";
//        sta_logo = "\uD83D\uDCAB";
        iniT = 1;
        nT = iniT;
        sta_pos = false;
        sta_neg = true;
    }


    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);
    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);

};

class tickTock : public status{
public:
    tickTock(){
        sta_name = "TICK TOCK";
        sta_info = "next turn will escape from time!";
        iniT = 0;
        sta_pos = false;
        sta_neg = false;
    }
    virtual void SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField);
    virtual void StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField);
};
#endif //GODS_ACTURAL_STATUSES_H
