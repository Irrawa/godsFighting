//
// Created by 梦芙兰 on 2019/5/15.
//

#include "note_page.h"
#include "cmove.h"
#include "field_status.h"
#include "character.h"
#include "status.h"

using namespace std;

character checkedCharacter1;
character checkedCharacter2;


character note_page::copy_char(character* originChar){
    character newChar = *originChar;
    int lenStat = originChar->statL.size();
    int lenAllStat = newChar.noteStatL.size();
    if(lenStat > 0) {
        vector <status*> newStatL;
        for (int i = 0; i < lenStat; i++){
            string staName = originChar->statL[i]->sta_name;
            for (int j = 0; j < lenAllStat; j++){
                if(staName == newChar.noteStatL[j]->sta_name){
                    newStatL.push_back(newChar.noteStatL[j]);
                }
            }
        }
        newChar.statL = newStatL;
    }
    return newChar;
}
