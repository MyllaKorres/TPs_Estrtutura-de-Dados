// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include "pilha_ligada.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	Pilha<char> p;
	string exp;
	char s, c;
	bool verifica;
	int cont;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t EXAMINADOR DE EXPRESSÕES MATEMÁTICAS" << endl;

		cout << "\n\n\t\t INSIRA A EXPRESSÃO QUE DESEJA VERIFICAR: ";
		getline(cin, exp);

		verifica = true;

		cont = 0;

		for (unsigned i = 0; i < exp.length(); i++)
		{
			s = exp.at(i);

			if (s == '(' || s == '[' || s == '{')
			{
				p.empilha(s);

				cont++;
			}

			if (s == ')' || s == ']' || s == '}')
			{
				if (p.pilhavazia())
				{
					verifica = false;
				}
				else
				{
					c = p.elementodotopo();

					if (c == '(' && s != ')' || c == '[' && s != ']' || c == '{' && s != '}')
					{
						verifica = false;
					}
					else
					{
						p.desempilha();

						cont--;
					}
				}
			}
		}

		if (verifica && p.pilhavazia())
		{
			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\t\t EXPRESSÃO VÁLIDA!!!" << endl;

			Sleep(3000);
		}
		else
		{
			SetConsoleTextAttribute(color, 12);

			cout << "\n\n\t\t EXPRESSÃO INVÁLIDA!!!" << endl;

			Sleep(3000);
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t DESEJA EXAMINAR OUTRA EXPRESSÃO MATEMÁTICA? S/N ";
		cin >> c;
		cin.ignore();

		if (c != 's' && c != 'S')
		{
			system("cls");

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\n\n\t\t\t FINALIZANDO..." << endl;

			Sleep(2000);

			system("cls");

			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

			SetConsoleTextAttribute(color, 15);
		}
		else if(!p.pilhavazia())
		{
			for (int i = 0; i < cont; i++)
			{
				p.desempilha();
			}
		}

	} while (c == 's' || c == 'S');

	return 0;
}