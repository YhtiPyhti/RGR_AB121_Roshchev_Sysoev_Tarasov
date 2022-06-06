#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string encodeText(string text, string key);
string decodeText(string text, string key);
void Vizhiner(ofstream& fout, const string& password, string& text, string& wish);
void eng(string text);

string encrypting(string ishText, vector<int> c, vector<int>& c1);

string decrypting(string ishText, vector<int> c, vector<int>& c1);

void TablCryp(ofstream& fout, const string& password, string& text, string& wish);

void numb(vector<int> number, int y);


int mod(int g, int X, int p);
void eng(string text);
void El_Gamal(ofstream& fout, const string& password, string& text, string& wish);
vector<int> El_Gamal_encode(int g, int p, int Xb, int k, int m);
int El_Gamal_decode(int g, int p, int Xb, vector<int> entext);