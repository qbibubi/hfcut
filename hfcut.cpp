#include "include/menu.h"

#define MINUTE 60000

int main()
{
    bool bpm = false;
    bool counter = false;

    Menu menu = Menu("WELCOME TO TAP DEMON!", "TAP AS FAST AS YOU CAN!");
    menu.AddElement("[CTRL] Test option1", 0);
    menu.AddElement("[ALT] Test option2", 0);
    menu.AddElement(0, 99, false);
    menu.Output();
    
    while (true)
    {
        if (GetAsyncKeyState(VK_LCONTROL))
        {
            bpm = !bpm;
            menu.UpdateElement(0, bpm);
        }
        
        if (GetAsyncKeyState(VK_LMENU))
        {
            counter = !counter;
            menu.UpdateElement(1);

            if (counter)
            {
                menu.UpdateGauge(0, 0);

                for (int i = 0; i < 99; i++)
                {
                    menu.UpdateGauge(0, (double)i);
                    Sleep(20);
                }
                menu.UpdateGauge(0, -1);
                menu.UpdateElement(1);
            }
        }
        Sleep(500);
    }
    
    return 0;
}