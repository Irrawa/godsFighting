//
// Created by 梦芙兰 on 2019/5/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "field_status.h"
#include "character.h"
#include "cmove.h"
#include "note_page.h"
#include "status.h"

using namespace std;

//character affecter;
//        状态生效的角色

string field_status::get_information(){
    return sta_info;
}