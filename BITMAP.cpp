#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

int dist[200][200];

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

int valid(int i,int j,pi lims){
	if(i < 0 || i >= lims.first || j < 0 || j >= lims.second)
		return 0;
	return 1;
}

int bfs(pi x,pi limits){
	deque< pi > q;
	q.pb(x);
	
	while(!q.empty()){
		pi s = q.front();
		q.pop_front();
		
		for(int i=0;i<4;i++){
			int x = s.first+di[i];
			int y = dj[i]+s.second;
			if(valid(x,y,limits) && dist[x][y] > 1+dist[s.first][s.second] ){
				dist[x][y] = dist[s.first][s.second]+1;
				q.pb(mp(x,y));
			}
		}
		
		
	}
	
	
}



int main(){
	
	freopen("in.txt","r",stdin);
	
	int t;
	cin>>t;
	while(t--){
		
		int n,m;
		cin>>n>>m;
		vector<string> data(n);
		for(int i=0;i<n;i++){
			cin>>data[i];
		}
		
		set< pi > process;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				dist[i][j] = INT_MAX;
				if(data[i][j] == '1'){
					dist[i][j] = 0;
					process.insert(mp(i,j));
				}
			}
		}
		pi lims = mp(n,m);
		for(auto x:process){
			bfs(x,lims);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<dist[i][j]<<" ";
			}
			cout<<"\n";
		}
		
	}
	
	return 0;
}
