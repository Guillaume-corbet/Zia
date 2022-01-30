/*
** EPITECH PROJECT, 2021
** GitHub
** File description:
** RequestList
*/

#include "../include/RequestList.hpp"

RequestList::RequestList()
{
    _list = new std::queue<std::pair<std::string, IClient *>>;
}

RequestList::~RequestList()
{
    while (!_list->empty())
        _list->pop();
}

bool RequestList::isEmpty() const
{
    return (_list->empty());
}

int RequestList::size() const
{
    return (_list->size());
}

const std::pair<std::string, IClient *> &RequestList::get() const
{
    // Be careful ! Reference to list front is only valid if list is not empty
    return(_list->front());
}

void RequestList::pop()
{
    if (!_list->empty()) {
        _list->pop();
    }
}

void RequestList::push(const std::pair<std::string, IClient *> &newElem)
{
    _list->push(newElem);
}

void RequestList::push(const std::string &newReq, IClient *ptr)
{
    _list->push(std::pair<std::string, IClient *>(newReq, ptr));
}