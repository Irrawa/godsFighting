cmake_minimum_required(VERSION 3.10)
project(gods)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(gods
        actural_characters.cpp
        actural_characters.h
        actural_field_status.cpp
        actural_field_status.h
        actural_moves.cpp
        actural_moves.h
        actural_statuses.cpp
        actural_statuses.h
        battle_handler.cpp
        battle_handler.h
        character.cpp
        character.h
        cmove.cpp
        cmove.h
        field.cpp
        field.h
        field_status.cpp
        field_status.h
        main.cpp
        note_page.cpp
        note_page.h
        status.cpp
        status.h)
