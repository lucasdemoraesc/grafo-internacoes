#ifndef GRAFO_H
#define GRAFO_H

#include <QHash>
#include <QList>
#include <queue>
#include <iostream>

using namespace std;

class Grafo {
private:
	QMultiHash<QString, int> hashAdj;

public:
	Grafo();
	void setAdjacencias(QString v1, QString v2);
	QList<int> getListAdj();
	int size();

};


#endif // GRAFO_H
