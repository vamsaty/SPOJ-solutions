#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

class graph{
	int v;
	list<int> *adj;
	bool *vis;
	
	public:
		long long int ans;
		graph(int n){
			this->v = n;
			this->ans = 0;
			this->adj = new list<int>[n];
		}
		
		void addEdge(int a,int b){
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		int dfsU(bool *vis,int b){
			int t=0,c=0;
			vis[b] = 1;
			for(auto x:adj[b]){
				if(!vis[x]){	
					t += dfsU(vis,x);
					c++;
				}
			}
			
//			cout<<"x = "<<b<<"\t"<<t<<" "<<c<<"\n";
			
			ans += t+c+1;
			return t+c+1;
		}
		
		int dfs(int x){
			bool *vis = new bool[v];
			memset(vis,0,sizeof(vis));
			return dfsU(vis,0);
			
		}
	
};

int main(){
	
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
		
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		graph data(n);
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			data.addEdge(a,b);
			data.addEdge(b,a);
		}
		data.dfs(0);
		cout<<data.ans<<"\n";
	}
	
	
	
	
	
	
	return 0;
}
