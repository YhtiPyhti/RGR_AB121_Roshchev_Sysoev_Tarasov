#include "Header1.h"

int mod(int g, int X, int p) {
	int t = 0, t0 = g % p;
	for (int i = 1; i <= X; i++) {
		t = g % p;
		g = t * t0;
	}
	return t;
}

int El_Gamal_decode(int g, int p, int Xb, vector<int> entext) {
	int m1, t;
	g = p - 1 - Xb;
	t = mod(entext[0], g, p);
	m1 = ((entext[1] % p) * t) % p;
	return m1;
}

vector<int> El_Gamal_encode(int g, int p, int Xb, int k, int m) {
	int r, t, e, Yb;
	vector<int> entext;
	Yb = mod(g, Xb, p);//открытый ключ
	r = mod(g, k, p);//зашифров 1
	entext.push_back(r);

	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;//зашифров 2
	entext.push_back(e);
	return entext;
}

void El_Gamal(ofstream& fout, const string& password, string& text, string& wish) {
	string decodtext, encodtext, s;
	int g = 5, p = 3571, t = 0, k = 7;//доп данные для шифровки 
	int Xb = 0;//ключ (11)
	int r = 0, e = 0, m = 0, decode = 0; //текста
	vector<int> zahiv;

	cout << "Origin text: " << text << endl;
	cout << "Input key (1 - " << p-1 << "): ";
	cin >> Xb;
	if (Xb < 1 || Xb > p - 1) {
		cout << "Incorrect key! " << endl;
	}
	fout << "ElGamal Cipher" << endl;
	fout << endl;
	fout << "Origin text: " << text << endl;
	fout << endl;
	if (wish == "3") {
		for (int i = 0; i < text.length(); i++) {

			m = text[i] - '0';

			zahiv = El_Gamal_encode(g, p, Xb, k, m);

			encodtext += to_string(zahiv[0]);
			encodtext += to_string(zahiv[1]);

			decodtext += (char)(El_Gamal_decode(g, p, Xb, zahiv) + '0');
		}
		cout << "Password: ";
		cin >> s;
		if (s == password) {
			cout << "Encode text: " << encodtext << endl;

			fout << "Encode text: " << encodtext << endl;
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
			cout << "Decode text: " << decodtext << endl;

			fout << "Decode text: " << decodtext << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
	}
	else if (wish == "2") {
		for (int i = 0; i < text.length(); i++) {
			m = text[i] - '0';

			zahiv = El_Gamal_encode(g, p, Xb, k, m);

			encodtext += to_string(zahiv[0]);
			encodtext += to_string(zahiv[1]);

		}
		cout << "Password: ";
		cin >> s;
		if (s == password) {
			cout << "Encode text: " << encodtext << endl;

			fout << "Encode text: " << encodtext << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
	}
	if (wish == "1") {
		for (int i = 0; i < text.length()/2; i++) {

			zahiv.clear();
			string stroka = to_string(text[i] - '0') + to_string(text[i + 1] - '0');
			int e = stoi(stroka);
			stroka = to_string(text[i + 2] - '0') + to_string(text[i + 3] - '0');
			int r = stoi(stroka);

			zahiv.push_back(e);
			zahiv.push_back(r);

			decodtext += (char)(El_Gamal_decode(g, p, Xb, zahiv) + '0');
		}

		cout << "Password: ";
		cin >> s;

		if (s == password) {
			cout << "Decode text: " << decodtext << endl;

			fout << "Decode text: " << decodtext << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
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

void Vizhiner(ofstream& fout, const string& password, string& text, string& wish) {
    string key, enText, deText, s;
	int k;
	cout << "Origin text: " << text << endl;
	try {
		cout << "Input key: ";
		cin >> key;
		eng(key);
		if (wish == "3") {

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
		if (wish == "2") {

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
		}
		if (wish == "1") {

			fout << "Vigenere Cipher" << endl;
			fout << endl;
			fout << "Origin text: " << text << endl;
			fout << endl;
			cout << "Password: ";
			cin >> s;

			if (s == password) {
				deText = decodeText(text, key);
				cout << "Decoded string: " << deText << endl;

				fout << "Decoded string: " << deText << endl;
				fout << endl;
			}
			else {
				cout << "Incorrect Password! " << endl;
				return;
			}
		}
	}
	catch (const char* err) {
		cout << err;
		Vizhiner(fout, password, text, wish);
	}
}

string encodeText(string text, string key) {
    int i, j;

    char newKey[1000];
    char encryptedText[10000];

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

    char newKey[1000];
    char encryptedText[10000];

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

	for (int i = 0; i < a; i++) {
		for (int j = b - 1; j >= 0; j--) {
			if (c1.size() > b) {
				k = c1[j + b];
			}
			else k = c1[j];
			matr1[i][k] = matr[i][j];
		}
	}

	map<int, vector<char>> t;
	for (int i = a - 1; i >= 0; i--) {
		k = c[i];
		t[i] = matr1[k];
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

void TablCryp(ofstream& fout, const string& password, string& text, string& wish) {

	string deText, enText, s;
	vector<int>	key;
	vector<int>	key1;
	int b, a, x;

	a = sqrt(text.length());
	if (text.length() % a == 0) b = text.length() / a;
	else b = text.length() / a + 1;
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

	cout << "Origin text: " << text << endl;

	fout << "Spreadsheet encryption using the double permutation method " << endl;
	fout << endl;
	fout << "Origin strings: " << text << endl;
	fout << endl;

	if (wish == "3") {
		cout << "Password: ";
		cin >> s;
		if (s == password) {
			enText = encrypting(text, key, key1);
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
	else if (wish == "2") {

		numb(key, a);
		numb(key1, b);

		cout << "Password: ";
		cin >> s;
		if (s == password) {
			enText = encrypting(text, key, key1);
			cout << endl;
			cout << "Encrypting text: " << enText << endl;

			fout << "Encode strings: " << enText << endl;
			fout << endl;
		}
		else {
			cout << "Incorrect Password! " << endl;
			return;
		}
	}
	else if (wish == "1") {

		cout << "Password: ";
		cin >> s;

		if (s == password) {
			deText = decrypting(text, key, key1);
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
}