//
// Created by 梦芙兰 on 2019/5/15.
//
#ifndef GODS_NOTE_PAGE_H
#define GODS_NOTE_PAGE_H

#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "status.h"

using namespace std;
class cmove;
class field;
class field_status;

class note_page{
public:
    //*******选择技能******
    //      记录先手方          0
    character C00;

    //      记录后手方          1
    character C01;

    //****先手方施放技能****
    //      记录先手方          2
    character C02;

    //      记录后手方          3
    character C03;

    //****后手方施放技能****
    //      记录先手方          4
    character C04;

    //      记录后手方          5
    character C05;

    //      先手方技能          A
    int MA;

    //      后手方技能          B
    int MB;

    //****先手方遭受状态****
    //      记录先手方          6
    character C06;

    //      记录后手方          7
    character C07;

    //****后手方遭受状态****
    //      记录先手方          8
    character C08;

    //      记录后手方          9
    character C09;

    vector <character*> CMemory = {&C00, &C01, &C02, &C03, &C04, &C05, &C06, &C07, &C08, &C09,};


    int pageNum; //页码

    void setPageNum(int num){
        pageNum = num;
    }

    character copy_char(character* originChar); //将原角色的所有特征拷贝（重点是状态指针的操作）

    void set_beforeMoveFast(character* c00);

    void set_beforeMoveSlow(character* c01){
        C01 = copy_char(c01);
    }

    void set_after1stMoveFast(character* c02){
        C02 = copy_char(c02);
    }

    void set_after1stMoveSlow(character* c03){
        C03 = copy_char(c03);
    }

    void set_after2ndMoveFast(character* c04){
        C04 = copy_char(c04);
    }

    void set_after2ndMoveSlow(character* c05){
        C05 = copy_char(c05);
    }

    void set_after1stStatFast(character* c06){
        C06 = copy_char(c06);
    }

    void set_after1stStatSlow(character* c07){
        C07 = copy_char(c07);
    }

    void set_after2ndStatFast(character* c08){
        C06 = copy_char(c08);
    }

    void set_after2ndStatSlow(character* c09){
        C09 = copy_char(c09);
    }

    void copyCharToCurrent(character* CToChange, int PageLine);


    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew}, {field_status, numTurn, }
    //   技能施放阶段：{character 行动方 cmove 行动技能, character 行动方 cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}

};


#endif //GODS_NOTE_PAGE_H
