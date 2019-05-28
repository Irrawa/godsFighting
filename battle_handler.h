#include "character.h"
#include "status.h"
#include "cmove.h"
#include "field.h"
#include "field_status.h"
#include "note_page.h"
#include "actural_moves.h"
#include "actural_characters.h"
#include <iostream>
#include <vector>
#include <string>
#include "actural_statuses.h"
#include "note_page.h"

using namespace std;
#ifndef GODS_BATTLE_HANDLER_H
#define GODS_BATTLE_HANDLER_H

class battle_handler{
public:
    field BattleField;
    character p1Character, p2Character;
    character* fasterCharacter;
    character* slowerCharacter;// 每回合都要重新判断一次，若两者速度一样，则随机分配。
    vector <character> characterList; //供选择的角色，不能被改变。

    void Initialize();//初始化，包括创建角色名单和所有技能。
    void showCharacterList(vector <character> theList); //打印角色名单
    void ChooseCharacter(vector <character>* showcase, int playerNum);//目标玩家在showcase中选择角色
    void DecideCharacter();//双方选择各自角色，P1先选，P2后选
    void JudgeSpeed();//将p1Character和p2character分别赋给对应速度的指针

    void GeneralChooseMove(int playerNum); //P1选择时，playerNum应为1；P2选择时，playerNum应为2。

    int p1MoveNum, p2MoveNum; //玩家1，2所选择的对应角色的技能标号
    
    void CastMove(int playerNum); //playNum号玩家的角色施放技能
    void SpeedChooseMove(int playerNum);//因速度而再次选择技能时，调用此函数
    void doStatus();//先快速角色，再慢速角色，再场地
    int Judge();//判断胜负，返回0为未分出胜负，返回1为p1获胜，返回2为p2获胜。

};

#endif