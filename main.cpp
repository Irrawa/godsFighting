#include "character.h"
#include "status.h"
#include "cmove.h"
#include "field.h"
#include "field_status.h"
#include "note_page.h"
#include "actural_moves.h"
#include "actural_characters.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "actural_statuses.h"
#include "note_page.h"
#include "battle_handler.h"
//#include "battle_handler.cpp"
using namespace std;




//To disable cout, use the following method:

void showScreen(battle_handler battleHandler){
    cout << "============================================" << endl;
    int fsLen = battleHandler.BattleField.FStatusL.size();
    if(fsLen > 0){
        for(int i = 0; i < fsLen; i++){
            cout << battleHandler.BattleField.FStatusL[i]->sta_logo << endl;
        }
    }
    battleHandler.p2Character.print();
    cout << endl;
    cout << endl;
    cout << endl;
    battleHandler.p1Character.print();
    if(fsLen > 0){
        for(int i = fsLen - 1; i >= 0; i--){
            cout << battleHandler.BattleField.FStatusL[i]->sta_logo << endl;
        }
    }
    cout << "============================================" << endl;
}



void PVPBattle(){
    srand (time(NULL));
    battle_handler PVPBattle;
    PVPBattle.GameMode = 1;
    PVPBattle.Initialize();
    PVPBattle.DecideCharacter();
    showScreen(PVPBattle);
    bool play = true;
    while(play == true) {
        PVPBattle.JudgeSpeed();
        if(rand() % 2 == 1) {
            PVPBattle.GeneralChooseMove(1);
            PVPBattle.GeneralChooseMove(2);
        }
        else{
            PVPBattle.GeneralChooseMove(2);
            PVPBattle.GeneralChooseMove(1);
        }
        if (PVPBattle.CastMove()) {
            break;
        };
        bool doubleBreak = false;
        int speedCount = 0;
        while (PVPBattle.IfSpeed() && speedCount < 3) {
            PVPBattle.SpeedChooseMove();
            if (PVPBattle.SpeedCastMove()) {
                doubleBreak = true;
                break;
            };
            speedCount++;
        }
        if (doubleBreak) {
            break;
        }
        if (PVPBattle.DoStatus()) {
            break;
        };
        showScreen(PVPBattle);
    }
    if (PVPBattle.Winner == 1) {
        cout << "P" << PVPBattle.Winner << " and his guardian god " << PVPBattle.p1Character.cName << " is winner!";
    } else {
        cout << "P" << PVPBattle.Winner << " and his guardian god " << PVPBattle.p2Character.cName << " is winner!";
    }
}

void PVABattle(){
    srand (time(NULL));
    battle_handler PVABattle;
    PVABattle.GameMode = 2;
    PVABattle.Initialize();
    PVABattle.AIMode = true;
    PVABattle.DecideCharacter();
    showScreen(PVABattle);
    bool play = true;
    while(!PVABattle.Winner) {
        PVABattle.JudgeSpeed();
        PVABattle.GeneralChooseMove(1);
        PVABattle.AIChooseMove(PVABattle.AIIQ,2);
        if(PVABattle.CastMove()){
            break;
        };
        bool doubleBreak = false;
        int speedCount = 0;
        while(PVABattle.IfSpeed() && speedCount < 3){
            PVABattle.SpeedChooseMove();
            speedCount += 1;
            if(PVABattle.SpeedCastMove()){
                doubleBreak = true;
                break;
            };
            speedCount += 1;
        }
        if(doubleBreak){
            break;
        }
        if(PVABattle.DoStatus()){
            break;
        };
        showScreen(PVABattle);
    }
    if(PVABattle.Winner == 1) {
        cout << "P" << PVABattle.Winner << " and his guardian god " << PVABattle.p1Character.cName << " is winner!";
    }
    else{
        cout << "P" << PVABattle.Winner << " and his guardian god " << PVABattle.p2Character.cName << " is winner!";
    }
}

