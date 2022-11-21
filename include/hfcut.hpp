#pragma once

#include <ncurses.h>
#include "menu.hpp"

class HFCUT {
private:
    bool m_running{false};

public:
    HFCUT();
    ~HFCUT() = default;

    void run();
};