#include "battle_handler.h"
#include "character.h"
#include "status.h"
#include "cmove.h"
#include "field.h"
#include "field_status.h"
#include "note_page.h"
#include "actural_moves.h"
#include "actural_characters.h"
#include <iostream>
#include <vector>
#include <string>
#include "actural_statuses.h"
#include "note_page.h"

using namespace std;

void battle_handler::Initialize(){

    cout << "initializing" << endl;
    characterList = {IRRAWA(), MEW(), ROSIE()};
    cmove aqua_ball = AquaBall();
    cmove wind_slash = WindSlash();
    cmove psycho_boost = PsychoBoost();
    cmove tsunami = Tsunami();
    cmove rain_of_nayad = RainOfNayad();
    cmove tailwind = Tailwind();
    cmove oneiro_sting = OneiroSting();
    cmove nether_veil = NetherVeil();
    cmove desolation = Desolation();
    cmove toxic_blast = ToxicBlast();
    cmove kiss_of_succubus = KissOfSuccubus();
    cmove lust_storm = LustStorm();
    cmove shadow_mirror = ShadowMirror();
    cmove devil_mentel = DevilMentel();
    cmove arc_turbo = ArcTurbo();
}

void battle_handler::showCharacterList(vector <character> theList){
    int charNum = theList.size();
    for(int i = 0; i < charNum; i++){
        cout << i + 1 << ": [-" << theList[i].cName << "-]" << endl;
    }
}

void battle_handler::ChooseCharacter(vector <character>* showcase, int playerNum){
    bool pChooseSuccess = false;
    while(!pChooseSuccess){
        cout << "P" << playerNum << " please choose your character:" << endl;
        cout << "Insert the number to see more information about the character..." << endl;
        int characterNum = showcase->size();
        showCharacterList(*showcase);
        string sss;
        int pChooseNum;
        cin >> sss;
        pChooseNum = atoi(sss.c_str());
        if(pChooseNum > 0 && pChooseNum <= characterNum){
            bool pVerified = false;
            while(!pVerified){
                (*showcase)[pChooseNum - 1].print();
                cout << "Will you choose her as your God?(Y/N)" << endl;
                char pVNum;
                cin >> pVNum;
                if(pVNum == 'y' || pVNum == 'Y') {
                    if(playerNum == 1) {
                        p1Character = (*showcase)[pChooseNum - 1];
                    }
                    else if(playerNum == 2) {
                        p2Character = (*showcase)[pChooseNum - 1];
                    }
                    cout << "P"<< playerNum <<" choosed " << (*showcase)[pChooseNum - 1].cName << " as his god! Good luck to you!"<< endl;
                    (*showcase).erase(showcase->begin() + pChooseNum);
                    pVerified = true;
                    pChooseSuccess = true;
                }
                else{
                    pChooseSuccess = false;
                    pVerified = true;
                }
            }
        }
        else{
            cout << "Invalid Input!" << endl;
            fflush(stdin);
            pChooseSuccess = false;
//            cin.clear();//清除错误标记，重新打开输入流，但是输入流中依旧保留着之前的不匹配的类型
            /*cin.sync();*///清楚cin缓存区的数据。
        }
    }
}

void battle_handler::DecideCharacter(){
    vector <character> showcase = characterList;
    ChooseCharacter(&showcase, 1);
    ChooseCharacter(&showcase, 2);
}

void battle_handler::JudgeSpeed(){

}