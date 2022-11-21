#include "include/hfcut.hpp"
/* The whole file has to be ported from Windows to Linux. 
 * The Windows version is in the file hfcut.cpp.
 * For the future reference, the Windows and Linux versions
 * will have separate files.
*/

int main()
{
    initscr();
    nocbreak();
    noecho();
    keypad(stdscr, TRUE);

    bool bpm = false;
    bool counter = false;

    // As of 21st November 2022, I now possess a Blahaj plushie.
    Menu menu = Menu("WELCOME TO [PROJECT NAME]!", "I WANT A BLAHAJ!");
    menu.AddElement("N0", "EXIT", 0);
    menu.AddElement("N1", "BPM", 0);
    menu.AddElement("N2", "COUNTER", 0);
    menu.AddElement(0, 99, false);
    menu.Output();
    
    while (true)
    {
        /*
        if (GetAsyncKeyState(VK_NUMPAD1))
        {
            bpm = !bpm;
            menu.UpdateElement(0, bpm);
        }
        
        if (GetAsyncKeyState(VK_NUMPAD2))
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

        if (GetAsyncKeyState(VK_NUMPAD0))
            return 0;

        Sleep(500);
    }
    */

    endwin();
    return 0;
}
