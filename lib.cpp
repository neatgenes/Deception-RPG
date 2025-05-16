#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
// add cstdlib and ctime to notes
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
        std::cout << "\nOptions:\n1) List Stats \n2) List Items\n3) Save\n4) Exit Menu\n5) Forward (Proceed through dungeon) \n6) Quit";
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

// Moves tracks what move you're on out of 4
std::uint32_t moves = 0U;


void Battle(Character& character)
        {
            // cs means character select, this is just what the user chooses as a battle action
            uint32_t defending = 0U;
            std::string cs;
            Character enemy_fighter;

            // Below decides who you will be facing based on your moves
            if(moves == 1U)
            {
                enemy_fighter = wolf;
            }
            else if(moves == 2U)
            {
                enemy_fighter = undead;
            }
            else if(moves == 3U)
            {
                enemy_fighter = warrior;
            }
            else if(moves == 4U)
            {
                std::cout << "Congratulations! You have completed the dungeon!";
                exit(1);
            }
                // brun means Battle Run, this is the boolean that keeps the battle going

                bool brun = true;
                uint32_t ct = 0U;
                system("cls");
                std::cout << "You encounter a " << enemy_fighter.name << "!\n";
                std::cout << "You have the first move\n";
                while(brun)
                {
                    if(character.health <= 0 or character.health > 20U )
                    {
                        std::cout << "You have died\nGame Over";
                        exit(1);
                    }
                    srand(time(0));
                    int enemy_hit_chance = rand() % (enemy_fighter.hit_chance - 0 + 1) + 0;
                    int character_hit_chance = rand() % (character.hit_chance - 0 + 1) + 0;
                    if(ct == 0U)
                    {
                        std::cout << "Select a below option\n";
                        std::cout << enemy_fighter.name << ": " << enemy_fighter.health << " " << character.name << ": " << character.health << std::endl;
                        std::cout << "attack\ndefend\n\n";
                        std::cin >> cs;
                        if(cs == "attack")
                        {
                            std::cout << "You attack the " << enemy_fighter.name << " for " << character.attack << " points\n";
                            if(character.attack >= enemy_fighter.health and character_hit_chance == 1U)
                            {
                                std::cout << "A crushing blow! The " << enemy_fighter.name << " has been defeated\n\n";
                                std::cout << "Your stats have increased!\n\n";
                                character.attack += 1U;
                                character.defense += 1U;
                                character.health = 8U;
                                brun = false;
                                return;
                            }
                            else if (character_hit_chance == 1U)
                            {
                                enemy_fighter.health = enemy_fighter.health - character.attack;
                                std::cout << "The " << enemy_fighter.name << " has " << enemy_fighter.health << " remaining\n\n";
                                std::cout << "Press Enter to continue..." << std::endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cin.get();
                                ct = 1U;
                                system("cls");
                            }
                            else
                            {
                                std::cout << "You missed!\n\n";
                                std::cout << "Press Enter to continue..." << std::endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cin.get();
                                system("cls");
                                ct = 1U;
                            }


                        }
                        else if(cs == "defend")
                        {
                            std::cout << "You prepare your defense\n";
                            std::cout << "Press Enter to continue..." << std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            defending = 1U;
                            ct = 1U;
                            system("cls");
                        }
                        else if(std::cin.fail())
                        {
                            std::cout << "Invalid option\n\n\n";
                            std::cout << "Press Enter to continue..." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            system("cls");
                        }
                        else if(cs != "attack" or cs != "defend")
                        {
                            std::cout << "Invalid option\n\n\n";
                            std::cout << "Press Enter to continue..." << std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            system("cls");
                        }
                        /*
                        else
                        {
                                continue;
                                brun = false;
                        }
                        */
                    }
                    if(ct == 1U)
                    {
                        // This goes into a continuous loop
                        std::cout << "The " << enemy_fighter.name << " prepares his attack\n";
                        if(enemy_hit_chance == 1U)
                        {
                            if(defending == 1U)
                            {
                                std::cout << "The enemy successfully attacks!\n";
                                std::cout << "You defend for " << character.defense << "!\n";
                                character.health = character.health - (enemy_fighter.attack - character.defense);
                                //std::cout << "You have " << character.health << " health remaining\n\n";
                                defending = 0U;
                                std::cout << "Press Enter to continue..." << std::endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                system("cls");
                            }
                            else if(defending == 0U)
                            {
                                std::cout << "The enemy successfully attacks!\n";
                                character.health = character.health - enemy_fighter.attack;
                                //std::cout << "You have " << character.health << " health remaining\n\n";
                                std::cout << "Press Enter to continue..." << std::endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                system("cls");
                            }
                            }

                        else
                        {
                            std::cout << "The enemy misses!\n\n";
                            std::cout << "Press Enter to continue..." << std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            system("cls");
                        }
                        // Resets ct so turn order returns to player
                        ct = 0U;
                    }
                }


        }


// This will check player commands
auto command_check(std::string &opt, Character& character, bool run)
{
    // This will check if you're entering a main command the program knows
    std::string test;
    std::cout << opt;
    if(opt == "help" or opt == "menu" or opt == "?")
        {
        std::cout << "\n\nMenu:\n1) stats\n2) items\n3) save\n5) forward (proceed through dungeon)\n6) quit\n\n";
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
        std::cout << "\n\nYou have no items\n\n";
        return 1;
    }
    else if(opt == "save")
    {
        std::cout << "\n\nSaving...\n";
        // clear this file out first
        std::ofstream CFile("Save.txt", std::ofstream::trunc);
        CFile.close();
        // Now that it's clear we'll update the stats to what they are currently
        std::ofstream MyFile("Save.txt", std::ios::app);
        MyFile << character.name << '\n';
        MyFile << character.attack << '\n';
        MyFile << character.defense << '\n';
        MyFile << character.health << '\n';
        MyFile << character.hit_chance;
        MyFile.close();
        return 1;
    }
    else if(opt == "forward")
    {
        // move += 1 and spawn possible event
        moves += 1;
        std::cout << "\nYou proceed through the dungeon\n";
        // Send to the battle function when user enters 'forward'
        Battle(character);
        return 1;

    }
    else if(opt == "quit")
    {
        exit(0);
    }
    else
    {
        std::cout << '\n';
        return 1;
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
