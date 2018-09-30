#include<bits/stdc++.h>

const long long MOD = 1000000007;
using namespace std;

long long tab[2*1000000+1];

long long int power(long long x,long long n){
	long long ans = 1,t = x;
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
	freopen("in.txt","r",stdin);	
//	freopen("out.txt","w",stdout);
	tab[0] = tab[1] = 1;
	for(long i = 2;i<2000001;i++)
		tab[i] = (tab[i-1]*i)%MOD;
	
	int t;
	cin>>t;
	while(t--){
		long m,n;
		cin>>m>>n;
		long long d = (power(tab[n],MOD-2)*power(tab[m],MOD-2))%MOD;
		d = (d*tab[m+n])%MOD;
		cout<<d<<"\n";
	}
	
	return 0;
}
