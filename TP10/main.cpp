// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#include<iostream>
#include<iomanip>
#include<locale>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include"recursiva.h"
#include"hashing.h"

#define ex7

using namespace std;

#ifdef ex5

int main()
{
	cout << "\n mt(2,5) = " << mt(2, 5) << endl;

	return 0;
}

#endif // ex5

#ifdef ex7

int main()
{
	setlocale(LC_ALL, "Portuguese");

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	Node* aux;
	Hash h;

	h.insere(10);
	h.insere(2);
	h.insere(15);
	h.insere(5);
	h.insere(9);
	h.insere(19);
	h.insere(6);
	h.insere(11);
	h.insere(14);
	h.insere(17);
	h.insere(13);
	h.insere(24);
	h.insere(1);
	h.insere(4);
	h.insere(20);
	h.insere(18);
	h.insere(7);
	h.insere(12);
	h.insere(21);
	h.insere(22);

	for (int i = 0; i < W; i++)
	{
		aux = h.h[i];

		cout << "\n\t\t h[" << i << "]->";

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

	return 0;
}

#endif //ex7