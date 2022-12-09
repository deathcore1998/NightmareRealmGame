#include "NightmareRealmGame.h"

void NightmareRealm::startgame()
{
    randGameField(4);
    randGameField(30);
    randGameField(6);
    printGameField();
    helper();

    setCursorPosition(31, 11);
    printf("  Поменять местами ячейку № ");
    setCursorPosition(31, 12);
    printf("  На ячейку № ");
}

void NightmareRealm::randGameField(const char& chip)
{
    vector<int> randindex;
    int index;

    for (int i = 0; i < 25; i++)
    {
        if (gamefield[i] == '0')
        {
            randindex.push_back(i);
        }
    }

    for (int i = 0; i < 5;)
    {
        index = randindex[rand() % randindex.size()];
        if (gamefield[index] == '0')
        {
            gamefield[index] = chip;
            i++;
        }
    }

    if (endGame())
    {
        randGameField(chip);
    }
}

void NightmareRealm::printGameField()
{
    string topwall = "\t ___________________";
    string topbot = " \t|___|___|___|___|___|";
    string wall = " \t|   |   |   |   |   |";

    printf("\n%s\n\t", topwall.c_str());

    for (int i = 0; i < 25; i++)
    {
        if (i % 5 == 0 && i != 0)
        {
            printf("|\n%s\n\t", topbot.c_str());
        }
        printf("| ");
        paintСell(i);
        printf(" ");
    }

    printf("|\n%s\n", topbot.c_str());
}

void NightmareRealm::movechip(const string& indexs1, const string& indexs2)
{
    int index1 = chechIsDigit(indexs1);
    int index2 = chechIsDigit(indexs2);

    if (gamefield[index1] != 'X' && gamefield[index2] != 'X' && permissionToTravel(index1, index2))
    {
        if (gamefield[index1] == '0' && gamefield[index2] != '0' || gamefield[index1] != '0' && gamefield[index2] == '0')
        {
            swap(gamefield[index1], gamefield[index2]);
            setCursorPosition(markupforreplacement[index1].first, markupforreplacement[index1].second);
            paintСell(index1);

            setCursorPosition(markupforreplacement[index2].first, markupforreplacement[index2].second);
            paintСell(index2);
        }
    }
    setCursorPosition(59, 11);
    printf("%s", "            ");
    setCursorPosition(45, 12);
    printf("%s", "            ");
}

void NightmareRealm::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

bool NightmareRealm::permissionToTravel(const int& index1, const int& index2)
{
    if (index1 >= 0 && index2 >= 0 && index1 <= 24 && index2 <= 24)
    {
        for (int i = 5; i <= 20; i += 5)
        {
            if (index1 == i && index2 == i - 1 || index1 == i - 1 && index2 == i)
            {
                return false;
            }
        }

        if (index1 + 1 == index2 || index1 == index2 + 1)// left/right
        {
            return true;
        }
        else if (index1 + 5 == index2 || index1 == index2 + 5) // up/down
        {
            return true;
        }
    }

    return false;
}

void NightmareRealm::helper()
{
    string topwall = "\t ___________________";
    string topbot = " \t|___|___|___|___|___|";
    string wall = " \t|   |   |   |   |   |";

    printf("\n\tТаблица индексов\n%s\n\t", topwall.c_str());

    for (int i = 0; i < 25; i++)
    {
        if (i % 5 == 0 && i != 0)
        {
            printf("|\n%s\n\t", topbot.c_str());
        }
        if (gamefield[i] == 'X')
        {
            printf("| \x1B[31m%c\033[0m ", 'X');
        }
        else if (i <= 9)
        {
            printf("| %i ", i);
        }
        else
        {
            printf("|%i ", i);
        }
    }

    printf("|\n%s\n", topbot.c_str());

    setCursorPosition(31, 2);
    printf("  Цель игры: Требуется, передвигая фишки, выставить их в три");
    setCursorPosition(31, 3);
    printf("  вертикальных ряда соответственно цветам ");
    setCursorPosition(31, 5);
    printf("  Правила игры: ");
    setCursorPosition(31, 6);
    printf("  X - заблокированный блок, нельзя менять с другими");
    setCursorPosition(31, 7);
    printf("  0 - пустой блок, только с ним можно менять другие блоки");
    setCursorPosition(31, 8);
    printf("  Можно менять только соседние блоки");
    setCursorPosition(31, 9);
    printf("  Фишки можно менять только по горизонтали или вертикали");

}

int NightmareRealm::chechIsDigit(string const& stringindex)
{
    for (int i = 0; i < stringindex.length(); i++)
    {
        if (stringindex[i] < '0' || stringindex[i] > '9')
        {
            return -1;
        }
    }
    return stoi(stringindex);
}

bool NightmareRealm::endGame()
{
    for (int i = 0; i < 5; i += 2)
    {
        if (!(gamefield[0 + i] == gamefield[5 + i] && gamefield[5 + i] == gamefield[10 + i]
            && gamefield[10 + i] == gamefield[15 + i] && gamefield[15 + i] == gamefield[20 + i]))
        {
            return false;
        }
    }

    return true;
}

void NightmareRealm::paintСell(const int& index)
{
    if (gamefield[index] == '0')
    {
        printf("\x1B[36m%c\033[0m", gamefield[index]);// blue
    }
    else if (gamefield[index] == 'X')
    {
        printf("%c", gamefield[index]); // white
    }
    else if (gamefield[index] == 4)
    {
        printf("\x1B[31m%c\033[0m", gamefield[index]);// red
    }
    else if (gamefield[index] == 30)
    {
        printf("\x1B[32m%c\033[0m", gamefield[index]);// green
    }
    else if (gamefield[index] == 6)
    {
        printf("\x1B[33m%c\033[0m", gamefield[index]); // yellow
    }
}