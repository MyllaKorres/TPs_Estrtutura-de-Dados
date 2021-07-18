// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef arvore_binaria_busca
#define arvore_binaria_busca

#include<iostream>

using namespace std;

template<typename Tipo>

struct Node
{
	Tipo info;
	Node <Tipo>* pEsq;
	Node <Tipo>* pDir;
};

template<typename Tipo>

struct BST // binary surch tree 
{
	Node <Tipo>* pRaiz;

	BST()
	{
		pRaiz = NULL;
	}

	void insere(Node<Tipo>*& t, Tipo x)
	{
		if (t == NULL)
		{
			t = new Node<Tipo>;
			t->info = x;
			t->pEsq = NULL;
			t->pDir = NULL;
		}
		else
		{
			if (x < t->info)
			{
				insere(t->pEsq, x);
			}
			else
			{
				insere(t->pDir, x);
			}
		}
	}

	void remove(Node<Tipo>*& t, Tipo x)
	{
		if (t != NULL)
		{
			if (t->info > x)
			{
				remove(t->pEsq, x);
			}
			else if (t->info < x)
			{
				remove(t->pDir, x);
			}
			else
			{
				if (t->pEsq == NULL && t->pDir == NULL)
				{
					Node <Tipo>* aux = t;
					t = NULL;
					delete aux;
				}
				else if (t->pEsq == NULL)
				{
					Node <Tipo>* aux = t;
					t = t->pDir;
					delete aux;
				}
				else if (t->pDir == NULL)
				{
					Node<Tipo>* aux = t;
					t = t->pEsq;
					delete aux;
				}
				else
				{
					Node<Tipo>* aux = t->pEsq;

					while (aux->pDir != NULL)
					{
						aux = aux->pDir;
					}

					t->info = aux->info;
					aux->info = x;
					remove(t->pEsq, x);
				}
			}
		}
	}

	bool bstvazia()
	{
		return pRaiz == NULL;
	}

	/*bool confere(Node<Tipo>* t, Tipo x)
	{
		if (t != NULL)
		{
			if (x == t->info)
			{
				return true;
			}
			confere(t->pEsq);
			confere(t->pDir);
		}
		return NULL;
	}*/


	void preOrdem(Node<Tipo>* t) // R E D
	{
		if (t != NULL)
		{
			cout << t->info << " ";
			preOrdem(t->pEsq);
			preOrdem(t->pDir);
		}
	}

	void posOrdem(Node<Tipo>* t) // E D R
	{
		if (t != NULL)
		{
			posOrdem(t->pEsq);
			posOrdem(t->pDir);
			cout << t->info << " ";
		}
	}

	void emOrdem(Node<Tipo>* t) // E R D
	{
		if (t != NULL)
		{
			emOrdem(t->pEsq);
			cout << t->info << " ";
			emOrdem(t->pDir);
		}
	}

	Tipo menor(Node<Tipo>* t)
	{
		if (t != NULL)
		{
			if (t->pEsq != NULL)
			{
				return menor(t->pEsq);
			}
			else
			{
				return t->info;
			}
		}
		else
		{
			return NULL;
		}
	}

	Tipo maior(Node<Tipo>* t)
	{
		if (t != NULL)
		{
			if (t->pDir != NULL)
			{
				return maior(t->pDir);
			}
			else
			{
				return t->info;
			}
		}
		else
		{
			return NULL;
		}
	}
};

#endif // arvore_binaria_busca