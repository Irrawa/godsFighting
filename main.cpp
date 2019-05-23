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


int main() {
//    choke c;
//    cout << c.get_information() << endl;
    character Irrawa = IRRAWA();
    character Mew = MEW();

//    cmove wind_slash = WindSlash();
//    cmove psycho_boost = PsychoBoost();
    field TestField;
//    cout << aqua_ball.slf_dm << endl;
//    cout << AllMoveList.size() << endl;
//    cout << IrrawaMoveList.size() << endl;
    cmove aqua_ball = AquaBall(&Irrawa, &Mew, &TestField);
    Irrawa.TakeTurn(&Mew, &aqua_ball, &TestField);
    Mew.SufferStatus(&Irrawa, &TestField);
    Mew.print();

    aqua_ball = AquaBall(&Irrawa, &Mew, &TestField);
    Irrawa.TakeTurn(&Mew, &aqua_ball, &TestField);
    Mew.SufferStatus(&Irrawa, &TestField);
    Mew.print();

    aqua_ball = AquaBall(&Irrawa, &Mew, &TestField);
    Irrawa.TakeTurn(&Mew, &aqua_ball, &TestField);
    Mew.SufferStatus(&Irrawa, &TestField);
    Mew.print();
//    Irrawa.print();
    Mew.SufferStatus(&Irrawa, &TestField);
//    Irrawa.SufferStatus(&Irrawa, &TestField);
    Mew.print();
//    Irrawa.print();
    Mew.SufferStatus(&Irrawa, &TestField);
    Mew.print();
    Mew.SufferStatus(&Irrawa, &TestField);
    Mew.print();


    return 0;
}