/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Php
*/

#include "../Server/modules/PhpModule/PhpModule.hpp"
#include "testUnitaire.hpp"

void test_unitaire_exist_php(int &good, int &total)
{
    PhpModule *php = new PhpModule();

    std::cout << "STARTING PHP EXIST UNIT TEST" << std::endl;
    if (php->exist(path + "test.php")) {
        good = good + 1;
        std::cout << GREEN << "real file" << WHITE << std::endl;
    } else {
        std::cout << RED << "real file" << WHITE << std::endl;
    }
    total = total + 1;
    if (!php->exist(path + "fauxfichier")) {
        good = good + 1;
        std::cout << GREEN << "fichier sans .php" << WHITE << std::endl;
    } else {
        std::cout << RED << "fichier sans .php" << WHITE << std::endl;
    }
    total = total + 1;
    if (!php->exist("test.php")) {
        good = good + 1;
        std::cout << GREEN << "filepath faux" << WHITE << std::endl;
    } else {
        std::cout << RED << "filepath faux" << WHITE << std::endl;
    }
    total = total + 1;
    if (good == total) {
        std::cout << GREEN << "test php exist: " << good << " bon, " << total << " total" << WHITE << std::endl;
    } else {
        std::cout << RED << "test php exist: " << good << " bon, " << total << " total" << WHITE << std::endl;
    }
}

void test_unitaire_run_php(int &good, int &total)
{
    PhpModule *php = new PhpModule();
    std::ifstream f(path + "response_test_php");
    std::string str((std::istreambuf_iterator<char>(f)),
                 std::istreambuf_iterator<char>());

    std::cout << "STARTING PHP RUN UNIT TEST" << std::endl;
    if (str == php->run(path + "test.php")) {
        good = good + 1;
        std::cout << GREEN << "real file" << WHITE << std::endl;
    } else {
        std::cout << RED << "real file" << WHITE << std::endl;
    }
    total = total + 1;
    if (std::string("Error no such file") == php->run("fauxfichier")) {
        good = good + 1;
        std::cout << GREEN << "fichier sans .php" << WHITE << std::endl;
    } else {
        std::cout << RED << "fichier sans .php" << WHITE << std::endl;
    }
    total = total + 1;
    if (std::string("Error no such file") == php->run("test.php")) {
        good = good + 1;
        std::cout << GREEN << "filepath faux" << WHITE << std::endl;
    } else {
        std::cout << RED << "filepath faux" << WHITE << std::endl;
    }
    total = total + 1;
    if (good == total) {
        std::cout << GREEN << "test php run: " << good << " bon, " << total << " total" << WHITE << std::endl;
    } else {
        std::cout << RED << "test php run: " << good << " bon, " << total << " total" << WHITE << std::endl;
    }
}

void test_unitaire_php(int &good, int &total)
{
    int goodExist = 0;
    int totalExist = 0;
    int goodRun = 0;
    int totalRun = 0;

    std::cout << "STARTING PHP UNIT TEST" << std::endl;

    test_unitaire_exist_php(goodExist, totalExist);
    test_unitaire_run_php(goodRun, totalRun);

    good = goodExist + goodRun;
    total = totalExist + totalRun;
    if (good == total) {
        std::cout << GREEN << "test php: " << good << " bon, " << total << " total" << WHITE << std::endl;
    } else {
        std::cout << RED << "test php: " << good << " bon, " << total << " total" << WHITE << std::endl;
    }
}