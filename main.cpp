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
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    choke c;
    cout << c.get_information() << endl;
    cmove aqua_ball = AquaBall();
    cmove wind_slash = WindSlash();
    cmove psycho_boost = PsychoBoost();
    cout << aqua_ball.slf_dm << endl;
    cout << AllMoveList.size() << endl;
    cout << IrrawaMoveList.size() << endl;
    character Irrawa = IRRAWA();
    character Mew = MEW();

    Irrawa.TakeTurn(Mew, wind_slash, {});
    cout << Mew.HP << endl;

    return 0;
}