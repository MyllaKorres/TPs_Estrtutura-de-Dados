// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef pilha_recursiva
#define recursiva

double mt(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		return mt(a, b - 1) + 1;
	}
}

#endif // recursiva
