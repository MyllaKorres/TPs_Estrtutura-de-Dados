// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef pilha_recursiva
#define pilha_recursiva
#include<cmath>

double fat(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fat(n - 1);
	}
}

double fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int mdc(int m, int n)
{
	if (m == n)
	{
		return m;
	}
	else if (m < n)
	{
		return mdc(n, m);
	}
	else
	{
		return mdc(m - n, n);
	}
}

int s(int m, int n)
{
	if (m == n)
	{
		return m;
	}
	else if (m < n)
	{
		return s(m, n - 1) + n;
	}
}

int s2(int m, int n)
{
	if (m == n)
	{
		return m;
	}
	else if (m < n)
	{
		return m + s2(m + 1, n);
	}
}

int dig(int n)
{
	if (abs(n) <= 9)
	{
		return 1;
	}
	else
	{
		return 1 + dig(n / 10);
	}
}

double pot(int m, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		return 1 / pot(m, abs(n));
	}
	else
	{
		return m * pot(m, n - 1);
	}
}

#endif // pilha_recursiva
