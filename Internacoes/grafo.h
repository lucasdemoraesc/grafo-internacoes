#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Grafo {
private:
	int v;	// Número de vértices
	list<int> *aresta;	// Lista de arestas
	int *peso;
	int qtdArestas;

public:
	Grafo();
	Grafo(int v);
	void adicionaAresta(int i, int v1, int v2);

	int getQtdArestas();
	int getPeso(int aresta);
	list<int>::iterator getAresta(int i);
	void getPesos();
};


#endif // GRAFO_H
