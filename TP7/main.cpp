// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"arvore_binaria_busca.h"

using namespace std;

int main()
{
	int opc, valor;

	BST<int> t;

	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t ÁRVORE BINÁRIA DE BUSCA" << endl;

		cout << "\n\n\t\t 1 - INSERIR NA ÁRVORE" << endl;
		cout << "\t\t 2 - REMOVER DA ÁRVORE" << endl;
		cout << "\t\t 3 - MENOR VALOR DA ÁRVORE" << endl;
		cout << "\t\t 4 - MAIOR VALOR DA ÁRVORE" << endl;
		cout << "\t\t 5 - EXIBIR ÁRVORE: EM ORDEM" << endl;
		cout << "\t\t 6 - EXIBIR ÁRVORE: PRÉ-ORDEM" << endl;
		cout << "\t\t 7 - EXIBIR ÁRVORE: PÓS-ORDEM" << endl;
		cout << "\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\n\n\t\t DIGITE O VALOR: ";
			cin >> valor;

			t.insere(t.pRaiz, valor);
			{
				SetConsoleTextAttribute(color, 10);

				cout << "\n\n\t\t VALOR INSERIDO COM SUCESSO!!!" << endl;

				Sleep(1500);
			}
			break;
		case 2:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t REMOVER: ";
				cin >> valor;

				//if (t.confere(t.pRaiz, valor))
				//{
					t.remove(t.pRaiz, valor);

					/*SetConsoleTextAttribute(color, 10);

					cout << "\n\n\t\t VALOR REMOVIDO COM SUCESSO!!!" << endl;
				}
				else
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t ESSE NÚMERO NÃO EXISTE NA ÁRVORE!!!" << endl;
				}*/

				Sleep(3000);
			}
			break;
		case 3:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t MENOR: " << t.menor(t.pRaiz) << endl;

				Sleep(3000);
			}
			break;
		case 4:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t MAIOR: " << t.maior(t.pRaiz) << endl;

				Sleep(3000);
			}
			break;
		case 5:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t EM ORDEM: ";

				t.emOrdem(t.pRaiz);

				cout << "\n\n\t\t";

				system("pause");

			}
			break;
		case 6:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t PRÉ-ORDEM: ";

				t.preOrdem(t.pRaiz);

				cout << "\n\n\t\t ";

				system("pause");

			}
			break;
		case 7:
			if (t.bstvazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t ÁRVORE VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t POS-ORDEM: ";

				t.posOrdem(t.pRaiz);

				cout << "\n\n\t\t ";

				system(" pause");

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