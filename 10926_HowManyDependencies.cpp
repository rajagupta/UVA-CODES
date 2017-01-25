#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<bool>&visited, vector<vector<int>>graph, int v, vector<int>&v_count )
{
    visited[v] = true;
    int v_sum=0;
    for(int i=0;i<graph[v].size();i++){
        if(visited[graph[v][i]]==false){
            v_sum++;
            dfs(visited, graph, graph[v][i], v_count);
            v_sum+=v_count[graph[v][i]];
        }
        
    }
    v_count[v]=v_sum;
}
int main()
{
    int n , d[105];
    while(scanf("%d",&n)==1 && n)
    {
        vector<vector<int> >graph(n+1,vector<int>());
        for(int i=1;i<=n;i++){
            int k;
            
            cin>>k;
            for(int j=0;j<k;j++){
                int temp;
                cin>>temp;
                graph[i].push_back(temp);
            }
        }
        vector<int>v_count(n+1,0);
        int max_=INT_MIN;
        for(int i=1;i<=n;i++){
            vector<bool>visited(n+1,false);
            if(v_count[i]==0){
                dfs(visited,graph, i,v_count);
            }
            else{
                continue;
            }
        }
        int index=1;
        for(int i=1;i<=n;i++){
            if(max_<v_count[i]){
                max_=v_count[i];
                index=i;
            }
        }
        printf("%d\n",index);
    }
    return 0;
}
