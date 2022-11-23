#pragma once

#include <string>
#include <vector>
#include "item.hpp"
#include "gauge.hpp"

class Menu
{
private:
    std::string m_text;
    std::string m_footer;

public:
    std::vector<Item> items;
    std::vector<Gauge> gauges;
    std::vector<int> options;

    Menu(std::string text);
    Menu(std::string header, std::string footer);
    ~Menu() = default;

    void AddElement(std::string text, int status);
    void AddElement(std::string key, std::string text, int status);
    void AddElement(double gaugeMinValue, double gaugeMaxValue, bool status);
    void Output();
    void UpdateElement();
    void UpdateElement(bool toggle);

    template <typename T>
    void UpdateElement(int index, T status);
    
    void UpdateGauge(int index, double currentValue);
};
