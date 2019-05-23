//
// Created by 梦芙兰 on 2019/5/15.
//
#include "character.h"
#include "cmove.h"
#include "status.h"
#include <iostream>
#include <vector>
#include <string>
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
    int damage = mv_atk * (*speller).ctr_atk / (*taker).ctr_def;
    opo_dh -= damage;
    if(opo_dh < 0){
        cout << "The move <" << mName <<"> inflicted *" << damage << "* damage to " << (*taker).cName << endl;
    }
}

void cmove::LaunchMove(character *speller, character *taker, field *thisField) {
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
    if (slf_adStat.size() != 0) {
        for (int i = 0; i < slf_adStat.size(); i++) {
            status *tempStatus = &slf_adStat[i];
//            cout << tempStatus->get_information() << endl;
            tempStatus->SetupStatus(speller, taker, thisField);
            (*speller).add_status(tempStatus);
        }
    }
    if (opo_adStat.size() != 0){
        for (int i = 0; i < opo_adStat.size(); i++) {
            status *tempStatus = &opo_adStat[i];
            cout << tempStatus->get_information() << endl;

            tempStatus->SetupStatus(speller, taker, thisField);  //<------出问题的地方

            cout << tempStatus->get_information() << endl;
            (*taker).add_status(tempStatus);
        }
    }
//    cout << (*taker).HP << endl;
}