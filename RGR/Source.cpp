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
	cout << "������� ����� � �������� �� 1 �� " << p << endl;
	cin >> m;
	Ya = mod(g, Xa, p);
	Yb = mod(g, Xb, p);
	cout << "������� A" << " ��������� ���� - " << Xa << " �������� ���� - " << Ya << endl;
	cout << "������� B" << " ��������� ���� - " << Xb << " �������� ���� - " << Yb << endl;
	r = mod(g, k, p);
	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;
	g = p - 1 - Xb;
	t = mod(r, g, p);
	m1 = ((e % p) * t) % p;

	cout << "�������� �����: " << m << endl;
	cout << "������������� �����: " << r << ", " << e << endl;
	cout << "�������������� �����: " << m1 << endl;
}