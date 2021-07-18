// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"teatro.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	int linha = 4;
	int coluna = 5;
	int aux1, aux2, aux3, aux4;
	int opc;
	Lugares<int> m(linha, coluna);

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\t\t       ____________" << endl;
		cout << "\t\t      |            |" << endl;
		cout << "\t\t      |   TEATRO   |" << endl;
		cout << "\t\t      |____________|" << endl;

		cout << "\n\n\t\t  POLTRONAS DISPONÍVEIS: " << m.getDisp() << endl;

		cout << "\n\n\t\t     1 - COMPRAR INGRESSO" << endl;
		cout << "\t\t     2 - DEVOLVER INGRESSO" << endl;
		cout << "\t\t     3 - TROCAR LUGAR" << endl;
		cout << "\t\t     0 - SAIR" << endl;
		cout << "\n\n\t\t     Selecione: ";
		cin >> opc;

		system("cls");

		if ((opc == 1 || opc == 3 && m.getDisp() != 0) || (opc == 2 || opc == 3 && m.getDisp() != 20))
		{
			cout << "\n\t\t              C O L U N A" << endl;
			cout << "\n\t\t       0     1     2     3     4";
			cout << "\n\t\t" << "     _____________________________";

			for (int i = 0; i < linha; i++)
			{

				cout << "\n\t\t" << "    |     |     |     |     |     |";
				cout << "\n\t\t " << i << "  |  ";

				for (int j = 0; j < coluna; j++)
				{
					if ((char)m.getValor(i, j) == '-')
					{
						SetConsoleTextAttribute(color, 10);
					}
					else
					{
						SetConsoleTextAttribute(color, 13);
					}
					cout << (char)m.getValor(i, j);

					SetConsoleTextAttribute(color, 15);

					cout << "  |  ";

					if (j == coluna - 1)
					{
						if (i == 1)
						{
							cout << "\n" << "     L I N H A      |_____|_____|_____|_____|_____| ";
						}
						else
						{
							cout << "\n\t\t" << "    |_____|_____|_____|_____|_____| ";
						}
					}
				}
			}

			SetConsoleTextAttribute(color, 13);

			cout << "\n\n\n\t\t\t X -> POLTRONA OCUPADA" << endl;
		}

		SetConsoleTextAttribute(color, 15);

		switch (opc)
		{
		case 1:
			if (m.getDisp() == 0)
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t\t   >>>>> ATENÇÃO <<<<<" << endl;
				cout << "\n\t\t\t     TEATRO CHEIO!!!" << endl;
				cout << "\n\t\tNÃO HÁ POLTRONAS DISPONÍVEIS PARA COMPRA!!!" << endl;
				Sleep(5000);
			}
			else
			{
				cout << "\n\n\t\tInsira o lugar desejado: \n" << endl;
				do
				{
					cout << "\t\tL: ";
					cin >> aux1;
				} while (aux1 < 0 || aux1>3);

				do
				{
					cout << "\t\tC: ";
					cin >> aux2;
				} while (aux2 < 0 || aux2>4);

				if ((char)m.getValor(aux1, aux2) == 'X')
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t\t >>>>> ATENÇÃO <<<<<" << endl;
					cout << "\n\t\t\t POLTRONA OCUPADA!!!" << endl;
					cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
					Sleep(5000);
				}
				else
				{
					m.reserva(aux1, aux2);
				}
			}
			break;
		case 2:
			if (m.getDisp() == 20)
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t\t  >>>>> ATENÇÃO <<<<<" << endl;
				cout << "\n\t\t\t    TEATRO VAZIO!!!" << endl;
				cout << "\n\t\t NÃO HÁ POLTRONAS A SEREM DEVOLVIDAS!!!" << endl;
				Sleep(5000);
			}
			else
			{
				cout << "\n\n\t\tInsira o lugar desejado: \n" << endl;
				do
				{
					cout << "\t\tL: ";
					cin >> aux1;
				} while (aux1 < 0 || aux1>3);

				do
				{
					cout << "\t\tC: ";
					cin >> aux2;
				} while (aux2 < 0 || aux2>4);

				if ((char)m.getValor(aux1, aux2) == '-')
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t\t >>>>> ATENÇÃO <<<<<" << endl;
					cout << "\n\t\t\t  POLTRONA VAZIA!!!" << endl;
					cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
					Sleep(5000);
				}
				else
				{
					m.cancela(aux1, aux2);
				}
			}
			break;
		case 3:
			if (m.getDisp() == 0)
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t\t   >>>>> ATENÇÃO <<<<<" << endl;
				cout << "\n\t\t\t     TEATRO CHEIO!!!" << endl;
				cout << "\n\t\tNÃO HÁ POLTRONAS DISPONÍVEIS PARA TROCA!!!" << endl;
				Sleep(5000);
			}
			else if (m.getDisp() == 20)
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t\t   >>>>> ATENÇÃO <<<<<" << endl;
				cout << "\n\t\t\t     TEATRO VAZIO!!!" << endl;
				cout << "\n\t\tNÃO HÁ POLTRONAS DISPONÍVEIS PARA TROCA!!!" << endl;
				Sleep(5000);
			}
			else
			{
				cout << "\n\n\t\tInsira o lugar a ser trocado: \n" << endl;
				do
				{
					cout << "\t\tL: ";
					cin >> aux1;
				} while (aux1 < 0 || aux1>3);

				do
				{
					cout << "\t\tC: ";
					cin >> aux2;
				} while (aux2 < 0 || aux2>4);

				if ((char)m.getValor(aux1, aux2) == '-')
				{
					SetConsoleTextAttribute(color, 12);

					cout << "\n\n\t\t\t >>>>> ATENÇÃO <<<<<" << endl;
					cout << "\n\t\t\t  POLTRONA VAZIA!!!" << endl;
					cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
					Sleep(5000);
				}
				else
				{
					cout << "\n\n\t\tInsira o lugar desejado: \n" << endl;
					do
					{
						cout << "\t\tL: ";
						cin >> aux3;
					} while (aux3 < 0 || aux3>3);

					do
					{
						cout << "\t\tC: ";
						cin >> aux4;
					} while (aux4 < 0 || aux4>4);

					if ((char)m.getValor(aux3, aux4) == 'X')
					{
						SetConsoleTextAttribute(color, 12);

						cout << "\n\n\t\t\t >>>>> ATENÇÃO <<<<<" << endl;
						cout << "\n\t\t\t POLTRONA OCUPADA!!!" << endl;
						cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
						Sleep(5000);
					}
					else
					{
						m.troca(aux1, aux2, aux3, aux4);
					}
				}
				break;
		case 0:
			cout << "\n\n\n\n\n\t\t\t   ENCERRANDO...\n\n" << endl;
			Sleep(2000);

			system("cls");

			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

			SetConsoleTextAttribute(color, 15);

			break;
		default:
			SetConsoleTextAttribute(color, 12);

			cout << "\n\n\t\t\t   >>>>> ATENÇÃO <<<<<" << endl;
			cout << "\n\n\t\t\t    OPÇÃO INVÁLIDA!!!" << endl;
			Sleep(3500);
			}
		} 
	}while (opc != 0);
	return 0;
}