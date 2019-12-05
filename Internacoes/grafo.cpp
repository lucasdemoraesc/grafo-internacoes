#include "grafo.h"

Grafo::Grafo()
{

}

Grafo::Grafo(int v) {
	this->v = v;
	aresta = new list<int>[v];
	peso = new int[v];
	qtdArestas = 0;
}

void Grafo::adicionaAresta(int i, int v1, int v2) {
	if(aresta[0].empty()) {
		// Adiciona vértice v2 à lista de vértices adjacentes de v1
		aresta[qtdArestas].push_back(v2);
		aresta[qtdArestas].push_back(v1);
		qtdArestas++;
		peso[0] = 1;
	}
	else {
		int cont = 0;
		list<int>::iterator it;

		while(cont < i) {
			it = aresta[cont].begin();
			if(*it == v1 && *it++ == v2) {
				peso[cont] += 1;
				break;
			}
			else {

				if(cont == qtdArestas) {
					// Adiciona vértice v2 à lista de vértices adjacentes de v1
					aresta[qtdArestas].push_back(v2);
					aresta[qtdArestas].push_back(v1);
					qtdArestas++;
					peso[qtdArestas-1] += 1;
					break;
				}
			}
			cont++;
		}
	}
}

int Grafo::getQtdArestas()
{
	return qtdArestas;
}

int Grafo::getPeso(int aresta)
{
	return peso[aresta];
}

list<int>::iterator Grafo::getAresta(int i)
{
	return aresta[i].begin();
}
