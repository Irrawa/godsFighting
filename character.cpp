//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "status.h"
#include "character.h"
#include "cmove.h"
#include "field.h"
#include "field_status.h"
#include "actural_statuses.h"
#include "actural_moves.h"

using namespace std;

void character::add_status(status* S, character* creator, field* thisField){
    status* tempStatus = S;
    bool duplicateFlag = false;
    int length = this->statL.size();
    int a = 0;
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            if ((this->statL[i])->sta_name == tempStatus->sta_name) {
                duplicateFlag = true;
                a = i;
                break;
            }
        }
    }
    if (!duplicateFlag) {
        tempStatus->SetupStatus(creator, this, thisField);
        (*this).statL.push_back(tempStatus);
        cout << "添加" << endl;
    } else {
        this->statL[a]->nT = this->statL[a]->iniT;
        cout << "覆盖" << endl;
    }
//    statL.push_back(tempStatus);
};

void character::Initialize(string name, vector <cmove> cmoveList, int hp, int mp, int atk, int def, int spd){
    cName = name;
    moveL = cmoveList;
    maxHP = hp;
    maxMP = mp;
    HP = hp;
    MP = mp;
    ctr_atk = atk;
    ctr_def = def;
    ctr_spd = spd;
    cout << "Character " << cName << " created!" << endl;
}

void character::TakeTurn(character* oppoCharacter, cmove* chosenMove,field* currentField){  //角色对对方施放技能的全过程
    if ((*chosenMove).selfTarget == false) {
        cout << cName << " casted move <" << (*chosenMove).mName << "> to " << (*oppoCharacter).cName << "!" << endl;
    }
    else{
        cout << cName << " casted move <" << (*chosenMove).mName << ">!" << endl;
    }

    (*chosenMove).SpellMove(this, oppoCharacter, currentField);
    (*chosenMove).LaunchMove(this, oppoCharacter, currentField);
    (*chosenMove).ResetMove(this, oppoCharacter, currentField);
//    cout << (*oppoCharacter).HP << endl;

}

void character::SufferStatus(character* oppoCharacter, field* currentField){
    if(statL.size() > 0){
        vector <status*> NewStatL;
        for(int i = 0; i < statL.size(); i++){
            status* tempStat = statL[i];
            (*tempStat).RefStatus(this, oppoCharacter, currentField);
            tempStat -> StatusTakeEffect(this, oppoCharacter, currentField);  //效果造成影响，效果持续时间减少也在此实现
            if((*tempStat).nT >= 0){
                NewStatL.push_back(statL[i]);
            }
            else{
                tempStat->StatusLoss(this, oppoCharacter, currentField);  //状态消失时将改变的状态复原
            }
        }
        statL.clear();
        statL = NewStatL;
    }
}


string character::print(){ //输出角色状态
    stringstream infof;
    infof << "[" << cName << "]" << "\n";
    infof <<"HP:" << HP << "   MP:" << MP << "   ATK:" << ctr_atk << "   DEF:" << ctr_def << "   SPD:" << ctr_spd << "\n";
    infof << "Status: ";
    if(statL.size() > 0){
        for(int i = 0; i < statL.size(); i++){
            infof << "{" << statL[i]->sta_name << "} ";
        }
    }
    else{
        infof << "None";
    }
    infof << "\n";
    string info = infof.str();
    cout << info;
    return info;
}

string character::showIntroduction(){
    stringstream infof;
    infof << "[" << cName << "]" << "\n";
    infof <<"HP:" << HP << "   MP:" << MP << "   ATK:" << ctr_atk << "   DEF:" << ctr_def << "   SPD:" << ctr_spd << "\n";
    infof << cIntroduction << "\n";
    string info = infof.str();
    cout << info;
    return info;
};

void character::SetMove(character* opponent, field* battleField){
    if(this->cName == "Irrawa"){
        this->moveL[0] = AquaBall(this, opponent, battleField);
        this->moveL[1] = WindSlash(this, opponent, battleField);
        this->moveL[2] = Tsunami(this, opponent, battleField);
        this->moveL[3] = RainOfNayad(this, opponent, battleField);
        this->moveL[4] = Tailwind(this, opponent, battleField);
        cout << "get Irrawa" << endl;
    }

    else if(this->cName == "Mew"){
        this->moveL[0] = OneiroSting(this, opponent, battleField);
        this->moveL[1] = NetherVeil(this, opponent, battleField);
        this->moveL[2] = Desolation(this, opponent, battleField);
        this->moveL[3] = PsychoBoost(this, opponent, battleField);
        this->moveL[4] = ToxicBlast(this, opponent, battleField);
    }
    else if(this->cName == "Rosie"){
        cout << "get Rosie" << endl;
        this->moveL[0] = KissOfSuccubus(this, opponent, battleField);
        this->moveL[1] = LustStorm(this, opponent, battleField);
        this->moveL[2] = ShadowMirror(this, opponent, battleField);
        this->moveL[3] = DevilMentel(this, opponent, battleField);
        this->moveL[4] = ArcTurbo(this, opponent, battleField);

    }
    else if(this->cName == "Asibi"){

    }
}


//string cName; //角色名
//int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
////最大生命值       最大魔法值     攻击力       防御力       速度      生命值  魔法值
//vector <status> statL;
////     状态列表
//vector <cmove> moveL;
////     技能列表
//vector <status> statM;