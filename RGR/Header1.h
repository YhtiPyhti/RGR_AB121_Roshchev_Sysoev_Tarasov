#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
string encodeText(string text, string key);
string decodeText(string text, string key);
void Vizhiner();
void eng(string text);

string encrypting(string ishText, vector<int> c, vector<int>& c1);

string decrypting(string ishText, vector<int> c, vector<int>& c1);

void TablCryp();
void numb(vector<int> number, int y);