#include "../include/menu.h"
#include <iostream>

Menu::Menu(std::string text)
{
    this->m_text = text;
    this->ShowCursor(false);
}

Menu::Menu(std::string header, std::string footer)
{
    this->m_text = header;
    this->m_footer = footer;
    this->ShowCursor(false);
}

void Menu::AddElement(std::string text, int status)
{
    Item option = Item(text, status);

    this->items.push_back(option);
    this->options.push_back(0);
}

void Menu::AddElement(double gaugeMinValue, double gaugeMaxValue, bool status)
{
    Gauge gauge = Gauge(gaugeMinValue, gaugeMaxValue, status);
    
    this->gauges.push_back(gauge);
    this->options.push_back(1);
}

void Menu::Output()
{
    int itemCount = 0;
    int gaugeCount = 0;

    system("CLS");

    std::cout << this->m_text << "\n\n";
    
    for (int i : options)
    {
        if (i == 0)
        {
            items[itemCount].Output();
            itemCount++;
        }
        else if (i == 1)
        {
            gauges[gaugeCount].Output();
            gaugeCount++;
        }
    }
    std::cout << "\n\n" << this->m_footer;
}

void Menu::UpdateElement()
{
    for(std::vector<Item>::size_type i = 0; i != items.size(); i++)
    {
        items[i].UpdateStatus();
    }
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

void Menu::UpdateElement(int index, int status)
{
    try
    {
        items[index].UpdateStatus(status);
    }
    catch (const std::exception& e) { std::cout << e.what(); };
    this->Output();
}

void Menu::UpdateElement(int index, bool status)
{
    try
    {
        items[index].UpdateStatus(status);
    }
    catch (const std::exception& e) { std::cout << e.what(); };
    this->Output();
}

void Menu::UpdateGauge(int index, double currentValue)
{
    try
    {
        this->gauges[index].Update(currentValue);
    }
    catch (const std::exception& e) { std::cout << e.what(); };
    this->Output();
}

void Menu::ShowCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}