//
// Created by 梦芙兰 on 2019/5/16.
//
#include <iostream>
#include <vector>
#include <string>
#include "cmove.h"

using namespace std;
#ifndef GODS_ACTURAL_MOVES_H
#define GODS_ACTURAL_MOVES_H


extern vector <cmove> AllMoveList;
extern vector <cmove> IrrawaMoveList;
extern vector <cmove> MewMoveList;
extern vector <cmove> RosieMoveList;
extern vector <cmove> AsibiMoveList;

//
//vector <cmove> IrrawaMoveList;

cmove AquaBall();
cmove AquaBall(character * owner, character * taker, field * place);  //move1

cmove WindSlash();
cmove WindSlash(character * owner, character * taker, field * place);  //move2

cmove Tsunami();
cmove Tsunami(character * owner, character * taker, field * place);  //move3

cmove RainOfNayad();
cmove RainOfNayad(character * owner, character * taker, field * place);  //move4

cmove Tailwind();
cmove Tailwind(character * owner, character * taker, field * place);  //move5

cmove NetherVeil();
cmove NetherVeil(character * owner, character * taker, field * place);  //move6

cmove PsychoBoost();
cmove PsychoBoost(character * owner, character * taker, field * place);  //move7

cmove OneiroSting();
cmove OneiroSting(character * owner, character * taker, field * place);  //move8

cmove MewsWonderland();
cmove MewsWonderland(character * owner, character * taker, field * place);  //move9

cmove ToxicBlast();
cmove ToxicBlast(character * owner, character * taker, field * place); //move10

cmove KissOfSuccubus();
cmove KissOfSuccubus(character * owner, character * taker, field * place);  //move11

cmove LustStorm();
cmove LustStorm(character * owner, character * taker, field * place);  //move12

cmove ShadowMirror();
cmove ShadowMirror(character * owner, character * taker, field * place);  //move13

cmove DevilMentel();
cmove DevilMentel(character * owner, character * taker, field * place);  //move14

cmove ArcTurbo();
cmove ArcTurbo(character * owner, character * taker, field * place);  //move15

cmove ObjectiveIllusion();
cmove ObjectiveIllusion(character * owner, character * taker, field * place);  //move16

cmove DarkVoid();
cmove DarkVoid(character * owner, character * taker, field * place); //move17

cmove Utopia();
cmove Utopia(character * owner, character * taker, field * place);  //move18

cmove FleetingMeme();
cmove FleetingMeme(character * owner, character * taker, field * place);  //move19

cmove DoomDesire();
cmove DoomDesire(character * owner, character * taker, field * place);  //move20


#endif //GODS_ACTURAL_MOVES_H
