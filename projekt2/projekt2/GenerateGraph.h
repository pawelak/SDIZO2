#pragma once
#include <ctime>
#include <vector>
#include <list>
class GenerateGraph
{
private:
	int zakresWagi, minK, ileK, nodes;
	double maxK;
	
	

public:
	//vector <vector <int>> wynik (int, vector<int>(int));
	int **wynik;
	int **matrix;
	int **matrix2;


	GenerateGraph();

	GenerateGraph(int nodes, float density);
	void makeMatrixIncycencji();
	void makeMatrixS();
	void printMatixS();
	void printMatrixI();
	void printMatrixS();
	void makeMatrixW();
	void prim();
	~GenerateGraph();
};

