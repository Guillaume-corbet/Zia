/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Module
*/

#include "../include/Module.hpp"

Module::Module(std::string name, bool active, std::string nameDLL):_name(name), _active(active), _nameDLL(nameDLL)
{
}

Module::~Module()
{
}

std::string Module::getName() const
{
    return (this->_name);
}

bool Module::isActive() const
{
    return (this->_active);
}

std::string Module::getNameDLL() const
{
    return (this->_nameDLL);
}