#include "Header1.h"

void eng(string text) {
    int k = 0;
    while (k < text.length()) {
        if ((text[k] >= 'a') && (text[k] <= 'z') || (text[k] == ' '));
        else if ((text[k] >= 'A') && (text[k] <= 'Z'));
        else 
            throw " Incorrect input! Use only english. (Be sure to use a space before entering)\n";
        
        k++;
    }
}

void Vizhiner() {
    string Key, Text, EnText, DeText;
    try {
        cout << "Input text: ";
        cin.ignore();
        getline(cin, Text);
        eng(Text);
    }
    catch (const char* err) {
        cout << err << endl;
        Text.clear();
        Vizhiner();
    }
    try {
        cout << "Input key: ";
        cin >> Key;
        eng(Key);
        EnText = encodeText(Text, Key);
        cout << "Encoded string " << EnText << endl;
        DeText = decodeText(EnText, Key);
        cout << "Decoded string: " << DeText << endl;
    }
    catch (const char* err) {
        cout << err << endl;
        Key.clear();
        Vizhiner();
    }
}
string encodeText(string text, string key) {
    int i, j;

    char newKey[100];
    char encryptedText[1000];

    //новый ключ
    for (i = 0, j = 0; i < text.length(); ++i, ++j) {
        if (j == key.length()) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    
    //шифровка
    for (i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            if (97 <= (int)text[i] && 97 <= (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') + (newKey[i] - 'a')) % 26);
                encryptedText[i] += 'a';
            }
            else if (97 > (int)text[i] && 97 <= (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'A') + (newKey[i] - 'a')) % 26);
                encryptedText[i] += 'A';
            }
            else if (97 <= (int)text[i] && 97 > (int)newKey[i]) {
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
    char encryptedText[1000];

    //новый ключ
    for (i = 0, j = 0; i < text.length(); ++i, ++j) {
        if (j == key.length()) {
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    //дешифровка
    for (i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            if (97 <= (int)text[i] && 97 <= (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') - (newKey[i] - 'a') + 26) % 26); // a a
                encryptedText[i] += 'a';
            }
            else if (97 > (int)text[i] && 97 <= (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'A') - (newKey[i] - 'a') + 26) % 26); // A a
                encryptedText[i] += 'A';
            }
            else if (97 <= (int)text[i] && 97 > (int)newKey[i]) {
                encryptedText[i] = (((text[i] - 'a') - (newKey[i] - 'A') + 26) % 26); // a A
                encryptedText[i] += 'a';
            }
            else {
                encryptedText[i] = (((text[i] - 'A') - (newKey[i] - 'A') + 26) % 26); // A A
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