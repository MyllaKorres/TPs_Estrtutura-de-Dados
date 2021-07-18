// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef fila
#define fila

template<typename Tipo>

class Fila
{
private:
	int fim, inic;
	unsigned qnt;
	unsigned tamanho;
	Tipo* v;

public:
	Fila(unsigned tam)
	{
		fim = -1;
		inic = 0;
		qnt = 0;
		tamanho = tam;
		v = new Tipo[tamanho];
	}

	~Fila()
	{
		delete[]v;
	}

	void insere(Tipo x)
	{
		fim++;
		// liga o início e o fim do vetor,
		// como se fosse um círculo
		if (fim == tamanho)
		{
			fim = 0;
		}
		v[fim] = x;
		qnt++;
	}

	Tipo remove()
	{
		Tipo rem = v[inic];
		inic++;
		if (inic == tamanho)
		{
			inic = 0;
		}
		qnt--;

		/*

		// funciona, porém se for um vetor grande,
		// ia levar muito tempo para executar.

		for (int i = 0; i <= fim; i++)
		{
			v[i] = v[i + 1];
		}
		fim--;
		qnt--;

		*/

		return rem;
	}

	Tipo primeiro()
	{
		return v[inic];
	}

	bool filacheia()
	{
		return qnt == tamanho;
	}

	bool filavazia()
	{
		return qnt == 0;
	}

	int getFim()
	{
		return fim;
	}

	int getInic()
	{
		return inic;
	}

	int getQnt()
	{
		return qnt;
	}

	Tipo getValor(unsigned pos)
	{
		return v[pos];
	}

	unsigned getTamanho()
	{
		return tamanho;
	}
};

#endif // fila
