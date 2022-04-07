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
	cout << "Введите число в пределах от 1 до " << p << endl;
	cin >> m;
	Ya = mod(g, Xa, p);
	Yb = mod(g, Xb, p);
	cout << "Абонент A" << " Секретный ключ - " << Xa << " Открытый ключ - " << Ya << endl;
	cout << "Абонент B" << " Секретный ключ - " << Xb << " Открытый ключ - " << Yb << endl;
	r = mod(g, k, p);
	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;
	g = p - 1 - Xb;
	t = mod(r, g, p);
	m1 = ((e % p) * t) % p;

	cout << "Исходный текст: " << m << endl;
	cout << "Зашифрованный текст: " << r << ", " << e << endl;
	cout << "Расшифрованный текст: " << m1 << endl;
}