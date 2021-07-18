// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include"fila.h"
#include"pilha.h"
#include"pilha_ligada.h"

#define ex8

using namespace std;

#ifdef ex4

/*

	4. Considere os protótipos, definidos abaixo, para uma estrutura de dados do
	   tipo fila, implementada em alocação sequencial com representação circular.

	   void insere(int x) : //insere um novo elemento na fila
	   int remove() :  //remove um elemento da fila, retornando este elemento removido
	   int primeiro() :  //retorna o valor do primeiro elemento da fila.

	   Mostre a situação de uma fila, inicialmente vazia
	   após cada uma das seguintes operações :

	   1. insere(5)  			 2. insere(8)			  3. insere(2)
	   4. insere(primeiro()) 	 5. remove()			  6. insere(remove())
	   7. remove()				 8. insere(1)			  9. remove()
	  10. insere(remove())	    11. insere(primeiro())	 12. insere(remove())
	  13. insere(3)			    14. insere(remove())	 15. insere(3)

*/

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

Fila<int> p(20);

void IMPRIME()
{
	if (p.filavazia())
	{
		SetConsoleTextAttribute(color, 12);

		cout << "\n\n\t\t FILA VAZIA!!!" << endl;

		Sleep(2000);
	}
	else
	{
		SetConsoleTextAttribute(color, 11);

		cout << "\n\n\t\t FILA: ";

		if (p.getInic() > p.getFim())
		{
			for (int i = p.getInic(); i < p.getTamanho(); i++)
			{
				cout << p.getValor(i) << " ";
			}

			for (int i = 0; i <= p.getFim(); i++)
			{
				cout << p.getValor(i) << " ";
			}
		}
		else
		{
			for (int i = p.getInic(); i <= p.getFim(); i++)
			{
				cout << p.getValor(i) << " ";
			}
		}
		cout << "\n\n\n\t\t ";

		SetConsoleTextAttribute(color, 15);

		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int opc, c;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t >>> FILA <<<" << endl;

		cout << "\n\n\t\t 1 - INSERE()" << endl;
		cout << "\n\t\t 2 - INSERE(REMOVE())" << endl;
		cout << "\n\t\t 3 - INSERE(PRIMEIRO())" << endl;
		cout << "\n\t\t 4 - REMOVE()" << endl;
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
				cout << "\n\n\t\t INSERE: ";
				cin >> c;

				p.insere(c);

				cout << "\n\t\t INSERE(" << c << ")";

				IMPRIME();
			}
			break;
		case 2:
			if (p.filacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA CHEIA!!!" << endl;

				Sleep(2000);
			}
			else if (p.filavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA VAZIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				cout << "\n\n\t\t REMOVE: " << p.getValor(p.getInic());

				p.insere(p.remove());

				cout << "\n\n\t\t INSERE(REMOVE())";

				IMPRIME();
			}
			break;
		case 3:
			if (p.filacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA CHEIA!!!" << endl;

				Sleep(2000);
			}
			else if (p.filavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t FILA VAZIA!!!" << endl;

				Sleep(2000);
			}
			else
			{
				cout << "\n\n\t\t PRIMEIRO: " << p.primeiro();

				p.insere(p.primeiro());

				cout << "\n\n\t\t INSERE(PRIMEIRO())";

				IMPRIME();
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
				cout << "\n\n\t\t REMOVE: " << p.remove();

				cout << "\n\n\t\t REMOVE()";

				IMPRIME();
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

			cout << "\n\n\t\t OPÇÃO INVÁLIDA!!!" << endl;

			Sleep(2000);
		}
	} while (opc != 0);

	return 0;
}

#endif // ex4

#ifdef ex5

/*
	5. Considere os protótipos, definidos abaixo, para uma estrutura de dados do tipo Pilha,
	   implementada em alocação sequencial:
	   
	   a) void empilha(int x): - empilha um novo elemento
   	   b) int desempilha(): - desempilha um elemento e retorna o elemento desempilhado
	   c) int topo(): - retorna o valor do  elemento do topo da pilha
	   
	   Mostre a situação de uma pilha , inicialmente vazia, após a execução de cada umas das operações:
	   
	   1. empilha(1)		  2. empilha(5)	      3. desempilha()
	   4. empilha(5)		  5. empilha(9)	      6. empilha(7)
	   7. empilha(topo())	  8. desempilha()     9. empilha(desempilha())
	  10. empilha(4)	     11. empilha(3)	     12. empilha(8)
*/

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

