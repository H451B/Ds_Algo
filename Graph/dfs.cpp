#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;

#define syncC ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define io freopen("i.txt","r",stdin);freopen("o.txt","w",stdout);
#define f1(n,m) for(int i=n;i<=m;i+=1)
#define f2(n,m) for(auto n:m)
#define sq(a) ((a)*(a))

vector<int>edges[100];
int edge_id[100];
int visited[100];

void dfs_recursion(int s);
void dfs(int s, int n){
    f1(0,n-1){
        edge_id[i]=visited[i]=0;
    }

    stack<int>sk;
    sk.push(s);
    int xx=1;
    while(!sk.empty()){
        
        int u = sk.top();
        sk.pop();
        cout<<endl<<u<<"-> ";
        
        //for(int i=0;i<edge[u].size();i+=1)
        int siz=edges[u].size(); //number od adj nodes 1->4 1->3 1->2
        while(edge_id[u]<siz){
            int v= edges[u][edge_id[u]]; //0->1->2 ...
            cout<<xx<<"| "<<v<<" ";
            edge_id[u]+=1;// asol kehla, 1 [2,3] id[0->2] -> 1[2,3] id[1->3]

            if(visited[v]==0){
                visited[v]=1;
                sk.push(u);// for backtrack
                sk.push(v);
                break;
            }
        }
        xx+=1;
    }
}

bool sortSec(const pair<int,int> &a,const pair<int,int> &b){return (a.second<b.second);}
ll solve(){};

int main(){
    syncC;
    //io;
    int x,y,node,edge;
    /*     0-1\
           |/| 2
           4-3/         */
    cin>>node>>edge; //number of node & number of edges
    f1(0,edge-1){
        cin>>x>>y; //node & adjance node
        edges[x].push_back(y);
        // edges[y].push_back(x);
    }
    // f1(0,node-1){
    //     cout<<i<<"->";
    //     for(int j=0;j<edges[i].size();j+=1){
    //         cout<<edges[i][j]<<" ";
    //     }            
    //     cout<<endl;
    // }
    dfs(0,5);

    /*
        for(int i=0;i<node;i+=1){
            if(visited[i]==false){
                dfs_recursion(i);
            }
            //int connected_comp+=1;
        }
    */

   return 0;
}

//------------------recursion[stack by nature]
/* void dfs_recursion(int s){
       visited[s]=true;
       for(int i=0;i<edges[s].size();i+=1){
           if(visited[edges[s][i]]==false){
               dfs[edges[s][i]];
           }
       }
    }
*/