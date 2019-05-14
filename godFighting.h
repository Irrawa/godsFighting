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
    //对对手造成的...变化
        iniT, nT, sta_id;
    //初始持续时间 目前持续时间 状态id
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

class field_status{
    //场地状态
public:
    void SetupStatus();
    //状态被施加时，使用此函数初始化
    void RefStatus();
    //每经过一回合，所有生效的status需要使用此函数刷新。
    void StatusTakeEffect(character maker, character non_maker);
    //效果产生影响
    void StatusEnd();
    //状态消失时调用的函数，主要功能为将一些状态造成的改变复原（如攻击力降低等）

private:
    string sta_name, sta_info;
    //      状态名    状态介绍
    character affecter;
    //        状态生效的角色
    int sta_dh, sta_dm, sta_da, sta_dd, sta_ds,
    //状态对造成的生命值、魔法值、攻击、防御、速度 的变化
            iniT, nT, sta_id;
    //初始持续时间 目前持续时间 状态id
    vector <status> sta_rmStat;
    bool sta_pos, sta_neg;
};

class note_page{
private:
    int numTurn;
    vector <character> StartCharacterL(2);
    vector <field_status> StartFStatusL(10);
    vector <character> CSerie(10); // 依顺序行动的角色
    vector <cmove> MSerie(10); //依顺序施放的技能
    character checkedCharacter1;
    character checkedCharacter2;

public:
    note_page(int npage){
        numTurn = npage;
    }

    set_start_characterL(vector <character> SC){
        StartCharacter[0] = SC[0];
        StartCharacter[1] = SC[1];
    }

    set_start_field_statusL(vector <field_status> SFS){
        int length = FSF.size();
        for (int i = 0; i < length; i++){
            StartFStatusL[i] = SFS[i];
        }
    }

    add_action(character acter, cmove act){ //添加角色和其行动
        CSerie.push_back(acter);
        MSerie.push_back(act);
    }

    set_C1(character acter){   //快速角色状态清算后记录
        checkedCharacter1 = acter;
    }

    set_C2(character acter){   //慢速角色状态清算后记录
        checkedCharacter2 = acter;
    }
    //****上次写到这里！5-15***接下来改写get函数

    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew},{field_status, numTurn, }
    //   技能施放阶段：{character 行动方, cmove 行动技能, character 行动方, cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}

    set_startTurn_characters


};


class field{
public:
    void FieldTakeEffect(character character1, character character2);
    //场地状态生效

private:
    vector <field_status> FStatusL;
    // 场地状态列表

    vector <note_page> BattleRecord;
    //   ！！！需要设计一个可以记录全部战斗流程的数据结构！！！
    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew},{field_status, numTurn, }
    //   技能施放阶段：{character 行动方, cmove 行动技能, character 行动方, cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}
};

#endif //GODS_GODFIGHTING_H
