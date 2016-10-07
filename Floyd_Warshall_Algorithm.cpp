// Floyd_Warshall_Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Graph_Functions.h"
#include <fstream>
#include <algorithm> // For std::min

//#include <limits>

void FloydWarshall(std::vector<std::vector<int>> &adjMatrix, std::vector<std::vector<int>> &shPaths); // Calculates shortest paths in a weighted graph

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::vector<int>> matrix; // Original matrix of a graph
	std::vector<std::vector<int>> shPaths; // Shortest paths in the graph

	ReadMatrix("matrix.txt", matrix); // Reads a matrix from the file
	MatrixOutput(matrix); // Outputs a graph in matrix form

	FloydWarshall(matrix, shPaths);

	std::cout << "\nEnd.";


	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores everything until it encounters newline or fills the stream
	std::cin.get(); // Usually newline remains on the stream after cin

	return 0;
}

// ------------------ FLOYD-WARSHALL ALGORITHM ------------------

void FloydWarshall(std::vector<std::vector<int>> &adjMatrix, std::vector<std::vector<int>> &shPaths)
{
	std::cout << "\n\n\t---------- Floyd-Warshall ----------" << std::endl;

	ReadMatrix("matrix.txt", shPaths); // In the beginning, matrix of shortest paths is equal to the adjacency matrix from the file

	int n = adjMatrix.size(); // Koliko vozlisc imamo

	std::cout << "\nNumber of vertices in a given graph: " << n << std::endl;

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				shPaths[i][j] = std::min(shPaths[i][j], shPaths[i][k] + shPaths[k][j]); // Picks a cheaper/shorter edge
			}
		}
	}

	std::cout << "\nShortest paths in a weighted graph presented in matrix form: " << std::endl;

	MatrixOutput(shPaths);

	std::cout << "\n\n\t------------------------------------" << std::endl;
}

