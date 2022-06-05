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

void El_Gamal(ofstream& fout, const string& password) {
    vector<string> rantext = {"we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor."};
    string decodtext, encodtext, text, n, s;
    int g = 5, p = 3571, t = 0, k = 7;//доп данные для шифровки 
    int Xb = 11;//ключи
    int r = 0, e = 0, m = 0, decode = 0; //текста
    vector<int> zahiv;
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << endl;
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
            El_Gamal(fout, password);
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
    else {
        cout << "Input 1 or 2" << endl;
        El_Gamal(fout, password);
    }
}

void Tarab_G(ofstream& fout, const string& password)
{
    string s;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    cout << "Введите буквы :" << endl;
    char str[1000];
    cin >> str;
    int v;

    fout << "Gibberish letter" << endl;
    fout << endl;
    fout << "Origin text: " << str << endl;
    fout << endl;

	for (int c=0;c<strlen(str); c++){
		char k='а';
		char y='А';
		v=0;
	   for (int i = 0; i < 33; i++) {
            if (str[i] == k){
                v++;
                break;
            }
            if (str[i] == 'ё') {
                v++;
                break;
            }
            if (str[i] == 'Ё') {
                v++;
                break;
            }
            if (str[i] == y) {
                v++;
                break;
            }
            if (str[i] == ' ') {
                v++;
                break;
            }
            k++;
            y++;
        }
        if (v == 0) {
            cout << "Введите русские буквы пожалуйста.\n";
            break;
        }
	}
    for (int i = 0; i < 1000; i++) 
    {
     if (str[i] == 'Б') 
     {
       str[i] = 'Щ';
    }
     else if (str[i] == 'Щ')
        str[i] = 'Б';

     if (str[i] == 'В')
        str[i] = 'Ш';
     else if (str[i] == 'Ш')
        str[i] = 'В';

     if (str[i] == 'Г')
        str[i] = 'Ч';
     else if (str[i] == 'Ч')
        str[i] = 'Г';

     if (str[i] == 'Д')
       str[i] = 'Ц';
     else if (str[i] == 'Ц')
	     str[i] = 'Д';

    if (str[i] == 'Ж')
        str[i] = 'Х';
     else if (str[i] == 'Х')
        str[i] = 'Ж';

     if (str[i] == 'З') 
       {       
	str[i] = 'Ф';
     }
     else 
     {
       if (str[i] == 'Ф')
            str[i] = 'З';
     }

     if (str[i] == 'К')
        str[i] = 'Т';
     else if (str[i] == 'Т')
        str[i] = 'К';

     if (str[i] == 'Л')
        str[i] = 'С';
     else if (str[i] == 'С')
        str[i] = 'Л';

     if (str[i] == 'М')
        str[i] = 'Р';
     else if (str[i] == 'Р')
        str[i] = 'М';

     if (str[i] == 'Н')
        str[i] = 'П';
     else if (str[i] == 'П')
        str[i] = 'Н';

     }
	 for (int i = 0; i < 1000; i++) 
    {
     if (str[i] == 'б') 
     {
       str[i] = 'щ';
    }
     else if (str[i] == 'щ')
        str[i] = 'б';

     if (str[i] == 'в')
        str[i] = 'ш';
     else if (str[i] == 'ш')
        str[i] = 'в';

     if (str[i] == 'г')
        str[i] = 'ч';
     else if (str[i] == 'ч')
        str[i] = 'г';

     if (str[i] == 'д')
       str[i] = 'ц';
     else if (str[i] == 'ц')
	     str[i] = 'д';

    if (str[i] == 'ж')
        str[i] = 'х';
     else if (str[i] == 'х')
        str[i] = 'ж';

     if (str[i] == 'з') 
       {       
	str[i] = 'ф';
     }
     else 
     {
       if (str[i] == 'ф')
            str[i] = 'з';
     }

     if (str[i] == 'к')
        str[i] = 'т';
     else if (str[i] == 'т')
        str[i] = 'к';

     if (str[i] == 'л')
        str[i] = 'с';
     else if (str[i] == 'с')
        str[i] = 'л';

     if (str[i] == 'м')
        str[i] = 'р';
     else if (str[i] == 'р')
        str[i] = 'м';

     if (str[i] == 'н')
        str[i] = 'п';
     else if (str[i] == 'п')
        str[i] = 'н';

     }
     cout << "Password: ";
     cin >> s;
     if (s == password) {
         cout << "Зашифрованное слово: " << str << endl;

         fout << "Encrypting text:" << str << endl;
         fout << endl;
     }
     else {
         cout << "Incorrect Password! " << endl;
         return;
     }


	for (int i = 0; i < 1000; i++) 
    {
     if (str[i] == 'Б') 
     {
       str[i] = 'Щ';
    }
     else if (str[i] == 'Щ')
        str[i] = 'Б';

     if (str[i] == 'В')
        str[i] = 'Ш';
     else if (str[i] == 'Ш')
        str[i] = 'В';

     if (str[i] == 'Г')
        str[i] = 'Ч';
     else if (str[i] == 'Ч')
        str[i] = 'Г';

     if (str[i] == 'Д')
       str[i] = 'Ц';
     else if (str[i] == 'Ц')
	     str[i] = 'Д';

    if (str[i] == 'Ж')
        str[i] = 'Х';
     else if (str[i] == 'Х')
        str[i] = 'Ж';

     if (str[i] == 'З') 
       {       
	str[i] = 'Ф';
     }
     else 
     {
       if (str[i] == 'Ф')
            str[i] = 'З';
     }

     if (str[i] == 'К')
        str[i] = 'Т';
     else if (str[i] == 'Т')
        str[i] = 'К';

     if (str[i] == 'Л')
        str[i] = 'С';
     else if (str[i] == 'С')
        str[i] = 'Л';

     if (str[i] == 'М')
        str[i] = 'Р';
     else if (str[i] == 'Р')
        str[i] = 'М';

     if (str[i] == 'Н')
        str[i] = 'П';
     else if (str[i] == 'П')
        str[i] = 'Н';

     }
    cout << "Password: ";
    s.clear();
    cin >> s;
    if (s == password) {
        cout << "Дешифрованное слово: " << str << endl;

        fout << "Decrypting text:" << str << endl;
        fout << endl;
    }
    else {
        cout << "Incorrect Password! " << endl;
        return;
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
void Grons(ofstream& fout, const string& password)
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
    cout << "1 - No" << endl << "2 - Yes" << endl;
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
            if (n == "2") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2") {
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
            if (n == "2") {
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
            if (n == "2") {
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
            if (n == "2") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2") {
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
            if (n == "2") {
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
            if (n == "2") {
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
            if (n == "2") {
                while (i.length() < text.length()) {
                    i = i + i;
                }
            }
            if (n == "2") {
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
        Grons(fout, password);
    }

}
void transp(ofstream& fout, const string& password) 
{
   SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<string> rantext = { "we", "do", "business", "around", "the", "world.", "Recognition", "is","most", "powerful", "motivation", "factor." };
    char n[1000];
    string s,y, text,q, wish;
    cout << "Generate text?" << endl;
    cout << "1 - No" << endl << "2 - Yes" << endl;
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
        transp(fout, password);
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

