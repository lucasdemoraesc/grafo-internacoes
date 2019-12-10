#ifndef GRAFO_H
#define GRAFO_H

#include <QHash>
#include <iostream>

using namespace std;

class Grafo {
private:
	QHash<QString, int> hashAdj;

public:
	Grafo();
	void setAdjacencias(QString v);
	void showAdj();
};

#endif // GRAFO_H
