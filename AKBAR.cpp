#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

class graph{
	int v;
	list<int> *adj;
	int *mark;
	public:
		long long int ans;
		graph(int n){
			this->v = n+1;
			this->ans = 0;
			this->adj = new list<int>[n+1];
			this->mark = (int*)malloc(sizeof(int)*(n+1));
			for(int i=0;i<=n;i++)
				mark[i] = 0;
		}
		
		void addEdge(int a,int b){
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		int bfs(pi there){
			int city = there.first;
			int range = there.second;
			
			deque< pi > q;
			q.pb(mp(city,range));
			if(!mark[city])
				mark[city] = city;
			else
				return -1;
			
			while(!q.empty() && q.front().second){
				
				pi s = q.front();
				q.pop_front();
				
				for(auto x:adj[s.first]){
					if(mark[x] == 0){
						q.pb(mp(x,s.second-1));
						mark[x] = city;
					}else if(mark[x] != city){
						return -1;
					}
				}
				
			}
			return 1;
		}
		
		bool check_all(){
			for(int i=1;i<v;i++)
				if(!mark[i])
					return 0; 
			return 1;
		}
		
	
};

int main(){
	
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
		
	int t;
	cin>>t;
	while(t--){
		int n,r,m,a,b;
		cin>>n>>r>>m;
		graph data(n);
		while(r--){
			cin>>a>>b;
			data.addEdge(a,b);
		}
		set< pi > cities;

		while(m--){
			int k,s;
			cin>>k>>s;
			cities.insert(mp(k,s));
		}

		bool f = 1;
		
		for(auto p:cities){
			if(data.bfs(p) < 0){
				f = 0;
				break;
			}
		}
		if(f){
			if(data.check_all()){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}else{
			cout<<"No\n";
		}
				
		
	}
	
	
	
	
	
	
	return 0;
}
