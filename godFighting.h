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
class field_status;

class status{
public:
    string sta_name, sta_info;
    //      状态名    状态介绍
    int sta_dh = 0, sta_dm = 0, sta_da = 0, sta_dd = 0, sta_ds = 0,
    //状态造成的生命值、魔法值、攻击、防御、速度 的变化
            sta_Odh = 0, sta_Odm = 0, sta_Oda = 0, sta_Odd = 0, sta_Ods = 0,
    //对对手造成的...变化
            iniT = 1, nT = 1, sta_id = 0;
    //初始持续时间 目前持续时间 状态id

    vector <status> sta_rmStat;
    //移除自身的状态

    bool sta_pos, sta_neg;
    //正面状态还是负面状态？

    bool showStatus = true;
    // 该状态是否可被玩家看到


    void SetupStatus();
    //状态被施加时，使用此函数初始化，
    void RefStatus();
    //每经过一回合，所有生效的status需要使用此函数刷新。
    void StatusTakeEffect(character selfCharacter, character oppoCharacter);
    //效果产生影响，状态消失时也调用此函数将一些状态造成的改变复原（如攻击力降低等）
    void StatusLoss();
    //状态消逝时的特殊行为，如失去状态时回血等等
    string get_information(){
        string output = "【" + sta_name + "】" + ":\n" + sta_info + "\n目前剩余" + to_string(nT) + "回合。";
        return output ;
    }



};

class character{
public:
    string cName; //角色名
    int maxHP = 1000, maxMP = 1000, ctr_atk = 100, ctr_def = 100, ctr_spd = 100, HP, MP;
    //最大生命值       最大魔法值     攻击力       防御力       速度      生命值  魔法值
    vector <status> statL;
    //     状态列表
    vector <cmove> moveL;
    //     技能列表
    vector <status> statM;

    void TakeTurn(character oppoCharacter, cmove chosenMove,field currentField);
    //玩家针对对手玩家行动
};

class cmove{
public:
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

    void SpellMove(character speller, character receiver, vector <field_status> SFS);
    /*表示搓技能的过程，在此函数中初始化技能的各项数值。
    例如要搓一个使对方受到其剩余生命值(10% + (攻击者攻击力/受攻击者防御) * 10%)的伤害，则应在此函数中做到：
    1，获取speller的攻击力
    2，获取receiver的防御力和当前生命值
    3，使用公式计算伤害值
    4，将伤害值赋予技能的O_dh,注意正负号！造成伤害为负数！
    5，初始化技能的其它数值
    6，结束搓技能，进入技能生效阶段*/
    void LaunchMove(character speller);
    //此阶段扣除施放技能消耗的魔法值/生命值，并造成应有的影响


};

class field_status{
    //场地状态
public:

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
    void SetupStatus();
    //状态被施加时，使用此函数初始化
    void RefStatus();
    //每经过一回合，所有生效的status需要使用此函数刷新。
    void StatusTakeEffect(character maker, character non_maker);
    //效果产生影响
    void StatusEnd();
    //状态消失时调用的函数，主要功能为将一些状态造成的改变复原（如攻击力降低等）
    string get_information(){
        return sta_info;
    }

};

class note_page{

public:
    int numTurn;
    vector <character> StartCharacterL;
    vector <field_status> StartFStatusL;
    vector <character> CSerie; // 依顺序行动的角色
    vector <cmove> MSerie; //依顺序施放的技能
    character checkedCharacter1;
    character checkedCharacter2;

    note_page(int npage){
        numTurn = npage;
    }

    void set_start_characterL(vector <character> SC){
        StartCharacterL[0] = SC[0];
        StartCharacterL[1] = SC[1];
    }

    void set_start_field_statusL(vector <field_status> SFS){
        int length = SFS.size();
        for (int i = 0; i < length; i++){
            StartFStatusL[i] = SFS[i];
        }
    }

    void add_action(character acter, cmove act){ //添加角色和其行动
        CSerie.push_back(acter);
        MSerie.push_back(act);
    }

    void set_C1(character acter){   //快速角色状态清算后记录
        checkedCharacter1 = acter;
    }

    void set_C2(character acter){   //慢速角色状态清算后记录
        checkedCharacter2 = acter;
    }


    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew},{field_status, numTurn, }
    //   技能施放阶段：{character 行动方, cmove 行动技能, character 行动方, cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}



};


class field{
public:
    vector <field_status> FStatusL;
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

    bool status_take_effect(character effectOwner, status S, character nonOwner);
    //状态生效，应包括
    //1，根据所剩回合数和总回合数判断是否为第一回合/随后一回合
    //2，计算状态将造成的影响
    //3，状态生效，造成变化
    //4，清算是否分出胜负，分出返回true，不分出返回false

    void FieldTakeEffect(character character1, character character2);
    //场地状态生效





    //   ！！！需要设计一个可以记录全部战斗流程的数据结构！！！
    //   每回合开始时（也是场地状态清算后的情况）：{character Irrawa, character Mew},{field_status, numTurn, }
    //   技能施放阶段：{character 行动方, cmove 行动技能, character 行动方, cmove 行动技能...}（一方可能行动多次）
    //   速度较快的一方状态清算后： {character 速度较快的角色}
    //   速度较慢的一方状态清算后： {character 速度较慢的角色}
};

#endif //GODS_GODFIGHTING_H
