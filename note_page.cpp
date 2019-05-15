//
// Created by 梦芙兰 on 2019/5/15.
//

#include "note_page.h"
#include "cmove.h"
#include "field_status.h"
#include "character.h"
using namespace std;


void note_page::add_action(character acter, cmove act){ //添加角色和其行动
    CSerie.push_back(acter);
    MSerie.push_back(act);
}

void note_page::set_start_field_statusL(vector <field_status> SFS){
    int length = SFS.size();
    for (int i = 0; i < length; i++){
        field_status tempFS;
        tempFS = SFS[i];
        StartFStatusL[i] = tempFS;
    }
}