#include <bits/stdc++.h>

#define ll long long int

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
 
using namespace std;
 
int main(){
	IN;
//	OUT;
	int t;
	cin>>t;
	while(t--){
		int i = 0,j = 0,n,b;
		cin>>n>>b;
		vector<ll>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ll val = a[0];
		ll vans = a[0];
		int ans = 0,last_ans = 0;
		pair<ll,ll> ans_val = make_pair(0,INT_MAX);
		i = 0;
		while(i<n){
			j = max(j,i);
			while(1){
				if(j < n && val <= b ){
					if(ans < j-i+1){
						ans = j-i+1;
						vans = val;
					}else if(ans == j-i+1){
						if(vans > val)
							vans = val;
					}
						
					val += a[++j];
				}else{
					val -= a[i];
					break;
				}
			}
			i++;
		}
		
		cout<<vans<<" "<<ans<<"\n";
		
	}
	
	
	
	
	 
    return 0;
}

