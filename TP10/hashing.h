// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef hashing
#define hashing
#define W 3 // tamanho do vetor

struct Node
    {       
        int info;
        Node* prox;
    };

struct Hash
{
    Node* h[W];

    Hash() 
    {
        for (int i = 0; i < W; i++)
        {
            h[i] = NULL;
        }
    }

    int fht(int x)
    {
        return x % W;
    }

   void insere(int x) 
    {
        int p = fht(x); // qual lista
        Node* aux = new Node;
        Node* aux2;

        aux->info = x;

        if (h[p] == NULL || x <= h[p]->info) 
        {
            aux->prox = h[p];
            h[p] = aux;
        }
        else 
        {
            aux2 = h[p];

            while (aux2->prox != NULL && x > aux2->prox->info) 
            {
                aux2 = aux2->prox;
            }

            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }
};

#endif // hashing
