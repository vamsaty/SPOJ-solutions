#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int n = 87000010;
int a[5000002];

int main(){

	
	a[0] = 0;
	bitset<n> prime(0);
	int sq = sqrt(n);
	prime[1] = 1;
	
	for(int i=2;i<=sq;i++){
		if(!prime[i]){
			for(ll j = i*i;j<n;j+=i){
				prime[j] = 1;
			}
		}
	}
	int prev = 0;
	for(int i = 1;i<n;i++){
		if(!prime[i]){
			prev++;
			a[prev] = i;
		}
		
	}
	
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		cout<<a[k]<<"\n";
	}
	
	
	
	
	return 0;
	
}


