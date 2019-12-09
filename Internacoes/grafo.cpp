#include "grafo.h"

Grafo::Grafo()
{

}

void Grafo::setAdjacencias(QString v1, QString v2)
{
	/****************************************************************************************\
	Cria um hash para a matriz de adjacências.
	O hash suporta multiplos valores para uma chave, sendo que:
		1) O primeiro valor na chave representa o vértice de partida no grafo direcionado;
		2) O segundo valor na chave representa o vértice de destino;
		3) O terceiro valor na chave representa o peso;
		4) A chave representa o índice.
	\****************************************************************************************/

	if(hashAdj.contains(v1+"_"+v2)) {
		int peso = hashAdj.value(v1+"_"+v2);
		hashAdj.replace(v1+"_"+v2, peso+1);
	}
	else {
		hashAdj.insert(v1+"_"+v2, v1.toInt());
		hashAdj.insert(v1+"_"+v2, v2.toInt());
		hashAdj.insert(v1+"_"+v2, 1);
	}
}

QList<int> Grafo::getListAdj()
{
	QList<int> adj[hashAdj.size()];
	int i = 0;
	QMultiHash<QString, int>::iterator it = hashAdj.begin();
	while(it != hashAdj.end() && i < hashAdj.size()) {
		adj[i] = hashAdj.values(it.key());
		++it;
	}
	return *adj;
}

int Grafo::size()
{
	return hashAdj.size();
}

