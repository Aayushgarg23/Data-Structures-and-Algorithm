#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){   

        this->V = V;
        l = new list<int>[V];
    }