// Mylla Cristhina Rodrigues da Costa Abreu Korres - 0050482011032

#ifndef lista_ordenada
#define lista_ordenada

template <typename Tipo>

struct Node
    {       
        Tipo info;
        Node<Tipo>* prox;
    };

template <typename Tipo>

struct ListaOrdenada 
{
    Node<Tipo>* h;

    ListaOrdenada() 
    {
        h = NULL;
    }

    bool listavazia() 
    {
        return h == NULL;
    }

    void insere(Tipo x) 
    {
        Node<Tipo>* aux = new Node<Tipo>;
        Node<Tipo>* aux2;

        aux->info = x;

        if (h == NULL || x < h->info) 
        {
            aux->prox = h;
            h = aux;
        }
        else 
        {
            aux2 = h;

            while (aux2->prox != NULL && x > aux2->prox->info) 
            {
                aux2 = aux2->prox;
            }

            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    bool remove(Tipo x)
    {
        Node<Tipo>* aux = new Node<Tipo>;

        aux = h;

        if (h->info == x)
        {
            h = h->prox;
            delete aux;

            return true;
        }
        else
        {
            while (aux->prox != NULL && aux->prox->info <= x)
            {
                if (x == aux->prox->info)
                {
                    Node<Tipo>* aux2 = new Node<Tipo>;
                    aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete aux2;

                    return true;
                }
                aux = aux->prox;
            }
        }
        return false;
    }

    int busca(Tipo x) 
    {
        int pos = 0;
        Node<Tipo>* aux = h;

        while (aux != NULL && aux->info <= x)
        {
            pos++;

            if (x == aux->info)
            {
                return pos;
            }

            aux = aux->prox;
        }
        return 0;
    }
};

#endif // lista_ordenada
