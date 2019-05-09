//
// Created by 梦芙兰 on 2019/5/1.
//
#include <vector>
#include <string>
using namespace std;

#ifndef GODS_GODFIGHTING_H
#define GODS_GODFIGHTING_H
class cmove;
class field;
class character;

class status{
public:
    void SetupStatus();
    //状态被施加时，使用此函数初始化
    void RefStatus();
    //每经过一回合，所有生效的status需要使用此函数刷新。
    void StatusTakeEffect(character selfCharacter, character oppoCharacter);
    //效果产生影响
    void StatusEnd();
    //状态消失时调用的函数，主要功能为将一些状态造成的改变复原（如攻击力降低等）
private:
    string sta_name, sta_info;
    //      状态名    状态介绍
    int sta_dh, sta_dm, sta_da, sta_dd, sta_ds,
    //状态造成的生命值、魔法值、攻击、防御、速度 的变化
        sta_Odh, sta_Odm, sta_Oda, sta_Odd, sta_Ods,
        iniT, nT, sta_id;
    vector <status> sta_rmStat;
    bool sta_pos, sta_neg;


};

class character{
public:
    void TakeTurn(character oppoCharacter, cmove chosenMove,field currentField);
    //玩家针对对手玩家行动
private:
    string cName; //角色名
    int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
    //最大生命值       最大魔法值     攻击力       防御力       速度      生命值  魔法值
    vector <status> statL;
    //     状态列表
    vector <cmove> moveL;
    //     技能列表
    vector <status> statM;
};

class cmove{
public:
    void SpellMove(character speller, character receiver, field currentField);
    /*表示搓技能的过程，在此函数中初始化技能的各项数值。
    例如要搓一个使对方受到其剩余生命值(10% + (攻击者攻击力/受攻击者防御) * 10%)的伤害，则应在此函数中做到：
    1，获取speller的攻击力
    2，获取receiver的防御力和当前生命值
    3，使用公式计算伤害值
    4，将伤害值赋予技能的O_dh,注意正负号！造成伤害为负数！
    5，初始化技能的其它数值
    6，结束搓技能，进入技能生效阶段*/
    void LaunchMove(character speller, character receiver);
    //发动技能
private:
    string mName, mInfo;
    //     技能名  技能介绍
    int slf_dh, slf_dm, slf_da, slf_dd, slf_ds,
    //自身的hp、mp、atk、def、spd 变化
        opo_dh, opo_dm, opo_da, opo_dd, opo_ds,
    //对方的hp、mp、atk、def、spd 变化
        mv_atk, mv_id;
    //技能攻击，技能id
    vector <status> slf_rmStat, opo_rmStat, slf_adStat, opo_adStat;
    //          移除自身状态，移除对手状态，增加自身状态，增加对手状态（这些均为vector容器）
    bool selfTarget;
    //   作用目标是否为自身
    vector <cmove> comMove;
    //   与此技能联动施放的技能
    static int mv_idCount;
    //   计数技能id。每一种技能拥有其独立的id。

};


class field{
public:
    void FieldTakeEffect(character character1, character character2);
    //场地状态生效

private:
    vector <field_status> FStatusL;

    // 场地状态列表

    //   ！！！需要设计一个可以记录全部战斗流程的数据结构！！！

};

#endif //GODS_GODFIGHTING_H
