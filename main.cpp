#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <limits>
#include <deque>
#include <stdlib.h>
#include <windows.h>
#include "lib.h"
#include <map>
// We'll use files, templates, classes, (try/catch/throw), arrays, references, possibly pointers
/*
TO DO:
Create Enemy Battles - in progress
Make game end in four moves - so variable that counts moves
Exp system
How stats actually work
Clear up errors
If enemy attack is strong enough, it gives you a ton of health
*/



int main() {
    // BELOW: name, health, attack, defense, hit_chance
    enemy_initialization(wolf, "wolf", 5U, 2U, 1U, 3U);
    enemy_initialization(undead, "undead", 3U, 2U, 1U, 3U);
    enemy_initialization(warrior, "warrior", 5U, 4U, 2U, 1U);

    // Deque for character loading
    std::deque<std::string> ls;

    // Initialize Character
    Character hero;

    // Answer option and character generator boolean
    bool mn_running = false;
    bool cg_running = true;
    char answer;
    // lf is your load file
    std::string lf;

    std::cout << "\nType \'load\' to load a character or '\continue\' to create your character:\n";
    std::cin >> lf;
    if(lf == "load")
        {
            // My Text will contain each line from the file
            std::string MyText;
            // The deque below will store the stats from the save file and give your character these stats... probably
            // Deque name ls means loaded stats or load save


            // READ FROM FILE, THROW IN AN ARRAY AND PUT THAT INFO INTO THE CHARACTER CLASS
            std::ifstream MyFile("save.txt", std::ios::app);
            while(getline(MyFile, MyText))
            {
                ls.push_back(MyText);
            }
            MyFile.close();

            mn_running = true;
            cg_running = false;
        }
    else if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        system("cls");



            std::cout << "                         D E C E P T I O N\n";
        std::cout << "                               R P G\n\n\n";

    // Character creation loop;
    while(cg_running)
    {
        std::cout << "Name your character: ";
        std::cin >> hero.name;
        std::cout << "Confirm hero name " << hero.name <<  " [y/n]: ";
        try
        {
            std::cin >> answer;
            if(answer == 'y')
            {
                cg_running = false;
                std::cout << "\nName confirmed\n\n";
                mn_running = true;
                Sleep(2);
                system("cls");
                //break; // this will need to close out of character creation. Introduce While loop.
            }
            else if(answer == 'n')
            {
                system("cls");
                continue;
                //break;
            }
            else if(std::cin.fail())
            {

                throw std::invalid_argument("Please only answer with \'y\' or \'n\'");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n');

                //Err_handler("cinfail");
            }
            else
            {
                std::cout << "Please only answer with \'y\' or \'n\'";
                Sleep(2);
                system("cls");
            }
        }

        catch(std::invalid_argument e)
        {
            std::cout << e.what();
            Sleep(2);
            system("cls");
        }


        }


        // four moves until you hit boss and win
        //If a load has happened ie: the deque isn't empty, load character
          if(not ls.empty())
        {
                uint32_t a = stoi(ls[1]);
                uint32_t d = stoi(ls[2]);
                uint32_t h = stoi(ls[3]);
                uint32_t hc = stoi(ls[4]);
                //nadhh
                hero.name = ls[0];
                hero.attack = a;
                hero.defense = d;
                hero.health = h;
                hero.hit_chance = hc;
        }


        std::cout << "You may open the menu at any time by typing \"menu\": \n";
    // Main Program Loop
    while(mn_running)
    {

        std::cout << "Enter a command: ";
        std::cin >> u_command;
        command_check(u_command, hero, mn_running);

    }
    return 0;
}

