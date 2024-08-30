#include <iostream>
#include "clsLoginScreen.h"
using namespace std;


int main()
{
    while (true)
    {
        if(!clsLoginScreen::ShowLoginScreen()) // Return false after 3 trails
            break;
    }

    return 0;
}
