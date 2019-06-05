//
// Created by 梦芙兰 on 2019/5/16.
//

#include "actural_moves.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "field_status.h"
#include "character.h"
#include "note_page.h"
#include "status.h"
#include "actural_statuses.h"

using namespace std;

vector <cmove> AllMoveList;   //全游戏技能表，已设为全局变量
vector <cmove> IrrawaMoveList;  //伊洛瓦的技能表，已设为全局变量
vector <cmove> MewMoveList;  //妙的技能表，已设为全局变量
vector <cmove> RosieMoveList;  //露丝的技能表，已设为全局变量
vector <cmove> AsibiMoveList;  //Asibi的技能表，已设为全局变量

//****************************************************************************************************

cmove AquaBall(character * owner, character * taker, field * place){
    cmove aquaBall;
    aquaBall.mName = "Aqua Ball";
    aquaBall.mInfo = "Standard move of Irrawa, inflict minor damage and choke the opponent, which lowers the speed.";
    aquaBall.slf_dm = -100;
    aquaBall.mv_atk = 20;
//    cout << "AquaBall established!" << endl;
    aquaBall.opo_adStat.push_back(&(taker->CharChoke));
    return aquaBall;
}

cmove AquaBall(){
    cmove aquaBall;
    aquaBall.mName = "Aqua Ball";
//    cout << "AquaBall established!" << endl;
    AllMoveList.push_back(aquaBall);
    IrrawaMoveList.push_back(aquaBall);
    return aquaBall;
}

//****************************************************************************************************

cmove WindSlash(character * owner, character * taker, field * place){
    srand(time(NULL));
    cmove windSlash;
    windSlash.mName = "Wind Slash";
    windSlash.mInfo = "Cut the opponent with razor wind, the damage can be doubled in some cases.";
    windSlash.slf_dm = -90;
    windSlash.mv_atk = 50 + 65 * (rand() % 2);
//    cout << "WindSlash established!" << endl;
    return windSlash;
}

cmove WindSlash(){
    cmove windSlash;
    windSlash.mName = "Wind Slash";
//    cout << "WindSlash established!" << endl;
    AllMoveList.push_back(windSlash);
    IrrawaMoveList.push_back(windSlash);
    return windSlash;
}

//****************************************************************************************************

cmove PsychoBoost(character * owner, character * taker, field * place){
    cmove psychoBoost;
    psychoBoost.mName = "Psycho Boost";
    psychoBoost.mInfo = "Induce a strong feeling of braveness. Increase the ATK.";
    psychoBoost.slf_dm = -25;
    psychoBoost.slf_da = 15;
    psychoBoost.selfTarget = true;
//    cout << "PsychoBoost established!" << endl;
    return psychoBoost;
}

cmove PsychoBoost(){
    cmove psychoBoost;
    psychoBoost.mName = "Psycho Boost";
    psychoBoost.slf_dm = -25;
    psychoBoost.slf_da = 15;
    psychoBoost.selfTarget = true;
//    cout << "PsychoBoost established!" << endl;
    AllMoveList.push_back(psychoBoost);
    MewMoveList.push_back(psychoBoost);
    return psychoBoost;
}

//****************************************************************************************************

cmove Tsunami(character * owner, character * taker, field * place){
    cmove tsunami;
    tsunami.mName = "Tsunami";
    tsunami.mInfo = "A deadly attack. Create an aqua bomb on the opponent, which will explode later and deal massive damage.";
    tsunami.slf_dm = -150;
    tsunami.mv_atk = 30;
    tsunami.opo_adStat.push_back(&(taker->CharAquaBlast));
    return tsunami;
}

cmove Tsunami(){
    cmove tsunami;
    tsunami.mName = "Tsunami";
    tsunami.slf_dm = -150;
    tsunami.mv_atk = 30;
    AllMoveList.push_back(tsunami);
    IrrawaMoveList.push_back(tsunami);
    return tsunami;
}

//****************************************************************************************************

