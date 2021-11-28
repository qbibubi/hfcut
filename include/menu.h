#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "item.h"
#include "gauge.h"

class Item;     // Forward declaration
class Gauge;    // of the classes

class Menu
{
private:
    std::string m_text;
    std::string m_footer = "";
    void ShowCursor(bool showFlag);

public:
    std::vector<Item> items;
    std::vector<Gauge> gauges;
    std::vector<int> options;

    Menu(std::string text);
    Menu(std::string header, std::string footer);

    void AddElement(std::string text, int status);
    void AddElement(std::string key, std::string text, int status);
    void AddElement(double gaugeMinValue, double gaugeMaxValue, bool status);
    void Output();
    void UpdateElement();
    void UpdateElement(bool toggle);
    void UpdateElement(int index, int status);
    void UpdateElement(int index, bool status);
    void UpdateGauge(int index, double currentValue);
};

#endif // MENU_H