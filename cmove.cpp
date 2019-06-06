//
// Created by 梦芙兰 on 2019/5/15.
//
#include "character.h"
#include "cmove.h"
#include "status.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void cmove::set_SODhmads(int sh = 0,int sm = 0,int sa = 0,int sd = 0,int ss = 0,int oh = 0 ,int om = 0,int oa = 0,int od = 0,int os = 0){
    slf_dh = sh;
    slf_dm = sm;
    slf_da = sa;
    slf_dd = sd;
    slf_ds = ss;
    opo_dh = oh;
    opo_dm = om;
    opo_da = oa;
    opo_dd = od;
    opo_ds = os;
}

void cmove::SpellMove(character *speller, character *taker, field *thisField){
    if((*taker).ctr_def < 1){
        (*taker).ctr_def = 1;
    }
    int damage = mv_atk * (*speller).ctr_atk / ((*taker).ctr_def + 1);
    opo_dh -= damage;
    if(opo_dh < 0){
        cout << "The move <" << mName <<"> inflicted *" << -opo_dh << "* damage to " << (*taker).cName << endl;
    }
    if(slf_dh < 0){
        cout << "The move <" << mName <<"> inflicted *" << -slf_dh << "* damage to " << (*speller).cName << endl;
    }
    if(opo_dh > 0){
        cout << "The move <" << mName <<"> healed *" << opo_dh << "* to " << (*taker).cName << endl;
    }
    if(slf_dh > 0){
        cout << "The move <" << mName <<"> healed *" << slf_dh << "* to " << (*speller).cName << endl;
    }

}

void cmove::LaunchMove(character *speller, character *taker, field *thisField) {
    owner = speller;
    int rmLen = slf_rmStat.size();  //删除自身的指定状态列表
    if(rmLen > 0){
        int len = speller->statL.size();
        vector <status*> NewStatL;
        for (int i = 0; i < len; i++){
            bool deleteFlag = false;
            string originName = speller->statL[i]->sta_name;
            for (int j = 0; j < rmLen; j++){
                if(originName == slf_rmStat[j]->sta_name){
                    deleteFlag = true;
                }
            }
            if(deleteFlag){
                speller->statL[i]->StatusLoss(speller, taker, thisField);
            }
            else{
                NewStatL.push_back(speller->statL[i]);
            }
        }
        speller->statL = NewStatL;
    }

    rmLen = opo_rmStat.size();  //删除对方的指定状态列表
    if(rmLen > 0){
        int len = taker->statL.size();
        vector <status*> NewStatL;
        for (int i = 0; i < len; i++){
            bool deleteFlag = false;
            string originName = taker->statL[i]->sta_name;
            for (int j = 0; j < rmLen; j++){
                if(originName == opo_rmStat[j]->sta_name){
                    deleteFlag = true;
                }
            }
            if(deleteFlag){
                taker->statL[i]->StatusLoss(taker, speller, thisField);
            }
            else{
                NewStatL.push_back(taker->statL[i]);
            }
        }
        taker->statL = NewStatL;
    }

    if (slf_adStat.size() != 0) {
//        cout << "add self stat" << endl;
        for (int i = 0; i < slf_adStat.size(); i++) {
            status *tempStatus = slf_adStat[i];
            speller->add_status(tempStatus, speller, thisField);
        }
    }

    if (opo_adStat.size() != 0) {
        for (int i = 0; i < opo_adStat.size(); i++) {
            status *tempStatus = opo_adStat[i];
            taker->add_status(tempStatus, speller, thisField);
        }
    }
    if (field_adStat.size() != 0) {
        for (int i = 0; i < field_adStat.size(); i++) {
            field_status *tempStatus = field_adStat[i];
            thisField->add_status(tempStatus, speller, taker);

        }
    }
    (*speller).HP += slf_dh;
    (*speller).MP += slf_dm;
    (*speller).ctr_atk += slf_da;
    (*speller).ctr_def += slf_dd;
    (*speller).ctr_spd += slf_ds;
    (*taker).HP += opo_dh;
    (*taker).MP += opo_dm;
    (*taker).ctr_atk += opo_da;
    (*taker).ctr_def += opo_dd;
    (*taker).ctr_spd += opo_ds;

    speller->MP = max(speller->MP, 0);
    speller->ctr_atk = max(speller->ctr_atk, 1);
    speller->ctr_def = max(speller->ctr_def, 1);
    speller->ctr_spd = max(speller->ctr_spd, 1);
    taker->MP = max(taker->MP, 0);
    taker->ctr_atk = max(taker->ctr_atk, 1);
    taker->ctr_def = max(taker->ctr_def, 1);
    taker->ctr_spd = max(taker->ctr_spd, 1);

}
//    cout << (*taker).HP << endl;

void cmove::ResetMove(character *speller, character *taker, field *thisField){
    int damage = mv_atk * (*speller).ctr_atk / (*taker).ctr_def;
    opo_dh -= damage;
}