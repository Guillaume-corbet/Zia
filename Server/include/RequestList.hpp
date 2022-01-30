/*
** EPITECH PROJECT, 2021
** GitHub
** File description:
** RequestList
*/

#ifndef REQUESTLIST_HPP_
#define REQUESTLIST_HPP_

#include <queue>
#include "../interfaces/IClient.hpp"

class RequestList {
    public:
        RequestList();
        ~RequestList();
        bool isEmpty() const;
        int size() const;
        const std::pair<std::string, IClient *> &get() const;
        void pop();
        void push(const std::pair<std::string, IClient *> &newElem);
        void push(const std::string &newReq, IClient *ptr);

    protected:
    private:
        std::queue<std::pair<std::string, IClient *>> *_list;
};

#endif /* !REQUESTLIST_HPP_ */