#include <iostream>
#include <clocale>
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

string symbols = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int i, j, c, sum;
using namespace std;

//Функция получения кода символа
void Keycode(string s)
{
    for (int i = 1; i <= symbols.Length(); i++)
        if (s == symbols[i])
            c = i;
}

//Функция шифрования
string Encode(string Text, String Key)
{
    String result;
    for (i = 1; i <= Text.Length(); i++)
    {
        if (j >= Key.Length())
            j = 0;
        j++;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum + c;
        if (sum > 118)
            sum = sum - 118;
        result += symbols[sum];
    }
    j = 0;
    return result;
}

//Функция дешифрования
String Decode(string Text, String Key)
{
    String result;
    for (i = 1; i <= Text.Length(); i++)
    {
        if (j >= Key.Length())
            j = 0;
        j++;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum - c;
        if (sum < 1)
            sum = sum + 118;
        result += symbols[sum];
    }
    j = 0;
    return result;
}