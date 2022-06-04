#include "Header.h"
#include "Header1.h"

enum instuction {
	Эль_Гамаля = 1,
	Тарабарская_грамота,
	Атбаш,
	Вижинер,
	Гронсфельд,
	Двойная_табличная_перестановка
};

void menu() {
	ofstream fout("C:\\Users\\Sergei\\Desktop\\Output.txt", ios::app);

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

	case Эль_Гамаля:
		system("cls");
		El_Gamal(fout);
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
		break;

	case Тарабарская_грамота:
		system("cls");
		Tarab_G(fout);
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
		break;

	case Атбаш:
		system("cls");
		char str[64];
		cout << "Введите строку:";
		cin >> str;

		fout << "Atbash" << endl;
		fout << endl;
		fout << "Origin strings: " << str << endl;
		fout << endl;

		cout << "Закодированная строка:";

		cout << code_atbash(str);    // закодированная
		fout << "Decoded string: " << str << endl;
		fout << endl;

		cout << "Декодированная строка:";

		cout << decode_atbash(str);   // декодированная
		fout << "Decoded string: " << str << endl;
		fout << endl;

		putchar('\n');
		getchar();
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
		break;

	case Вижинер:
		system("cls");
		Vizhiner(fout);
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
		break;

	case Гронсфельд:
		system("cls");
        Grons(fout);
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
		break;

	case Двойная_табличная_перестановка:
		system("cls");
		TablCryp(fout);
		system("notepad C:\\Users\\Sergei\\Desktop\\Output.txt ");
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
