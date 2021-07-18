// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"pilha.h"

using namespace std;

struct CONTEINER
{
	char cod[5];
	unsigned tam;
	char forn[25];
};

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int opc, np;
	Pilha<CONTEINER> *p[10]; // quantidade de pilhas
	CONTEINER c;

	for (int i = 0; i < 10; i++)
	{
		p[i] = new Pilha<CONTEINER>(5); // quantidade de elementos de cada pilha
	}

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t >>> P�TIO DE CONT�INERES <<<" << endl;

		cout << "\n\n\t\t 1 - EMPILHAR CONT�INER" << endl;
		cout << "\n\t\t 2 - DESEMPILHAR CONT�INER" << endl;
		cout << "\n\t\t 3 - EXIBIR PILHA DE CONT�INER" << endl;
		cout << "\n\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			do
			{
				system("cls");

				cout << "\n\n\t\t INSIRA O N�MERO DA PILHA: ";
				cin >> np;

				if (np < 0 || np>9)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t PILHA INEXISTENTE!!!" << endl;

					SetConsoleTextAttribute(color, 15);

					Sleep(3500);
				}
			} while (np < 0 || np>9);

			if (p[np]->pilhacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA CHEIA!!!" << endl;

				Sleep(3500);
			}
			else
			{
				cout << "\n\n\t\t INSIRA O C�DIGO DO CONT�INER: ";
				cin >> c.cod;
				cout << "\n\n\t\t INSIRA O TAMANHO DO CONT�INER (FT): ";
				cin >> c.tam;
				cout << "\n\n\t\t INSIRA O FORNECEDOR DO CONT�INER: ";
				cin >> c.forn;

				if (p[np]->pilhavazia() != true && p[np]->elementodotopo().tam != c.tam)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t TAMANHO DE CONT�INER N�O COMPAT�VEL!!!";
					cout << "\n\n\t\t OPERA��O CANCELADA!!!" << endl;

					Sleep(7500);
				}
				else
				{
					p[np]->empilha(c);

					SetConsoleTextAttribute(color, 10);

					cout << "\n\n\t\t CONT�INER EMPILHADO COM SUCESSO!!!" << endl;

					Sleep(3500);
				}
			}
			break;
		case 2:
			do
			{
				system("cls");

				cout << "\n\n\t\t INSIRA O N�MERO DA PILHA: ";
				cin >> np;

				if (np < 0 || np>9)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t PILHA INEXISTENTE!!!" << endl;

					SetConsoleTextAttribute(color, 15);

					Sleep(3500);
				}
			} while (np < 0 || np>9);

			if (p[np]->pilhavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

				Sleep(3500);
			}
			else
			{
				system("cls");

				cout << "\n\n\t\t  _____________________________________________________";
				cout << "\n\t\t |       |        |         |                          |";
				cout << "\n\t\t | PILHA | C�DIGO | TAMANHO |        FORNECEDOR        |";
				cout << "\n\t\t |_______|________|_________|__________________________|";
				cout << "\n\t\t |       |        |         |                          |";
				cout << "\n\t\t |   " << np << "   |  ";
				cout.width(5);
				cout.setf(ios::left, ios::adjustfield);
				cout << p[np]->getValor(p[np]->getTopo()).cod << " |  ";
				cout.width(2);
				cout.setf(ios::left, ios::adjustfield);
				cout << p[np]->getValor(p[np]->getTopo()).tam << " FT  | ";
				cout.width(25);
				cout.setf(ios::left, ios::adjustfield);
				cout << p[np]->desempilha().forn << "|";
				cout << "\n\t\t |_______|________|_________|__________________________|" << endl;

				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t CONT�INER DESEMPILHADO COM SUCESSO!!!" << endl;

				Sleep(7500);
			}
			break;
		case 3:
			do
			{
				system("cls");

				cout << "\n\n\t\t INSIRA O N�MERO DA PILHA: ";
				cin >> np;

				if (np < 0 || np>9)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t PILHA INEXISTENTE!!!" << endl;

					SetConsoleTextAttribute(color, 15);

					Sleep(3500);
				}
			} while (np < 0 || np>9);

			if (p[np]->pilhavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

				Sleep(3500);
			}
			else
			{
				system("cls");

				cout << "\n\n\t\t PILHA: " << np << endl;;
				cout << "\n\n\t\t CONT�INERES: " << p[np]->getTopo() + 1;
				cout << "\n\n\t\t  _____________________________________________";
				cout << "\n\t\t |        |         |                          |";
				cout << "\n\t\t | C�DIGO | TAMANHO |        FORNECEDOR        |";
				cout << "\n\t\t |________|_________|__________________________|";

				for (int i = p[np]->getTopo(); i >= 0; i--)
				{
					cout << "\n\t\t |        |         |                          |";
					cout << "\n\t\t |  ";
					cout.width(5);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->getValor(i).cod << " |  ";
					cout.width(2);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->getValor(i).tam << " FT  | ";
					cout.width(25);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->getValor(i).forn << "|";
					cout << "\n\t\t |________|_________|__________________________|";
				}
				cout << "\n";
				
				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t CONT�INERES ENCONTRADOS COM SUCESSO!!!\n\n\n\t\t ";

				SetConsoleTextAttribute(color, 15);
				system("pause");
			}
		break;
		case 0:
			system("cls");

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\n\n\t\t\t      FINALIZANDO..." << endl;

			Sleep(2000);

			system("cls");

			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n\n\n\n" << endl;

			SetConsoleTextAttribute(color, 15);

			break;
		default:

			SetConsoleTextAttribute(color, 12);

			cout << "OP��O INV�LIDA!!!" << endl;

			Sleep(3500);
		}
	} while (opc != 0);

	return 0;
}