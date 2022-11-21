#include "../include/gauge.hpp"
#include <iostream>

Gauge::Gauge(double gaugeMinValue, double gaugeMaxValue) :
    m_gaugeMinValue(gaugeMinValue), m_gaugeMaxValue(gaugeMaxValue)
{
    this->m_active = (gaugeMinValue < gaugeMaxValue);
}

Gauge::Gauge(double gaugeMinValue, double gaugeMaxValue, bool status) :
    m_gaugeMinValue(gaugeMinValue), m_gaugeMaxValue(gaugeMaxValue), m_active(status)
{}

void Gauge::Output()
{
    if (this->m_active)
    {
        m_gaugeValue = m_currentValue / (m_gaugeMaxValue - m_gaugeMinValue);

        int pos = m_gaugeWidth * m_gaugeValue;

        std::cout << ANSI::foreground_red << "[";

        for (int i = 0; i < m_gaugeWidth; i++)
        {
            if (i < pos)
            {
                std::cout << "=";
            }
            else if (i == pos)
            {
                std::cout << ">";
            }
            else std::cout << " ";
        }
        std::cout << "] " << int(m_gaugeValue * 100) << "%" << ANSI::reset << std::endl;
    }
}

void Gauge::Update(double currentValue)
{
    this->m_active = true;

    if (currentValue == -1) this->m_active = false;

    this->m_currentValue = currentValue;
}

void Gauge::SetState(bool status)
{
    this->m_active = status;
}