void AVABattle(int IQ1, int IQ2, bool doBalancing, int balance_round) {
    int iterator = 1;
    int dAbility = 0;
    if (doBalancing) {
        iterator = balance_round;
    }
    srand(time(NULL));
    battle_handler AVABattle;
    AVABattle.GameMode = 3;
    AVABattle.Initialize();
    AVABattle.AIMode = true;
    AVABattle.DecideCharacter();

    ifstream inputS("suggested.txt");
    if (inputS){
        inputS >> AVABattle.p1Character.maxHP >> AVABattle.p1Character.maxMP >> AVABattle.p1Character.ctr_atk\
               >> AVABattle.p1Character.ctr_def >> AVABattle.p1Character.ctr_spd;
        cout << "Original Input File Loaded!" << endl;
    }
    else{
        cout << "No File Loaded!" << endl;
    }
    inputS.close();

//    showScreen(AVABattle);
    battle_handler backupBattle = AVABattle;
    vector <int> record;
    for (int i = 0; i < iterator; i++) {
        AVABattle = backupBattle;

        if(doBalancing){
//            int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
            AVABattle.p1Character.maxHP += dAbility * 10;
            AVABattle.p1Character.maxMP += dAbility * 10;
            AVABattle.p1Character.HP = AVABattle.p1Character.maxHP;
            AVABattle.p1Character.MP = AVABattle.p1Character.maxMP;
            AVABattle.p1Character.ctr_atk += dAbility;
            AVABattle.p1Character.ctr_def += dAbility;
            AVABattle.p1Character.ctr_spd += dAbility;
            cout.setstate(std::ios_base::failbit);
        }

        ofstream suggested("suggested.txt");
        suggested << AVABattle.p1Character.maxHP << ' ' << AVABattle.p1Character.maxMP << ' ' << AVABattle.p1Character.ctr_atk \
        << ' ' << AVABattle.p1Character.ctr_def << ' ' << AVABattle.p1Character.ctr_spd;
        suggested.close();


        while (!AVABattle.Winner) {
            AVABattle.JudgeSpeed();
            AVABattle.AIChooseMove(IQ1, 1);
            AVABattle.AIChooseMove(IQ2, 2);
            if (AVABattle.CastMove()) {
                break;
            };
            bool doubleBreak = false;
            int speedCount = 0;
            while (AVABattle.IfSpeed() && speedCount < 3) {
                AVABattle.SpeedChooseMove();
                if (AVABattle.SpeedCastMove()) {
                    doubleBreak = true;
                    break;
                };
                speedCount++;
            }
            if (doubleBreak) {
                break;
            }
            if (AVABattle.DoStatus()) {
                break;
            };
            showScreen(AVABattle);
        }
        if (AVABattle.Winner == 1) {
            cout << "P" << AVABattle.Winner << " and his guardian god " << AVABattle.p1Character.cName << " is winner!";
            dAbility -= 1;
        } else {
            cout << "P" << AVABattle.Winner << " and his guardian god " << AVABattle.p2Character.cName << " is winner!";
            dAbility += 1;
        }
        cout.clear();
        cout << "Current Estimated Delta Ability:" << dAbility << endl;
        record.push_back(dAbility);

    }
//    ofstream suggested("suggested.txt");
//    suggested << AVABattle.p1Character.maxHP << ' ' << AVABattle.p1Character.maxMP << ' ' << AVABattle.p1Character.ctr_atk \
//        << ' ' << AVABattle.p1Character.ctr_def << ' ' << AVABattle.p1Character.ctr_spd;
    ofstream serie("serie.txt");
    serie << AVABattle.p1Character.cName << endl;
    for(int i = 0; i < record.size(); i++){
        serie << record[i] << endl;
    }
}


void GodsFighting(){
    bool p = true;
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' <<endl;
    cout << "========================================================" << endl;
    cout << "=============Welcome to the God's Fighting!=============" << endl;
    cout << "========================================================" << endl;
    cout << '\n' << '\n' << '\n' << endl;
    while(p) {
        cout << "Please insert 1, 2 or 3 to choose game mode!" << endl;
        cout << "1, [PVP Mode]-----You can battle with a friend here!" << endl;
        cout << "2, [PVA Mode]-----You can battle with AI here!" << endl;
        cout << "3, [AVA Mode]-----You can test the balance of the characters here!" << endl;
        cout << "Other key to exit the game!" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            PVPBattle();
            p = false;
        } else if (choice == 2) {
            PVABattle();
            p = false;
        } else if (choice == 3) {
            AVABattle(5, 5, true, 20);
            p = false;
        }
        else{
            break;
        }
        string playAgain;
        cout << "Y to return to main menu! Other to exit the game!" << endl;
        cin >> playAgain;
        if(playAgain == "y" || playAgain == "Y"){
            p = true;
        }
    }
    cout << "========================================================" << endl;
    cout << "=========================BYE!===========================" << endl;
    cout << "========================================================" << endl;
}

int main() {
    GodsFighting();
    return 0;
}