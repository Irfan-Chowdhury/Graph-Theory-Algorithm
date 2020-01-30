#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

const int Max= 1e4+5;  ///1e4+6 means 10^4+5

int nodes,edges,parent[100];
pair<int, pair<int,int> >Graph[Max];

void graphInput()
{
    int x,y,cost;
    cout<<"Enter nodes number and edges number: ";
    cin>>nodes>>edges;
    cout<<"Enter graph with weight: "<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>cost;
        Graph[i]=make_pair(cost,make_pair(x,y));  ///making pair of nodes with cost.Double pair
    }
}

///Find function search for parent of 'a' node. when 'a' node is the parent of it;s own then it return
int Find(int a)
{
    if(parent[a]==a)
    {
        return a;
    }
    parent[a]= Find(parent[a]);
    return parent[a];
}

///this function check if the node are in the same tree by their parent. if same parent return false.
bool Union(int x, int y)
{
    int u= Find(x);
    int v= Find(y);
    ///cout<<u<<" "<<v<<endl;
    if(u==v)
        return false;
    else
        return true;
}

void Kruskal()
{
    for(int i=0; i<nodes; i++)
    {
        parent[i]=i;
        ///cout<<i<<" "<<parent[i]<<endl;
    }

    int MST[nodes-1]; ///As in MST there are only (Node-1) edges. So we take a array for storing (node-1) edge's index
    sort(Graph,Graph+edges); ///sorting Graph edges by their cost

    int x,y,cost;
    for(int i=0, j=0; i<edges; i++)
    {
        x=Graph[i].second.first;
        y=Graph[i].second.second;
        cost = Graph[i].first;
        bool Notcycle = Union(x,y);
        if(Notcycle)///Not creating cycle then we'll take that node
        {
            ///cout<<Notcycle<<endl;
            parent[x] = parent[y]; ///changing parent of x by parent of y
            MST[j] = i; ///index of pair with low cost
            j++;
            if(j>=nodes-1)
                break;
        }
    }

    int totalCost = 0;

    for(int i=0; i<nodes-1; i++)
    {
        int j= MST[i];

        cout<<"Node "<<Graph[j].second.first<<" "<<Graph[j].second.second<<endl;
        totalCost+=Graph[j].first;
    }
    cout<<"Cost "<<totalCost<<endl;
}

int main()
{
    graphInput();
    Kruskal();

    return 0;
}

