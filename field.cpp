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

void field::add_status(field_status* S){
    field_status* tempStatus = S;
    FStatusL.push_back(tempStatus);
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