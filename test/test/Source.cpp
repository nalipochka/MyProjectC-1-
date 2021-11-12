#define _CRT_SECURE_NO_WARNINGS
#include<iostream>;
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<stdio.h>
#include<Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int task;
	do
	{
		cout << "Выберите действие:" << endl;
		cout << "1 --- Генератор паролей" << endl;
		cin >> task;
		switch (task)
		{
		case 1: {
			char str[256];
			FILE* f1;
			bool passw;
			int size = 0;
			cout << "Укажите длину пароля:";
			cin >> size;
			cout << "Укажите тип пароля: 1 --- циферный или 0 --- с символами:";
			cin >> passw;
			if (fopen_s(&f1, "password.txt", "w") == NULL) {
				if (passw == true) {
					cout << "password: ";
					for (size_t i = 0; i < size; i++) {
						int buffer;
						buffer = rand() % (9 - 0) + 0;
						cout << buffer;
						_itoa(buffer, str, 10);
						fputs(str, f1);
					}
					cout << endl;
				}
				else {
					cout << "password: ";
					for (size_t i = 0; i < size; i++)
					{
						int tmp = rand() % 2 + 1;
						if (tmp == 1) {
							char buffer = (char)(101 + rand() % 16);
							cout << buffer;
							fputc(buffer, f1);
						}
						else {
							int buffer = rand() % 9 + 1;
							cout << buffer;
							_itoa(buffer, str, 10);
							fputs(str, f1);
						}
					}
					cout << endl;
					fclose(f1);
				}
			}
		}
			  break;
		default: cout << "Error!";
		}
	} while (task != 0);
}