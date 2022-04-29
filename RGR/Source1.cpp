#include <iostream>
#include <clocale>
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <Windows.h>

using namespace std;
void Vizhiner() {
	string Key, Text, EnText, DeText;
	cout << "������� ������: ";
	cin >> Text;
	cout << "������� ����: ";
	cin >> Key;
	EnText = encodeText(Text, Key);
	cout << "�������������� ������: " << EnText << endl;
    DeText = decodeText(EnText, Key);
    cout << "��������������� ������: " << DeText << endl;
}
string encodeText(string text, string key) {
    int i, j;

    char newKey[100];
    char encryptedText[100];

    //����� ����
    for (i = 0, j = 0; i < text.length(); ++i, ++j) {
        if (j == key.length()) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    
    //��������
    for (i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            if (97 < (int)text[i] && 97 < (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') + (newKey[i] - 'a')) % 26);
                encryptedText[i] += 'a';
            }
            else if (97 > (int)text[i] && 97 < (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'A') + (newKey[i] - 'a')) % 26);
                encryptedText[i] += 'a';
            }
            else if (97 < (int)text[i] && 97 > (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') + (newKey[i] - 'A')) % 26);
                encryptedText[i] += 'a';
            }
            else {
                encryptedText[i] = (((text[i] - 'A') + (newKey[i] - 'A')) % 26);
                encryptedText[i] += 'A';
            }
        }
        else {
            encryptedText[i] = ' ';
        }
    }
    encryptedText[i] = '\0';
    return encryptedText;
}

string decodeText(string text, string key) {
    int i, j;

    char newKey[100];
    char encryptedText[100];

    //����� ����
    for (i = 0, j = 0; i < text.length(); ++i, ++j) {
        if (j == key.length()) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    //��������
    for (i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            if (97 < (int)text[i] && 97 < (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') - (newKey[i] - 'a') + 26) % 26);
                encryptedText[i] += 'a';
            }
            else if (97 > (int)text[i] && 97 < (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'A') - (newKey[i] - 'a') + 26) % 26);
                encryptedText[i] += 'A';
            }
            else if (97 < (int)text[i] && 97 > (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') - (newKey[i] - 'A') + 26) % 26);
                encryptedText[i] += 'a';
            }
            else {
                encryptedText[i] = (((text[i] - 'A') - (newKey[i] - 'A') + 26) % 26);
                encryptedText[i] += 'A';
            }
        }
        else {
            encryptedText[i] = ' ';
        }
    }
    encryptedText[i] = '\0';
    return encryptedText;
}