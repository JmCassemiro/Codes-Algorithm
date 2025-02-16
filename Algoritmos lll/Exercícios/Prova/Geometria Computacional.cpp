#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

// Função dada na questão

typedef struct
{
    int x;
    int y;
} Ponto;

double area_triangulo(
    Ponto a,
    Ponto b,
    Ponto c)
{
    return ((a.x * b.y) - (a.y * b.x) +
            (a.y * c.x) - (a.x * c.y) +
            (b.x * c.y) - (b.y * c.x)) /
           2.0;
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c)
{
    double area = area_triangulo(a, b, c);
    if (area > 0)
    {
        return 1;
    }
    else if (area < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    Ponto p1, p2, p3; // 3 pontos pedidos na questão

    int dist; // Variável pro diametro e distancia entre os ponto

    // Entrada de dados com os 3 pontos, valor em x e y

    cin >> p1.x >> p1.y;

    cin >> p2.x >> p2.y;

    cin >> p3.x >> p3.y;

    // Chamando a função

    dist = distancia(p1, p2);

    // Saida de dados

    cout << dist << endl;

    return 0;
}