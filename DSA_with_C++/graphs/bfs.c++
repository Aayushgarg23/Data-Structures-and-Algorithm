#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

void prepareAdjList(unordered_map<int,list<int>>&adjList, vector<pair<int,int>>&edges)
{
    for(int i =0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


vector<int> BFS(int vertex, vector<pair<int,int>>edges)
{
    unordered_map<int,list<int>>adjList;
    prepareAdjList(adjList,edges);
    vector<int>bfs;
    unordered_map<int,bool>visited;
    queue<int>q;
    q.push(vertex);
    visited[vertex] = true;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        bfs.push_back(front);
        for(auto i:adjList[front])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return bfs;
}