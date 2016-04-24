// projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenerateGraph.h"

int main()
{
	GenerateGraph generategraph(5, 70);
	cout << endl;
	generategraph.makeMatrixIncycencji();
	generategraph.printMatrixI();
	cout << endl;
	generategraph.makeMatrixS();
	generategraph.printMatrixS();

    return 0;
}

