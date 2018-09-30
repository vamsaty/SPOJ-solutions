#include<bits/stdc++.h>

using namespace std;


int jos(int n,int k){
	if(n == 1)
		return 1;
	
	return (jos(n-1,k+1)+k-1)%n+1;
	
}



int main(){
//	freopen("in.txt","r",stdin);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<jos(n,1)<<"\n";
	}
	
	return 0;
}
