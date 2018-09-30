#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	const int n = 100000;
	bitset<n> prime(0);
	
	long long int sq = sqrt(n);
	
	prime[1] = 1;
	
	for(long long int i=2;i<=sq;i++){
		
		if(!prime[i]){
			for(ll j = i*i;j<n;j+=i){
				prime[j] = 1;
			}
		}
	}
	
	ll next = 1,prev = 0;
	for(long long int i = 1;i<n;i++){
		if(!prime[i]){
			prev++;
		}
		if(prev == next && !prime[i]){
			cout<<i<<"\n";
			next += 100;
		}
		
	}
	
	
	
	return 0;
	
}


