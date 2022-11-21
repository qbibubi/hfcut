#pragma once

#include <string>

class Item
{
private:
    std::string m_text{""};
    std::string m_key{""};
    int m_status{-1};

public:
    Item(std::string text, int status);
    Item(std::string key, std::string text, int status);

    void Output();
    void UpdateStatus();

    template <typename T>
    void UpdateStatus(T status);
};
