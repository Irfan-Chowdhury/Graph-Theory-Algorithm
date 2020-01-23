#include<bits/stdc++.h>
using namespace std;

int number;
int graph[100][100], Distance[100];

void dfs(int s)
{
    int visited[number]= {0};
    Distance[s] = 0;
    stack<int>q;
    q.push(s); ///first node enter into stack
    while(!q.empty())
    {
        int node = q.top();
        if(visited[node]==0)
        {
            cout<<node<<" Node "<<endl;
            visited[node] = 1;
            for(int V=0; V<number; V++)
            {
                if(graph[node][V]==1 && visited[V]==0)
                {
                    Distance[V] = Distance[node]+1;///24 line is only useable when ask o calculate distance of each node from source
                    q.push(V);
                }
            }
        }
        else
        {
            q.pop();
        }

        ///Stack Print
        stack<int> tmp = q;
        cout<<"Stack Size "<<tmp.size()<<endl;
        for(;!tmp.empty();)
        {
            cout<<" | "<<tmp.top()<<" |"<<endl;
            tmp.pop();
        }
        cout<<"_____"<<endl;
    }
}

int main()
{
    cout<<"Enter Number of Node: ";
    cin>>number; ///Number of Node
    cout<<"Enter adjacency matrix for graph: "<<endl;

    for(int i=0;i<number;i++)
    {
        for(int j=0;j<number;j++)
        {
            cin>>graph[i][j];
        }
    }

    dfs(0);  ///function call

    for(int i=0; i<number;i++)
    {
        cout<<"Distance of "<<i<<" is "<<Distance[i]<<endl;
    }

    return 0;
}
