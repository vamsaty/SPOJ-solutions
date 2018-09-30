#include<bits/stdc++.h>

using namespace std;

int pro(int n){
	int x = n;
	int ans = n;
	while(n){
		ans += n%10;
		n = n/10;
	}
	
	return ans;
}

int main(){
	const int n = 1000001;
	bitset<n> p(0);
	for(int i=1;i<n-1;i++){
		if(!p[i]){
			int x = pro(i);
			while(x<=n){
				if(!p[x]){
					p[x] = 1;
				}else{
					break;
				}
				x = pro(x);
			}
		}
	}
	int cn = 0;
	for(int i=1;i<1000000;i++){
		if(!p[i]){
			cout<<i<<"\n";
		}
	}
	
	
	return 0;
}
