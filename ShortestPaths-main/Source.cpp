#include "DirectedGraph.h"
#include<chrono>
#include<fstream>
#include <iomanip>// std::setprecision

using namespace std;
DirectedGraph* readGraph(int size, int s, int t);
bool validInput(int size, int s, int t);
void addArchesFromString(string line, DirectedGraph* dGraph, int size);
void checkSize(int size);
void checkS(int s, int size);
void checkT(int t, int size);
void checkVertex(int vertex, int  size);
string extractVertexesFromString(string line, int* vertex);
DirectedGraph* getInput(int*s,int*t);
void shortWayFrom2Points(int s, int t, DirectedGraph*graph);
int countDigits(int num);
int main() {
	int s, t;
	DirectedGraph*graph= getInput(&s,&t);
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	shortWayFrom2Points(s,t, graph);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	cout << "Time taken by function <shortWayFrom2Points> is : " << fixed << time_taken << setprecision(9);
	cout << " sec" << endl;
	
}


void checkSize(int size)
{
	if (size <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}

void checkS(int s, int size)
{
	if (s <= 0 || s > size)
	{
		cout << "invalid input" << endl;
		exit(1);

	}
}

void checkT(int t, int size)
{
	if (t <= 0 || t > size)
	{
		cout << "invalid input" << endl;
		exit(1);
	}

}

void checkVertex(int vertex, int  size)
{
	if (vertex <= 0 || vertex > size)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}



DirectedGraph* readGraph(int size, int s, int t) {
	DirectedGraph* dGraph = nullptr;
	string line;
	dGraph = new DirectedGraph(size);
	cin.clear();
	while (!cin.eof()) {
		getline(cin, line);
		if (cin.fail()) {
			//error
			break;
		}
		addArchesFromString(line, dGraph, size);

	}
	//dGraph->PrintGraph();

	return dGraph;
}

bool validInput(int size, int s, int t)
{

	return true;
}

void addArchesFromString(string line, DirectedGraph* dGraph, int size) {

	int i, j;
	while (line.size()>1){
		line = extractVertexesFromString(line, &i);
		line = extractVertexesFromString(line, &j);
		checkVertex(i, size);
		checkVertex(j, size);
		if (!dGraph->AddEdge(i, j)) {
			cout << "invalid input";
			exit(1);
		}
	}
}

string extractVertexesFromString(string line, int* vertex) {


	// For atoi, the input string has to start with a digit, so lets search for the first digit
	int k = 0;
	for (; k < line.length(); k++) { if (isdigit(line[k])) break; }

	// remove the first chars, which aren't digits
	line = line.substr(k, line.length() - k);

	// convert the remaining text to an integer
	 *vertex = atoi(line.c_str());
	int numOfDigits = countDigits(*vertex);
	line = line.substr(numOfDigits, line.length() - numOfDigits);
	return line;
}
DirectedGraph* getInput(int*s, int*t) {
	DirectedGraph* dGraph = nullptr, *dGraphTranspose = nullptr, *finalGraph = nullptr;
	int size, s2, t2, *distanceArray, *distanceArrayTranspose;
	cin >> size;
	checkSize(size);
	cin >> s2;
	checkS(s2, size);
	cin >> t2;
	checkT(t2, size);
	dGraph = readGraph(size, s2, t2);
	*s = s2;
	*t = t2;
	return dGraph;
}
void shortWayFrom2Points(int s,int t, DirectedGraph*dGraph){
	DirectedGraph *dGraphTranspose = nullptr, *finalGraph = nullptr;
	int size, s2, t2, *distanceArray, *distanceArrayTranspose;
	distanceArray = dGraph->BFS(s);//running BFS and return the distane array from vertex s
	dGraph->updateGraph(distanceArray); //grafh after after condition d[v] = d[u]+1
	//dGraph->PrintGraph();
	dGraphTranspose = dGraph->buildGraphT();// build transpose graph
	//dGraph->PrintGraph();//print grafh after after conditiov d[v] = d[u]+1
	//cout << endl;
	//cout << "graph T " << endl;
	//dGraphTranspose->PrintGraph();// print transpose graph
	distanceArrayTranspose = dGraphTranspose->BFS(t);
	dGraphTranspose->updateGraph(distanceArrayTranspose);
	//dGraphTranspose->PrintGraph();
	finalGraph = dGraphTranspose->buildGraphT();
	finalGraph->PrintGraph();
}


int countDigits(int num)
{
	int count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}
		
	


	
	




