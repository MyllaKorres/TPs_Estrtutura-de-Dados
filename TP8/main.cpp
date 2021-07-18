// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"lista_ordenada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    int opc, valor;

    ListaOrdenada<int> lista;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t LISTA ORDENADA" << endl;

		cout << "\n\n\t\t 1 - INSERIR NA LISTA" << endl;
		cout << "\t\t 2 - REMOVER DA LISTA" << endl;
		cout << "\t\t 3 - BUSCAR NA LISTA" << endl;
		cout << "\t\t 4 - EXIBIR LISTA" << endl;
		cout << "\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\n\n\t\t DIGITE O VALOR: ";
			cin >> valor;

			lista.insere(valor);
			
			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\t\t VALOR INSERIDO COM SUCESSO!!!" << endl;

			Sleep(1500);

			break;
		case 2:
			if (lista.listavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t LISTA VAZIA!!!" << endl;
			}
			else
			{
				cout << "\n\n\t\t REMOVER: ";
				cin >> valor;

				if (lista.remove(valor))
				{
					SetConsoleTextAttribute(color, 10);

					cout << "\n\n\t\t VALOR REMOVIDO COM SUCESSO!!!" << endl;
				}
				else
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA LISTA!!!" << endl;
				}
			}

			Sleep(3000);

			break;
		case 3:
			if (lista.listavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t LISTA VAZIA!!!" << endl;
			}
			else
			{
				cout << "\n\n\t\t BUSCA: ";
				cin >> valor;

				if (lista.busca(valor)>0)
				{
					SetConsoleTextAttribute(color, 10);

					cout << "\n\n\t\t O NÚMERO " << valor << " É O " << lista.busca(valor) << "º VALOR DA LISTA!!!" << endl;
				}
				else
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA LISTA!!!" << endl;
				}
			}

			Sleep(3000);

			break;
		case 4:
			if (lista.listavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t LISTA VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				Node<int>* aux = lista.h;

				cout << "\n\n\t\t LISTA: ";

				while (aux != NULL)
				{
					cout << aux->info << " ";
					aux = aux->prox;
				}

				cout << "\n\n\t\t ";

				system("pause");
			}
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