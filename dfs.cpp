#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//поиск target в графе, начиная с head
void search(vector<int> adjList[], bool visited[], int head, int target)
{
    if (!visited[head])
    {
        cout << "Looking on " << head << "..." << endl;
        visited[head] = true;
        if (head == target)
        {
            cout << "Success! Found " << head << endl;
            exit(0);
        }
        for (auto v : adjList[head])
        {
            search(adjList, visited, v, target);
        }
   }
}

//Создание связного графа (списка смежности)
void createGraph(vector<int> adjList[])
{
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 6};
    adjList[2] = {0, 3, 4, 5};
    adjList[3] = {1, 2, 6};
    adjList[4] = {2};
    adjList[5] = {2};
    adjList[6] = {1, 3, 7};
    adjList[7] = {6};
}

int main()
{
    int vnum = 8; //Количество вершин в графе
    vector<int> adjList[vnum];
    createGraph(adjList); //Список смежности

    int head = 3;
    int target = 6;
    cout << "Searching for " << target
         << " starting from " << head << ":" << endl;
    bool visited[vnum];
    for (auto v : visited) v = false;
    search(adjList, visited, head, target);

    return 0;
}
