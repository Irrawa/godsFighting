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

//    cout << "initializing" << endl;
    characterList = {IRRAWA(), MEW(), ROSIE(), ASIBI()};
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
    cmove objective_illusion = ObjectiveIllusion();
    cmove dark_void = DarkVoid();
    cmove utopia = Utopia();
    srand(time(NULL));
    Winner = 0;
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
                (*showcase)[pChooseNum - 1].showIntroduction();  //输出角色简介
                cout << "Will you choose her as your God?(Y/N)" << endl;
                char pVNum;
                cin >> pVNum;
                if(pVNum == 'y' || pVNum == 'Y') {
                    if(playerNum == 1) {
                        p1Character = (*showcase)[pChooseNum - 1];
                        cout << "P"<< playerNum <<" choosed " << p1Character.cName << " as his god! Good luck to you!"<< endl;
                    }
                    else if(playerNum == 2) {
                        p2Character = (*showcase)[pChooseNum - 1];
                        cout << "P"<< playerNum <<" choosed " << p2Character.cName << " as his god! Good luck to you!"<< endl;
                    }
                    (*showcase).erase(showcase->begin() + pChooseNum - 1);
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
//            fflush(stdin);
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
    p1Character.SetMove(&p2Character, &BattleField);
    p2Character.SetMove(&p1Character, &BattleField);
}

void battle_handler::JudgeSpeed(){
    if(p1Character.ctr_spd > p2Character.ctr_spd){
        fasterCharacter = &p1Character;
        slowerCharacter = &p2Character;
    }
    else if (p1Character.ctr_spd < p2Character.ctr_spd){
        fasterCharacter = &p2Character;
        slowerCharacter = &p1Character;
    }
    else{
        //两者速度相同的情况
        srand ( time(NULL) );
        int faster = rand() % 2;
        if(faster == 0){
            fasterCharacter = &p1Character;
            slowerCharacter = &p2Character;
        }
        else{
            fasterCharacter = &p2Character;
            slowerCharacter = &p1Character;
        }
    }
}

void battle_handler::GeneralChooseMove(int playNum){
    if(playNum == 1){
        p1Character.showMoveInfo();
    }
    else{
        p2Character.showMoveInfo();
    }

    bool validInput = false;
    int MLen = 0;
    int mChooseNum;
    if(playNum == 1){
        MLen = p1Character.moveL.size();
    }
    else{
        MLen = p2Character.moveL.size();
    }

    while(!validInput) {
        string sss;
        cin >> sss;
        mChooseNum = atoi(sss.c_str());
        if (mChooseNum <= MLen && mChooseNum > 0){
            validInput = true;
        }
    }

    if(playNum == 1){
        p1MoveNum = mChooseNum - 1;
        if(p1Character.cName == fasterCharacter->cName){
            fasterMoveNum = p1MoveNum;
        }
        else{
            slowerMoveNum = p1MoveNum;
        }
    }
    else if(playNum == 2){
        p2MoveNum = mChooseNum - 1;
        if(p2Character.cName == fasterCharacter->cName){
            fasterMoveNum = p2MoveNum;
        }
        else{
            slowerMoveNum = p2MoveNum;
        }
    }
}

int battle_handler::IfWin(){
    if(p1Character.HP <= 0 && p2Character.HP >= 0){
        Winner = 2;
        return 2;
    }
    else if (p2Character.HP <= 0 && p1Character.HP > 0){
        Winner = 1;
        return 1;
    }
    else{
        return 0;
    }
}

int battle_handler::CastMove(){
    BattleField.NewPage();
    fasterCharacter->SetMove(slowerCharacter, &BattleField);
    BattleField.WriteRecord(fasterCharacter, 0);
    BattleField.WriteRecord(slowerCharacter, 1);
    fasterCharacter->TakeTurn(slowerCharacter, &(fasterCharacter->moveL[fasterMoveNum]), &BattleField);
    if(IfWin()){
        return IfWin();
    }
    slowerCharacter->SetMove(fasterCharacter, &BattleField);
    BattleField.WriteRecord(fasterCharacter, 2);
    BattleField.WriteRecord(slowerCharacter, 3);
    slowerCharacter->TakeTurn(fasterCharacter, &(slowerCharacter->moveL[slowerMoveNum]), &BattleField);
    BattleField.WriteRecord(fasterCharacter, 4);
    BattleField.WriteRecord(slowerCharacter, 5);
    return IfWin();
}

bool battle_handler::IfSpeed(){
    //P = min(max([(SPD_A/SPD_B) – 1] * softer, 0),maxP)
    float maxP = 0.9;
    float softer = 0.5;
    float P = (((float)fasterCharacter->ctr_spd / (float)slowerCharacter->ctr_spd) - 1.) * softer;
//    cout << fasterCharacter->ctr_spd << endl;
//    cout << slowerCharacter->ctr_spd << endl;
    if(P < 0.){
        P = 0.;
    }
    else if(P > maxP){
        P = maxP;
    };
    float random = (float)(rand() % (10000)) / (float)(10000);
//    cout << P << endl;
//    cout << random << endl;
    if(random <= P){
        return true;
    }
    else{
        return false;
    }
}

