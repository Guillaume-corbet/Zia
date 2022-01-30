/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include <iostream>

class Module {
    public:
        Module(std::string name, bool active, std::string nameDLL);
        ~Module();
        std::string getName() const;
        bool isActive() const;
        std::string getNameDLL() const;
        std::string _name;
        std::string _nameDLL;
        bool _active;

    protected:
    private:
};

#endif /* !MODULE_HPP_ */
