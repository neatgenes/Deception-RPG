#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <deque>
#include <fstream>
// Class for creating characters
class Character
{

public:
    // This will be used for both main character and enemies
    // Name, health, defense, attack power hit chance
    std::string name = "Enemy";
    uint32_t health;
    uint32_t attack;
    uint32_t defense;
    uint32_t hit_chance;

    void mm()
    {
        std::cout << "\nOptions:\n1) List Stats \n2) List Items\n3) Save\n4) Quit";
        uint32_t option;
    }


};

// Initialize enemies with this
void enemy_initialization(Character& character, const std::string &name, uint32_t h, uint32_t a, uint32_t d, uint32_t hc);

// Checks player commands
void command_check(std::string &opt, Character& character, bool run);
   // Test command
extern std::string test;



// Standard enemy classes
extern Character wolf;
extern Character undead;
extern Character warrior;

// User Command Variable
extern std::string u_command;

// Error handling function
/*
template<typename T>
std::string Err_handler(T err);
*/
