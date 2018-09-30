#include<bits/stdc++.h>
#define pi pair<long long,long long>
#define mp make_pair
#define pb push_back

using namespace std;

bool vis[1000002];
int dist[1000002];

int main(){
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	for(int i=0;i<1000002;i++)
		dist[i] = vis[i] = 0;
	
	int flag = 1;
	deque< int > q;
	q.pb(s);
	dist[g] = -1;
	dist[s] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop_front();
		if(t == g)break;
		int up = t+u;
		int down = t-d;
		if(up <= f && !vis[up]){
			vis[up] = 1;
			dist[up] = dist[t]+1;
			q.pb(up);
		}
		
		if(down >= 1 && !vis[down]){
			vis[down] = 1;
			dist[down] = dist[t]+1;
			q.pb(down);
		}
		
		
	}
	if(dist[g]==-1){
		cout<<"use the stairs\n";
	}else{
		cout<<dist[g]<<"\n";
	}
	
	return 0;
}
