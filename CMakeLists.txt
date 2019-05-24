cmake_minimum_required(VERSION 3.10)
project(gods)

set(CMAKE_CXX_STANDARD 17)

add_executable(gods main.cpp godFighting.h status.cpp character.cpp cmove.cpp field_status.cpp field.cpp status.h cmove.h character.h field_status.h note_page.cpp note_page.h field.h actural_moves.cpp actural_moves.h actural_characters.cpp actural_characters.h actural_statuses.cpp actural_statuses.h actural_field_status.cpp actural_field_status.h)