cmove RainOfNayad(character * owner, character * taker, field * place){
    cmove rainOfNayad;
    rainOfNayad.slf_dm = -50;
    rainOfNayad.mName = "Rain Of Nayad";
    rainOfNayad.mInfo = "This comforting rain will continously boost ther users speed and recover their HP.";
    rainOfNayad.field_adStat.push_back(&(place->RainOfNayad));
    return rainOfNayad;
}

cmove RainOfNayad(){
    cmove rainOfNayad;
    rainOfNayad.mName = "Aqua Ball";
//    cout << "Rain of Nayad established!" << endl;
    AllMoveList.push_back(rainOfNayad);
    IrrawaMoveList.push_back(rainOfNayad);
    return rainOfNayad;
}

//****************************************************************************************************

cmove Tailwind(character * owner, character * taker, field * place){
    cmove tailwind;
    tailwind.slf_dm = -25;
    tailwind.mName = "Tailwind";
    tailwind.mInfo = "Randomly remove negative status problems from the user.";
    vector <status*> badStatL;
    vector <int> NumShoot;
    tailwind.selfTarget = true;
    int NumStatus = owner->statL.size();
    srand (time(NULL));
    for(int i = 0; i < NumStatus; i++){
        if(owner->statL[i]->sta_neg == true){
            if(rand() % 2 == 0) {
                tailwind.slf_rmStat.push_back(owner->statL[i]);
            }
        }
    }
    return tailwind;
}

cmove Tailwind(){
    cmove tailwind;
    tailwind.mName = "Tailwind";
//    cout << "Tailwind established!" << endl;
    AllMoveList.push_back(tailwind);
    tailwind.selfTarget = true;
    IrrawaMoveList.push_back(tailwind);
    return tailwind;
}

//****************************************************************************************************

cmove NetherVeil(character * owner, character * taker, field * place){
    cmove netherVeil;
    netherVeil.slf_dm = -75;
    netherVeil.mName = "Nether Veil";
    netherVeil.mInfo = "Give the user a dark aura that increases ATK and DEF, and can get healed from poison.";
    netherVeil.slf_adStat.push_back(&(owner->NetherCircuit));
    netherVeil.selfTarget = true;
    return netherVeil;
}

cmove NetherVeil(){
    cmove netherVeil;
    netherVeil.mName = "Nether Veil";
    netherVeil.selfTarget = true;
    AllMoveList.push_back(netherVeil);
    MewMoveList.push_back(netherVeil);
    return netherVeil;
}

//****************************************************************************************************

cmove OneiroSting(character * owner, character * taker, field * place){
    cmove oneiroSting;
    oneiroSting.mName = "Oneiro Sting";
    oneiroSting.mInfo = "Stab the opponent with a taunted inspiration, causes Toxic status, which deals increasing damage each turn.";
    oneiroSting.slf_dm = -25;
    oneiroSting.mv_atk = 30;
//    cout << "Oneiro Sting established!" << endl;
    oneiroSting.opo_adStat.push_back(&(taker->CharToxic));
    return oneiroSting;
}

cmove OneiroSting(){
    cmove oneiroSting;
    oneiroSting.mName = "Oneiro Sting";
    oneiroSting.slf_dm = -25;
    oneiroSting.mv_atk = 30;
//    cout << "Oneiro Sting established!" << endl;
    AllMoveList.push_back(oneiroSting);
    MewMoveList.push_back(oneiroSting);
    return oneiroSting;
}

//****************************************************************************************************

cmove Desolation(character * owner, character * taker, field * place){
    cmove desolation;
    desolation.slf_dm = -25;
    desolation.mName = "Desolation";
    desolation.mInfo = "Taint the battlefield, giving all the character poison status each turn.";
    desolation.field_adStat.push_back(&(place->PoisonAura));
    desolation.selfTarget = true;
    return desolation;
}

cmove Desolation(){
    cmove desolation;
    desolation.mName = "Desolation";
//    cout << "Desolation established!" << endl;
    AllMoveList.push_back(desolation);
    MewMoveList.push_back(desolation);
    return desolation;
}

