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

void menu(const string& password) {
	string s;
	ofstream fout("C:\\Users\\Output.txt", ios::app);

	int k;
	cout << endl;
	cout << "Выберите шифр: " << endl;
	cout << "Нажмите <1> если выбрали  Эль Гамаля " << endl;
	cout << "Нажмите <2> если выбрали  Тарабарская грамота " << endl;
	cout << "Нажмите <3> если выбрали  Атбаш " << endl;
	cout << "Нажмите <4> если выбрали  Вижинер" << endl;
	cout << "Нажмите <5> если выбрали  Гронсфельд " << endl;
	cout << "Нажмите <6> если выбрали  Двойная табличная перестановка " << endl;
	cout << "Нажмите <7> если выбрали  Транспонирование " << endl;
	cout << "Нажмите <8> если выбрали  ??? " << endl;
	cout << "Нажмите <9> если выбрали  ??? " << endl;

	cout << "Нажмите <10> если выбрали  выход " << endl;

	cin >> k;

	switch (k) {

	case Эль_Гамаля:
		system("cls");
		El_Gamal(fout, password);
		system("notepad C:\\Users\\Output.txt ");
		break;

	case Тарабарская_грамота:
		system("cls");
		Tarab_G(fout);
		system("notepad C:\\Users\\Output.txt ");
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

		cout << "Пароль: ";
		cin >> s;
		if (s == password) {
			cout << "Закодированная строка:";
			cout << code_atbash(str) << endl;    // закодированная

			fout << "Decoded string: " << str << endl;
			fout << endl;
		}
		else {
			cout << "Неверный пароль " << endl;
			break;
		}

		s.clear();
		cout << "Пароль: ";
		cin >> s;

		if (s == password) {
			cout << "Декодированная строка:";

			cout << decode_atbash(str) << endl;   // декодированная
			fout << "Decoded string: " << str << endl;
			fout << endl;
		}
		else {
			cout << "Неверный пароль " << endl;
			break;
		}
		putchar('\n');
		getchar();
		system("notepad C:\\Users\\Output.txt ");
		break;

	case Вижинер:
		system("cls");
		Vizhiner(fout, password);
		system("notepad C:\\Users\\Output.txt ");
		break;

	case Гронсфельд:
		system("cls");
        Grons(fout);
		system("notepad C:\\Users\\Output.txt ");
		break;

	case Двойная_табличная_перестановка:
		system("cls");
		TablCryp(fout, password);
		system("notepad C:\\Users\\Output.txt ");
		break;

	case 7:
          system("cls");
          void transp();
	      system("notepad C:\\Users\\Output.txt ");
		break;

	case 8:

		break;

	case 9:

		break;

	case 10:
		exit(0);
	}
	menu(password);
}

void main(){
	setlocale(LC_ALL, "Russian");
	string s, password = "1111";

	cout << "Пароль: ";

	cin >> s;

	if (s == password) {
		remove("C:\\Users\\Output.txt");
		menu(password);
	}

	else {

		cout << "Неверный пароль " << endl;

	}

	system("pause");

}
