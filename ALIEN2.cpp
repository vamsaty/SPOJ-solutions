#include<bits/stdc++.h>

using namespace std;

int dp[2][10010];
int vis[2][10010];
int lim = 0;
int ans = INT_MIN;
int aval = INT_MAX;
int klim = 0;

bool check(int i,int j){
	if(i < 0 || i > 1 || j < 0 || j >= lim)
		return false;
	return true;
}

void solveUtil(int i,int j,int val,int steps){
	
	
	if(!check(i,j) || vis[i][j]){
//		cout<<"i,j = "<<i<<","<<j<<"\n";
		return ;
	}
//	cout<<"i,j = "<<i<<","<<j<<"\n";
//	cout<<val+dp[i][j]<<"\n";
	if(val + dp[i][j] > klim){
//		cout<<"i,j = "<<i<<","<<j<<"\n";
//		cout<<val<<"\t"<<dp[i][j]<<"\n\n\n";
		return ;
	}
	
	val += dp[i][j];
//	cout<<"Val = "<<val<<"\n\n\n\n";
	vis[i][j] = 1;
	if(ans < steps+1){
		ans = steps+1;
		aval = val;
	}else if(ans == steps+1){
		aval = min(aval,val);
	}
	
	solveUtil(i-1,j,val,steps);
	solveUtil(i,j+1,val,steps+1);
	solveUtil(i+1,j,val,steps);
}


int main(){
	freopen("in.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	lim = n;
	klim = k;
	for(int i=0;i<n;i++){
		cin>>dp[0][i];
		vis[0][i] = 0;
	}
	for(int i=0;i<n;i++){
		cin>>dp[1][i];
		vis[1][i] = 0;
	}
	
//	for(int i=0;i<2;i++){
//		for(int j=0;j<n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	int a1,b1,a2,b2;
	solveUtil(0,0,0,0);
	for(int i=0;i<n;i++)
		vis[0][i] = vis[1][i] = 0;
	solveUtil(1,0,0,0);
	cout<<ans<<" "<<aval<<"\n";
	
	return 0;
}