//****************************************************************************************************

cmove ToxicBlast(character * owner, character * taker, field * place){
    cmove toxicBlast;
    toxicBlast.mName = "Toxic Blast";
    toxicBlast.mInfo = "Remove all the poison status on opponent and deal damage. The harsher the status removed is, the higher the damage will be.";
    toxicBlast.slf_dm = -150;
    int statLen = taker->statL.size();
    int totalDh = 0;
    vector <status*> NewStatL;
    for(int i = 0; i < statLen; i++){
        if(taker->statL[i]->specialProperty == "poison"){
            toxicBlast.opo_rmStat.push_back(taker->statL[i]);
            totalDh += 5 * taker->statL[i]->sta_dh * owner->ctr_atk / taker->ctr_def;
        }
    }
    if(totalDh > -30){
        toxicBlast.opo_dh = -30;
    }
    else {
        toxicBlast.opo_dh = totalDh;
    }
    return toxicBlast;
}

cmove ToxicBlast(){
    cmove toxicBlast;
    toxicBlast.mName = "Toxic Blast";
//    cout << "Toxic Blast established!" << endl;
    AllMoveList.push_back(toxicBlast);
    MewMoveList.push_back(toxicBlast);
    return toxicBlast;
}

//****************************************************************************************************

cmove KissOfSuccubus(character * owner, character * taker, field * place){
    cmove kissOfSuccubus;
    kissOfSuccubus.mName = "Kiss Of Succubus";
    kissOfSuccubus.mInfo = "Deals damage and recover half the damage dealt.";
    kissOfSuccubus.mv_atk = 75;
    kissOfSuccubus.slf_dm = -90;
    kissOfSuccubus.slf_dh += (owner->ctr_atk * kissOfSuccubus.mv_atk / taker->ctr_def) * 0.5;
    return kissOfSuccubus;
}

cmove KissOfSuccubus(){
    cmove kissOfSuccubus;
    kissOfSuccubus.mName = "Kiss Of Succubus";
//    cout << "Kiss of Succubus established!" << endl;
    AllMoveList.push_back(kissOfSuccubus);
    RosieMoveList.push_back(kissOfSuccubus);
    return kissOfSuccubus;
}

//****************************************************************************************************

cmove LustStorm(character * owner, character * taker, field * place){
    cmove lustStorm;
    lustStorm.slf_dm = -50;
    lustStorm.mv_atk = 10;
    lustStorm.mName = "Lust Storm";
    lustStorm.mInfo = "Give the user Static Overload status, which deflects 30% the damage the user taken to the oppoent.";
    lustStorm.slf_adStat.push_back(&(owner->StaticOverload));
    lustStorm.selfTarget = false;
    return lustStorm;
}

cmove LustStorm(){
    cmove lustStorm;
    lustStorm.mName = "Lust Storm";
    lustStorm.selfTarget = true;
    AllMoveList.push_back(lustStorm);
    RosieMoveList.push_back(lustStorm);
    return lustStorm;
}

//****************************************************************************************************

cmove ShadowMirror(character * owner, character * taker, field * place){
    cmove shadowMirror;
    character mirrorOwner;
    int oppoMoveLen = taker->moveL.size();
    if(oppoMoveLen == 0){
        taker->SetMove(owner, place);
        oppoMoveLen = taker->moveL.size();
    }
    int chooseMoveNum = rand() % oppoMoveLen;
//    cout << rand() << endl;
//    cout << chooseMoveNum << endl;
    shadowMirror = taker->moveL[chooseMoveNum];
//    cout << "copied " << shadowMirror.mName << endl;
    shadowMirror.mName += "(shadow)";
    shadowMirror.nameChanged = true;
    shadowMirror.realName = "Shadow Mirror";
    shadowMirror.mInfo = "Using this move will randomly copy one of the opponent's move and cast it without additional cost.";
    shadowMirror.slf_dm = -30;
    return shadowMirror;
}