Pilha<int> p(20);

void IMPRIME()
{
	if (p.pilhavazia())
	{
		SetConsoleTextAttribute(color, 12);

		cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

		Sleep(3000);

	}
	else
	{
		SetConsoleTextAttribute(color, 11);

		cout << "\n\n\t\t PILHA: ";

		for (int i = 0; i <= p.getTopo(); i++)
		{
			cout << p.getValor(i) << " ";
		}
		cout << "\n\n\t\t ";

		SetConsoleTextAttribute(color, 15);

		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int opc, valor;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t >>> PILHA <<<" << endl;

		cout << "\n\n\t\t 1 - EMPILHA()" << endl;
		cout << "\t\t 2 - EMPILHA(DESEMPILHA())" << endl;
		cout << "\t\t 3 - EMPILHA(TOPO())" << endl;
		cout << "\t\t 4 - DESEMPILHA()" << endl;
		cout << "\t\t 0 - SAIR" << endl;
		cout << "\n\n\t\t SELECIONE: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			if (p.pilhacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA CHEIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t EMPILHA: ";
				cin >> valor;

				p.empilha(valor);

				cout << "\n\n\t\t EMPILHA(" << valor << ")";

				IMPRIME();
			}
			break;
		case 2:
			if (p.pilhacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA CHEIA!!!" << endl;

				Sleep(3000);
			}
			else if (p.pilhavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t DESEMPILHA: " << p.elementodotopo();

				p.empilha(p.desempilha());

				cout << "\n\n\t\t EMPILHA(DESEMPILHA())";

				IMPRIME();
			}
			break;
		case 3:
			if (p.pilhacheia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA CHEIA!!!" << endl;

				Sleep(3000);
			}
			else if (p.pilhavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t TOPO: " << p.elementodotopo();

				p.empilha(p.elementodotopo());

				cout << "\n\n\t\t EMPILHA(TOPO())";

				IMPRIME();
			}
			break;
		case 4:
			if (p.pilhavazia())
			{
				SetConsoleTextAttribute(color, 12);

				cout << "\n\n\t\t PILHA VAZIA!!!" << endl;

				Sleep(3000);
			}
			else
			{
				cout << "\n\n\t\t DESEMPILHA: " << p.desempilha();

				cout << "\n\n\t\t DESEMPILHA()";

				IMPRIME();
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

#endif // ex5

#ifdef ex6

/*
	6. Utilizando as implementações de uma estrutura de dados pilha, 
	   elabore um programa que converta um número decimal em binário.
*/

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

Pilha<int>p(16);

void bin(int dec)
{
	while (dec != 0) 
	{
		if (dec % 2 == 0)
		{
			p.empilha(0);
		}
		else
		{
			p.empilha(1);
		}

		dec /= 2;
	}
}

int main() 
{
	setlocale(LC_ALL, "Portuguese");

	int dec;
	char c;

	do
	{
		system("cls");

		do 
		{
			cout << "\n\n\t\t Insira um número decimal: ";
			cin >> dec;
		} while (dec < 0);
		
		system("cls");

		cout << "\n\n\n\n\t\t DECIMAL: " << dec;

		bin(dec);

		cout << "\n\n\n\t\t BINÁRIO: ";

		SetConsoleTextAttribute(color, 11);

		if (!p.pilhavazia())
		{
			for (int i = p.getTopo(); i >= 0; i--)
			{
				cout << p.getValor(i);
			}
		}
		else
		{
			cout << "0";
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\n\n\t\t DESEJA CONVERTER OUTRO DECIMAL EM BINÁRIO? S/N ";
		cin >> c;

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
		else
		{
			while (!p.pilhavazia())
			{
				p.desempilha();
			}
		}

	} while (c == 's' || c == 'S');

	return 0;
}

#endif // ex6

#ifdef ex7

/*
	7. Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que:

	   a) define uma pilha e uma fila de tamanho 20.
	   b) carrega a fila com números aleatórios compreendidos entre 35 e 78
	   c) exibe a fila
	   d) transfere todos os elementos da fila para a pilha
	   e) exibe a pilha
*/

int main()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "Portuguese");

	char c;
	Fila<int>f(20);  // a) define uma fila de tamanho 20.
	Pilha<int>p(20); // a) define uma pilha de tamanho 20.

	do
	{
		system("cls");

		srand(time(NULL));

		for (int i = 0; i < 20; i++)
		{
			f.insere(35 + rand() % 44); // b) carrega a fila com números aleatórios compreendidos entre 35 e 78
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t FILA: ";

		SetConsoleTextAttribute(color, 11);

		if (f.getInic() > f.getFim()) // c) exibe a fila
		{
			for (int i = f.getInic(); i < f.getTamanho(); i++)
			{
				cout << f.getValor(i) << " ";
			}

			for (int i = 0; i <= f.getFim(); i++)
			{
				cout << f.getValor(i) << " ";
			}
		}
		else
		{
			for (int i = f.getInic(); i <= f.getFim(); i++)
			{
				cout << f.getValor(i) << " ";
			}
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\n\t\t TRANSFERINDO OS ELEMENTOS..." << endl;

		SetConsoleTextAttribute(color, 15);

		Sleep(2000);

		while (!f.filavazia()) // d) transfere todos os elementos da fila para a pilha
		{
			p.empilha(f.remove());
		}

		cout << "\n\n\t\t PILHA: ";

		SetConsoleTextAttribute(color, 14);

		for (int i = p.getTopo(); i >= 0; i--) // e) exibe a pilha
		{
			cout << p.getValor(i) << " ";
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\n\n\t\t DESEJA CRIAR OUTRA FILA DE NÚMEROS ALEATÓRIOS? S/N ";
		cin >> c;

		if (c != 's' && c != 'S')
		{
			system("cls");

			cout << "\n\n\n\n\n\t\t\t FINALIZANDO..." << endl;

			Sleep(2000);

			system("cls");

			SetConsoleTextAttribute(color, 10);

			cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

			SetConsoleTextAttribute(color, 15);
		}
		else
		{
			while (!p.pilhavazia())
			{
				p.desempilha();
			}
		}

	} while (c == 's' || c == 'S');

	return 0;
}

#endif // ex7

#ifdef ex8

/*
	8. Um pangrama é uma frase que contém pelo menos uma vez cada uma das 26 letras do novo
	   alfabeto Português. Um exemplo de pangrama é: 

	   “UM PEQUENO JABUTI XERETA CHAMADO KYA VIU DEZ CEGONHAS FELIZES E GRITOU IWUP, IWUP!”

	   Construa uma aplicação que recebe uma frase e verifica se ela é pangrama (utilize os conceitos de listas e strings da linguagem C++).
	
	   Frases para teste:

	•	jackdawf loves my big quartz sphinx
	•	abcdefghijklmnopqrstuvwxyz
	•	the quick brown fox jumps over a lazy dog
	•	jackdaws loves my big sphinx of quartz
	•	hello world
	•	esta frase es muy larga y contiene todas las letras  abc def ghij klmnopqr stu vw x y zzzzz
	•	supercalifragilistico espialidoso
	•	alfa beta gamma delta epsilon iotta kappa lambda
*/

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	Pilha_Lig<char> p;
	string frase;
	char c;

	do
	{
		system("cls");

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t VERIFICADOR DE PANGRAMA" << endl;

		cout << "\n\n\t\t INSIRA A FRASE A SER VERIFICADA: ";
		getline(cin, frase);

		unsigned i = 0;

		int M = 65; // A
		int m = 97; // a

		for (i; i < frase.length(); i++)
		{
			c = frase.at(i);

			if (M != 91) // [ --> primeiro simbolo depois do Z
			{
				if (c == M || c == m)
				{
					p.empilha(c);

					M++; 
					m++; 

					i = -1;
				}
			}
			else
			{
				i = frase.length();
			}
		}

		if (p.elementodotopo() == 'z' || p.elementodotopo() == 'Z')
		{
			SetConsoleTextAttribute(color, 11);

			cout << "\n\n\t\t A FRASE É UM PANGRAMA!!!" << endl;

			Sleep(3000);
		}
		else
		{
			SetConsoleTextAttribute(color, 12);

			cout << "\n\n\t\t A FRASE NÃO É UM PANGRAMA!!!" << endl;

			Sleep(3000);
		}

		SetConsoleTextAttribute(color, 15);

		cout << "\n\n\t\t DESEJA VERIFICAR OUTRA FRASE? S/N ";
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
		else
		{
			while (!p.pilhavazia())
			{
				p.desempilha();
			}
		}

	} while (c == 's' || c == 'S');

	return 0;
}

#endif // ex8

