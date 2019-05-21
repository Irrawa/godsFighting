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
    cmove aqua_ball = AquaBall();
//    cmove wind_slash = WindSlash();
//    cmove psycho_boost = PsychoBoost();
    field TestField;
//    cout << aqua_ball.slf_dm << endl;
//    cout << AllMoveList.size() << endl;
//    cout << IrrawaMoveList.size() << endl;
    character Irrawa = IRRAWA();
    character Mew = MEW();
    aqua_ball.LaunchMove(&Irrawa, &Mew, &TestField);
//    Irrawa.TakeTurn(&Mew, &aqua_ball, &TestField);
//    Mew.TakeTurn(&Irrawa, &psycho_boost,&TestField);
//    Mew.print();
//    Irrawa.print();
//    Mew.SufferStatus(&Irrawa, &TestField);
//    cout << Mew.statL[0].get_information() << endl;
//    Mew.print();
//    Mew.SufferStatus(&Irrawa, &TestField);
//    cout << Mew.statL[0].get_information() << endl;
//    Mew.print();
//    Mew.SufferStatus(&Irrawa, &TestField);
//    cout << Mew.statL[0].get_information() << endl;
//    Mew.print();
//    Mew.SufferStatus(&Irrawa, &TestField);
//    cout << Mew.statL[0].get_information() << endl;
//    Mew.print();
//    Mew.SufferStatus(&Irrawa, &TestField);
//    Mew.print();


    return 0;
}