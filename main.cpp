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
using namespace std;

void establish_moves(){
    cmove aqua_ball = AquaBall();
    cmove wind_slash = WindSlash();
    cmove psycho_boost = PsychoBoost();
    cmove tsunami = Tsunami();
    cmove rain_of_nayad = RainOfNayad();
    cmove tailwind = Tailwind();
    cmove oneiro_sting = OneiroSting();
}

int main() {
//    choke c;
//    cout << c.get_information() << endl;
    establish_moves();
    character Irrawa = IRRAWA();
    character Mew = MEW();

//    cmove wind_slash = WindSlash();
//    cmove psycho_boost = PsychoBoost();
    field TestField;
    Mew.moveL[0] = OneiroSting(&Mew, &Irrawa, &TestField);
    Mew.TakeTurn(&Mew, &(Mew.moveL[0]), &TestField);
    Irrawa.moveL[0] = AquaBall(&Irrawa, &Mew, &TestField);
    Irrawa.TakeTurn(&Mew, &(Irrawa.moveL[0]), &TestField);
    Mew.SufferStatus(&Mew, &TestField);
    Mew.print();
    Mew.SufferStatus(&Mew, &TestField);
    Mew.print();
    Mew.SufferStatus(&Mew, &TestField);
    Mew.print();

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