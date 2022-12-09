#include "NightmareRealmGame.h"

using namespace std;

int main()
{
    system("title NightmareRealm");
    system("mode con cols=103 lines=26");

    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    NightmareRealm NR;

    NR.startgame();
    string movechip ="";
    string movechip2 ="";

    while (1)
    {
        NR.setCursorPosition(59, 11);
        cin >> movechip;

        NR.setCursorPosition(45, 12);
        cin >> movechip2;

        NR.movechip(movechip, movechip2);

        if (NR.endGame())
        {
            NR.setCursorPosition(33, 0);
            printf("\x1B[31m%s\033[0m", "Поздравляю с победой!");
            break;
        }
    }
    _getch();
}
