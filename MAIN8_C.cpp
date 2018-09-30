#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(),x.end()

using namespace std;

ll box(vector<ll> a,ll x,int n){
	ll cnt = 0;
	if(x == 0)return 0;
	for(int i=0;i<n;i++){
		cnt += (a[i]/x);
	}
	return cnt;
}

ll search(vector<ll>a,ll k,int n){
	ll l = 0;
	ll h = LLONG_MAX/10;
	ll m = (l+h)/2;
	ll ans = INT_MIN;
	while(l < h){
		m = (l+h)/2;
		ll w = box(a,m,n);
		if(w>=k){
			l = m+1;
			ans = max(ans,m);
		}else{
			h = m;
		}
	}
	if(ans == INT_MIN){
		return 0;
	}
	return ans;
}


int main(){
	freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		ll k;
		cin>>n>>k;
		vector<ll> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<search(a,k,n)<<"\n";
		
	}
	
	
	return 0;
}
