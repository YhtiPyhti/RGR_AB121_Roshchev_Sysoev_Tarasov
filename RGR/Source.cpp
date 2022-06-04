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

void El_Gamal(ofstream& fout) {
    //переименовываем операции

    string decodtext, encodtext;
    string text;
    int g = 5, p = 3571, t = 0, k = 7;//доп данные для шифровки 
    int Xb = 11;//ключи
    int r = 0, e = 0, m = 0, decode = 0; //текста
    vector<int> zahiv;

    try {
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
        cout << "Encode text: " << encodtext << endl;

        fout << "Encode text: " << encodtext << endl;
        fout << endl;


        cout << "Decode text: " << decodtext << endl;

        fout << "Decode text: " << decodtext << endl;
        fout << endl;

    }catch (const char* err) {
        cout << err << endl;
        text.clear();
        El_Gamal(fout);
    }
}

void Tarab_G(ofstream& fout)
{
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
    cout <<"Зашифрованное слово: "<< str << endl;

    fout << "Encrypting text:" << str << endl;
    fout << endl;


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
  cout <<"Дешифрованное слово: "<< str << endl;

  fout << "Decrypting text:" << str << endl;
  fout << endl;


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
void Grons(ofstream& fout)
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int res = 0;
    string i;
    char alph[] = { '!','#','$','%','&','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{',' ','|','}','~','а','б','в','г','д','е','ж','з', 'е','ё','ж','з', 'и','й','к','л',
        'м','н','о','п', 'р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Ь','Ъ','Щ','Ы','Э','Ю','Я' };

    cout << "Введите сообщение: \n";
    string msg;
    cin >> msg;
    cout << "\n";
    cout << "Введите ключ: \n";
    cin >> i;
    int u = strlen(alph);

    fout << "Gronsfeld" << endl;
    fout << endl;
    fout << "Origin text: " << msg << endl;
    fout << endl;

    while (i.length() < msg.length()) {
        i = i + i;
    }
    for (int j = 0; j != msg.length();j++) {//шифр
        for (int v = 0; v != strlen(alph);v++) {
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
    cout << "Зашифрованное соббщение: " << msg << endl;

    fout << "Encoded string: " << msg << endl;
    fout << endl;

    for (int j = 0; j != msg.length();j++) { //дешифр
        for (int v = 0; v != strlen(alph);v++) {
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
    cout << "Расшифрованное сообщение: " << msg;

    fout << "Decoded string: " << msg << endl;
    fout << endl;

}
void transp(ofstream& fout) {
    char n[1000];
    cin.getline(n,1000);
    string q = n;
    if (q.length() % 2 != 0)
        q =q+ ' ';


    for (int i = 0; i < q.length() / 2; i += 2) {
        swap(q[i], q[q.length() -(i+1)-1]);
        swap(q[i+1], q[q.length() -i-1]);
    }


    cout << q << endl;

    for (int i = 0; i < (q.length() / 2); i += 2) {
        swap(q[i], q[q.length() - (i + 1) - 1]);
        swap(q[i + 1], q[q.length() - i - 1]);
    }
    cout << q << endl;

}
