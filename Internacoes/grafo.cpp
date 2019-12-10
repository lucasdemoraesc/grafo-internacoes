#include "grafo.h"

Grafo::Grafo()
{

}

void Grafo::setAdjacencias(QString v)
{
	/***********************************************************\
					Cria um hash de adjacências.
		  A chave do hash é formada pelos valores dos vértices.
			O valor em uma chave representa o peso da aresta.
	\***********************************************************/

	if(hashAdj.contains(v)) {
		int peso = hashAdj.value(v);
		hashAdj.insert(v, peso+1);
	}
	else {
		hashAdj.insert(v, 1);
	}
}

void Grafo::showAdj()
{
	QHashIterator<QString, int> i(hashAdj);
	while (i.hasNext()) {
		i.next();
		cout << "|" << i.key().toStdString() << "| Peso: " << i.value() << endl;
	}
	cout << "\nQuantidade de arestas: " << hashAdj.size() << endl;
}
