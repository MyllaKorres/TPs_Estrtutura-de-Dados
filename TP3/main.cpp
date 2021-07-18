// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"fila.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	int opc, senha = 1;
	unsigned tamanho;

	SetConsoleTextAttribute(color, 14);

	cout << "\n\n\t\t INFORME O TAMANHO DA FILA: ";
	cin >> tamanho;

	Fila<unsigned> p(tamanho);

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t >>> CONTROLE DE PESSOAS <<<" << endl;

		cout << "\n\n\t\t 1 - INCLUIR NA FILA" << endl;
		cout << "\n\t\t 2 - REMOVER DA FILA" << endl;
		cout << "\n\t\t 3 - EXIBIR PRIMEIRO DA FILA " << endl;
		cout << "\n\t\t 4 - EXIBIR FILA" << endl;
		cout << "\n\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			if (p.filacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA CHEIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				p.insere(senha);

				senha++;

				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t FILA INCREMENTADA COM SUCESSO!!!" << endl;

				Sleep(2000);
			}
			break;
		case 2:
			if (p.filavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA VAZIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				SetConsoleTextAttribute(color, 11);

				cout << "\n\t\t  _______________";
				cout << "\n\t\t |               |";
				cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << p.remove() << " |";
				cout << "\n\t\t |_______________|" << endl;

				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t FILA DECREMENTADA COM SUCESSO!!!" << endl;

				Sleep(3000);
			}
			break;
		case 3:
			if (p.filavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA VAZIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				SetConsoleTextAttribute(color, 11);

				cout << "\n\t\t  _______________";
				cout << "\n\t\t |               |";
				cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << p.primeiro() << " |";
				cout << "\n\t\t |_______________|\n\n\n\t\t";

				SetConsoleTextAttribute(color, 15);

				system("pause");
			}
			break;
		case 4:
			if (p.filavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA VAZIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				SetConsoleTextAttribute(color, 11);

				cout << "\n\t\t  _______________";

				if (p.getInic() > p.getFim())
				{
					for (int i = p.getInic(); i < p.getTamanho(); i++)
					{
						cout << "\n\t\t |               |";
						cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << p.getValor(i) << " |";
						cout << "\n\t\t |_______________|";
					}

					for (int i = 0; i <= p.getFim(); i++)
					{
						cout << "\n\t\t |               |";
						cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << p.getValor(i) << " |";
						cout << "\n\t\t |_______________|";
					}
				}
				else
				{
					for (int i = p.getInic(); i <= p.getFim(); i++)
					{
						cout << "\n\t\t |               |";
						cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << p.getValor(i) << " |";
						cout << "\n\t\t |_______________|";
					}
				}
				cout << "\n\n\n\t\t";

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

			cout << "OPÇÃO INVÁLIDA!!!" << endl;

			Sleep(2000);
		}
	} while (opc != 0);

	return 0;
}