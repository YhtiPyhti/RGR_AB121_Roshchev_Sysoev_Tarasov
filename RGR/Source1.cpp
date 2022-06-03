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

void numb(vector<int> number, int y) {
	int S2 = 0, S1 = 0;
	for (int i = 0; i < y; i++) {
		 S1 += i;
		 S2 += number[i];
	}
	if(S1 != S2) throw " Incorrect input! Repeating numbers. (Be sure to use a space before entering)\n";
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

string encrypting(string ishText, vector<int> c, vector<int>& c1) {
	string text;
	int b, k = 0, a = sqrt(ishText.length());

	if (ishText.length() % a == 0) b = ishText.length() / a;
	else b = ishText.length() / a + 1;

	vector<vector<char>> matr(a, vector<char>(b));
	vector<vector<char>> matr1(a, vector<char>(b));


	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			if (k < ishText.length()) {
				matr[i][j] = ishText[k];
				if (ishText[k] == ' ')matr[i][j] = '_';
				k++;
			}
			else matr[i][j] = '*';
		}
	}
	matr1 = matr;
	for (auto i : matr) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			k = c1[j];
			matr1[i][k] = matr[i][j];

		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			if (matr1[0][i] == matr[0][j]) {
				c1.push_back(j);
				break;
			}
		}
	}
	map<int, vector<char>> t;
	for (size_t i = 0; i < a; i++) {
		k = c[i];
		t[k] = matr1[i];
	}


	cout << "First permutation" << endl;
	for (auto i : matr1) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Second permutation" << endl;
	for (auto i : t) {
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}

	for (int j = 0; j < b; j++) {
		for (int i = 0; i < a; i++) {
			text += t[i][j];
		}
	}
	return text;
}

string decrypting(string ishText, vector<int> c, vector<int>& c1) {
	string text;
	int b, k = 0, a = sqrt(ishText.length());

	if (ishText.length() % a == 0) b = ishText.length() / a;
	else b = ishText.length() / a + 1;

	vector<vector<char>> matr(a, vector<char>(b));
	vector<vector<char>> matr1(a, vector<char>(b));

	for (size_t j = 0; j < b; j++) {
		for (size_t i = 0; i < a; i++) {
			if (k < ishText.length()) {
				matr[i][j] = ishText[k];
				if (ishText[k] == ' ') matr[i][j] = '_';
				k++;
			}
			else matr[i][j] = '*';
		}
	}
	matr1 = matr;
	for (auto i : matr) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < a; i++) {
		for (int j = b - 1; j >= 0; j--) {
			k = c1[j + b];
			matr1[i][k] = matr[i][j];
		}
	}

	map<int, vector<char>> t;
	for (int i = a - 1; i >= 0; i--) {
		k = c[i];
		t[i] = matr1[k];
	}


	cout << "First permutation" << endl;
	for (auto i : matr1) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Second permutation" << endl;
	for (auto i : t) {
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (t[i][j] == '*') break;
			else if (t[i][j] == '_') text += ' ';
			else text += t[i][j];
		}
	}
	return text;
}

void TablCryp() {
	setlocale(LC_ALL, "Russian");
	string deText, enText, ishText;
	vector<int>	key;
	vector<int>	key1;
	int b, a, x;
	bool is_End = false;

	try {
		cout << "Input text: ";
		cin.ignore();
		getline(cin, ishText);

		eng(ishText);

		try {
			a = sqrt(ishText.length());
			if (ishText.length() % a == 0) b = ishText.length() / a;
			else b = ishText.length() / a + 1;
			cout << "Input first key(numbers 0 - " << a - 1 << "): " << endl;

			for (auto i = 0; i < a; i++) {
				cin >> x;
				key.push_back(x);
			}
	
			cout << "Input second key(numbers 0 - " << b - 1 << "): " << endl;//для stolbik

			for (auto i = 0; i < b; i++) {
				cin >> x;
				key1.push_back(x);
			}

			numb(key, a);
			numb(key1, b);


			enText = encrypting(ishText, key, key1);
			cout << endl;
			cout << "Encrypting text: " << enText << endl;

			deText = decrypting(enText, key, key1);
			cout << endl;
			cout << "Decrypting text: " << deText << endl;

		}
		catch (const char* err) {
			cout << err << endl;
			ishText.clear();
			key.clear();
			key1.clear();
			TablCryp();
		}
	}
	catch (const char* err) {
		cout << err << endl;
		ishText.clear();
		TablCryp();
	}
}