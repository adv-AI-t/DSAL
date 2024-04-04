#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

class Edge{
    int start;
    int end;
    int weight;

    friend class Graph;

    public:
    Edge()
    {
        start = end = 0;
        weight = -1;
    }
    Edge(int start, int end, int weight)
    {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

class Graph
{
    int n;
    vector<Edge>v1;
    vector<Edge>sorted;
    vector<int>visited;
    public:
    Graph()
    {
        n=0;
    }
    Graph(int n)
    {
        this->n = n;
        int start, end, weight;
        for(int i=0; i<n; i++)
        {
            cin>>start>>end>>weight;
            v1.push_back(Edge(start, end, weight));
        }
    }
    void displayEdges()
    {
        for(int j=0; j<v1.size(); j++)
        {
            Edge temp = v1[j];
            cout<<temp.start<<"---"<<temp.weight<<"---"<<temp.end<<endl;
        }
    }
    static bool compareWeights(Edge e1, Edge e2)
    {
        return(e1.weight<e2.weight);
    }
    void sortEdges()
    {
        sort(v1.begin(), v1.end(), compareWeights);
    }
    bool isVisited(int vertex)
    {
        for(int j=0; j<visited.size(); j++)
        {
            if(visited[j]==vertex)
            return true;
        }
        return false;
    }
    int kruskal()
    {
        int totalWeight = 0;
        for(int i=0; i<n; i++)
        {
            if(visited.size()==n)
            break;
            Edge temp = v1.front();
            v1.erase(v1.begin());
            // cout<<"\nUPDATED EDGE LIST\n";
            // displayEdges();
            bool startvisited = isVisited(temp.start);
            bool endvisited = isVisited(temp.end);
            if(startvisited && endvisited)
                continue;
            else
            {
                if(!startvisited)
                visited.push_back(temp.start);
                if(!endvisited)
                visited.push_back(temp.end);
                totalWeight+=temp.weight;
            }
        }
        return totalWeight;
    }
};

int main()
{
    cout<<"Enter number of edges:";
    int n;
    cin>>n;
    Graph g1(n);
    g1.displayEdges();
    g1.sortEdges();
    
    cout<<"After sorting\n";
    g1.displayEdges();

    int result = g1.kruskal();
    cout<<endl<<result;
    return 0;
}