void battle_handler::SpeedChooseMove(){
    if(AIMode == false) {
        cout << fasterCharacter->cName << "'s speed advantage gained her another turn!" << endl;
        fasterCharacter->showMoveInfo();
        int sChooseNum;
        bool validInput = false;
        int MLen = fasterCharacter->moveL.size();
        while (!validInput) {
            string sss;
            cin >> sss;
            sChooseNum = atoi(sss.c_str());
            if (sChooseNum <= MLen && sChooseNum > 0) {
                validInput = true;
            }
        }
        speedMoveNum = sChooseNum - 1;
    }
    else{
        speedMoveNum = rand() % fasterCharacter->moveL.size();
    }
}


int battle_handler::SpeedCastMove(){
    fasterCharacter->SetMove(slowerCharacter, &BattleField);
    fasterCharacter->TakeTurn(slowerCharacter, &(fasterCharacter->moveL[speedMoveNum]), &BattleField);
    BattleField.WriteRecord(fasterCharacter, 4);
    BattleField.WriteRecord(slowerCharacter, 5);
    return IfWin();
}

int battle_handler::DoStatus(){
    fasterCharacter->SufferStatus(slowerCharacter, &BattleField);
    if(IfWin()){
        return IfWin();
    }
    BattleField.WriteRecord(fasterCharacter, 6);
    BattleField.WriteRecord(slowerCharacter, 7);
    slowerCharacter->SufferStatus(fasterCharacter, &BattleField);
    if(IfWin()){
        return IfWin();
    }
    BattleField.WriteRecord(fasterCharacter, 8);
    BattleField.WriteRecord(slowerCharacter, 9);
    BattleField.FieldSufferStatus(&p1Character, &p2Character);
    return IfWin();
}

static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long xorshf96(void) {          //period 2^96-1
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    return z;
}

int MontCarlo(battle_handler* thisBattle, int AIThisMoveNum, int AIplayerNum){
    cout.setstate(std::ios_base::failbit);
    battle_handler mirrorBattle;
    mirrorBattle.Initialize();
    mirrorBattle = *thisBattle;
    if(AIplayerNum == 1){
        mirrorBattle.AICharacter = &mirrorBattle.p1Character;
    }
    else{
        mirrorBattle.AICharacter = &mirrorBattle.p2Character;
    }
    mirrorBattle.JudgeSpeed();
    mirrorBattle.MirrorMode = true;
    int turn = 0;
    srand(time(NULL));
    while(!mirrorBattle.Winner){
        mirrorBattle.JudgeSpeed();
        if(turn > 0) {
            mirrorBattle.fasterMoveNum = rand() % mirrorBattle.fasterCharacter->moveL.size();
            mirrorBattle.slowerMoveNum = rand() % mirrorBattle.slowerCharacter->moveL.size();
        }
        else{
            if(mirrorBattle.AICharacter->cName == mirrorBattle.fasterCharacter->cName){

                mirrorBattle.fasterMoveNum = AIThisMoveNum;

//                cout.clear();
//                cout << xorshf96() << endl;
//                cout.setstate(std::ios_base::failbit);

                mirrorBattle.slowerMoveNum = xorshf96() % mirrorBattle.slowerCharacter->moveL.size();
            }
            else{
                mirrorBattle.slowerMoveNum = AIThisMoveNum;
                mirrorBattle.fasterMoveNum = xorshf96() % mirrorBattle.fasterCharacter->moveL.size();
            }
        }
        if(mirrorBattle.CastMove()){
            break;
        };
        bool doubleBreak = false;
        while(mirrorBattle.IfSpeed()){
            mirrorBattle.speedMoveNum = rand() % mirrorBattle.fasterCharacter->moveL.size();
            if(mirrorBattle.SpeedCastMove()){
                doubleBreak = true;
                break;
            };
        }
        if(doubleBreak){
            break;
        }
        if(mirrorBattle.DoStatus()){
            break;
        };
        turn += 1;
    }
    return mirrorBattle.Winner;
}

int battle_handler::AIChooseMove(int IQ, int AIplayerNum){
    if(AIplayerNum == 1){
        AICharacter = &p1Character;
    }
    else{
        AICharacter = &p2Character;
    }
    battle_handler backupBattle = *this;
    cout.setstate(std::ios_base::failbit); //屏蔽cout输出
    vector <int> winList;
    int MaxCount = 0;
    int recommendedMove = rand() % this->AICharacter->moveL.size() ;
    for (int i = 0; i < AICharacter->moveL.size(); i++) { //
        int winCount = 0;
        for (int j = 0; j < IQ; j++) {
            if(MontCarlo(this, i, AIplayerNum) == 2){
                winCount += 1;
//                cout.clear();
//                cout << i << ": Win" << endl;
//                cout.setstate(std::ios_base::failbit);
            }
//            else {
//                cout.clear();
//                cout << i << ": Lose" << endl;
//                cout.setstate(std::ios_base::failbit);
//            }
        }
        winList.push_back(winCount);
        if(winCount > MaxCount){
            MaxCount = winCount;
            recommendedMove = i;
        }
//                cout.clear();
//                cout << i << ":" << winCount << endl;
//                cout.setstate(std::ios_base::failbit);
    }
    *this = backupBattle;
    if(AICharacter->cName == fasterCharacter->cName){
        fasterMoveNum = recommendedMove;
    }
    else{
        slowerMoveNum = recommendedMove;
    }
    cout.clear();//解放cout输出
    return recommendedMove;
}

//Rosie.SufferStatus(&Irrawa, &TestField);