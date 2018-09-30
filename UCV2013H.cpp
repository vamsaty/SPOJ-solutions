#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;
int a[300][300];
bool vis[300][300];
map<int,int> data;
int total = 0;
int val = 0;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};


int valid(int i,int j,int n,int m){
	if(i < 0 || i >= n || j < 0 || j >= m)
		return 0;
	return 1;
}

int bfs(int i,int j,int n,int m){
	
	deque< pi >q;
	q.pb(mp(i,j));
	int ans = 0;
	while(!q.empty()){
		
		pi s = q.front();
		q.pop_front();
		
		cout<<s.first<<" "<<s.second<<"\n";
		
		for(int i=0;i<4;i++){
			int x = s.first+di[i];
			int y = s.second+dj[i];
			cout<<x<<"\t"<<y<<"_\n";
			if(valid(x,y,n,m) && !vis[x][y] && a[x][y]==0){
				q.pb(mp(x,y));
				vis[x][y] = 1;
			}
		}
		
	}
	
	return ans;
}


int main(){
	
	freopen("in.txt","r",stdin);

	while(1){
		data.clear();
		total = 0;
		int n,m;
		cin>>n>>m;
		if(!n && !m)
			break;
		pi lims = mp(n,m);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				vis[i][j] = 0;
			}
		}		
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(valid[i][j]){
					bfs(i,j,n,m);
				}
			}
		}
		cout<<"\n\n";
		cout<<total<<"\n";
		for(auto l:data){
			cout<<l.first<<" "<<l.second<<"\n";
		}
		
		
	}
	
	return 0;
}
