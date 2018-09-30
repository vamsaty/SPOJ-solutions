#include<bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair

using namespace std;

int x[10]={0,-1,-1,-2,-2,2,2,1,1};
int y[10]={0,-2,2,-1,1,-1,1,-2,2};


int bfs(int a1,int b1,int a2,int b2){
	
        int moves[9][9],vis[9][9],m,n;
        memset(moves,0,sizeof moves);
        memset(vis,0,sizeof vis);
        
		pair<int,int>p1;
        queue< pair<int,int> >q;
        q.push(p1);
        
        
        vis[p1.first][p1.second]=0;
        
        while(!q.empty()){
            p1 = q.front();
            q.pop();
            
			if(p1.first == a2 && p1.second == b2)
        	    return moves[a2][b2];
             
            for(int i=1;i<=8;i++){
                m = p1.first+x[i],n = p1.second+y[i];
                if(m>8 || m<1 || n>8 || n<1)
            	    continue;
	            else{
	                vis[m][n] = 1;
	                moves[m][n] = moves[p1.first][p1.second]+1;
	                q.push(make_pair(m,n));
	            }
        	}
    	}
    	
}
    
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    char a1,a2;
    long long b1,b2,t;
    cin>>t;
    while(t--){
        cin>>a1>>b1>>a2>>b2;
        cout<<bfs(a1-'a'+1,b1,a2-'a'+1,b2)<<endl;
    } 
    return 0;
} 
