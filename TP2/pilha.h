// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef pilha
#define pilha

template<typename Tipo>

class Pilha
{
private:
	Tipo* v;
	unsigned tamanho;
	int topo;

public:
	Pilha(unsigned tam)
	{
		tamanho = tam;
		v = new Tipo[tamanho];
		topo = -1;
	}

	~Pilha()
	{
		delete[]v;
	}

	void empilha(Tipo x)
	{
		topo++;
		v[topo] = x;
	}

	Tipo desempilha()
	{
		Tipo temp = v[topo];
		topo--;
		return temp;
	}

	Tipo elementodotopo()
	{
		return v[topo];
	}

	bool pilhacheia()
	{
		return topo == tamanho - 1;
	}

	bool pilhavazia()
	{
		return topo == -1;
	}

	unsigned getTopo()
	{
		return topo;
	}

	unsigned getTamanho()
	{
		return tamanho;
	}

	Tipo getValor(unsigned pos)
	{
		return v[pos];
	}
};

#endif // pilha
