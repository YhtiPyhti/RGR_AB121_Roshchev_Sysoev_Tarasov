#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>

using namespace std;
string encodeText(string text, string key);
string decodeText(string text, string key);
void Vizhiner(ofstream& fout, const string& password);
void eng(string text);

string encrypting(string ishText, vector<int> c, vector<int>& c1);

string decrypting(string ishText, vector<int> c, vector<int>& c1);

void TablCryp(ofstream& fout, const string& password);
void numb(vector<int> number, int y);
