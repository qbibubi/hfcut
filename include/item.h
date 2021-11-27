#ifndef ITEM_H
#define ITEM_H

#include <Windows.h>
#include <string>

class Item
{
private:
    std::string text;
    int status;

public:
    Item(std::string text, int status);

    void Output();
    void UpdateStatus();
    void UpdateStatus(int status);
    void UpdateStatus(bool status);
};

#endif // ITEM_H