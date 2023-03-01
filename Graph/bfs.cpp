#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;

#define syncC ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define io freopen("i.txt","r",stdin);freopen("o.txt","w",stdout);
#define f1(n,m) for(int i=n;i<=m;i+=1)
#define f2(n,m) for(auto n:m)
#define sq(a) ((a)*(a))
#define MAX 100000

bool sortSec(const pair<int,int> &a,const pair<int,int> &b){return (a.second<b.second);}
ll solve(){};

vector<int>edges[100];
vector<int>cost[100];
int visited[100];

void bfs(int s,int n){//------------------ s(starting node)  n(number of node)
    queue<int>qe;

    f1(0,n-1){
        visited[i]=0;
    }
    qe.push(s);
    visited[s]=1;

    while(!qe.empty()){
        int u = qe.front();
        qe.pop();

        f1(0,edges[u].size()-1){
            if(visited[edges[u][i]]==0){
                int v=edges[u][i];
                visited[v]=1;
                qe.push(v);
            }
        }
    }

}

int main(){
    syncC;
    //io;

    int node,edge;

    cin>>node>>edge;
    f1(1,edge){
      int x, y;
      cin>>x>>y;
      edges[x].push_back(y);
      edges[y].push_back(x);
      cost[x].push_back(1);
      cost[y].push_back(1);
    }

   return 0;
}