#include <iostream>
using namespace std;
int mod(int g, int X, int p) {
	int t = 0, t0 = g % p;
	for (int i = 1; i <= X; i++) {
		t = g % p;
		g = t * t0;
	}
	return t;
}

void El_Gamal()
{
	int g = 5, p = 23, Xa = 4, Xb = 11, Ya = 0, Yb = 0, k = 7, r = 0, e = 0, m = 0, m1 = 0, t = 0;
	cout << "Ââåäèòå ÷èñëî â ïðåäåëàõ îò 1 äî " << p << endl;
	cin >> m;
	Ya = mod(g, Xa, p);
	Yb = mod(g, Xb, p);
	cout << "Àáîíåíò A" << " Ñåêðåòíûé êëþ÷ - " << Xa << " Îòêðûòûé êëþ÷ - " << Ya << endl;
	cout << "Àáîíåíò B" << " Ñåêðåòíûé êëþ÷ - " << Xb << " Îòêðûòûé êëþ÷ - " << Yb << endl;
	r = mod(g, k, p);
	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;
	g = p - 1 - Xb;
	t = mod(r, g, p);
	m1 = ((e % p) * t) % p;

	cout << "Èñõîäíûé òåêñò: " << m << endl;
	cout << "Çàøèôðîâàííûé òåêñò: " << r << ", " << e << endl;
	cout << "Ðàñøèôðîâàííûé òåêñò: " << m1 << endl;
}

void Tarab_G()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    
    char str[1000];
    cin.getline(str, 1000);
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
