#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

long long exp(int a,long long n){
	long long ans = 1;
	long long t = a;
	while(n){
		if(n&1){
			ans = (ans*t)%MOD;
		}
		t = (t*t)%MOD;
		n = n/2;
	}
	return ans%MOD;
}

int main(){
		
	int t;
	cin>>t;
	while(t--){
		long long int n,a,b,c;
		cin>>n;
		a = (((50*(exp(10,n)-1)+36*n)%MOD)*(exp(81,MOD-2)))%MOD;
		cout<<a<<"\n";
		
		
	}
	
	
	
	
	return 0;
}
