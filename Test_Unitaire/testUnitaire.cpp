/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** testUnitaire
*/

void test_unitaire_php(int &good, int &total);
void test_unitaire_config(int &good, int &total);
void test_unitaire_core(int &good, int &total);
void test_unitaire_security(int &good, int &total);

#include <iomanip>
#include <iostream>

int main(int argc, char **argv)
{
    int goodPhp = 0;
    int totalPhp = 0;
    int goodConfig = 0;
    int totalConfig = 0;
    int goodCore = 0;
    int totalCore = 0;
    int goodSecurity = 0;
    int totalSecurity = 0;
    int good = 0;
    int total = 0;

    std::cout << "STARTING UNIT TEST" << std::endl;

    test_unitaire_php(goodPhp, totalPhp);
    test_unitaire_config(goodConfig, totalConfig);
    test_unitaire_core(goodCore, totalCore);
    test_unitaire_security(goodSecurity, totalSecurity);

    good = goodPhp + goodConfig + goodCore + goodSecurity;
    total = totalPhp + totalConfig + totalCore + totalSecurity;
    if (good == total) {
        std::cout << "\x1B[32m" << "test: " << good << " bon, " << total << " total" << "\033[0m" << std::endl;
    } else {
        std::cout << "\x1B[31m" << "test: " << good << " bon, " << total << " total" << "\033[0m" << std::endl;
    }
    return (0);
}