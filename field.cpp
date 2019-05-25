//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "field.h"
#include "character.h"
#include "cmove.h"
using namespace std;

void field::add_status(field_status* S, character* maker, character* other){
    field_status* tempStatus = S;
    bool duplicateFlag = false;
    int length = this->FStatusL.size();
    int a = 0;
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            if ((this->FStatusL[i])->sta_name == tempStatus->sta_name) {
                duplicateFlag = true;
                a = i;
                break;
            }
        }
    }
    if (!duplicateFlag) {
        tempStatus->SetupStatus(maker, other, this);
        this->FStatusL.push_back(tempStatus);
        cout << "添加" << tempStatus->sta_name << endl;
    } else {
        this->FStatusL[a]->nT = this->FStatusL[a]->iniT;
        cout << "覆盖" << endl;
    }
};

void field::FieldSufferStatus(character* owner, character* other){
    if(FStatusL.size() > 0){
        vector <field_status*> NewStatL;
        for(int i = 0; i < FStatusL.size(); i++){
            field_status* tempStat = FStatusL[i];
            (*tempStat).RefStatus(owner, other, this);
            tempStat -> StatusTakeEffect(owner, other, this);  //效果造成影响，效果持续时间减少也在此实现
            if((*tempStat).nT >= 0){
                NewStatL.push_back(FStatusL[i]);
            }
            else{
                tempStat->StatusLoss(owner, other, this);  //状态消失时将改变的状态复原
            }
        }
        FStatusL.clear();
        FStatusL = NewStatL;
    }
}