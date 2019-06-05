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

void note_page::set_beforeMoveFast(character* c){
    character C;
    C = copy_char(c);
    C00 = C;
}

void note_page::copyCharToCurrent(character* CToChange, int PageLine){
    character loadedChar;
    switch(PageLine){
        case 0: loadedChar = C00;
        case 1: loadedChar = C01;
        case 2: loadedChar = C02;
        case 3: loadedChar = C03;
        case 4: loadedChar = C04;
        case 5: loadedChar = C05;
        case 6: loadedChar = C06;
        case 7: loadedChar = C07;
        case 8: loadedChar = C08;
        case 9: loadedChar = C09;
        default: cout << "Bad input in reading history character!";
    }
    *CToChange = copy_char(&loadedChar);
}