cmove ShadowMirror(){
    cmove shadowMirror;
    shadowMirror.nameChanged = true;
    shadowMirror.mName = "Shadow Mirror";
    shadowMirror.realName = "Shadow Mirror";
    AllMoveList.push_back(shadowMirror);
    RosieMoveList.push_back(shadowMirror);
    return shadowMirror;
}

//****************************************************************************************************

cmove DevilMentel(character * owner, character * taker, field * place){
    cmove devilMentel;
    devilMentel.slf_dm = -45;
    devilMentel.mName = "Devil Mentel";
    devilMentel.mInfo = "Spirify the user for a while, greatly lower the physical damage she takes.";
    devilMentel.slf_adStat.push_back(&(owner->Spiritified));
    devilMentel.selfTarget = true;
    return devilMentel;
}

cmove DevilMentel(){
    cmove devilMentel;
    devilMentel.mName = "Devil Mentel";
    devilMentel.selfTarget = true;
    AllMoveList.push_back(devilMentel);
    RosieMoveList.push_back(devilMentel);
    return devilMentel;
}

//****************************************************************************************************

cmove ArcTurbo(character * owner, character * taker, field * place){
    cmove arcTurbo;
    arcTurbo.mName = "Arc Turbo";
    arcTurbo.mInfo = "A double edge move,greatly increases the user's ATK and DEF at the cost of both MP and HP.";
    arcTurbo.slf_dm = -50;
    arcTurbo.slf_dh = -50;
    arcTurbo.slf_da = 25;
    arcTurbo.slf_dd = 25;
    arcTurbo.selfTarget = true;
    return arcTurbo;
}

cmove ArcTurbo(){
    cmove arcTurbo;
    arcTurbo.mName = "Arc Turbo";
    arcTurbo.selfTarget = true;
//    cout << "Arc Turbo established!" << endl;
    AllMoveList.push_back(arcTurbo);
    RosieMoveList.push_back(arcTurbo);
    return arcTurbo;
}

//****************************************************************************************************

cmove ObjectiveIllusion(character * owner, character * taker, field * place){
    cmove objectiveIllusion;
    objectiveIllusion.mName = "Objective Illusion";
    objectiveIllusion.mInfo = "A strategic move which recalls the time past 3 turns ago. Using it wisely may override the battle!";
    objectiveIllusion.slf_dm -= 50;
    objectiveIllusion.selfTarget = true;

    int NumStatus = owner->statL.size();
    for(int i = 0; i < NumStatus; i++){
        if(owner->statL[i]->specialProperty == "dream"){
            objectiveIllusion.slf_rmStat.push_back(owner->statL[i]);
        }
    }

    NumStatus = taker->statL.size();
    for(int i = 0; i < NumStatus; i++){
        if(taker->statL[i]->specialProperty == "dream") {
            objectiveIllusion.opo_rmStat.push_back(taker->statL[i]);
        }
    }

    if(place->battleRecord.size() > 1) {
        note_page thePage = place->GetPage(place->battleRecord.size() - 4);
        character theOwner;
        character theTaker;
        if (owner->cName == thePage.C00.cName) {
            theOwner = thePage.C00;
            theTaker = thePage.C01;
        } else if (owner->cName == thePage.C01.cName) {
            theOwner = thePage.C01;
            theTaker = thePage.C00;
        }
        objectiveIllusion.slf_dh += (theOwner.HP - owner->HP);
        objectiveIllusion.slf_dm += (theOwner.MP - owner->MP);
        objectiveIllusion.slf_da += (theOwner.ctr_atk - owner->ctr_atk);
        objectiveIllusion.slf_dd += (theOwner.ctr_def - owner->ctr_def);
        objectiveIllusion.slf_ds += (theOwner.ctr_spd - owner->ctr_spd);
        objectiveIllusion.opo_dh += (theTaker.HP - taker->HP);
        objectiveIllusion.opo_dm += (theTaker.MP - taker->MP);
        objectiveIllusion.opo_da += (theTaker.ctr_atk - taker->ctr_atk);
        objectiveIllusion.opo_dd += (theTaker.ctr_def - taker->ctr_def);
        objectiveIllusion.opo_ds += (theTaker.ctr_spd - taker->ctr_spd);
    }
    else{
        cout << "There is no history to recall!" << endl;
    }
    return objectiveIllusion;

}

