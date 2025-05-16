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


// Battle method
void Battle(Character& character);

// These pick a number between 0 and your hit chance to decide how likely you will hit
extern uint32_t enemy_hit_chance;
extern uint32_t defending;
extern uint32_t character_hit_chance;
extern Character enemy_fighter;
// cs means character select, this is just what the user chooses as a battle action
extern std::string cs;
extern uint32_t ct;
// Variable to run the battle loop
extern bool brun;

// Test command
extern std::string test;

// What move you're on. There's 4 in total
extern std::uint32_t moves;

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
