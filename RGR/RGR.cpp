#include "Header.h"
#include "Header1.h"

enum instuction {
	Эль_Гамаля = 1,
	Тарабарская_грамота,
	Атбаш,
	Вижинер,
	Гронсфельд,
	Двойная_табличная_перестановка,
	Транспонирования,
	RSA,
	Табличная_перестановка
};

void menu(const string& password) {
	string s, vibor, wish;
	ofstream fout("Output.txt", ios::app);
	ifstream in("Input.txt");

	int k;

	cout << endl;
	cout << "Выберите шифр: " << endl;
	cout << "Нажмите <1> если выбрали  Эль Гамаля " << endl;
	cout << "Нажмите <2> если выбрали  Тарабарская грамота " << endl;
	cout << "Нажмите <3> если выбрали  Атбаш " << endl;
	cout << "Нажмите <4> если выбрали  Вижинер" << endl;
	cout << "Нажмите <5> если выбрали  Гронсфельд " << endl;
	cout << "Нажмите <6> если выбрали  Двойная табличная перестановка " << endl;
	cout << "Нажмите <7> если выбрали  Шифр Транспонирования " << endl;
	cout << "Нажмите <8> если выбрали  RSA " << endl;
	cout << "Нажмите <9> если выбрали  Табличная перестановка " << endl;

	cout << "Нажмите <10> если выбрали  выход " << endl;

	cin >> vibor;
	if (vibor.length()<3) {
		k = stoi(vibor);
	}
	else {
		system("cls");
		cout << "Введите число от 1 до 10";
		vibor.clear();
		menu(password);
	}
	switch (k) {

	case Эль_Гамаля:
		system("cls");
		El_Gamal(fout, password, in);
		system("notepad Output.txt ");
		break;

	case Тарабарская_грамота:
		system("cls");
		Tarab_G(fout, password, in);
		system("notepad Output.txt ");
		break;

	case Атбаш:
		system("cls");
		char str[64];
		while (1) {
			cout << "What would you like:" << endl << "1) decryption only" << endl << "2) only encrypt" << endl << "3) this and that" << endl;
			cin >> wish;
			if (wish == "3") {
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
				system("notepad Output.txt ");
				break;
			}
			else if (wish == "2") {
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

				putchar('\n');
				getchar();
				system("notepad Output.txt ");
				break;
			}
			else if (wish == "1") {
				cout << "Введите строку:";
				cin >> str;
				fout << "Atbash" << endl;
				fout << endl;
				fout << "Origin strings: " << str << endl;
				fout << endl;

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
				system("notepad Output.txt ");
				break;
			}
			else {
				system("cls");
				cout << "Введите число от 1 до 3" << endl;
				wish.clear();
			}
		}
		break;

	case Вижинер:
		system("cls");
		Vizhiner(fout, password, in);
		system("notepad Output.txt ");
		break;

	case Гронсфельд:
		system("cls");
        Grons(fout, password,in);
		system("notepad Output.txt ");
		break;

	case Двойная_табличная_перестановка:
		system("cls");
		TablCryp(fout, password, in);
		system("notepad Output.txt ");
		break;

	case Транспонирования:
          system("cls");
          transp(fout, password, in);
		  system("notepad Output.txt ");
		break;

	case RSA:
		system("cls");
		rsa(fout, password);
		system("notepad Output.txt ");
		break;

	case Табличная_перестановка:
		system("cls");
		tablichnaya_perestanovka();
		system("notepad Output.txt ");
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
		remove("Output.txt");
		menu(password);
	}

	else {

		cout << "Неверный пароль " << endl;

	}

	system("pause");

}
