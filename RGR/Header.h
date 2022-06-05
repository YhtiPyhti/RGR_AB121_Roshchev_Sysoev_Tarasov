#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <vector>
#include <random>
#include <string>
#include <cctype>

#include <Windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef map        < char, char    >   T_key;
typedef string                             T_text;
typedef set        < char  >               T_char_set;
typedef vector     < char  >               T_symbols;


#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"


using namespace std;

int mod(int g, int X, int p);
void eng(string text);
void El_Gamal(ofstream& fout, const string& password, ifstream& in);
vector<int> El_Gamal_encode(int g, int p, int Xb, int k, int m);
int El_Gamal_decode(int g, int p, int Xb, vector<int> entext);

void Tarab_G(ofstream& fout, const string& password);

char* code_atbash(char* src);
char* decode_atbash(char* src);

void Grons(ofstream& fout, const string& password);
void transp(ofstream& fout, const string& password);

int rsa(ofstream& fout, const string& password);

bool isPrime(long int prime);
long int calculateE(long int t);
long int greatestCommonDivisor(long int e, long int t);
long int calculateD(long int e, long int t);
long int encrypt(long int i, long int e, long int n);
long int decrypt(long int i, long int d, long int n);