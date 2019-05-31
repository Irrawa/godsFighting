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



void status::StatusTakeEffect(character* self, character* oppo, field* currentField){
    (*self).HP += sta_dh;
    (*self).MP += sta_dm;
    (*self).ctr_atk += sta_da;
    (*self).ctr_def += sta_dd;
    (*self).ctr_spd += sta_ds;
    (*oppo).HP += sta_Odh;
    (*oppo).MP += sta_Odm;
    (*oppo).ctr_atk += sta_Oda;
    (*oppo).ctr_def += sta_Odd;
    (*oppo).ctr_spd += sta_Ods;
    nT -= 1;
    sta_da = 0;
    sta_dd = 0;
    sta_ds = 0;
    sta_Oda = 0;
    sta_Odd = 0;
    sta_Ods = 0;
}

void status::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status setup..."<< endl;
}

void status::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status refreshed..."<< endl;
}


void status::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status Lost.."<< endl;
}

string status::get_information(){
    string output = "[" + sta_name + "]" + ":\n" + sta_info + "\nLEFT:" + to_string(nT + 1) + "turns\n";
    return output;
}

//💥💦💧🌊🌨🌧💨🌬🔮💗💖💞☣️☢️❌💢♥️🗯💭☠️🌪🌈🔥☄️⚡️
