#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista1;
    list<int> lista2;
    list<int> lista3;
    list<int>::iterator p1;
    list<int>::iterator p2;
    list<int>::iterator p3;
    int x;
    
    cin >> x;
    while(x != 0)
    {
        lista1.push_back(x);
        cin >> x;
    }
    
    cin >> x;
    while(x != 0)
    {
        lista2.push_back(x);
        cin >> x;
    }
    
    while(!lista1.empty() || !lista2.empty())
    {
        p1 = lista1.begin();
        p2 = lista2.begin();
        
        if(*p1 < *p2 || lista2.empty())
        {
            lista3.push_back(*p1);
            lista1.pop_front();
        }
        else if(*p1 > *p2 || lista1.empty())
        {
            lista3.push_back(*p2);
            lista2.pop_front();
        }
        else
        {
            lista3.push_back(*p1);
            lista1.pop_front();
            lista2.pop_front();
        }
    }
    
    for(p3 = lista3.begin(); p3 != lista3.end(); p3++)
    {
        cout << *p3 << " ";
    }
    
    while(!lista3.empty())
        lista3.pop_front();
    
    
    
    return 0;
}
