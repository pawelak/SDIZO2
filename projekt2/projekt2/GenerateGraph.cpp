#include "stdafx.h"
#include "GenerateGraph.h"


GenerateGraph::GenerateGraph(int nodes, float density)
{
	int minK = nodes - 1;			//�eby by� graf musi mie� minium tyle to jest w zasadzie drzewo w tedy
	double maxK = ((nodes - 1)*nodes) / 2;	//to jest maksymalna liczna kraw�dzi dla grafu
	int ileMinGestosc = ceil((minK / maxK) * 100);

	if (density > ileMinGestosc && density<100 )
	{	
		int ileK = ceil(maxK*(density/100));		//tyle chcemy kraw�dzi
		//cout << minK << " " << maxK << " " << ileMinGestosc << " " << ileK <<  endl;
		vector <int> tab;
		int **wynik = new int *[ileK];
		for (int i = 0; i < nodes; i++)
		{
			tab.push_back(i);
		}
		srand(time(NULL));
		int nastepny, poprzedni;

		poprzedni = rand() % nodes;
		tab[poprzedni]=-1;
		for (int i = 1; i < minK+1; i++)
		{
			while (true)
			{
				nastepny = rand() % nodes;
				if (tab[nastepny] >= 0)break;
				
			}
			wynik[i-1] = new int[2];
			wynik[i-1][0] = poprzedni;
			wynik[i-1][1] = nastepny;
			//cout << wynik[i-1][0] << " " << wynik[i-1][1] << endl;
			tab[nastepny] = -1;
			poprzedni = nastepny;
		}
		bool czyJest = false;
		for (int i = minK; i < ileK; i++)
		{
			while (true)
			{
				czyJest = false;
				poprzedni = rand() % nodes;
				nastepny = rand() % nodes;
				for (int j = 0; j < i; j++)
				{
					if ((wynik[j][0] == poprzedni && wynik[j][1] == nastepny) || (wynik[j][0] == nastepny && wynik[j][1] == poprzedni) || (nastepny == poprzedni))
					{
						czyJest = true;
						break;
					}
				}
				if (czyJest==false)
				{
					wynik[i] = new int[2];
					wynik[i][0] = poprzedni;
					wynik[i][1] = nastepny;
					//cout << wynik[i][0] << " " << wynik[i][1] << endl;
					break;
				}
			}
			
		}

		for (int i = 0; i < ileK; i++)
		{
			cout << wynik[i][0] << " " << wynik[i][1] << endl;
		}

	}
	else
	{
		cout << "blendna gestosc " << endl;
	}

	
	
}


GenerateGraph::~GenerateGraph()
{
}



/*
int doJakiejWagi;
if (density < 0,2 && nodes < 10)
{
cout << "blendna gestosc lub za malo wierzholkow" << endl;
}
else
{
int mini = nodes - 1;			//�eby by� graf musi mie� minium tyle to jest w zasadzie drzewo w tedy
int max = ((nodes - 1)*nodes) / 2;	//to jest maksymalna liczna kraw�dzi dla grafu
int ile = ceil(max*density);		//tyle chcemy kraw�dzi
int **wynik = new int *[ile];	//tu b�da �adne pary reprezentuj�ce kraw�dzie potem dolosuj� wagi
int *tab = new int[ile];		// tu na potrzeby drzewa, cudo kt�re pami�ta przez co ju� przeszli�my
for (int i = 0; i < ile; i++)
{
tab[i] = NULL;			//zerowanie bo te piepszone dynamiczne g�wna s� nie zerowane chyba
}
srand(time(NULL));				//og�lnie to lipa i nei wiem jak zrobi� graf dlatego zrobi� drzewo �eby graf by� sp�jny a potem si� dolosuje do zadanej g�sto�ci
int los,edge=0;					// licznik krw�dzi x
int tmp= rand() % nodes+1;		//losuje pierwszy element od 1 sa numerowane
tab[0] = tmp;

//cout << mini << " " << max << " " << ile << " " << tab[0]  << " " << edge << " " << tmp  << endl;
for (int i = 0; i < mini-1; i++) //bo wz�r na drzewo spinaj�ce jest n-1
{
while (true)		//bardzo pojebane ale innymi s�owy losuje a� nie wylosuje czego� oryginalnego
{					//czyli wierzcho�ka przez kt�ry jeszcze nie przechodzi�o
//cout << "totoot" << endl;
los = rand() % nodes + 1;
bool czyDobryWierzcholek = 1;
for (int j = 0; j < edge; j++)
{
if (tab[j] == los)czyDobryWierzcholek = 0;
cout << czyDobryWierzcholek <<  "bo "  << los <<  endl;
}
if(czyDobryWierzcholek)break;		//nooo paskudne
}
edge++;
wynik[i] = new int[2];
wynik[i][0] = tmp;
wynik[i][1] = los;
tab[i + 1] = los;
tmp = los;
}

for (int i = edge+1; i < ile-1; i++)		//bo krw�dzie sa od 0 numerowane
{
wynik[i] = new int[2];
los = rand() % nodes + 1;
wynik[i][0] = los;
los = rand() % nodes + 1;
wynik[i][1] = los;
}


fstream plik("plik.txt", ios::out);
if (plik.good())
{
plik << nodes << " " << edge << "\n";
for (int i = 1; i < ile; i++)
{
plik << wynik[i][0] << " " << wynik[i][1] << " " << "\n";
}
plik.close();
}




}

*/