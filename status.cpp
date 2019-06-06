//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "character.h"
#include "status.h"
#include "cmove.h"
using namespace std;



void status::StatusTakeEffect(character* self, character* oppo, field* currentField){
    (*self).HP += sta_dh;
    if(sta_dh > 0){
        cout << this->sta_name << " healed " << self->cName << " " << sta_dh << " HP!" << endl;
    }
    else if(sta_dh < 0){
        cout << this->sta_name << " damaged " << self->cName << " " << -sta_dh << " HP!" << endl;
    }


    (*self).MP += sta_dm;
    if(sta_dm > 0){
        cout << this->sta_name << " recovered " << self->cName << " " << sta_dm << " MP!" << endl;
    }
    else if(sta_dm < 0){
        cout << this->sta_name << " reduced " << self->cName << " " << -sta_dm << " MP!" << endl;
    }
    (*self).MP = max(self->MP, 0);


    (*self).ctr_atk += sta_da;
    if(sta_da > 0){
        cout << this->sta_name << " boosted " << self->cName << " " << sta_da << " Attack!" << endl;
    }
    else if(sta_da < 0){
        cout << this->sta_name << " weakened " << self->cName << " " << -sta_da << " Attack!" << endl;
    }
    (*self).ctr_atk = max(self->ctr_atk, 1);


    (*self).ctr_def += sta_dd;
    if(sta_dd > 0){
        cout << this->sta_name << " boosted " << self->cName << " " << sta_dd << " Defence!" << endl;
    }
    else if(sta_dd < 0){
        cout << this->sta_name << " weakened " << self->cName << " " << -sta_dd << " Defence!" << endl;
    }
    (*self).ctr_def = max(self->ctr_def, 1);


    (*self).ctr_spd += sta_ds;
    if(sta_ds > 0){
        cout << this->sta_name << " boosted " << self->cName << " " << sta_ds << " Speed!" << endl;
    }
    else if(sta_ds < 0){
        cout << this->sta_name << " weakened " << self->cName << " " << -sta_ds << " Speed!" << endl;
    }
    (*self).ctr_spd = max(self->ctr_spd, 1);


    (*oppo).HP += sta_Odh;
    if(sta_Odh > 0){
        cout << this->sta_name << " healed " << oppo->cName << " " << sta_Odh << " HP!" << endl;
    }
    else if(sta_Odh < 0){
        cout << this->sta_name << " damaged " << oppo->cName << " " << -sta_Odh << " HP!" << endl;
    }


    (*oppo).MP += sta_Odm;
    if(sta_Odm > 0){
        cout << this->sta_name << " recovered " << oppo->cName << " " << sta_Odm << " MP!" << endl;
    }
    else if(sta_Odm < 0){
        cout << this->sta_name << " reduced " << oppo->cName << " " << -sta_Odm << " MP!" << endl;
    }
    oppo->MP = max(oppo->MP,0);


    (*oppo).ctr_atk += sta_Oda;
    if(sta_Oda > 0){
        cout << this->sta_name << " boosted " << oppo->cName << " " << sta_Oda << " Attack!" << endl;
    }
    else if(sta_Oda < 0){
        cout << this->sta_name << " weakened " << oppo->cName << " " << -sta_Oda << " Attack!" << endl;
    }
    oppo->ctr_atk = max(oppo->ctr_atk,1);


    (*oppo).ctr_def += sta_Odd;
    if(sta_Odd > 0){
        cout << this->sta_name << " boosted " << oppo->cName << " " << sta_Odd << " Defence!" << endl;
    }
    else if(sta_Odd < 0){
        cout << this->sta_name << " weakened " << oppo->cName << " " << -sta_Odd << " Defence!" << endl;
    }
    oppo->ctr_def = max(oppo->ctr_def,1);


    (*oppo).ctr_spd += sta_Ods;
    if(sta_Ods > 0){
        cout << this->sta_name << " boosted " << oppo->cName << " " << sta_Ods << " Speed!" << endl;
    }
    else if(sta_Ods < 0){
        cout << this->sta_name << " weakened " << oppo->cName << " " << -sta_Ods << " Speed!" << endl;
    }
    oppo->ctr_spd = max(oppo->ctr_spd,1);

    nT -= 1;
    sta_da = 0;
    sta_dd = 0;
    sta_ds = 0;
    sta_Oda = 0;
    sta_Odd = 0;
    sta_Ods = 0;
}

void status::SetupStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status setup..."<< endl;
}

void status::RefStatus(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status refreshed..."<< endl;
}


void status::StatusLoss(character* selfCharacter, character* oppoCharacter, field* currentField){
//    cout << "General status Lost.."<< endl;
}

string status::get_information(){
    string output = "[" + sta_name + "]" + ":\n" + sta_info + "\nLEFT:" + to_string(nT + 1) + "turns\n";
    return output;
}

//💥💦💧🌊🌨🌧💨🌬🔮💗💖💞☣️☢️❌💢♥️🗯💭☠️🌪🌈🔥☄️⚡️
