/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Config
*/

// #include "testUnitaire.hpp"
#define RED std::string("\x1B[31m")
#define WHITE std::string("\033[0m")
#define GREEN std::string("\x1B[32m")
#include "../Config/include/ConfigHandler.hpp"

void test_unitaire_config(int &good, int &total)
{
    ConfigHandler *config = new ConfigHandler();

    int mygood = 0;
    int mytotal = 0;

    std::cout << "STARTING CONFIG UNIT TEST" << std::endl;
    std::cout << "DEFAULT CONFIG : ";
    try {
        if (config->test_unitaire_defaultconfig() == true) {
            std::cout << GREEN << "OK" << WHITE << std::endl;
            mygood = mygood + 1;
        } else {
            std::cout << RED << "KO" << WHITE << std::endl;
        }
    }
    catch (...) {
        std::cout << RED << "KO (CRASH)" << WHITE << std::endl;
    }
    mytotal = mytotal + 1;

    std::cout << "DEFAULT PATH FOR CONFIG FILE : ";
    try {
        if (config->test_unitaire_goodpath() == true) {
            std::cout << GREEN << "OK" << WHITE << std::endl;
            mygood = mygood + 1;
        } else {
            std::cout << RED << "KO" << WHITE << std::endl;
        }
    }
    catch (...) {
        std::cout << RED << "KO (CRASH)" << WHITE << std::endl;
    }
    mytotal = mytotal + 1;

    std::cout << "DEFAULT MODULE: ";
    try {
        if (config->test_unitaire_defaultmodule() == true) {
            std::cout << GREEN << "OK" << WHITE << std::endl;
            mygood = mygood + 1;
        } else {
            std::cout << RED << "KO" << WHITE << std::endl;
        }
    }
    catch (...) {
        std::cout << RED << "KO (CRASH)" << WHITE << std::endl;
    }
    mytotal = mytotal + 1;

    good = mygood;
    total = mytotal;
    if (good == total) {
        std::cout << GREEN << "TEST CONFIG: " << good << "/" << total << WHITE << std::endl;
    } else {
        std::cout << RED << "TEST CONFIG: " << good << "/" << total << WHITE << std::endl;
    }
}