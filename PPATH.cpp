#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

bitset<10002> p(0);
int pos[10001],vis[10001];


int bfs(string a,string b){
	
	deque< pair<string,int> > q;
	int le = 0,cnt = 0;
	
	memset(pos,0,sizeof(pos));
	memset(vis,0,sizeof(vis));
	
	pos[stoi(a)] = 0;
	q.pb(mp(a,-1));
	if(a == b){
		return 0;
	}
	while(!q.empty()){
	
		pair<string,int> s = q.front();
		q.pop_front();
		string x = s.first;
		vis[stoi(x)] = 1;
		
		if(x == b)
			return pos[stoi(b)];
		
		int p1 = s.second;
		
		for(int j=0;j<=3;j++){
			int i = (j == 0)? 1:0;
			while(i<=9 && p1 != j){
				string d = x;
					d[j] = i+'0';
					int m = stoi(d);
					if(!pos[m] && !p[m] && !vis[m]){
						pos[m] = pos[stoi(x)]+1;
						q.pb(mp(d,j));
					}
				i++;
			}
		}
		
		
		
	}
	
	return -1;
}


int main(){
	
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	p[1] = 1;
	for(int i=2;i<10002;i+=2)
		p[i] = 1;
	int sq = sqrt(10002);
	for(int i=3;i<=sq;i+=2){
		if(!p[i]){
			for(int j = i*i;j<10002;j+=i){
				p[j] = 1;
			}
		}
	}
	
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int x = bfs(a,b);
		if(x < 0){
			cout<<"Impossible\n";
		}else{
			cout<<x<<"\n";
		}
		
		
	}
	
	
	
	
	
	
	return 0;
}
