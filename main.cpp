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
    cmove lust_storm = LustStorm();
    cmove shadow_mirror = ShadowMirror();
    cmove devil_mentel = DevilMentel();
    cmove arc_turbo = ArcTurbo();
}

int main() {
//    choke c;
//    cout << c.get_information() << endl;
    establish_moves();
    character Irrawa = IRRAWA();
    character Mew = MEW();
    character Rosie = ROSIE();
    field TestField;
    TestField.NewPage();

//    cout << "page address:" << &(TestField.battleRecord[0]) << endl;
//    Irrawa.print();
//    Rosie.print();
//    RosieMoveReset(&Rosie, &Irrawa, &TestField);
//    Rosie.TakeTurn(&Irrawa, &(Rosie.moveL[0]), &TestField);
//    Asibi.print();
//    AsibiMoveReset(&Asibi, &Irrawa, &TestField);
//    Asibi.TakeTurn(&Irrawa, &(Asibi.moveL[0]), &TestField);

//    TestField.battleRecord[0].set_beforeMoveFast(&Rosie);
//    TestField.battleRecord[0].set_beforeMoveSlow(&Irrawa);
//
//    Irrawa.print();
//    Rosie.print();
//
//    TestField.battleRecord[0].set_after1stMoveFast(&Rosie);
//    TestField.battleRecord[0].set_after1stMoveSlow(&Irrawa);
//
    cout << "================================================" <<endl;

    Rosie.print();
    Irrawa.SetMove(&Rosie, &TestField);
    Irrawa.TakeTurn(&Rosie, &(Irrawa.moveL[1]), &TestField);
    Rosie.print();
    Rosie.SetMove(&Irrawa, &TestField);
    Rosie.TakeTurn(&Irrawa, &(Rosie.moveL[4]), &TestField);
    Rosie.print();
    Rosie.SufferStatus(&Irrawa, &TestField);
    Mew.SetMove(&Rosie, &TestField);
    Mew.TakeTurn(&Rosie, &(Mew.moveL[1]), &TestField);
    Mew.print();
    Irrawa.SetMove(&Rosie, &TestField);
    Irrawa.TakeTurn(&Rosie, &(Irrawa.moveL[1]), &TestField);
    Rosie.print();
    Irrawa.print();
    Rosie.SufferStatus(&Irrawa, &TestField);
    Irrawa.SetMove(&Rosie, &TestField);
    Irrawa.TakeTurn(&Rosie, &(Irrawa.moveL[1]), &TestField);
    Rosie.print();
    Rosie.SufferStatus(&Irrawa, &TestField);
    Irrawa.SetMove(&Rosie, &TestField);
    Irrawa.TakeTurn(&Rosie, &(Irrawa.moveL[1]), &TestField);
    Rosie.print();
    Rosie.SufferStatus(&Irrawa, &TestField);



    return 0;
}