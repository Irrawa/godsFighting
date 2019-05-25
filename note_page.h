//
// Created by 梦芙兰 on 2019/5/15.
//
#ifndef GODS_NOTE_PAGE_H
#define GODS_NOTE_PAGE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class cmove;
class field;
class character;
class field_status;

class note_page{
public:
    int numTurn;
    vector <character> StartCharacterL;
    vector <field_status> StartFStatusL;
    vector <character> CSerie; // 依顺序行动的角色
    vector <cmove> MSerie; //依顺序施放的技能

    note_page(int npage){
        numTurn = npage;
    }

    void set_start_characterL(vector <character> SC);

    void set_start_field_statusL(vector <field_status> SFS);

    void add_action(character acter, cmove act);

    void set_C1(character acter);

    void set_C2(character acter);


    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew}, {field_status, numTurn, }
    //   技能施放阶段：{character 行动方 cmove 行动技能, character 行动方 cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}

};


#endif //GODS_NOTE_PAGE_H
