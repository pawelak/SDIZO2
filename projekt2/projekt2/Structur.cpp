#include "stdafx.h"
#include "Structur.h"


Structur::Structur()
{
	deque<graf*> kolejka;
	fstream plik;
	plik.open("plik.txt", ios::in);
	if (plik.is_open())
	{
		
		plik >> nodes;
		plik >> edges;
		while (plik.eof())
		{
			graf *data = new graf;
			plik >> data->idSour;
			plik >> data->idDest;
			plik >> data->waga;
			kolejka.push_front(data);
		}

	}
}


Structur::~Structur()
{
}
