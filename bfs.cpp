#include <iostream>
#include <vector>
#include <list>

using namespace std;

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

void search(vector<int> adjList[], int vnum, int head, int target)
{
    bool visited[vnum];
    for (auto v : visited) v = false;
    list<int> queue = {};

    visited[head] = true;
    queue.push_back(head);
    while (!queue.empty())
    {
        int curr = queue.front();
        queue.pop_front();
        cout << "Looking on " << curr << "..." << endl;
        if (curr == target)
        {
            cout << "Success! Found " << curr << endl;
            exit(0);
        }
        for (auto v : adjList[curr])
        {
            if (!visited[v])
            {
                visited[v] = true;
                queue.push_back(v);
            }
        }

    }

}


int main()
{
    int vnum = 8; //Количество вершин в графе
    vector<int> adjList[vnum];
    createGraph(adjList); //Список смежности

    int head = 1;
    int target = 4;
    cout << "Searching for " << target
         << " starting from " << head << ":" << endl;

    search(adjList, vnum, head, target);

    return 0;
}
