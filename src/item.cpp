#include "../include/item.h"
#include "../include/menu.h"
#include <iostream>

Item::Item(std::string text, int status)
{
    this->text = text;
    this->status = status;
}

void Item::Output()
{
    std::cout << this->text;

    if (status != -1) {

        std::cout << " [";
        if (status == 0)
        {
            std::cout << ANSI::foreground_red << "OFF";
        }
        else if (status == 1) 
        {
            std::cout << ANSI::foreground_yellow << "LOADING";
        }
        else if (status == 2)
        {
            std::cout << ANSI::foreground_green << "ON";
        }
        std::cout << ANSI::reset << "]";
    }
    std::cout << std::endl;
}

void Item::UpdateStatus()
{
    if (this->status == 2)
    {
        this->status = 0;
    }
    else if (this->status == 0) 
    {
        this->status = 1;
    }
    else if (this->status == 1)
    {
        this->status = 2;
    }
}

void Item::UpdateStatus(int status)
{
    this->status = status;
}

void Item::UpdateStatus(bool status)
{
    int iStatus = status ? 2 : 0;
    this->status = iStatus;
}
