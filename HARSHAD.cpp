#include<bits/stdc++.h>

using namespace std;
const int n = 1000001;
int pro(int x){
	int ans = x;
	while(x){
		ans += x%10;x = x/10;
	}
	return ans;
}

int main(){
	bitset<n>p(0);
	bitset<n>dev(0);
	int *a = (int*)malloc(sizeof(int)*(n+1));
	int sq = sqrt(n);
	p[0] = p[1] = 1;
	for(int i=2;i<=sq;i++){
		for(int j = i*i;j<n;j+=i){
			if(!p[j]){
				p[j] = 1;
			}
		}
	}
	
	for(int i=1;i<n-1;i++){
		if(!dev[i]){
			int x = pro(i);
			while(x<=n){
				if(!dev[x]){
					dev[x] = 1;
				}else{
					break;
				}
				x = pro(x);
			}
		}
	}
	
	p.flip();dev.flip();
	
	dev = dev&p;
	int cn = 0;
	for(int i=0;i<=n;i++){
		if(dev[i])
			cn++;
		a[i] = cn;
	}
	
	int q;
	cin>>q;
	while(q--){
		int A,B;
		cin>>A>>B;
		
		if(!dev[A]){
			cout<<a[B]-a[A]<<"\n";
		}else{
			cout<<a[B]-a[A]+1<<"\n";
		}
		
	}
		
	
	return 0;
}
