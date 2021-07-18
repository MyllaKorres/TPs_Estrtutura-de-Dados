// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"pilha_recursiva.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	int opc, n, m;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t RECURSIVAS" << endl;

		cout << "\n\n\t\t 1 - FATORIAL" << endl;
		cout << "\t\t 2 - FIBONACCI" << endl;
		cout << "\t\t 3 - MDC" << endl;
		cout << "\t\t 4 - SOMA(s)" << endl;
		cout << "\t\t 5 - SOMA(s2)" << endl;
		cout << "\t\t 6 - DIGITOS" << endl;
		cout << "\t\t 7 - POTÊNCIA" << endl;
		cout << "\t\t 0 - SAIR" << endl;

		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			do
			{
				system("cls");

				SetConsoleTextAttribute(color, 15);

				cout << "\n\n\t\t INSIRA UM VALOR: ";
				cin >> n;

				if (n < 0)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t VALOR INVÁLIDO!!!" << endl;

					Sleep(2500);
				}

			} while (n < 0);

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t " << n << "! = " << fat(n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 2:
			do
			{
				system("cls");

				SetConsoleTextAttribute(color, 15);

				cout << "\n\n\t\t INSIRA UM VALOR: ";
				cin >> n;

				if (n < 0)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t VALOR INVÁLIDO!!!" << endl;

					Sleep(2500);
				}

			} while (n < 0);

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t FIBONACCI DE " << n << " = " << fib(n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 3:
			system("cls");

			cout << "\n\n\t\t INSIRA O PRIMEIRO VALOR: ";
			cin >> m;
			cout << "\n\n\t\t INSIRA O SEGUNDO VALOR: ";
			cin >> n;

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t MDC(" << m << "," << n << ") = " << mdc(m, n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 4:
			do
			{
				system("cls");

				SetConsoleTextAttribute(color, 15);

				cout << "\n\n\t\t INSIRA O PRIMEIRO VALOR: ";
				cin >> m;
				cout << "\n\n\t\t INSIRA O SEGUNDO VALOR: ";
				cin >> n;

				if (n < 0)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t O 1º VALOR NÃO PODE SER MAIOR QUE O 2º!!!" << endl;

					Sleep(2500);
				}

			} while (m > n);

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t S(" << m << "," << n << ") = " << s(m, n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 5:
			do
			{
				system("cls");

				SetConsoleTextAttribute(color, 15);

				cout << "\n\n\t\t INSIRA O PRIMEIRO VALOR: ";
				cin >> m;
				cout << "\n\n\t\t INSIRA O SEGUNDO VALOR: ";
				cin >> n;

				if (n < 0)
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t O 1º VALOR NÃO PODE SER MAIOR QUE O 2º!!!" << endl;

					Sleep(2500);
				}

			} while (m > n);

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t S2(" << m << "," << n << ") = " << s2(m, n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 6:
			system("cls");

			cout << "\n\n\t\t INSIRA O VALOR: ";
			cin >> n;

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t " << n << " POSSUI " << dig(n) << " DÍGITO(S)";

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

			system("pause");

			break;
		case 7:
			system("cls");

			cout << "\n\n\t\t INSIRA O VALOR DA BASE: ";
			cin >> m;
			cout << "\n\n\t\t INSIRA O VALOR DA POTÊNCIA: ";
			cin >> n;

			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t " << m << " ELEVADO A " << n << " = " << pot(m,n);

			SetConsoleTextAttribute(color, 15);

			cout << "\n\n\n\t\t ";

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