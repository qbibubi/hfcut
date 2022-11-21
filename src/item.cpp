#include "../include/item.hpp"
#include "../include/menu.hpp"
#include <iomanip>

Item::Item(std::string text, int status)
{
    this->m_text = text;
    this->m_status = status;
}

Item::Item(std::string key, std::string text, int status)
{
    this->m_key = key;
    this->m_text = text;
    this->m_status = status;
}

/* Output will go through a big overhaul
 * due to swapping to ncurses
*/

void Item::Output()
{
    if (this->m_key != "")
    {
        //std::cout << "[" << this->m_key << "]" << std::right << std::setw(10) << this->m_text;
    }
    else
    {
        //std::cout << this->m_text << std::right << std::setw(10) ;
    }

    if (m_status != -1) 
    {
        //std::cout << std::right << std::setw(10) << "[";
        if (m_status == 0)
        {
            //std::cout<< ANSI::foreground_red << "OFF";
        }
        else if (m_status == 1) 
        {
            //std::cout << ANSI::foreground_yellow << "LOADING";
        }
        else if (m_status == 2)
        {
            //std::cout << ANSI::foreground_green << "ON";
        }
        //std::cout << ANSI::reset << "]";
    }
    //std::cout << std::endl;
}

void Item::UpdateStatus()
{
    switch (this->m_status)
    {
    case 0:
        this->m_status = 1;
        break;
    case 1:
        this->m_status = 2;
        break;
    case 2:
        this->m_status = 0;
        break;
    
    default:
        break;
    }
}

template <typename T>
void Item::UpdateStatus(T status)
{
    this->m_status = status;
}
