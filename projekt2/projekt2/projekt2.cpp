// projekt2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "GenerateGraph.h"

using namespace std;

int main()
{
	GenerateGraph generategraph(20, 70);
	cout << endl;
	//generategraph.makeMatrixIncycencji();
	//generategraph.printMatrixI();
	cout << endl;
	//generategraph.makeMatrixS();
	//generategraph.printMatrixS();

	cout << endl;
	generategraph.makeMatrixW();
	cout << endl;
	generategraph.prim();


	system("PAUSE");

    return 0;
}

