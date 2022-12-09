#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <unordered_map>

using namespace std;

class NightmareRealm
{
    char gamefield[25] = { '0', 'X', '0', 'X', '0',
                          '0', '0', '0', '0', '0',
                          '0', 'X', '0', 'X', '0',
                          '0', '0', '0', '0', '0',
                          '0', 'X', '0', 'X', '0' };

    unordered_map<int, pair< int, int>> markupforreplacement = {
     {0, { 10,2 }}, { 2,{18,2} }, { 4,{26,2} },
     { 5,{10,4} }, { 6,{14,4} }, { 7,{18,4} }, { 8,{22,4} }, { 9,{26,4} },
     { 10,{10,6} }, { 12,{18,6} }, { 14,{26,6} },
     { 15,{10,8} }, { 16,{14,8} }, { 17,{18,8} },  {18,{22,8}}, {19,{26,8}},
      {20,{10,10}}, {22,{18,10}}, {24,{26,10}}
    };

    void randGameField(const char& chip);

    void printGameField();

    void paint—ell(const int& index);

    bool permissionToTravel(const int& index1, const int& index2);

    void helper();

    int chechIsDigit(string const& stringindex);

public:

    bool endGame();

    void startgame();

    void movechip(const string& index1, const string& index2);

    void setCursorPosition(int x, int y);
};

