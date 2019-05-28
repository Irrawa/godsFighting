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
//        cout << "添加" << tempStatus->sta_name << endl;

    } else {
        this->FStatusL[a]->StatusLoss(this->FStatusL[a]->owner, this->FStatusL[a]->non_owner, this);
        this->FStatusL[a]->nT = this->FStatusL[a]->iniT;
        this->FStatusL[a]->owner = maker;
        this->FStatusL[a]->non_owner = other;
//        cout << "覆盖" << endl;
    }
};

void field::FieldSufferStatus(character* p1, character* p2){
    if(FStatusL.size() > 0){
        vector <field_status*> NewStatL;
        for(int i = 0; i < FStatusL.size(); i++){
            field_status* tempStat = FStatusL[i];
            string OwnerName = FStatusL[i]->owner->cName;
            string NonOwnerName = FStatusL[i]->non_owner->cName;
            character* owner;
            character* other;
            if(OwnerName == p1->cName){
                owner = p1;
                other = p2;
            }
            else{
                owner = p2;
                other = p1;
            }
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

void field::NewPage(){
    note_page NewPage;
    cout << "Page in New: " << &NewPage << endl;
    int lastNum = battleRecord.size();
    NewPage.setPageNum(lastNum + 1);
    battleRecord.push_back(NewPage);
    cout << "Page in record in funciton: " << &(battleRecord[0]) << endl;
    cout << "Page " << lastNum + 1 << " created!" << endl;
}

note_page field::GetPage(int PageNum){
    int currentTail = battleRecord.size() - 1;
    if(PageNum > currentTail && currentTail >= 0){
        cout << "Recalled bad page No." << PageNum << ", returning current tail page No. "<< currentTail << "!!!" << endl;
        return battleRecord[currentTail];
    }
    else if(currentTail >= 0 && PageNum >= 0){
        return battleRecord[PageNum];
    }
    else if(currentTail < 0){
        cout << "No record Founded!" << endl;
        note_page NewPage;
        return NewPage;
    }
    else{
        cout << "Recalled bad page No." << PageNum << ", returning current head page No. "<< 0 << "!!!" << endl;
        return battleRecord[0];
    }
}

note_page field::GetCurrentPage(){
    return GetPage(battleRecord.size() - 1);
}

void field::WriteRecord(character *targetC, int pageLine){
    note_page* lastPage = &(this->battleRecord[this->battleRecord.size() - 1]);
    switch (pageLine){
        case 0: lastPage->set_beforeMoveFast(targetC); break;
        case 1: lastPage->set_beforeMoveSlow(targetC); break;
        case 2: lastPage->set_after1stMoveFast(targetC); break;
        case 3: lastPage->set_after1stMoveSlow(targetC); break;
        case 4: lastPage->set_after2ndMoveFast(targetC); break;
        case 5: lastPage->set_after2ndMoveSlow(targetC); break;
        case 6: lastPage->set_after1stStatFast(targetC); break;
        case 7: lastPage->set_after1stStatSlow(targetC); break;
        case 8: lastPage->set_after2ndStatFast(targetC); break;
        case 9: lastPage->set_after2ndStatSlow(targetC); break;
    }
}