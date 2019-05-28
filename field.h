//
// Created by 梦芙兰 on 2019/5/15.
//

#ifndef GODS_FIELD_H
#define GODS_FIELD_H

#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "actural_field_status.h"
#include "note_page.h"
using namespace std;

class cmove;
class field;
class character;
class field_status;
class note_page;

class field{
public:
    vector <field_status*> FStatusL;
    // 场地状态列表
    vector <note_page> BattleRecord;

    character fasterCharacter;
    character slowerCharacter;

    int current_control_state[3];
    //[当前是第几回合，C1已行动几次，C2已行动几次]

    void build_begin_state(character C1, character C2);
    //建立初始场地状态，包括建立current_control_state[3]的初始状态[0,0,0]，
    //初始化各角色，建立第一页记录

    void judge_speed();
    //判断双方速度，修改fasterCharacter和slowerCharacter参数

    bool A_moveto_B(character A, cmove M, character B);
    //A搓技能
    //A施放技能
    //清算，判断是否分出胜负
    //若分出胜负，则返回true，否则false

    character& get_winner();
    //返回胜利者

    bool if_move_again(character fasterC, character slowerC);
    //判断快速一方是否应继续行动

    bool status_take_effect(character* faster, character* slower);
    //状态生效，应包括
    //1，根据所剩回合数和总回合数判断是否为第一回合/随后一回合
    //2，计算状态将造成的影响
    //3，状态生效，造成变化
    //4，清算是否分出胜负，分出返回true，不分出返回false

    void FieldSufferStatus(character* p1, character* p2);
    //场地状态生效


    //   ！！！需要设计一个可以记录全部战斗流程的数据结构！！！
    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew},{field_status, numTurn, }
    //   技能施放阶段：{character 行动方, cmove 行动技能, character 行动方, cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}

    void add_status(field_status* S, character* maker, character* other);

    nayadBreeze RainOfNayad;
    poisonAura PoisonAura;

    vector <note_page> battleRecord;

    void NewPage();  //在战斗记录中新加一页

    note_page GetPage(int PageNum);  //读取战斗记录的指定页

    note_page GetCurrentPage();  //读取当前页

    void WriteRecord(character *targetC, int pageLine);





};

#endif //GODS_FIELD_H
