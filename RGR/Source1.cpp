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

void Vizhiner(ofstream& fout, const string& password) {
	mt19937 gen(time(0));
	uniform_int_distribution<int> uid1(0, 11);
	vector<string> rantext = { "we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor." };//0-11
    string key, text, enText, deText, n, s;
	cout << "Generate text?" << endl;
	cout << "1 - No" << endl << "2 - Yes" << endl;
	cin >> n;
	if (n == "1") {
		try {
			cout << "Input text: ";
			cin.ignore();
			getline(cin, text);
			eng(text);
		}
		catch (const char* err) {
			cout << err << endl;
			text.clear();
			Vizhiner(fout, password);
		}
		try {
			cout << "Input key: ";
			cin >> key;
			eng(key);

			fout << "Vigenere Cipher" << endl;
			fout << endl;
			fout << "Origin text: " << text << endl;
			fout << endl;
			cout << "Password: ";
			cin >> s;
			if (s == password) {
				enText = encodeText(text, key);
				cout << "Encoded string: " << enText << endl;

				fout << "Encoded string: " << enText << endl;
				fout << endl;
			}
			else {
				cout << "Incorrect Password! " << endl;
				return;
			}

			cout << "Password: ";
			s.clear();
			cin >> s;

			if (s == password) {
				deText = decodeText(enText, key);
				cout << "Decoded string: " << deText << endl;

				fout << "Decoded string: " << deText << endl;
				fout << endl;
			}
			else {
				cout << "Incorrect Password! " << endl;
				return;
			}
		}
		catch (const char* err) {
			cout << err << endl;
			key.clear();
			Vizhiner(fout, password);
		}
	}
	else if (n == "2") {
		text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
		key = "KEY";
		cout << "Origin text: " << text << endl;
		cout << "Key: " << key << endl;

		fout << "Vigenere Cipher" << endl;
		fout << endl;
		fout << "Origin text: " << text << endl;
		fout << endl;
		cout << "Password: ";
		cin >> s;
		if (s == password) {
			enText = encodeText(text, key);
			cout << "Encoded string: " << enText << endl;

			fout << "Encoded string: " << enText << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}

		cout << "Password: ";
		s.clear();
		cin >> s;

		if (s == password) {
			deText = decodeText(enText, key);
			cout << "Decoded string: " << deText << endl;

			fout << "Decoded string: " << deText << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
	}
	else {
		cout << "Input 1 or 2" << endl;
		Vizhiner(fout, password);
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

void TablCryp(ofstream& fout, const string& password) {
	mt19937 gen(time(0));
	uniform_int_distribution<int> uid1(0, 11);
	vector<string> rantext = { "we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor." };
	string deText, enText, ishText, n, s;
	vector<int>	key;
	vector<int>	key1;
	int b, a, x;
	bool is_End = false;
	cout << "Generate text?" << endl;
	cout << "1 - No" << endl << "2 - Yes" << endl;
	cin >> n;
	if (n == "1") {
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

				fout << "Spreadsheet encryption using the double permutation method " << endl;
				fout << endl;
				fout << "Origin strings: " << ishText << endl;
				fout << endl;

				cout << "Password: ";
				cin >> s;
				if (s == password) {
					enText = encrypting(ishText, key, key1);
					cout << endl;
					cout << "Encrypting text: " << enText << endl;

					fout << "Encode strings: " << enText << endl;
					fout << endl;
				}
				else {
					cout << "Incorrect Password! " << endl;
					return;
				}
				cout << "Password: ";
				s.clear();
				cin >> s;

				if (s == password) {
					deText = decrypting(enText, key, key1);
					cout << endl;
					cout << "Decrypting text: " << deText << endl;

					fout << "Decoded string: " << deText << endl;
					fout << endl;
				}
				else {
					cout << "Incorrect Password! " << endl;
					return;
				}

			}
			catch (const char* err) {
				cout << err << endl;
				ishText.clear();
				key.clear();
				key1.clear();
				TablCryp(fout, password);
			}
		}
		catch (const char* err) {
			cout << err << endl;
			ishText.clear();
			TablCryp(fout, password);
		}
	}
	else if (n == "2") {
		ishText = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
		a = sqrt(ishText.length());
		if (ishText.length() % a == 0) b = ishText.length() / a;
		else b = ishText.length() / a + 1;
		cout << "Input first key(numbers 0 - " << a - 1 << "): " << endl;
		for (auto i = a-1; i >= 0; i--) {
			key.push_back(i);
		}

		cout << "Input second key(numbers 0 - " << b - 1 << "): " << endl;//для stolbik

		for (auto i = b-1; i >= 0; i--) {
			key1.push_back(i);
		}

		numb(key, a);
		numb(key1, b);

		fout << "Spreadsheet encryption using the double permutation method " << endl;
		fout << endl;
		fout << "Origin strings: " << ishText << endl;
		fout << endl;

		cout << "Password: ";
		cin >> s;
		if (s == password) {
			enText = encrypting(ishText, key, key1);
			cout << endl;
			cout << "Encrypting text: " << enText << endl;

			fout << "Encode strings: " << enText << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}

		cout << "Password: ";
		s.clear();
		cin >> s;

		if (s == password) {
			deText = decrypting(enText, key, key1);
			cout << endl;
			cout << "Decrypting text: " << deText << endl;

			fout << "Decoded string: " << deText << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
	}
	else {
       cout << "Input 1 or 2" << endl;
       TablCryp(fout, password);
	}
}