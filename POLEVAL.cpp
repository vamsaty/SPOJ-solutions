#include<bits/stdc++.h>

using namespace std;

int eval(int *c,int x,int n){
	int ans = 0;
	ans = c[0];
	for(int i=1;i<=n;i++){
		ans = ans*x+c[i];
	}
	return ans;
}


int main(){
	
	int n;
	int cn = 1;
	while(1){
		cin>>n;
		if(n<0){
			break;
		}
		int *c = (int*)malloc(sizeof(int)*(n+1));
		for(int i=0;i<=n;i++){
			cin>>c[i];
		}
		int k;
		cin>>k;
		cout<<"Case "<<cn<<":\n";
		cn++;
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			
			cout<<eval(c,x,n)<<"\n";
		}
		
	}
	
	return 0;
}
