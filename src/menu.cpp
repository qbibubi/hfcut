#include "../include/menu.hpp"
#include <iostream>

Menu::Menu(std::string text) : m_text(text) {}

Menu::Menu(std::string header, std::string footer) : m_text(header), m_footer(footer) {}

void Menu::AddElement(std::string text, int status)
{
    Item i = Item(text, status);

    this->items.push_back(i);
    this->options.push_back(0);
}

void Menu::AddElement(std::string key, std::string text, int status)
{
    Item i = Item(key, text, status);

    this->items.push_back(i);
    this->options.push_back(0);
}

void Menu::AddElement(double gaugeMinValue, double gaugeMaxValue, bool status)
{
    Gauge g = Gauge(gaugeMinValue, gaugeMaxValue, status);
    
    this->gauges.push_back(g);
    this->options.push_back(1);
}

void Menu::Output()
{
    int itemCount = 0;
    int gaugeCount = 0;

    // std::cout << this->m_text << "\n\n";

    // cls

    for (const auto &x : options)
    {
        if (x == 0)
        {
            items[itemCount].Output();
            itemCount++;
        }
        else if (x == 1)
        {
            gauges[gaugeCount].Output();
            gaugeCount++;
        }
    }
    // std::cout << "\n\n" << this->m_footer;
}

void Menu::UpdateElement()
{
    for(std::vector<Item>::size_type i = 0; i != items.size(); i++)
        items[i].UpdateStatus();

    this->Output();
}

void Menu::UpdateElement(bool toggle)
{
    for(std::vector<Item>::size_type i = 0; i != items.size(); i++)
    {
        if (toggle)
        {
            items[i].UpdateStatus(2);
        }
        else items[i].UpdateStatus(0);
    }
    this->Output();
}

template <typename T>
void Menu::UpdateElement(int index, T status)
{
    try
    {
        items[index].UpdateStatus(status);
    }
    catch (const std::exception& e) { 
        std::cout << e.what(); 
    };
    
    this->Output();
}

void Menu::UpdateGauge(int index, double currentValue)
{
    try
    {
        this->gauges[index].Update(currentValue);
    }
    catch (const std::exception& e) { 
        std::cout << e.what(); 
    };

    this->Output();
}