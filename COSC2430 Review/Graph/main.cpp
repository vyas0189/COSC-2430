#include <iostream>
#include <fstream>
#include <string>
#include "unorderedLinkedList.h"
using namespace std;

class graphType
{
  public:
    bool isEmpty() const;

    void createGraph();

    void clearGraph();

    void printGraph() const;

    void depthFirstTraversal();

    void dftAtVertex(int vertex);
    void breadthFirstTraversal();

    graphType(int size = 0);

    ~graphType();

  protected:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> *graph;

  private:
    void dft(int v, bool visited[]);
};

bool graphType::isEmpty() const
{
    return (gSize == 0);
}

void graphType::createGraph()
{
    ifstream infile;
    char fileName[50];
    int vertex;
    int adjacentVertex;
    if (gSize != 0) //if the graph is not empty, make it empty
        clearGraph();
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;
    infile.open(fileName);
    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    infile >> gSize; //get the number of vertices
    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;
        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        }
        //end while
    }
    // end for
    infile.close();
}

void graphType::clearGraph()
{
    for (int index = 0; index < gSize; index++)
        graph[index].destroyList();
    gSize = 0;
}

void graphType::printGraph() const
{
    for (int index = 0; index < gSize; index++)
    {
        cout << index << " ";
        graph[index].print();
        cout << endl;
    }
    cout << endl;
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}
//Destructor
graphType::~graphType()
{
    clearGraph();
}

void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " "; //visit the vertex
    linkedListIterator<int> graphIt;
    //for each vertex adjacent to v
    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited);
    }
    //end while
}

void graphType::depthFirstTraversal()
{
    bool *visited; //pointer to create the array to keep
    //track of the visited vertices
    visited = new bool[gSize];
    for (int index = 0; index < gSize; index++)
        visited[index] = false;
    //For each vertex that is not visited, do a depth
    //first traverssal
    for (int index = 0; index < gSize; index++)
        if (!visited[index])
            dft(index, visited);
    delete[] visited;
}

void graphType::dftAtVertex(int vertex)
{
    bool *visited;
    visited = new bool[gSize];
    for (int index = 0; index < gSize; index++)
        visited[index] = false;
    dft(vertex, visited);
    delete[] visited;
}

void graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue;
    bool *visited;
    visited = new bool[gSize];
    for (int ind = 0; ind < gSize; ind++)
        visited[ind] = false; //initialize the array
    //visited to false
    linkedListIterator<int> graphIt;
    for (int index = 0; index < gSize; index++)
        if (!visited[index])
        {
            queue.addQueue(index);
            visited[index] = true;
            cout << " " << index << " ";
            while (!queue.isEmptyQueue())
            {
                int u = queue.front();
                queue.deleteQueue();
                for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.addQueue(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            }
            //end while
        }
    delete[] visited;
}