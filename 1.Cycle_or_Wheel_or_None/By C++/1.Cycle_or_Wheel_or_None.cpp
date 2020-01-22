/// Cycle or Wheel or None
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///graph input
    int n, a[100][100];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    ///vertex degree calculation
    int degree[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                degree[i]++;
            }
        }
    }

    bool cycle= true;
    int cnt3=0,cnt=0; ///counting vertex with 3 degree ='cnt3'

    for(int i=0;i<n;i++)
    {
        if(degree[i]!=2){
            cycle=false;
        }
        if(degree[i]==3){
            cnt3++;
        }
        else if(degree[i]==n-1){
            cnt++;
        }
    }
    ///cout<<cnt3<<" "<<cnt<<endl;
    if(cycle){
        cout<<"It is Cycle";
    }
    else if((cnt3==n-1 && cnt==1)||(cnt3==n && n==4)){
        cout<<"It is Wheel";
    }
    else{
        cout<<"None";
    }

    return 0;
}
