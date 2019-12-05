#include <QCoreApplication>
#include <fstream>
#include <string.h>
#include "grafo.h"

using namespace std;

#define TAM 28427

int main(void)
{
	setlocale(LC_ALL, "");

	Grafo grafo(TAM);
	ifstream arq("rdgo1201.csv");	// Arquivo usado
	string linha;					// String para armazenar o conteúdo da linha lida
	QString m_resid;				// String para armazenar o municipio de residencia
	QString m_dest;					// String para armazenar o municipio de destino
	int linhaAtual = 0;				// O indice da linha atual
	bool passouVirgula;				// Variável para auxiliar na quebra de linha

	if(arq.fail()) {
		cout << "Erro ao abrir arquivo: " << arq.fail() << endl;
		return 1;
	}

	// Percorrer linhas do arquivo
	if(arq.is_open() && arq.good()) {
		while(!arq.fail() && linhaAtual < TAM) {

			arq >> linha;	// Lê linha do arquivo;
			passouVirgula = false;

			// Quebrar linha para dividir municipio de residencia e destino
			// Caracteres antes da virgula, residencia. Depois da virgula, destino
			for(unsigned i = 0; i < linha.length(); i++) {
				if(!passouVirgula && linha.at(i) != ',')
					m_resid += linha.at(i);
				else {
					if (linha.at(i) != ',')
						m_dest += linha.at(i);
					else
						passouVirgula = true;
				}
			}

			grafo.adicionaAresta(linhaAtual, m_resid.toInt(), m_dest.toInt());

			linha.erase();
			m_resid.clear();
			m_dest.clear();

			linhaAtual++;
		}
	}

	cout << "Quantidade de arestas: " << grafo.getQtdArestas() << endl;
	list<int>::iterator it;
	for(int i = 0; i < grafo.getQtdArestas(); i++) {
		it = grafo.getAresta(i);
		cout << "Aresta " << i << ": [" << *it << "]---->[" << *it++ << "]\tPeso: " << grafo.getPeso(i) << endl;
	}
	return 0;
}
