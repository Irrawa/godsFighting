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

void establish_moves(){
    cmove aqua_ball = AquaBall();
    cmove wind_slash = WindSlash();
    cmove psycho_boost = PsychoBoost();
    cmove tsunami = Tsunami();
    cmove rain_of_nayad = RainOfNayad();
    cmove tailwind = Tailwind();
    cmove oneiro_sting = OneiroSting();
    cmove nether_veil = NetherVeil();
    cmove desolation = Desolation();
    cmove toxic_blast = ToxicBlast();
    cmove kiss_of_succubus = KissOfSuccubus();
}
void IrrawaMoveReset(character* irrawa, character* opponent, field* battleField){
    irrawa->moveL[0] = AquaBall(irrawa, opponent, battleField);
    irrawa->moveL[1] = WindSlash(irrawa, opponent, battleField);
    irrawa->moveL[2] = Tsunami(irrawa, opponent, battleField);
    irrawa->moveL[3] = RainOfNayad(irrawa, opponent, battleField);
    irrawa->moveL[4] = Tailwind(irrawa, opponent, battleField);
}

void MewMoveReset(character* mew, character* opponent, field* battleField){
    mew->moveL[0] = OneiroSting(mew, opponent, battleField);
    mew->moveL[1] = NetherVeil(mew, opponent, battleField);
    mew->moveL[2] = Desolation(mew, opponent, battleField);
    mew->moveL[3] = PsychoBoost(mew, opponent, battleField);
    mew->moveL[4] = ToxicBlast(mew, opponent, battleField);
}

void RosieMoveReset(character* rosie, character* opponent, field* battleField){
    rosie->moveL[0] = KissOfSuccubus(rosie, opponent, battleField);
}

int main() {
//    choke c;
//    cout << c.get_information() << endl;
    establish_moves();
    character Irrawa = IRRAWA();
    character Mew = MEW();
    character Rosie = ROSIE();
    character Asibi = ASIBI();
    note_page testPage;

//    cmove wind_slash = WindSlash();
//    cmove psycho_boost = PsychoBoost();
    field TestField;
//    Irrawa.print();
//    Rosie.print();
//    RosieMoveReset(&Rosie, &Irrawa, &TestField);
//    Rosie.TakeTurn(&Irrawa, &(Rosie.moveL[0]), &TestField);
//    Asibi.print();
//    AsibiMoveReset(&Asibi, &Irrawa, &TestField);
//    Asibi.TakeTurn(&Irrawa, &(Asibi.moveL[0]), &TestField);

    MewMoveReset(&Mew, &Irrawa, &TestField);
    Mew.TakeTurn(&Irrawa, &(Mew.moveL[0]), &TestField);
    Mew.print();
    Irrawa.print();
    Irrawa.SufferStatus(&Mew, &TestField);
    Irrawa.print();
    testPage.set_after1stStatSlow(&Irrawa);
    Irrawa.SufferStatus(&Mew, &TestField);
    Irrawa.print();
    Irrawa.SufferStatus(&Mew, &TestField);
    Irrawa.print();
    Irrawa.SufferStatus(&Mew, &TestField);
    Irrawa.print();
    testPage.C07.print();


//    MewMoveReset(&Mew, &Irrawa, &TestField);
//    Mew.TakeTurn(&Irrawa, &(Mew.moveL[4]), &TestField);
//    Irrawa.SufferStatus(&Mew, &TestField);
//    Irrawa.print();


//    TestField.FieldSufferStatus(&Mew, &Irrawa);
//    Mew.SufferStatus(&Irrawa, &TestField);
//    Irrawa.moveL[0] = Tailwind(&Irrawa, &Mew, &TestField);
//    Irrawa.TakeTurn(&Irrawa, &(Irrawa.moveL[0]), &TestField);
//    Mew.SufferStatus(&Mew, &TestField);
//    Mew.print();
//    Mew.moveL[2] = PsychoBoost(&Mew, &Irrawa, &TestField);
//    Mew.TakeTurn(&Irrawa, &(Mew.moveL[2]), &TestField);
//
//    Mew.SufferStatus(&Mew, &TestField);
//    Mew.print();
//    Mew.SufferStatus(&Mew, &TestField);
//    Mew.print();


//    cout << aqua_ball.slf_dm << endl;
//    cout << AllMoveList.size() << endl;
//    cout << IrrawaMoveList.size() << endl;
//    Irrawa.moveL[0] = AquaBall(&Irrawa, &Mew, &TestField);
//    Irrawa.print();
//    Irrawa.TakeTurn(&Irrawa, &(Irrawa.moveL[0]), &TestField);
//    Irrawa.SufferStatus(&Mew, &TestField);
//    Irrawa.print();
//    Irrawa.moveL[1] = Tailwind(&Irrawa, &Mew, &TestField);
//    Irrawa.TakeTurn(&Irrawa, &(Irrawa.moveL[1]), &TestField);
//    Irrawa.SufferStatus(&Mew, &TestField);
//    Irrawa.print();
//    Irrawa.SufferStatus(&Mew, &TestField);
//    Irrawa.print();


    //    TestField.FieldSufferStatus(&Irrawa, &Mew);





//    Irrawa.moveL[1] = WindSlash(&Irrawa, &Mew, &TestField);
//    Irrawa.TakeTurn(&Mew, &(Irrawa.moveL[1]), &TestField);
//
//    cout << Irrawa.moveL[0].mName << endl;



    return 0;
}