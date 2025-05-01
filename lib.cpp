#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <fstream>

// cut out bool run from command_check!

class Character
{
public:
    // This will be used for both main character and enemies
    // Name, health, defense, attack power hit chance
    std::string name = "Base Character";
    uint32_t health = 6U;
    uint32_t attack = 2U;
    uint32_t defense = 1U;
    uint32_t hit_chance = 2U;

    // Main Menu
    void mm()
    {
        // We can make this what is done based on user interaction. We'll have to send an argument to it and allow it to do whatever based on that
        std::cout << "\nOptions:\n1) List Stats \n2) List Items\n3) Save\n4) Exit Menu\n5) Quit";
        uint32_t option;
        std::cin >> option;
        //switch()
    }

    // Save File


};

Character wolf;
Character undead;
Character warrior;

void enemy_initialization(Character& character, const std::string &name, uint32_t h, uint32_t a, uint32_t d, uint32_t hc)
{
    character.name = name;
    character.health = h;
    character.attack = a;
    character.defense = d;
    character.hit_chance = hc;
}

// User Command Variable
std::string u_command;

// This will check player commands
auto command_check(std::string &opt, Character& character, bool run)
{
    // This will check if you're entering a main command the program knows
    std::string test;
    std::cout << opt;
    if(opt == "help" or opt == "menu" or opt == "?")
        {
        std::cout << "\n\nMenu:\n1) stats\n2) items\n3) save\n4) quit\n\n";
        return 1;
     //   std::cin >> test;
        }
    else if(opt == "stats")
    {   std::cout << '\n' << '\n' << character.name << ":\n";
        std::cout << "Attack : " << character.attack << '\n' << "Defense: " << character.defense << '\n' << "Max health: " << character.health << '\n' << "Hit Chance: " << character.hit_chance << '\n' << '\n';
        return 1;
    }
    else if(opt == "items")
    {
        // Add items to the character class later
        std::cout << "You have no items";
        return 1;
    }
    else if(opt == "save")
    {
        std::cout << "\n\nSaving...\n";
        std::ofstream MyFile("Save.txt", std::ios::app);
        MyFile << character.name << '\n';
        MyFile << character.attack << '\n';
        MyFile << character.defense << '\n';
        MyFile << character.health << '\n';
        MyFile << character.hit_chance;
        MyFile.close();
        return 1;
    }
    else if(opt == "quit\n")
    {
        exit(0);
    }
}
// Error handling function
/*
template<typename T>
T Err_handler(T err)
{
    try
    {
        err;
    // We should be able to put a catch here that returns
    if(err == "cinfail")
    {
        throw std::invalid_argument("Please only answer with \'y\' or \'n\'");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n');

    }
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
        system("cls");
    }

}
*/
