//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include "character.h"
#include "field.h"
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
    string realName = "";
    bool nameChanged = false;
    //     技能名  技能介绍
    int slf_dh = 0, slf_dm = 0, slf_da = 0, slf_dd = 0, slf_ds = 0,
    //自身的hp、mp、atk、def、spd 变化
            opo_dh = 0, opo_dm = 0, opo_da = 0, opo_dd = 0, opo_ds = 0,
    //对方的hp、mp、atk、def、spd 变化
            mv_atk = 0, mv_id;
    //技能攻击，技能id
    vector <status*> slf_rmStat, opo_rmStat, slf_adStat, opo_adStat;
    //          移除自身状态，移除对手状态，增加自身状态，增加对手状态（这些均为vector容器）
    vector <field_status*> field_adStat, field_rmStat;
    character* owner;
    character* taker;
    field* place;
    bool selfTarget = false;
    //   作用目标是否为自身
    vector <cmove> comMove;
    //   与此技能联动施放的技能
    static int mv_idCount;
    //   计数技能id。每一种技能拥有其独立的id。

    void set_SODhmads(int sh,int sm,int sa,int sd,int ss,int oh, int om,int oa,int od,int os);
    //用于快速定义技能，共十项参数。

    void SpellMove(character *speller, character *taker, field *thisField);
    /*表示搓技能的过程，在此函数中初始化技能的各项数值。
    例如要搓一个使对方受到其剩余生命值(10% + (攻击者攻击力/受攻击者防御) * 10%)的伤害，则应在此函数中做到：
    1，获取speller的攻击力
    2，获取receiver的防御力和当前生命值
    3，使用公式计算伤害值
    4，将伤害值赋予技能的O_dh,注意正负号！造成伤害为负数！
    5，初始化技能的其它数值
    6，结束搓技能，进入技能生效阶段*/
    void LaunchMove(character *speller, character *taker, field *thisField);
    //此阶段扣除施放技能消耗的魔法值/生命值，并造成应有的影响

    void ResetMove(character *speller, character *taker, field *thisField);

    void set_atk(int attack){ //设置技能攻击
        mv_atk = attack;
    }


};


#endif //GODS_CMOVE_H
