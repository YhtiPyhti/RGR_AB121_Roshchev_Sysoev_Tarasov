#include "Header.h"

void eng(string text);

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

void El_Gamal(ofstream& fout, const string& password, ifstream& in) {
    vector<string> rantext = {"we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor."};
    string decodtext, encodtext, text, n, s;
    int g = 5, p = 3571, t = 0, k = 7;//доп данные для шифровки 
    int Xb = 11;//ключи
    int r = 0, e = 0, m = 0, decode = 0; //текста
    vector<int> zahiv;
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << endl << "3 - Take from file" << endl;
    cin >> n;
    if (n == "1") {
        try {
            system("cls");
            cout << "Input text: ";
            cin.ignore();
            getline(cin, text);
            eng(text);

            fout << "ElGamal Cipher" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;

            for (int i = 0; i < text.length(); i++) {
                m = text[i] - '0';
                zahiv = El_Gamal_encode(g, p, Xb, k, m);

                encodtext += (char)(zahiv[0] + '0');
                encodtext += (char)(zahiv[1] + '0');

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
        catch (const char* err) {
            cout << err << endl;
            text.clear();
            El_Gamal(fout, password, in);
        }
    }
    else if (n == "2") {
        system("cls");
        mt19937 gen(time(0));
        uniform_int_distribution<int> uid1(0, 11);
        text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
        cout << "Origin text: " << text << endl;

        fout << "ElGamal Cipher" << endl;
        fout << endl;
        fout << "Origin text: " << text << endl;
        fout << endl;

        for (int i = 0; i < text.length(); i++) {
            m = text[i] - '0';
            zahiv = El_Gamal_encode(g, p, Xb, k, m);

            encodtext += (char)(zahiv[0] + '0');
            encodtext += (char)(zahiv[1] + '0');

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
    else if (n == "3") {
        system("cls");
        mt19937 gen(time(0));
        uniform_int_distribution<int> uid1(0, 11);
        getline(in, text);
        cout << "Origin text: " << text << endl;

        fout << "ElGamal Cipher" << endl;
        fout << endl;
        fout << "Origin text: " << text << endl;
        fout << endl;

        for (int i = 0; i < text.length(); i++) {
            m = text[i] - '0';
            zahiv = El_Gamal_encode(g, p, Xb, k, m);

            encodtext += (char)(zahiv[0] + '0');
            encodtext += (char)(zahiv[1] + '0');

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
    else {
        cout << "Input 1 or 2" << endl;
        El_Gamal(fout, password, in);
    }
}

void Tarab_G(ofstream& fout, const string& password, ifstream& in)
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string s, n, text, str;
    int v = 0, p, k, ss = 0;
    char alph[] = { '!','#','$','%','&','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','[',']','^','_','`','{','|','}','~','а','б','в','г','д','е','ж','з','ё','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Ь','Ъ','Щ','Ы','Э','Ю','Я' };
    vector<string> rantext = { "we", "do", "business", "around", "the", "world", "Recognition", "is","most", "powerful", "motivation", "factor" };
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << "3 - file" << endl;
    cin >> n;
    if (n == "1")
    {
        cout << "Vvedite soobshenie: " << endl;
        cin.ignore();
        getline(cin, str);
        k = str.length();
        cout << "Origin text: " << str << endl;
        fout << "Gibberish letter" << endl;
        fout << endl;
        fout << "Origin text: " << str << endl;
        fout << endl;
    }
    if (n == "2")
    {
        system("cls");
        mt19937 gen(time(0));
        uniform_int_distribution<int> uid1(0, 11);
        text = rantext[uid1(gen)] +  rantext[uid1(gen)] + rantext[uid1(gen)];
        k = text.length();
        cout << "Origin text: " << text << endl;
        fout << "Gibberish letter" << endl;
        fout << endl;
        fout << "Origin text: " << text << endl;
        fout << endl;
    }
    if (n == "3")
    {
        system("cls");
        mt19937 gen(time(0));
        uniform_int_distribution<int> uid1(0, 11);
        getline(in,text);
        k = text.length();
        cout << "Origin text: " << text << endl;
        fout << "Gibberish letter" << endl;
        fout << endl;
        fout << "Origin text: " << text << endl;
        fout << endl;
    }
    if (n == "1") { //проверка str
        for (int i = 0; i < k; i++)
        {
            for (int x = 0; x < strlen(alph); x++)
            {
                if (str[i] == alph[x])
                {
                    ss++;
                }
            }
        }
    }
    if (ss != 0) {
        cout << "Error.Write again.";
    }
    else {
        if (n == "2" || n == "3") {  //проверка text
            for (int i = 0; i < k; i++)
            {
                for (int x = 0; x < strlen(alph); x++)
                {
                    if (text[i] == alph[x])
                    {
                        ss++;
                    }
                }
            }
        }
        if (ss != 0) {
            cout << "Error.Write again.";
        }
        else
        {
            if (n == "1") {   //Encoded str
                for (int i = 0; i < k; i++)
                {
                    if (str[i] == 'B')
                        str[i] = 'C';
                    else if (str[i] == 'C')
                        str[i] = 'B';

                    if (str[i] == 'D')
                        str[i] = 'F';
                    else if (str[i] == 'F')
                        str[i] = 'D';

                    if (str[i] == 'G')
                    {
                        str[i] = 'H';
                    }
                    else
                    {
                        if (str[i] == 'H')
                            str[i] = 'G';
                    }

                    if (str[i] == 'J')
                        str[i] = 'L';
                    else if (str[i] == 'L')
                        str[i] = 'J';

                    if (str[i] == 'K')
                        str[i] = 'M';
                    else if (str[i] == 'M')
                        str[i] = 'K';

                    if (str[i] == 'N')
                        str[i] = 'P';
                    else if (str[i] == 'P')
                        str[i] = 'N';

                    if (str[i] == 'Q')
                        str[i] = 'R';
                    else if (str[i] == 'R')
                        str[i] = 'Q';

                    if (str[i] == 'S')
                    {
                        str[i] = 'T';
                    }
                    else if (str[i] == 'T')
                        str[i] = 'S';

                    if (str[i] == 'V')
                        str[i] = 'W';
                    else if (str[i] == 'W')
                        str[i] = 'V';

                    if (str[i] == 'X')
                        str[i] = 'Z';
                    else if (str[i] == 'Z')
                        str[i] = 'X';
                }
                for (int i = 0; i < k; i++)
                {

                    if (str[i] == 'b')
                        str[i] = 'c';
                    else if (str[i] == 'c')
                        str[i] = 'b';

                    if (str[i] == 'd')
                        str[i] = 'f';
                    else if (str[i] == 'f')
                        str[i] = 'd';

                    if (str[i] == 'g')
                    {
                        str[i] = 'h';
                    }
                    else
                    {
                        if (str[i] == 'h')
                            str[i] = 'g';
                    }

                    if (str[i] == 'j')
                        str[i] = 'l';
                    else if (str[i] == 'l')
                        str[i] = 'j';

                    if (str[i] == 'k')
                        str[i] = 'm';
                    else if (str[i] == 'm')
                        str[i] = 'k';

                    if (str[i] == 'n')
                        str[i] = 'p';
                    else if (str[i] == 'p')
                        str[i] = 'n';

                    if (str[i] == 'q')
                        str[i] = 'r';
                    else if (str[i] == 'r')
                        str[i] = 'q';

                    if (str[i] == 's')
                    {
                        str[i] = 't';
                    }
                    else if (str[i] == 't')
                        str[i] = 's';

                    if (str[i] == 'v')
                        str[i] = 'w';
                    else if (str[i] == 'w')
                        str[i] = 'v';

                    if (str[i] == 'x')
                        str[i] = 'z';
                    else if (str[i] == 'z')
                        str[i] = 'x';
                }

                     cout << "Password: ";
                     cin >> s;
                     if (s == password) 
                     {
                        cout << "Encoded: " << str << endl;

                        fout << "Encrypting text: " << str << endl;
                        fout << endl;
                     }
                     else 
                     {
                        cout << "Incorrect Password! " << endl;
                        return;
                     }
                
            }

            if (n == "2" || n == "3")
            {   //Encoded text
                for (int i = 0; i < k; i++)
                {
                    if (text[i] == 'B')
                        text[i] = 'C';
                    else if (text[i] == 'C')
                        text[i] = 'B';

                    if (text[i] == 'D')
                        text[i] = 'F';
                    else if (text[i] == 'F')
                        text[i] = 'D';

                    if (text[i] == 'G')
                    {
                        text[i] = 'H';
                    }
                    else
                    {
                        if (text[i] == 'H')
                            text[i] = 'G';
                    }

                    if (text[i] == 'J')
                        text[i] = 'L';
                    else if (text[i] == 'L')
                        text[i] = 'J';

                    if (text[i] == 'K')
                        text[i] = 'M';
                    else if (text[i] == 'M')
                        text[i] = 'K';

                    if (text[i] == 'N')
                        text[i] = 'P';
                    else if (text[i] == 'P')
                        text[i] = 'N';

                    if (text[i] == 'Q')
                        text[i] = 'R';
                    else if (text[i] == 'R')
                        text[i] = 'Q';

                    if (text[i] == 'S')
                    {
                        text[i] = 'T';
                    }
                    else if (text[i] == 'T')
                        text[i] = 'S';

                    if (text[i] == 'V')
                        text[i] = 'W';
                    else if (text[i] == 'W')
                        text[i] = 'V';

                    if (text[i] == 'X')
                        text[i] = 'Z';
                    else if (text[i] == 'Z')
                        text[i] = 'X';
                }
                for (int i = 0; i < k; i++)
                {

                    if (text[i] == 'b')
                        text[i] = 'c';
                    else if (text[i] == 'c')
                        text[i] = 'b';

                    if (text[i] == 'd')
                        text[i] = 'f';
                    else if (text[i] == 'f')
                        text[i] = 'd';

                    if (text[i] == 'g')
                    {
                        text[i] = 'h';
                    }
                    else
                    {
                        if (text[i] == 'h')
                            text[i] = 'g';
                    }

                    if (text[i] == 'j')
                        text[i] = 'l';
                    else if (text[i] == 'l')
                        text[i] = 'j';

                    if (text[i] == 'k')
                        text[i] = 'm';
                    else if (text[i] == 'm')
                        text[i] = 'k';

                    if (text[i] == 'n')
                        text[i] = 'p';
                    else if (text[i] == 'p')
                        text[i] = 'n';

                    if (text[i] == 'q')
                        text[i] = 'r';
                    else if (text[i] == 'r')
                        text[i] = 'q';

                    if (text[i] == 's')
                    {
                        text[i] = 't';
                    }
                    else if (text[i] == 't')
                        text[i] = 's';

                    if (text[i] == 'v')
                        text[i] = 'w';
                    else if (text[i] == 'w')
                        text[i] = 'v';

                    if (text[i] == 'x')
                        text[i] = 'z';
                    else if (text[i] == 'z')
                        text[i] = 'x';
                }

                    cout << "Password: ";
                    cin >> s;
                    if (s == password) {
                        cout << "Encoded: " << text << endl;

                        fout << "Encrypting text: " << text << endl;
                        fout << endl;
                    }
                    else {
                        cout << "Incorrect Password! " << endl;
                        return;
                    }
                
            }
            if (n == "1") {   //Decoded str
                for (int i = 0; i < k; i++)
                {
                    if (str[i] == 'B')
                        str[i] = 'C';
                    else if (str[i] == 'C')
                        str[i] = 'B';

                    if (str[i] == 'D')
                        str[i] = 'F';
                    else if (str[i] == 'F')
                        str[i] = 'D';

                    if (str[i] == 'G')
                    {
                        str[i] = 'H';
                    }
                    else
                    {
                        if (str[i] == 'H')
                            str[i] = 'G';
                    }

                    if (str[i] == 'J')
                        str[i] = 'L';
                    else if (str[i] == 'L')
                        str[i] = 'J';

                    if (str[i] == 'K')
                        str[i] = 'M';
                    else if (str[i] == 'M')
                        str[i] = 'K';

                    if (str[i] == 'N')
                        str[i] = 'P';
                    else if (str[i] == 'P')
                        str[i] = 'N';

                    if (str[i] == 'Q')
                        str[i] = 'R';
                    else if (str[i] == 'R')
                        str[i] = 'Q';

                    if (str[i] == 'S')
                    {
                        str[i] = 'T';
                    }
                    else if (str[i] == 'T')
                        str[i] = 'S';

                    if (str[i] == 'V')
                        str[i] = 'W';
                    else if (str[i] == 'W')
                        str[i] = 'V';

                    if (str[i] == 'X')
                        str[i] = 'Z';
                    else if (str[i] == 'Z')
                        str[i] = 'X';
                }
                for (int i = 0; i < k; i++)
                {

                    if (str[i] == 'b')
                        str[i] = 'c';
                    else if (str[i] == 'c')
                        str[i] = 'b';

                    if (str[i] == 'd')
                        str[i] = 'f';
                    else if (str[i] == 'f')
                        str[i] = 'd';

                    if (str[i] == 'g')
                    {
                        str[i] = 'h';
                    }
                    else
                    {
                        if (str[i] == 'h')
                            str[i] = 'g';
                    }

                    if (str[i] == 'j')
                        str[i] = 'l';
                    else if (str[i] == 'l')
                        str[i] = 'j';

                    if (str[i] == 'k')
                        str[i] = 'm';
                    else if (str[i] == 'm')
                        str[i] = 'k';

                    if (str[i] == 'n')
                        str[i] = 'p';
                    else if (str[i] == 'p')
                        str[i] = 'n';

                    if (str[i] == 'q')
                        str[i] = 'r';
                    else if (str[i] == 'r')
                        str[i] = 'q';

                    if (str[i] == 's')
                    {
                        str[i] = 't';
                    }
                    else if (str[i] == 't')
                        str[i] = 's';

                    if (str[i] == 'v')
                        str[i] = 'w';
                    else if (str[i] == 'w')
                        str[i] = 'v';

                    if (str[i] == 'x')
                        str[i] = 'z';
                    else if (str[i] == 'z')
                        str[i] = 'x';
                }
                    cout << "Password: ";
                    cin >> s;
                    if (s == password) {
                        cout << "Decoded: " << str << endl;

                        fout << "Decrypting text: " << str << endl;
                        fout << endl;
                    }
                    else {
                        cout << "Incorrect Password! " << endl;
                        return;
                    }
                
            }
            if (n == "2" || n == "3") {     //Decoded text
                for (int i = 0; i < k; i++)
                {
                    if (text[i] == 'B')
                        text[i] = 'C';
                    else if (text[i] == 'C')
                        text[i] = 'B';

                    if (text[i] == 'D')
                        text[i] = 'F';
                    else if (text[i] == 'F')
                        text[i] = 'D';

                    if (text[i] == 'G')
                    {
                        text[i] = 'H';
                    }
                    else
                    {
                        if (text[i] == 'H')
                            text[i] = 'G';
                    }

                    if (text[i] == 'J')
                        text[i] = 'L';
                    else if (text[i] == 'L')
                        text[i] = 'J';

                    if (text[i] == 'K')
                        text[i] = 'M';
                    else if (text[i] == 'M')
                        text[i] = 'K';

                    if (text[i] == 'N')
                        text[i] = 'P';
                    else if (text[i] == 'P')
                        text[i] = 'N';

                    if (text[i] == 'Q')
                        text[i] = 'R';
                    else if (text[i] == 'R')
                        text[i] = 'Q';

                    if (text[i] == 'S')
                    {
                        text[i] = 'T';
                    }
                    else if (text[i] == 'T')
                        text[i] = 'S';

                    if (text[i] == 'V')
                        text[i] = 'W';
                    else if (text[i] == 'W')
                        text[i] = 'V';

                    if (text[i] == 'X')
                        text[i] = 'Z';
                    else if (text[i] == 'Z')
                        text[i] = 'X';
                }
                for (int i = 0; i < k; i++)
                {

                    if (text[i] == 'b')
                        text[i] = 'c';
                    else if (text[i] == 'c')
                        text[i] = 'b';

                    if (text[i] == 'd')
                        text[i] = 'f';
                    else if (text[i] == 'f')
                        text[i] = 'd';

                    if (text[i] == 'g')
                    {
                        text[i] = 'h';
                    }
                    else
                    {
                        if (text[i] == 'h')
                            text[i] = 'g';
                    }

                    if (text[i] == 'j')
                        text[i] = 'l';
                    else if (text[i] == 'l')
                        text[i] = 'j';

                    if (text[i] == 'k')
                        text[i] = 'm';
                    else if (text[i] == 'm')
                        text[i] = 'k';

                    if (text[i] == 'n')
                        text[i] = 'p';
                    else if (text[i] == 'p')
                        text[i] = 'n';

                    if (text[i] == 'q')
                        text[i] = 'r';
                    else if (text[i] == 'r')
                        text[i] = 'q';

                    if (text[i] == 's')
                    {
                        text[i] = 't';
                    }
                    else if (text[i] == 't')
                        text[i] = 's';

                    if (text[i] == 'v')
                        text[i] = 'w';
                    else if (text[i] == 'w')
                        text[i] = 'v';

                    if (text[i] == 'x')
                        text[i] = 'z';
                    else if (text[i] == 'z')
                        text[i] = 'x';
                }

                    cout << "Password: ";
                    cin >> s;
                    if (s == password) {
                        cout << "Decoded: " << text << endl;

                        fout << "Decrypting text: " << text << endl;
                        fout << endl;
                    }
                    else {
                        cout << "Incorrect Password! " << endl;
                        return;
                    }
                
                
            }
        }
    }

}

    char* code_atbash(char* src) {
        char* dst = src;
        const char* cch, * dch;

        while (*src) {
            if (isalpha(*src)) {
                for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                    if (*cch == toupper(*src)) {
                        *src = (isupper(*src)) ? *dch : tolower(*dch);
                        break;
                    }
                }
            }
            *src++;
        }
        return dst;
    }

    // функция декодирования
    char* decode_atbash(char* src) {
        char* dst = src;
        const char* cch, * dch;

        while (*src) {
            if (isalpha(*src)) {
                for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                    if (*dch == toupper(*src)) {
                        *src = (isupper(*src)) ? *cch : tolower(*cch);
                        break;
                    }
                }
            }
            *src++;
        }
        return dst;
    }
void Grons(ofstream& fout, const string& password, ifstream& in)
{
    vector<string> rantext = { "we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor." };
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int res = 0;
    string i, s, n, text, msg, wish;
    char alph[] = { ' ','!','#','$','%','&','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{',' ','|','}','~','а','б','в','г','д','е','ж','з','ё','и','й','к','л',
        'м','н','о','п', 'р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Ь','Ъ','Щ','Ы','Э','Ю','Я' };
    int u = strlen(alph);
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << endl << "3 - File" << endl;
    cin >> n;
    cout << "What would you like:" << endl << "1) decryption only" << endl << "2) only encrypt" << endl << "3) this and that" << endl;
    cin >> wish;

    if (wish == "3") {
        if (n == "1") {
            cout << "Vvedite soobshenie: \n";
            cin.ignore();
            getline(cin, msg);
            cout << "\n";
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << msg << endl;
            fout << endl;
        }
        else if (n == "2") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        else if (n == "3") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            getline(in,text);
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        cout << "Key: \n";
        cin.ignore();
        getline(cin, i);
        int q = 0;
        for (int j = 0; j != i.length(); j++) {
            q = 0;
            if (i[j] == '0') {
                q++;
            }
            if (i[j] == '1') {
                q++;
            }
            if (i[j] == '2') {
                q++;
            }
            if (i[j] == '3') {
                q++;
            }
            if (i[j] == '4') {
                q++;
            }
            if (i[j] == '5') {
                q++;
            }
            if (i[j] == '6') {
                q++;
            }
            if (i[j] == '7') {
                q++;
            }
            if (i[j] == '8') {
                q++;
            }
            if (i[j] == '9') {
                q++;
            }
        }
        if (q == 0)
            cout << "Error. Try again.";
        else {
            if (n == "1") {
                while (i.length() < msg.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                for (int j = 0; j != text.length(); j++) {//шифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (text[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v + res >= u) {

                                text[j] = alph[v + res - u];
                            }
                            else
                                text[j] = alph[v + res];
                            break;
                        }
                    }
                }
            }
            if (n == "2" || n == "3") {
                cout << "Password: ";
                s.clear();
                cin >> s;
                if (s == password) {
                    cout << "Encoded: " << text << endl;

                    fout << "Encoded string: " << text << endl;
                    fout << endl;
                }
                else {
                    cout << "Incorrect Password! " << endl;
                    return;
                }
            }
            if (n == "1") {
                for (int j = 0; j != msg.length(); j++) {//шифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (msg[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v + res >= u) {

                                msg[j] = alph[v + res - u];
                            }
                            else
                                msg[j] = alph[v + res];
                            break;
                        }
                    }
                }

            }
            if (n == "1") {
                cout << "Password: ";
                s.clear();
                cin >> s;
                if (s == password) {
                    cout << "Encoded: " << msg << endl;

                    fout << "Encoded string: " << msg << endl;
                    fout << endl;
                }
                else {
                    cout << "Incorrect Password! " << endl;
                    return;
                }
            }
            if (n == "2" || n == "3") {
                for (int j = 0; j != text.length(); j++) { //дешифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (text[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v - res < 0) {

                                text[j] = alph[v - res + u];


                            }
                            else
                                text[j] = alph[v - res];
                            break;
                        }
                    }
                }
            }
            if (n == "1") {
                for (int j = 0; j != msg.length(); j++) { //дешифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (msg[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v - res < 0) {

                                msg[j] = alph[v - res + u];


                            }
                            else
                                msg[j] = alph[v - res];
                            break;
                        }
                    }
                }
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password) {
                if (n == "1") {
                    cout << "Decoded: " << msg;
                    fout << "Decoded string: " << msg << endl;
                    fout << endl;
                }
                if (n == "2" || n == "3") {
                    cout << "Decoded: " << text;
                    fout << "Decoded string: " << text << endl;
                    fout << endl;
                }
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
    }
    else if (wish == "2") {
        if (n == "1") {
            cout << "Vvedite soobshenie: \n";
            cin.ignore();
            getline(cin, msg);
            cout << "\n";
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << msg << endl;
            fout << endl;
        }
        else if (n == "2") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        else if (n == "3") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            getline(in, text);
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        cout << "Key: \n";
        cin.ignore();
        getline(cin, i);
        int q = 0;
        for (int j = 0; j != i.length(); j++) {
            q = 0;
            if (i[j] == '0') {
                q++;
            }
            if (i[j] == '1') {
                q++;
            }
            if (i[j] == '2') {
                q++;
            }
            if (i[j] == '3') {
                q++;
            }
            if (i[j] == '4') {
                q++;
            }
            if (i[j] == '5') {
                q++;
            }
            if (i[j] == '6') {
                q++;
            }
            if (i[j] == '7') {
                q++;
            }
            if (i[j] == '8') {
                q++;
            }
            if (i[j] == '9') {
                q++;
            }
        }
        if (q == 0)
            cout << "Error. Try again.";
        else {
            if (n == "1") {
                while (i.length() < msg.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                for (int j = 0; j != text.length(); j++) {//шифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (text[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v + res >= u) {

                                text[j] = alph[v + res - u];
                            }
                            else
                                text[j] = alph[v + res];
                            break;
                        }
                    }
                }
            }
            if(n == "2" || n == "3") {
                cout << "Password: ";
                s.clear();
                cin >> s;
                if (s == password) {
                    cout << "Encoded: " << text << endl;

                    fout << "Encoded string: " << text << endl;
                    fout << endl;
                }
                else {
                    cout << "Incorrect Password! " << endl;
                    return;
                }
            }
            if (n == "1") {
                for (int j = 0; j != msg.length(); j++) {//шифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (msg[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v + res >= u) {

                                msg[j] = alph[v + res - u];
                            }
                            else
                                msg[j] = alph[v + res];
                            break;
                        }
                    }
                }

            }
            if (n == "1") {
                cout << "Password: ";
                s.clear();
                cin >> s;
                if (s == password) {
                    cout << "Encoded: " << msg << endl;

                    fout << "Encoded string: " << msg << endl;
                    fout << endl;
                }
                else {
                    cout << "Incorrect Password! " << endl;
                    return;
                }
            }
            if (n == "2" || n == "3") {
                for (int j = 0; j != text.length(); j++) { //дешифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (text[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v - res < 0) {

                                text[j] = alph[v - res + u];


                            }
                            else
                                text[j] = alph[v - res];
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (wish == "1") {
        if (n == "1") {
            cout << "Vvedite soobshenie: \n";
            cin.ignore();
            getline(cin, msg);
            cout << "\n";
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << msg << endl;
            fout << endl;
        }
        else if (n == "2") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        else if (n == "3") {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            getline(in, text);
            cout << "Origin text: " << text << endl;
            fout << "Gronsfeld" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        cout << "Key: \n";
        cin.ignore();
        getline(cin, i);
        int q = 0;
        for (int j = 0; j != i.length(); j++) {
            q = 0;
            if (i[j] == '0') {
                q++;
            }
            if (i[j] == '1') {
                q++;
            }
            if (i[j] == '2') {
                q++;
            }
            if (i[j] == '3') {
                q++;
            }
            if (i[j] == '4') {
                q++;
            }
            if (i[j] == '5') {
                q++;
            }
            if (i[j] == '6') {
                q++;
            }
            if (i[j] == '7') {
                q++;
            }
            if (i[j] == '8') {
                q++;
            }
            if (i[j] == '9') {
                q++;
            }
        }
        if (q == 0)
            cout << "Error. Try again.";
        else {
            if (n == "1") {
                while (i.length() < msg.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2" || n == "3") {
                for (int j = 0; j != text.length(); j++) { //дешифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (text[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v - res < 0) {

                                text[j] = alph[v - res + u];


                            }
                            else
                                text[j] = alph[v - res];
                            break;
                        }
                    }
                }
            }
            if (n == "1") {
                for (int j = 0; j != msg.length(); j++) { //дешифр
                    for (int v = 0; v != strlen(alph); v++) {
                        if (msg[j] == alph[v]) {
                            if (i[j] == '0') {
                                res = 0;
                            }
                            if (i[j] == '1') {
                                res = 1;
                            }
                            if (i[j] == '2') {
                                res = 2;
                            }
                            if (i[j] == '3') {
                                res = 3;
                            }
                            if (i[j] == '4') {
                                res = 4;
                            }
                            if (i[j] == '5') {
                                res = 5;
                            }
                            if (i[j] == '6') {
                                res = 6;
                            }
                            if (i[j] == '7') {
                                res = 7;
                            }
                            if (i[j] == '8') {
                                res = 8;
                            }
                            if (i[j] == '9') {
                                res = 9;
                            }
                            if (v - res < 0) {

                                msg[j] = alph[v - res + u];


                            }
                            else
                                msg[j] = alph[v - res];
                            break;
                        }
                    }
                }
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password) {
                if (n == "1") {
                    cout << "Decoded: " << msg;
                    fout << "Decoded string: " << msg << endl;
                    fout << endl;
                }
                if (n == "2") {
                    cout << "Decoded: " << text;
                    fout << "Decoded string: " << text << endl;
                    fout << endl;
                }
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
    }
    else {
        system("cls");
        cout << "Incorrect input!" << endl;
        wish.clear();
        Grons(fout, password,in);
    }

}
void transp(ofstream& fout, const string& password, ifstream& in)
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<string> rantext = { "we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor." };
    char n[1000];
    string s,y, text,q, wish;
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << endl << "3 - file" << endl;
    cin >> y;

    cout << "What would you like:" << endl << "1) decryption only" << endl << "2) only encrypt" << endl << "3) this and that" << endl;
    cin >> wish;

    if (wish == "3") {
        if (y == "1")
        {
            cout << "Vvedite soobshenie: ";
            q = n;
            cin.ignore();
            getline(cin, q);
            cout << "Origin text: " << q << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << q << endl;
            fout << endl;
        }
        if (y == "2")
        {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        if (y == "3")
        {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            getline(in,text);
            cout << "Origin text: " << text << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        if (y == "1")
        {
            if (q.length() % 2 != 0) {
                q = q + ' ';
            }
        }
        if (y == "2" || y == "3")
        {
            if (text.length() % 2 != 0) {
                text = text + ' ';
            }
        }
        if (y == "1")
        {
            for (int i = 0; i < q.length() / 2; i += 2)
            {
                swap(q[i], q[q.length() - (i + 1) - 1]);
                swap(q[i + 1], q[q.length() - i - 1]);
            }
            cout << "Password: ";
            cin >> s;
            if (s == password) {
                cout << "Encoded: ";
                cout << q << endl;
                fout << "Encoded string: " << q << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
        if (y == "2" || y == "3")
        {
            for (int i = 0; i < text.length() / 2; i += 2) {
                swap(text[i], text[text.length() - (i + 1) - 1]);
                swap(text[i + 1], text[text.length() - i - 1]);
            }
            cout << "Password: ";
            cin >> s;
            if (s == password) {
                cout << "Encoded :";
                cout << text << endl;
                fout << "Encoded string: " << text << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
        if (y == "1")
        {
            for (int i = 0; i < (q.length() / 2); i += 2)
            {
                swap(q[i], q[q.length() - (i + 1) - 1]);
                swap(q[i + 1], q[q.length() - i - 1]);
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password)
            {
                cout << "Decoded: ";
                cout << q << endl;
                fout << "Decoded string: " << q << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
        if (y == "2" || y == "3")
        {
            for (int i = 0; i < (text.length() / 2); i += 2) {
                swap(text[i], text[text.length() - (i + 1) - 1]);
                swap(text[i + 1], text[text.length() - i - 1]);
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password) {
                cout << "Decoded: ";
                cout << text << endl;
                fout << "Decoded string: " << text << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
    }
    else if (wish == "2") {
        if (y == "1")
        {
            cout << "Vvedite soobshenie: ";
            q = n;
            cin.ignore();
            getline(cin, q);
            cout << "Origin text: " << q << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << q << endl;
            fout << endl;
        }
        if (y == "2")
        {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        if (y == "3")
        {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            getline(in, text);
            cout << "Origin text: " << text << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        if (y == "1")
        {
            if (q.length() % 2 != 0) {
                q = q + ' ';
            }
        }
        if (y == "2" || y == "3")
        {
            if (text.length() % 2 != 0) {
                text = text + ' ';
            }
        }
        if (y == "1")
        {
            for (int i = 0; i < q.length() / 2; i += 2)
            {
                swap(q[i], q[q.length() - (i + 1) - 1]);
                swap(q[i + 1], q[q.length() - i - 1]);
            }
            cout << "Password: ";
            cin >> s;
            if (s == password) {
                cout << "Encoded: ";
                cout << q << endl;
                fout << "Encoded string: " << q << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
        if (y == "2")
        {
            for (int i = 0; i < text.length() / 2; i += 2) {
                swap(text[i], text[text.length() - (i + 1) - 1]);
                swap(text[i + 1], text[text.length() - i - 1]);
            }
            cout << "Password: ";
            cin >> s;
            if (s == password) {
                cout << "Encoded :";
                cout << text << endl;
                fout << "Encoded string: " << text << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
    }
    else if (wish == "1") {
        if (y == "1")
        {
            cout << "Vvedite soobshenie: ";
            q = n;
            cin.ignore();
            getline(cin, q);
            cout << "Origin text: " << q << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << q << endl;
            fout << endl;
        }
        if (y == "2")
        {
            system("cls");
            mt19937 gen(time(0));
            uniform_int_distribution<int> uid1(0, 11);
            text = rantext[uid1(gen)] + ' ' + rantext[uid1(gen)] + ' ' + rantext[uid1(gen)];
            cout << "Origin text: " << text << endl;
            fout << "Transponirovania" << endl;
            fout << endl;
            fout << "Origin text: " << text << endl;
            fout << endl;
        }
        if (y == "1")
        {
            if (q.length() % 2 != 0) {
                q = q + ' ';
            }
        }
        if (y == "2")
        {
            if (text.length() % 2 != 0) {
                text = text + ' ';
            }
        }
        if (y == "1")
        {
            for (int i = 0; i < (q.length() / 2); i += 2)
            {
                swap(q[i], q[q.length() - (i + 1) - 1]);
                swap(q[i + 1], q[q.length() - i - 1]);
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password)
            {
                cout << "Decoded: ";
                cout << q << endl;
                fout << "Decoded string: " << q << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
        if (y == "2")
        {
            for (int i = 0; i < (text.length() / 2); i += 2) {
                swap(text[i], text[text.length() - (i + 1) - 1]);
                swap(text[i + 1], text[text.length() - i - 1]);
            }
            cout << "Password: ";
            s.clear();
            cin >> s;
            if (s == password) {
                cout << "Decoded: ";
                cout << text << endl;
                fout << "Decoded string: " << text << endl;
                fout << endl;
            }
            else {
                cout << "Incorrect Password! " << endl;
                return;
            }
        }
    }
    else{
        system("cls");
        cout << "Incorrect input!" << endl;
        wish.clear();
        transp(fout, password, in);
    }

}
int rsa(ofstream& fout, const string& password)
{
    long int p, q, n, t, e, d;

    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));

    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));

    bool flag;

    std::string msg;

    std::cout << "Welcome to RCA program" << std::endl << std::endl;

    // Cоздание открытого и секретного ключей

    // 1. Выбираются два различных случайных простых числа p и q заданного размера

    do
    {
        std::cout << "Enter a Prime number  p :" << std::endl;
        std::cin >> p;
        flag = isPrime(p);

        if (flag == false)
        {
            std::cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while (flag == false);


    do
    {
        std::cout << "Enter a Prime number  q :" << std::endl;
        std::cin >> q;
        flag = isPrime(q);

        if (flag == false)
        {
            std::cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while (flag == false);

    // 2. Вычисляется их произведение n = p ⋅ q, которое называется модулем.
    n = p * q;
    std::cout << "\nResult of computing n = p*q = " << n << std::endl;

    // 3. Вычисляется значение функции Эйлера от числа n: φ(n) = (p−1)⋅(q−1)
    t = (p - 1) * (q - 1);
    std::cout << "Result of computing Euler's totient function:\t t = " << t << std::endl;

    // 4. Выбирается целое число e ( 1 < e < φ(n) ), взаимно простое со значением функции Эйлера (t)
    //	  Число e называется открытой экспонентой
    e = calculateE(t);

    // 5. Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))
    d = calculateD(e, t);

    // 6. Пара {e, n} публикуется в качестве открытого ключа RSA
    std::cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;

    // 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
    std::cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;



    std::cout << "\nEnter Message to be encryped:" << std::endl;

    // there is a newline character left in the input stream, so we use ignore()
    std::cin.ignore();

    std::getline(std::cin, msg);

    std::cout << "\nThe message is: " << msg << std::endl;
    fout << "RSA" << endl;
    fout << endl;
    fout << "Origin text: " << msg << endl;

    // encryption

    for (long int i = 0; i < msg.length(); i++)
    {
        encryptedText[i] = encrypt(msg[i], e, n);
    }

    std::cout << "\nTHE ENCRYPTED MESSAGE IS:" << std::endl;

    fout << "Encrypted text: ";

    for (long int i = 0; i < msg.length(); i++)
    {
        printf("%c", (char)encryptedText[i]);
        fout << (char)encryptedText[i];
    }
    fout << endl;

    //decryption

    for (long int i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }

    std::cout << "\n\nTHE DECRYPTED MESSAGE IS:" << std::endl;
    fout << "Decrypted text: ";
    for (long int i = 0; i < msg.length(); i++)
    {
        printf("%c", (char)decryptedText[i]);
        fout << (char)decryptedText[i];
    }
    fout << endl;

    std::cout << std::endl << std::endl;

    return 0;
}

bool isPrime(long int prime)
{
    long int i, j;

    j = (long int)sqrt((long double)prime);

    for (i = 2; i <= j; i++)
    {
        if (prime % i == 0)
        {
            return false;
        }
    }

    return true;
}

long int calculateE(long int t)
{
    // Выбирается целое число e ( 1 < e < t ) // взаимно простое со значением функции Эйлера (t)

    long int e;

    for (e = 2; e < t; e++)
    {
        if (greatestCommonDivisor(e, t) == 1)
        {
            return e;
        }
    }

    return -1;
}

long int greatestCommonDivisor(long int e, long int t)
{
    while (e > 0)
    {
        long int myTemp;

        myTemp = e;
        e = t % e;
        t = myTemp;
    }

    return t;
}

long int calculateD(long int e, long int t)
{
    // Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))

    long int d;
    long int k = 1;

    while (1)
    {
        k = k + t;

        if (k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }

}


long int encrypt(long int i, long int e, long int n)
{
    long int current, result;

    current = i - 97;
    result = 1;

    for (long int j = 0; j < e; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;

    current = i;
    result = 1;

    for (long int j = 0; j < d; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result + 97;
}
unsigned char     get_rand_symb()
{
    int k = rand() % (27 - 1 + 1) + 1;
    return  abs(k);
}
void    make_rand_key
(
    T_key& key,
    T_key& reverse_key
)
{
    const   char    FIRST_ALPHABET_LETTER = 'a';
    const   char    LAST_ALPHABET_LETTER = 'z';

    const   int  ALPHABET_SIZE = LAST_ALPHABET_LETTER
        - FIRST_ALPHABET_LETTER
        + 1;

    T_char_set      symbols_set;

    while (
        symbols_set.size()
        < ALPHABET_SIZE
        )
    {
        char    rand_alnum_symb{};

        do
        {
            rand_alnum_symb = get_rand_symb();
        } while (
            isalpha(rand_alnum_symb)
            );

        symbols_set.insert(rand_alnum_symb);
    }//while

    T_symbols   symbols(
        symbols_set.begin(),
        symbols_set.end()
    );

    random_shuffle
    (
        symbols.begin(),
        symbols.end()
    );

    for (
        char
        symb{ FIRST_ALPHABET_LETTER };
        symb <= LAST_ALPHABET_LETTER;
        ++symb
        )
    {
        key[symb] = symbols[symb - FIRST_ALPHABET_LETTER];

        reverse_key
            [
                key[symb]
            ]
        = symb;
    }
}

void    input_text(T_text& text)
{
    cout << "\n\nEnter text in lower-case Latin letters:\n-> ";
    cin >> text;
}
///////////////////////////////////////////////////////////////////////////////
void    encrypt_text
(
    T_text  const& text,
    T_key   const& key,
    T_text& encrypted_text
)
{
    for (auto symb : text)
    {
        auto    it = key.find(symb);

        if (
            it == key.end()
            )
        {
            throw   domain_error("Invalid symbol in text.");
        }

        encrypted_text.push_back(it->second);
    }//for
}
///////////////////////////////////////////////////////////////////////////////
void    print_text_with_comment
(
    T_text  const& text,
    T_text  const& comment
)
{
    cout << endl
        << comment
        << endl
        << text
        << endl;
}
///////////////////////////////////////////////////////////////////////////////
void    tablichnaya_perestanovka()
{
    ios::sync_with_stdio(false);
    srand(unsigned(time(0)));

    T_key   key;
    T_key   reverse_key;

    make_rand_key
    (
        key,
        reverse_key
    );



    T_text   text;
    input_text(text);
    T_text   encrypted_text;

    try
    {
        encrypt_text
        (
            text,
            key,
            encrypted_text
        );
    }
    catch (
        exception& e
        )
    {
        cout << e.what()
            << std::endl;


    }//catch

    print_text_with_comment
    (
        encrypted_text,
        "Encrypted text:"
    );

    T_text   decrypted_text;

    encrypt_text
    (
        encrypted_text,
        reverse_key,
        decrypted_text
    );

    print_text_with_comment
    (
        decrypted_text,
        "Decrypted text:"
    );


}

