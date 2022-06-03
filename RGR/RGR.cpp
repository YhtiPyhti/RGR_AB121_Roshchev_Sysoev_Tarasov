#include "Header.h"
#include "Header1.h"

void menu() {
	int k;
	cout << endl;
	cout << "Выберите шифр: " << endl;

	cout << "Нажмите <1> если выбрали  Эль Гамаля " << endl;
	cout << "Нажмите <2> если выбрали  Тарабарская грамота " << endl;
	cout << "Нажмите <3> если выбрали  Атбаш " << endl;
	cout << "Нажмите <4> если выбрали  Вижинер" << endl;
	cout << "Нажмите <5> если выбрали  Гронсфельд " << endl;
	cout << "Нажмите <6> если выбрали  Двойная табличная перестановка " << endl;
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
		char str[64];
		cout << "Введите строку:";
		cin >> str;
		cout << "Закодированная строка:";
		cout << code_atbash(str);    // закодированная
		cout << "Декодированная строка:";
		cout << decode_atbash(str);   // декодированная

		putchar('\n');
		getchar();

		break;

	case 4:
		Vizhiner();
		break;

	case 5:
        Grons();
		break;

	case 6:
		TablCryp();
		break;

	case 7:

		break;

	case 8:

		break;

	case 9:

		break;

	case 10:
		exit(0);
	}
	menu();
}

void main(){
	setlocale(LC_ALL, "Russian");
	string s;

	cout << "Пароль: ";

	cin >> s;

	if (s == "1111") {
		menu();
	}

	else {

		cout << "Неверный пароль " << endl;

	}

	system("pause");

}
