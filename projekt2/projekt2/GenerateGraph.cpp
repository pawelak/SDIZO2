#include "stdafx.h"
#include "GenerateGraph.h"




GenerateGraph::GenerateGraph(int nodes, float density)
{
	this->nodes = nodes;
	zakresWagi = 9;
	int minK = nodes - 1;			//¿eby by³ graf musi mieæ minium tyle to jest w zasadzie drzewo w tedy
	maxK = ((nodes - 1)*nodes) / 2;	//to jest maksymalna liczna krawêdzi dla grafu
	int ileMinGestosc = ceil((minK / maxK) * 100);
	ileK = ceil(maxK*(density / 100));		//tyle chcemy krawêdzi
	int waga;
	wynik = new int *[ileK];
	//vector <int, int> wynik;
	//vector <vector <int>> wynik(ileK,vector<int>(3));
	//wynik(ileK, vector<int>(3));
	//matrix = <vector<vector<int>>(CAPACITY, <vector<int>


	if (density > ileMinGestosc && density<100 )
	{	
		//cout << minK << " " << maxK << " " << ileMinGestosc << " " << ileK <<  endl;
		vector <int> tab;
		
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
			wynik[i-1] = new int[3];
			wynik[i-1][0] = poprzedni;
			wynik[i-1][1] = nastepny;
			waga = (rand() % zakresWagi) + 1;
			wynik[i - 1][2] = waga;
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
					wynik[i] = new int[3];
					wynik[i][0] = poprzedni;
					wynik[i][1] = nastepny;
					waga = rand() % zakresWagi + 1;
					wynik[i][2] = waga;
					//cout << wynik[i][0] << " " << wynik[i][1] << endl;
					break;
				}
			}
			
		}

		for (int i = 0; i < ileK; i++)
		{
			cout << wynik[i][0] << " " << wynik[i][1] << " " << wynik[i][2] <<  endl;
		}

	}
	else
	{
		cout << "blendna gestosc " << endl;
	}

	fstream plik("plik.txt", ios::out);
	if (plik.good())
	{
		plik << nodes << " " << ileK << "\n";
		for (int i = 0; i < ileK; i++)
		{
			plik << wynik[i][0] << " " << wynik[i][1] <<" " << wynik[i][2] << "\n";
		}
		plik.close();
	}	
}


void GenerateGraph::makeMatrixIncycencji()
{

	this->matrix = new int *[nodes];
	cout << " tak bartoszu:" << endl;

	for (int i = 0; i < nodes; i++)
	{
		matrix[i] = new int[ileK];
	}

	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < ileK; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < ileK; i++)
	{
		int pocz = wynik[i][0];
		int kon = wynik[i][1];
		matrix[pocz][i] = 1;
		matrix[kon][i] = 1;

		/*int x = wynik[i][0];
		int y = wynik[i][1];
		this->matrix[x][y] = 1;*/
	}
}

void GenerateGraph::makeMatrixS()
{

	this->matrix = new int *[nodes];

	for (int i = 0; i < nodes; i++)
	{
		matrix[i] = new int[nodes];
	}

	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < ileK; i++)
	{
		int pocz = wynik[i][0];
		int kon = wynik[i][1];
		matrix[pocz][kon] = 1;
	}
}



void GenerateGraph::printMatrixI()
{
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < ileK; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


void GenerateGraph::printMatrixS()
{
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
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
int mini = nodes - 1;			//¿eby by³ graf musi mieæ minium tyle to jest w zasadzie drzewo w tedy
int max = ((nodes - 1)*nodes) / 2;	//to jest maksymalna liczna krawêdzi dla grafu
int ile = ceil(max*density);		//tyle chcemy krawêdzi
int **wynik = new int *[ile];	//tu bêda ³adne pary reprezentuj¹ce krawêdzie potem dolosujê wagi
int *tab = new int[ile];		// tu na potrzeby drzewa, cudo które pamiêta przez co ju¿ przeszliœmy
for (int i = 0; i < ile; i++)
{
tab[i] = NULL;			//zerowanie bo te piepszone dynamiczne gówna s¹ nie zerowane chyba
}
srand(time(NULL));				//ogólnie to lipa i nei wiem jak zrobiæ graf dlatego zrobiê drzewo ¿eby graf by³ spójny a potem siê dolosuje do zadanej gêstoœci
int los,edge=0;					// licznik krwêdzi x
int tmp= rand() % nodes+1;		//losuje pierwszy element od 1 sa numerowane
tab[0] = tmp;

//cout << mini << " " << max << " " << ile << " " << tab[0]  << " " << edge << " " << tmp  << endl;
for (int i = 0; i < mini-1; i++) //bo wzór na drzewo spinaj¹ce jest n-1
{
while (true)		//bardzo pojebane ale innymi s³owy losuje a¿ nie wylosuje czegoœ oryginalnego
{					//czyli wierzcho³ka przez który jeszcze nie przechodzi³o
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

for (int i = edge+1; i < ile-1; i++)		//bo krwêdzie sa od 0 numerowane
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