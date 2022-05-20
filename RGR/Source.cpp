#include "Header.h"
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

void El_Gamal() {
    string decodtext, encodtext;
    string text;
    int g = 5, p = 3571, t = 0, k = 7;//доп данные для шифровки 
    int Xb = 11;//ключи
    int r = 0, e = 0, m = 0, decode = 0; //текста
    vector<int> zahiv;
    cout << "Input strings: ";
    cin >> text;
    for (int i = 0; i < text.length(); i++) {
        m = text[i] - '0';
        zahiv = El_Gamal_encode(g, p, Xb, k, m);

        encodtext += (char)(zahiv[0] + '0');
        encodtext += (char)(zahiv[1] + '0');

        decodtext += (char)(El_Gamal_decode(g, p, Xb, zahiv) + '0');
    }
    cout << "Encode text: " << encodtext << endl;
    cout << "Decode text: " << decodtext;

}

void Tarab_G()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
   SetConsoleOutputCP(1251);
    
       char str[1000];
    cout << "Введите буквы :" << endl;
    cin >> str;
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
  cout <<"Зашифрованное слово: "<< str << endl;


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


   

