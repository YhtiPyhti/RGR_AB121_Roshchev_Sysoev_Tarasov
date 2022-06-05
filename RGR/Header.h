#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <stdio.h>
#include <string>
#include <cctype>
#include <Windows.h>
#include <vector>
#include <random>
#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"


using namespace std;

int mod(int g, int X, int p);
void eng(string text);
void El_Gamal(ofstream& fout, const string& password);
vector<int> El_Gamal_encode(int g, int p, int Xb, int k, int m);
int El_Gamal_decode(int g, int p, int Xb, vector<int> entext);

void Tarab_G(ofstream& fout, const string& password);

char* code_atbash(char* src);
char* decode_atbash(char* src);

void Grons(ofstream& fout, const string& password);
void transp(ofstream& fout, const string& password);
