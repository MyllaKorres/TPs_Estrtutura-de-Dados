// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef pilha_ligada
#define pilha_ligada

template <typename Tipo>

struct Node
{
	Tipo info;
	Node<Tipo>* prox;
};

template <typename Tipo>

class Pilha_Lig
{
private:
	Node<Tipo>* topo;
public:
	Pilha_Lig()
	{
		topo = NULL;
	}

	bool empilha(Tipo x)
	{
		bool v = true;

		Node<Tipo>* aux = new Node<Tipo>;

		if (aux == NULL)
		{
			v = false;
		}
		else
		{
			aux->info = x;
			aux->prox = topo;
			topo = aux;
		}

		return v;
	}

	Tipo desempilha()
	{
		Tipo temp = topo->info;

		Node<Tipo>* aux = topo;
		topo = topo->prox;
		delete aux;

		return temp;
	}

	Tipo elementodotopo()
	{
		return topo->info;
	}

	bool pilhavazia()
	{
		return topo == NULL;
	}

	Node<Tipo>* getTopo()
	{
		return topo;
	}

};

#endif // pilha_ligada
