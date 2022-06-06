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
#include <climits>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>

using namespace std;

typedef map        < char, char    >   T_key;
typedef string                             T_text;
typedef set        < char  >               T_char_set;
typedef vector     < char  >               T_symbols;


#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"


using namespace std;



void Tarab_G(ofstream& fout, const string& password, ifstream& in);

char* code_atbash(char* src);
char* decode_atbash(char* src);

void Grons(ofstream& fout, const string& password, ifstream& in);
void transp(ofstream& fout, const string& password, ifstream& in);

int rsa(ofstream& fout, const string& password);

bool isPrime(long int prime);
long int calculateE(long int t);
long int greatestCommonDivisor(long int e, long int t);
long int calculateD(long int e, long int t);
long int encrypt(long int i, long int e, long int n);
long int decrypt(long int i, long int d, long int n);

unsigned char     get_rand_symb();
void    make_rand_key(T_key& key,T_key& reverse_key);
void    input_text(T_text& text);
void    encrypt_text(T_text  const& text,T_key   const& key,T_text& encrypted_text);
void    print_text_with_comment(T_text  const& text,T_text  const& comment);
void    tablichnaya_perestanovka();