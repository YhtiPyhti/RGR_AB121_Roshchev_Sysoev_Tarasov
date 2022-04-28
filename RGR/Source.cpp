#include <iostream>
#include "Header.h"
#include <clocale>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <Windows.h>
#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"

using namespace std;
int mod(int g, int X, int p) {
	int t = 0, t0 = g % p;
	for (int i = 1; i <= X; i++) {
		t = g % p;
		g = t * t0;
	}
	return t;
}

void El_Gamal(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int g = 5, p = 3571, Xa = 4, Xb = 11, Ya = 0, Yb = 0, k = 7, r = 0, e = 0, m = 0, m1 = 0, t = 0;
	cout << "Выберете число от 1 до " << p << endl;
	cin >> m;
	Ya = mod(g, Xa, p);
	Yb = mod(g, Xb, p);
    cout << "Абонент A" << " Секретный ключ - " << Xa << " Открытый ключ - " << Ya << endl;
    cout << "Абонент B" << " Секретный ключ - " << Xb << " Открытый ключ - " << Yb << endl;
	r = mod(g, k, p);
	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;
	g = p - 1 - Xb;
	t = mod(r, g, p);
	m1 = ((e % p) * t) % p;

	cout << "Исходный текст:" << m << endl;
	cout << "Зашифрованный текст:" << r << ", " << e << endl;
	cout << "Расшифрованный текст:" << m1 << endl;
}

void Tarab_G()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
   SetConsoleOutputCP(1251);
    
       char str[1000];
    cout << "Введите буквы :" << endl;
    cin >> str;
    for (int i = 0; i < 1000; i++) 
    {
     if (str[i] == 'Б') 
     {
       str[i] = 'Щ';
    }
     else if (str[i] == 'Щ')
        str[i] = 'Б';

     if (str[i] == 'В')
        str[i] = 'Ш';
     else if (str[i] == 'Ш')
        str[i] = 'В';

     if (str[i] == 'Г')
        str[i] = 'Ч';
     else if (str[i] == 'Ч')
        str[i] = 'Г';

     if (str[i] == 'Д')
       str[i] = 'Ц';
     else if (str[i] == 'Ц')
	     str[i] = 'Д';

    if (str[i] == 'Ж')
        str[i] = 'Х';
     else if (str[i] == 'Х')
        str[i] = 'Ж';

     if (str[i] == 'З') 
       {       
	str[i] = 'Ф';
     }
     else 
     {
       if (str[i] == 'Ф')
            str[i] = 'З';
     }

     if (str[i] == 'К')
        str[i] = 'Т';
     else if (str[i] == 'Т')
        str[i] = 'К';

     if (str[i] == 'Л')
        str[i] = 'С';
     else if (str[i] == 'С')
        str[i] = 'Л';

     if (str[i] == 'М')
        str[i] = 'Р';
     else if (str[i] == 'Р')
        str[i] = 'М';

     if (str[i] == 'Н')
        str[i] = 'П';
     else if (str[i] == 'П')
        str[i] = 'Н';

     }
  cout <<"Зашифрованное слово: "<< str << endl;


}

    char* code_atbash(char* src) {
        char* dst = src;
        const char* cch, * dch;

        while (*src) {
            if (isalpha(*src)) {
                for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                    if (*cch == toupper(*src)) {
                        *src = (isupper(*src)) ? *dch : tolower(*dch);
                        break;
                    }
                }
            }
            *src++;
        }
        return dst;
    }

    // функция декодирования
    char* decode_atbash(char* src) {
        char* dst = src;
        const char* cch, * dch;

        while (*src) {
            if (isalpha(*src)) {
                for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                    if (*dch == toupper(*src)) {
                        *src = (isupper(*src)) ? *cch : tolower(*cch);
                        break;
                    }
                }
            }
            *src++;
        }
        return dst;
    }


   

