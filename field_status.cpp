//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "character.h"
#include "cmove.h"
#include "note_page.h"
#include "status.h"
#include "field.h"

using namespace std;

//character affecter;
//        状态生效的角色

void field_status::SetupStatus(character* maker, character* other, field* currentField){
    owner = maker;
    non_owner = other;
}
//状态被施加时，使用此函数初始化

void field_status::RefStatus(character* maker, character* other, field* currentField){}
//每经过一回合，所有生效的status需要使用此函数刷新。
void field_status::StatusTakeEffect(character* maker, character* other, field* currentField){
    (*maker).HP += sta_dh;
    (*maker).MP += sta_dm;
    (*maker).ctr_atk += sta_da;
    (*maker).ctr_def += sta_dd;
    (*maker).ctr_spd += sta_ds;
    (*other).HP += sta_Odh;
    (*other).MP += sta_Odm;
    (*other).ctr_atk += sta_Oda;
    (*other).ctr_def += sta_Odd;
    (*other).ctr_spd += sta_Ods;
//    cout << "场地效果生效："<< sta_ds << endl;
    nT -= 1;
    sta_da = 0;
    sta_dd = 0;
    sta_ds = 0;
    sta_Oda = 0;
    sta_Odd = 0;
    sta_Ods = 0;
}
//效果产生影响
void field_status::StatusLoss(character* maker, character* other, field* currentField){}
//状态消失时调用的函数，主要功能为将一些状态造成的改变复原（如攻击力降低等）