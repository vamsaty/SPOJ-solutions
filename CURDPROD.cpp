#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <math.h>
#include <sstream>
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()	// all the elements of the container
#define tr(container,it)\
for(typeof(container.begin()) it=container.begin();it!=container.end();it++)	// iterator
#define msearch(cont,ele) (cont.find(ele)!=cont.end())	//search for map
#define vsearch(cont,ele) (cont.find(all(x),ele)!=cont.end())	//search for vector
#define ll long long int
#define ull unsigned long long int
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define fora(i,z,n,a) for(int i=z;i<n;i++) cin>>a[i]
#define MALL(t,n) (t*)malloc(sizeof(t)*n)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)

using namespace std;


void b_sear(vector< ll >a,ll T,ll n){
	ull l = 0,h = ULLONG_MAX/10;
	ll m = (l+h)/2;
	ll ans = LLONG_MAX;
	while(l<h){
		m = (l+h)/2;
		ll val = 0;
		for(int i=0;i<n;i++){
			val += (m/a[i]);
		}
		
		if(val >= T){
			ans = min(ans,m);
			h = m;
		}else{
			l = m+1;
		}
	}
	cout<<ans<<"\n";
	
}


int main(){
	IN;
	
	int t;
	cin>>t;
	while(t--){
		ll n,T;
		cin>>n>>T;
		vector<ll> a(n);
		fora(i,0,n,a);
		b_sear(a,T,n);
	}
	
	
	
	
    return 0;
}  
