#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(),x.end()

using namespace std;

ll box(vector<ll> a,ll dist,int n,int req){
	int cow = 1;	// as it is at least 2
	int pos = a[0];
	for(int i=1;i<n-1;i++){
		if(a[i]-pos >= dist){
			cow++;
			pos = a[i];		// we placed the last cow, now we decide the place for the current cow
			if(cow == req)
				return 1;
		}
	}
	
	return 0;
}

ll search(vector<ll>a,ll cows,int n){
	ll l = 0;
	ll h = a[n-1]-a[0]+10;
	ll m = (l+h)/2;
	ll ans = a[0];
	while(l < h){
		m = (l+h)/2;
		ll w = box(a,m,n,cows);
		if(w){
			ans = max(ans,m);
			l = m+1;
		}else{
			h = m;
		}
	}
	return m;
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
		
		sort(all(a));
		cout<<search(a,k,n)<<"\n";
		
	}
	
	
	return 0;
}
