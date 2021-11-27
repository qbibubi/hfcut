#ifndef GAUGE_H
#define GAUGE_H

#include "color.h"

class Gauge
{
private:
    double m_gaugeValue = 0.0;  // 0 -> 1
    double m_currentValue = 0.0;
    double m_gaugeMinValue = 0;
    double m_gaugeMaxValue = 1;
    int m_gaugeWidth = 70; 
    bool m_active = false;

public:
    Gauge(double gaugeMinValue, double gaugeMaxValue);
    Gauge(double gaugeMinValue, double gaugeMaxValue, bool status);

    void Output();
    void Update(double currentValue);
    double GetProgress() { return m_gaugeValue; }
    bool GetState() { return m_active; }
    void SetState(bool status);
};

#endif // GAUGE_H