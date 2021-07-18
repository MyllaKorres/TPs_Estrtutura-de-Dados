// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"hashing.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    int opc, valor;
	Node* aux;
	Hash h;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t TABELA HASHING" << endl;

		cout << "\n\n\t\t 1 - INSERIR" << endl;
		cout << "\t\t 2 - REMOVER" << endl;
		cout << "\t\t 3 - BUSCAR" << endl;
		cout << "\t\t 4 - EXIBIR" << endl;
		cout << "\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\n\n\t\t DIGITE O VALOR: ";
			cin >> valor;

			h.insere(valor);
			
			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\t\t VALOR INSERIDO COM SUCESSO!!!" << endl;

			Sleep(1500);

			break;
		case 2:
			cout << "\n\n\t\t REMOVER: ";
			cin >> valor;

			if (h.listavazia(h.fht(valor)))
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA LISTA!!!" << endl;
			}
			else if (h.remove(valor))
			{
				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t VALOR REMOVIDO COM SUCESSO!!!" << endl;
			}
			else
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA LISTA!!!" << endl;
			}

			Sleep(3000);

			break;
		case 3:
			cout << "\n\n\t\t BUSCA: ";
			cin >> valor;

			if (h.busca(valor)>0)
			{
				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t O NÚMERO " << valor << " É O " << h.busca(valor) << "º VALOR DA LISTA h[" << h.fht(valor) << "] !!!\n\n\n\t\t ";

				SetConsoleTextAttribute(color, 15);

				system("pause");
			}
			else
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA LISTA!!!" << endl;

				Sleep(3000);
			}

			break;
		case 4:
			for (int i = 0; i < W; i++)
			{
				aux = h.h[i];

				cout << "\n\t\t h[" << i << "]->";

				if (h.listavazia(i))
				{
					SetConsoleTextAttribute(color, 12);

					cout << " LISTA VAZIA!!!";
				}
				else
				{
					while (aux != NULL)
					{
						cout << aux->info << "->";
						aux = aux->prox;
					}
				}
				SetConsoleTextAttribute(color, 15);
			}

			cout << "\n\n\t\t ";

			system("pause");

			break;
		case 0:
			system("cls");

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\n\n\t\t\t FINALIZANDO..." << endl;

			Sleep(2000);

			system("cls");

			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

			SetConsoleTextAttribute(color, 15);

			break;
		default:

			SetConsoleTextAttribute(color, 12);

			cout << "\n\n\t\t OPÇÃO INVÁLIDA!!!" << endl;

			Sleep(3000);
		}
	} while (opc != 0);

	return 0;
}