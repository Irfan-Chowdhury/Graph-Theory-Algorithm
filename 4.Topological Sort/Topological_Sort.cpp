#include<bits/stdc++.h>
using namespace std;

int number;
int matrix[100][100];
int visited[100]= {0};
stack<int>topologicalOrder;

void topologicalSort(int start)
{
    stack<int>q;
    q.push(start);
    while(!q.empty())
    {
        int node = q.top();
        if(visited[node]==0)
        {
            visited[node]=1;
            for(int V=0; V<number; V++)
            {
                if(matrix[node][V]==1 && visited[V]==0)
                {
                    q.push(V);
                }
            }
        }
        else
        {
            int x = q.top();
            topologicalOrder.push(x);
            q.pop();
        }
    }
}

int main()
{
    ///graph input
    cout<<"Enter Number of Node: ";
    cin>>number;

    cout<<"input Value in matrix:"<<endl;
    for(int i=0; i<number; i++)
    {
        for(int j=0; j<number; j++)
        {
            cin>>matrix[i][j];
        }
    }


    for(int i=0; i<number; i++)
    {
        if(visited[i]==0)
        {
            topologicalSort(i);
        }
    }

    cout<<"Order : ";
    while(!topologicalOrder.empty())
    {
        cout<<topologicalOrder.top()<<" ";
        topologicalOrder.pop();
    }

    return 0;

}
