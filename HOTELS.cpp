#include <bits/stdc++.h>

#define ll long long int

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
 
using namespace std;
 
int main(){
	IN;
//	OUT;
	
		int i = 0,j = 0,n,b;
		cin>>n>>b;
		vector<ll>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ll val = a[0];
		ll ans = 0;
		i = 0,j = 0;
		while(i<n){
			j = max(j,i);
			while(1){
				if(val <= b && j<n){
					ans = max(ans,val);
					val += a[++j];
				}else{
					val -= a[i];
					i++;
					break;
				}
			}
			
		}
		
		cout<<ans<<"\n";
	
	 
    return 0;
}