cmove ObjectiveIllusion(){
    cmove objectiveIllusion;
    objectiveIllusion.mName = "Objective Illusion";
    objectiveIllusion.selfTarget = true;
    AllMoveList.push_back(objectiveIllusion);
    AsibiMoveList.push_back(objectiveIllusion);

    return objectiveIllusion;
}

//****************************************************************************************************
cmove DarkVoid(character * owner, character * taker, field * place){
    cmove darkVoid;
    darkVoid.mName = "Dark Void";
    darkVoid.mInfo = "Weave a nightmare for your opponent, temporarily lower her HP.";
    darkVoid.slf_dm -= 50;
    bool locateFlag = false;
    if(taker->statL.size() > 0){
        for(int i = 0; i < taker->statL.size(); i++){
            if(taker->statL[i]->sta_name == "NIGHTMARE"){
                locateFlag = true;
            }
        }
    }
    if(!locateFlag) {
        darkVoid.opo_dh -= 200;
    }
    darkVoid.opo_adStat.push_back(&(taker->Nightmare));
    return darkVoid;
}

cmove DarkVoid(){
    cmove darkVoid;
    darkVoid.mName = "Dark Void";
    AllMoveList.push_back(darkVoid);
    AsibiMoveList.push_back(darkVoid);
    return darkVoid;
}

//****************************************************************************************************
cmove Utopia(character * owner, character * taker, field * place){
    cmove utopia;
    utopia.mName = "Utopia";
    utopia.mInfo = "Weave a lotus land for you to dream on, temporarily boost your HP.";
    utopia.slf_dm -= 50;
    utopia.selfTarget = true;
    bool locateFlag = false;
    if(owner->statL.size() > 0){
        for(int i = 0; i < owner->statL.size(); i++){
            if(owner->statL[i]->sta_name == "LOTUS"){
                locateFlag = true;
            }
        }
    }
    if(!locateFlag) {
        utopia.slf_dh += 200;
    }
    utopia.slf_adStat.push_back(&(taker->Lotus));
    return utopia;
}
cmove Utopia(){
    cmove utopia;
    utopia.mName = "Utopia";
    AllMoveList.push_back(utopia);
    AsibiMoveList.push_back(utopia);
    return utopia;
}



//****************************************************************************************************

cmove FleetingMeme(character * owner, character * taker, field * place){
    cmove fleetingMeme;
    fleetingMeme.mName = "Fleeting Meme";
    fleetingMeme.mInfo = "Freeze the next move into time and skip it!";
    fleetingMeme.slf_dm -= 10;
    fleetingMeme.slf_adStat.push_back(&(taker->TickTock));
    return fleetingMeme;
}

cmove FleetingMeme(){
    cmove fleetingMeme;
    fleetingMeme.mName = "Fleeting Meme";
    AllMoveList.push_back(fleetingMeme);
    AsibiMoveList.push_back(fleetingMeme);
    return fleetingMeme;
}

//****************************************************************************************************

cmove DoomDesire(character * owner, character * taker, field * place){
    cmove doomDesire;
    doomDesire.mName = "Doom Desire";
    doomDesire.mInfo = "This move will release Asibi's Ture Power only after the 50th turn.";
    doomDesire.mv_atk = 5;
    if(place->battleRecord.size() >= 50){
        doomDesire.mv_atk = 500;
    }
    return doomDesire;
}
cmove DoomDesire(){
    cmove doomDesire;
    doomDesire.mName = "Doom Desire";
    AllMoveList.push_back(doomDesire);
    AsibiMoveList.push_back(doomDesire);
    return doomDesire;
}