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
#include "battle_handler.h"
//#include "battle_handler.cpp"
using namespace std;




//To disable cout, use the following method:

void PVPBattle(){
    srand (time(NULL));
    battle_handler PVPBattle;
    PVPBattle.GameMode = 1;
    PVPBattle.Initialize();
    PVPBattle.DecideCharacter();
    PVPBattle.p1Character.print();
    PVPBattle.p2Character.print();
    while(!PVPBattle.Winner) {
        PVPBattle.JudgeSpeed();
        PVPBattle.GeneralChooseMove(1);
        PVPBattle.GeneralChooseMove(2);
        if(PVPBattle.CastMove()){
            break;
        };
        bool doubleBreak = false;
        while(PVPBattle.IfSpeed()){
            PVPBattle.SpeedChooseMove();
            if(PVPBattle.SpeedCastMove()){
                doubleBreak = true;
                break;
            };
        }
        if(doubleBreak){
            break;
        }
        if(PVPBattle.DoStatus()){
            break;
        };
        PVPBattle.p1Character.print();
        PVPBattle.p2Character.print();
    }
    if(PVPBattle.Winner == 1) {
        cout << "P" << PVPBattle.Winner << " and his guardian god " << PVPBattle.p1Character.cName << " is winner!";
    }
    else{
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
    PVABattle.p1Character.print();
    PVABattle.p2Character.print();
    while(!PVABattle.Winner) {
        PVABattle.JudgeSpeed();
        PVABattle.GeneralChooseMove(1);
        PVABattle.AIChooseMove(PVABattle.AIIQ,2);
        if(PVABattle.CastMove()){
            break;
        };
        bool doubleBreak = false;
        while(PVABattle.IfSpeed()){
            PVABattle.SpeedChooseMove();
            if(PVABattle.SpeedCastMove()){
                doubleBreak = true;
                break;
            };
        }
        if(doubleBreak){
            break;
        }
        if(PVABattle.DoStatus()){
            break;
        };
        PVABattle.p1Character.print();
        PVABattle.p2Character.print();
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
    AVABattle.p1Character.print();
    AVABattle.p2Character.print();
    battle_handler backupBattle = AVABattle;
    for (int i = 0; i < iterator; i++) {
        AVABattle = backupBattle;
        if(doBalancing){
//            int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
            AVABattle.p1Character.maxHP += dAbility * 10;
            AVABattle.p1Character.maxMP += dAbility * 10;
            AVABattle.p1Character.HP += dAbility * 10;
            AVABattle.p1Character.MP += dAbility * 10;
            AVABattle.p1Character.ctr_atk += dAbility;
            AVABattle.p1Character.ctr_def += dAbility;
            AVABattle.p1Character.ctr_spd += dAbility;
            cout.setstate(std::ios_base::failbit);
        }
        while (!AVABattle.Winner) {
            AVABattle.JudgeSpeed();
            AVABattle.AIChooseMove(IQ1, 1);
            AVABattle.AIChooseMove(IQ2, 2);
            if (AVABattle.CastMove()) {
                break;
            };
            bool doubleBreak = false;
            while (AVABattle.IfSpeed()) {
                AVABattle.SpeedChooseMove();
                if (AVABattle.SpeedCastMove()) {
                    doubleBreak = true;
                    break;
                };
            }
            if (doubleBreak) {
                break;
            }
            if (AVABattle.DoStatus()) {
                break;
            };
            AVABattle.p1Character.print();
            AVABattle.p2Character.print();
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
    }


}

void GodsFighting(){
    cout << "Welcome!" << endl;
    cout << "Please insert 1, 2 or 3 to choose game mode!" << endl;
    cout << "1, [PVP Mode]-----You can battle with a friend here!" << endl;
    cout << "2, [PVA Mode]-----You can battle with AI here!" << endl;
    cout << "3, [AVA Mode]-----You can test the balance of the characters here!" << endl;
    cout << "Other key to exit the game!" << endl;
    int choice;
    cin >> choice;
    if (choice == 1){
        PVPBattle();
    }else if(choice == 2){
        PVABattle();
    }else if(choice == 3){
        AVABattle(5,5,true,50);
    }
    else{
        cout << "Bye!";
    }
}

int main() {
    GodsFighting();
    return 0;
}