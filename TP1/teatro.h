// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef teatro
#define teatro

template<typename Tipo>

class Lugares
{
private:
	int vagas;
	int linha;
	int coluna;
	Tipo* m;

public:
	Lugares(int i, int j)
	{
		linha = i;
		coluna = j;
		vagas = linha * coluna;
		m = new Tipo[vagas];

		for (i = 0; i < linha; i++)
		{
			for (j = 0; j < coluna; j++)
			{
				m[i * coluna + j] = '-';
			}
		}
	}

	~Lugares()
	{
		delete[]m;
	}

	void reserva(int i, int j)
	{
		m[i * coluna + j] = 'X';
	}

	void cancela(int i, int j)
	{
		m[i * coluna + j] = '-';
	}

	void troca(int i, int j, int x, int y)
	{
		m[i * coluna + j] = '-';
		m[x * coluna + y] = 'X';
	}

	Tipo getDisp()
	{
		int cont = 0;

		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j < coluna; j++)
			{
				if (m[i * coluna + j] == '-')
				{
					cont++;
				}
			}
		}

		return cont;
	}

	Tipo getValor(int i, int j)
	{
		return m[i * coluna + j];
	}
};

#endif // teatro