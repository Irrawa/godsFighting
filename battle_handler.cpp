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

void BattleHandler::Initialize(){
    characterList = {IRRAWA(), MEW(), ROISE()};
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

void BattleHandler::showCharacterList(vector <character> theList){
    charNum = theList.size();
    for(int i = 0; i < charNum; i++){
        cout << i + 1 << ": [-" << theList[i].cName << "-]" << end;
    }
}

void BattleHandler::ChooseCharacter(){
    vector <character> showcase;
    showcase = characterList;
    cout << "P1 please choose your character:" << endl;
    cout << "Insert the number to see more information about the character..." << endl;
    int characterNum = showcase.size();
    showCharacterList(showcase);
    int p1chooseNum;
    cin >> p1chooseNum;
    //接下来要完善选角色的工作，从此开始！
}

void BattleHandler::JudgeSpeed(){

}