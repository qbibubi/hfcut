#ifndef ITEM_H
#define ITEM_H

// missing include library "Linux.h"
#include <string>

class Item
{
private:
    std::string text;
    std::string key = "";
    int status;

public:
    Item(std::string text, int status);
    Item(std::string key, std::string text, int status);

    void Output();
    void UpdateStatus();
    void UpdateStatus(int status);
    void UpdateStatus(bool status);
};

#endif // ITEM_H
