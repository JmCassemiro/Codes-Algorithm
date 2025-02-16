#include <iostream>

using namespace std;

typedef struct
{
    int x;
    int y;
} ponto;

double Area_triangulo(ponto a, ponto b, ponto c)
{
    double A;

    A = (a.x * b.y) - (a.y * b.x) + (a.y * c.x) - (a.x * c.y) + (b.x * c.y) - (b.y * c.x);

    return A / 2.0;
}

int main()
{
    ponto p1, p2, p3, p;
    double Y1, Y2, Y3;
    double area, area1, area2, area3;

    for (int i = 0; i < 3; i++)
    {
        cout << "Entre com as coordenadas do ponto 1 (x, y): ";
        cin >> p1.x >> p1.y;

        cout << "Entre com as coordenadas do ponto 2 (x, y): ";
        cin >> p2.x >> p2.y;

        cout << "Entre com as coordenadas do ponto 3 (x, y): ";
        cin >> p3.x >> p3.y;

        cout << "Entre com as coordenadas do ponto p (x, y): ";
        cin >> p.x >> p.y;

        area = Area_triangulo(p1, p2, p3);
        area1 = Area_triangulo(p, p2, p3);
        area2 = Area_triangulo(p1, p, p3);
        area3 = Area_triangulo(p1, p2, p);

        Y1 = area1 / area;
        Y2 = area2 / area;
        Y3 = area3 / area;

        cout << "Y1: " << Y1 << endl;
        cout << "Y2: " << Y2 << endl;
        cout << "Y3: " << Y3 << endl;

        cout << endl;
    }

    return 0;
}
