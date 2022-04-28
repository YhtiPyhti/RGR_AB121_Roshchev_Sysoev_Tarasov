#include <iostream>
#include <clocale>
#include "Header.h"

using namespace std;

void main(){
	setlocale(LC_ALL, "Russian");

	string s;

	cout << "Пароль: ";

	cin >> s;

	if (s == "123") {

		int k;
		cout << "Выберите шифр: " << endl;

		cout << "Нажмите <1> если выбрали  Эль Гамаля " << endl;
		cout << "Нажмите <2> если выбрали  Тарабарская грамота " << endl;
		cout << "Нажмите <3> если выбрали  Атбаш " << endl;
		cout << "Нажмите <4> если выбрали  ??? " << endl;
		cout << "Нажмите <5> если выбрали  ??? " << endl;
		cout << "Нажмите <6> если выбрали  ??? " << endl;
		cout << "Нажмите <7> если выбрали  ??? " << endl;
		cout << "Нажмите <8> если выбрали  ??? " << endl;
		cout << "Нажмите <9> если выбрали  ??? " << endl;

		cout << "Нажмите <10> если выбрали  выход " << endl;

		cin >> k;

		switch (k) {

		case 1:
			El_Gamal();
			break;

		case 2:
                        Tarab_G();
			break;

		case 3:
			Atbash();

			break;

		case 4:

			break;
		case 6:

			break;

		case 7:

			break;

		case 8:

			break;

		case 9:

			break;

		case 10:
			exit;
		}


	}

	else {

		cout << "Неверный пароль " << endl;

	}

	system("pause");

}
