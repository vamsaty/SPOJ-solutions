#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll g = __gcd(a[1]-a[0],0LL);
	for(int i=0;i<n-1;i++){
		g = __gcd(g,a[i+1]-a[i]);
	}
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		ans += ((a[i+1]-a[i])/g)-1;
	}
	cout<<ans<<"\n";
	
	return 0;
}
