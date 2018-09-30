#include<bits/stdc++.h>
#define ll long long int

using namespace std;
const ll n = 1e15+1;
const ll sq = sqrt(n)+1;
vector< ll > primes;


void phi(ll n){
	ll res = n,p = 2;
	
	int cnt = 0;
	for(auto x:primes){
		cnt = 0;
		while((n%x == 0)){
			n/=x;
			cnt++;
		}
		if(cnt){
			cout<<x<<"^"<<cnt<<" ";
		}
	}
	if(n>1){
		cout<<n<<"^1";
	}
	cout<<"\n";

}

int main(){

	ll t;
	int sq1 = sqrt(sq);
	bitset<sq> pr(0);
	ll j = sq,i=4;
	pr[1] = 1;
	if(sq&1)
		j--;
		
	while(i<=j){
		pr[j] = pr[i] = 1;
		j-=2;
		i+=2;
	}
	
	for(ll i=3;i<=sq;i++){
		if(!pr[i]){
			for(ll j = i*i;j<=sq;j+=2*i){
				pr[j] = 1;
			}
		}
	}
	
	for(int i=1;i<sq;i++){
		if(!pr[i]){
			primes.push_back(i);
		}
	}
	
	while(1){
		cin>>t;
		if(t==0){
			break;
		}
		phi(t);
	}
	
	
	return 0;
}
