#include <QCoreApplication>
#include <fstream>
#include "grafo.h"
using namespace std;

#define TAM 28427

int main(void)
{
	setlocale(LC_ALL, "");

	Grafo grafo;
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

			// Lê linha do arquivo;
			arq >> linha;
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

			grafo.setAdjacencias(m_resid+"--->"+m_dest);

			linha.erase();
			m_resid.clear();
			m_dest.clear();
			linhaAtual++;
		}
	}
	grafo.showAdj();
	return 0;
}
