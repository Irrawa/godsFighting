//
// Created by 梦芙兰 on 2019/5/15.
//
#include "character.h"
#include "cmove.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void cmove::SpellMove(character speller, character taker, vector <field_status> SFS){

}

void cmove::LaunchMove(character speller, character taker, vector <field_status> SFS) {
    speller.HP += slf_dh;
    speller.MP += slf_dm;
    speller.ctr_atk += slf_da;
    speller.ctr_def += slf_dd;
    speller.ctr_spd += slf_ds;
    taker.HP += opo_dh;
    taker.MP += opo_dm;
    taker.ctr_atk += opo_da;
    taker.ctr_def += opo_dd;
    taker.ctr_spd += opo_ds;
    if (slf_adStat.size() != 0) {
        for (int i = 0; i < slf_adStat.size(); i++) {
            speller.add_status(slf_adStat[i]);
        }
    }
}