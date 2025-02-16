#include <iostream>
using namespace std;

// Definindo a estrutura do nó da árvore
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Função para criar um novo nó na árvore
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inserir um novo nó na árvore
Node *insert(Node *root, int data)
{
    // Caso a raiz seja nula, criamos um novo nó com o dado fornecido
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }

    // Se o dado fornecido for menor que o dado da raiz, inserimos na subárvore esquerda
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    // Se o dado fornecido for maior que o dado da raiz, inserimos na subárvore direita
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para verificar se um dado está presente na árvore
bool search(Node *root, int data)
{
    // Caso a raiz seja nula ou o dado da raiz seja igual ao dado procurado, retorna true
    if (root == NULL || root->data == data)
    {
        return root != NULL; // Retorna true se encontrou o valor ou false se a raiz for nula
    }

    // Se o dado fornecido for menor que o dado da raiz, procura na subárvore esquerda
    if (data < root->data)
    {
        return search(root->left, data);
    }
    // Se o dado fornecido for maior que o dado da raiz, procura na subárvore direita
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    Node *root = NULL;
    int N; // Quantidade de números a serem inseridos na árvore
    int num; // Número a ser inserido na árvore
    int X; // Número a ser procurado na árvore

    // Lendo a quantidade de números a serem inseridos
    cin >> N;

    // Lendo os números e inserindo na árvore
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        root = insert(root, num);
    }

    // Lendo o número a ser procurado
    cin >> X;

    // Verificando se o número está na árvore
    if (search(root, X))
    {
        cout << "Encontrado" << endl;
    }
    else
    {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
