//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef GODS_CMOVE_H
#define GODS_CMOVE_H

class field;
class character;
class field_status;
class status;

class cmove{
public:
    string mName, mInfo;
    //     技能名  技能介绍
    int slf_dh = 0, slf_dm = 0, slf_da = 0, slf_dd = 0, slf_ds = 0,
    //自身的hp、mp、atk、def、spd 变化
            opo_dh = 0, opo_dm = 0, opo_da = 0, opo_dd = 0, opo_ds = 0,
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

    void SpellMove(character speller, character taker, vector <field_status> SFS);
    /*表示搓技能的过程，在此函数中初始化技能的各项数值。
    例如要搓一个使对方受到其剩余生命值(10% + (攻击者攻击力/受攻击者防御) * 10%)的伤害，则应在此函数中做到：
    1，获取speller的攻击力
    2，获取receiver的防御力和当前生命值
    3，使用公式计算伤害值
    4，将伤害值赋予技能的O_dh,注意正负号！造成伤害为负数！
    5，初始化技能的其它数值
    6，结束搓技能，进入技能生效阶段*/
    void LaunchMove(character speller, character receiver, vector <field_status> SFS);
    //此阶段扣除施放技能消耗的魔法值/生命值，并造成应有的影响

    void set_SODhmads(int sh = 0,int sm = 0,int sa = 0,int sd = 0,int ss = 0,int oh = 0 ,int om = 0,int oa = 0,int od = 0,int os = 0){
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

    void set_atk(int attack){
        mv_atk = attack;
    }
};




#endif //GODS_CMOVE_H