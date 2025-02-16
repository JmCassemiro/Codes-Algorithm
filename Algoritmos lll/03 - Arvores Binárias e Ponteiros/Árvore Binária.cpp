#include <iostream>

#include <queue>

using namespace std;

struct Card
{
    int number;
    int naipe;
};

struct Node
{

    Card data;

    Node *right;
    Node *left;
};

Node *insert(Node *root, Card data)
{

    if (root == NULL)
    {

        Node *a = new Node;

        a->data = data;
        a->right = NULL;
        a->left = NULL;
        return a;
    }

    else
    {

        if (data.number >= root->data.number)
        {

            // Ir para a direita

            root->right = insert(root->right, data);
        }

        else
        {

            // Ir para a esquerda

            root->left = insert(root->left, data);
        }
    }
    return root;
}

Node *search(Node *root, int x)
{

    if (root == NULL)
    {

        return NULL;
    }

    if (x == root->data.number)
    {

        return root;
    }

    else
    {

        if (x >= root->data.number)
        {

            return search(root->right, x);
        }
        else
        {

            return search(root->left, x);
        }
    }
}

void show_Ordem(Node *root)
{

    // Varrer a esquerda
    if (root->left != NULL)
        show_Ordem(root->left);

    // Exibir
    cout << root->data.number << endl;

    // Varrer a direita
    if (root->right != NULL)
        show_Ordem(root->right);
}

void show_levels(Node *curr)
{

    if (curr == NULL)
    {
        return;
    }

    queue<Node *> nodes;

    nodes.push(curr);

    while (!nodes.empty())
    {

        Node *aux = nodes.front();

        cout << aux->data.number << ": " << aux->data.naipe << endl;

        if (aux->left != NULL)
            nodes.push(aux->left);

        if (aux->right != NULL)
            nodes.push(aux->right);

        nodes.pop();
    }
}

// O objetivo dessa função é:
// 1 - Encontrar o nó com o menor valor
// 2 - Desconectar ele da árvore
// 3 - Retornar uma referência para esse nó
Node *disconnect_lesser(Node *&curr)
{

    Node *aux = curr;
    if (aux->left == NULL)
    {                       // encontrou o menor elemento da subárvore
        curr = curr->right; // temos que salvar os filhos da direita
        return aux;         // retornamos a referência para esse nó
    }
    else
    { // senão continua a busca na subárvore da esquerda
        return disconnect_lesser(curr->left);
    }
}

int remove(Node *&curr, int number)
{
    if (curr == NULL)
    {
        return 0;
    }
    Node *aux;
    if (curr->data.number == number)
    {
        aux = curr;
        if (curr->left == NULL)
        {
            curr = aux->right;
        }
        else if (curr->right == NULL)
        {
            curr = aux->left;
        }
        else
        {

            // Caso o nó a ser removido tenha dois filhos
            // Pedimos para encontrar o menhor nó da subárvore da direita
            // Além disso devemos disconectar esse nó da árvore
            // (não podemos esquecer de salvar os filhos desse nó)
            aux = disconnect_lesser(curr->right);
            // O nó a ser removido vai receber o valor do menor nó à direita
            curr->data = aux->data;
            // Em seguida podemos desalocar a memória desse nó
        }
        delete aux;
        return 1;
    }
    else
    {
        if (number >= curr->data.number)
        {
            return remove(curr->right, number);
        }
        else
        {
            return remove(curr->left, number);
        }
    }
}

void destruct(Node *&curr)
{

    if (curr->left == NULL)
        destruct(curr->left);

    if (curr->right == NULL)
        destruct(curr->right);

    delete curr;
    curr = NULL;
    return;
}

int main()
{

    Node *root = NULL;

    int n = 7, p, t;

    float v, e, o;

    cin >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> v >> e >> o;
        t = int(v * e * n * e * n * o);
        Card peixe;
        peixe.number = t;
        peixe.naipe = i;
        insert(root, peixe);
    }
    show_levels(root);
    destruct(root);

    return 0;
}