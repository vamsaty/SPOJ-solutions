#include<bits/stdc++.h>

using namespace std;

int main(){
	int *a = (int*)malloc(sizeof(int)*(1000001));
	bitset<1000001>p(0);
	int n = 1000001;
	int cu = ceil(pow(n,1/3.0));

	for(int i=2;i<=cu;i++){
		if(!p[i]){
			long long int x = i*i*i;
			for(long long int j=1;j*x <= n;j++){
				p[j*x] = 1;
			}
		}
	}
	
	p[1] = 0;
	int prev = 0;
	for(int i=1;i<=n;i++){
		if(!p[i]){
			a[i] = prev+1;
			prev++;
		}else{
			a[i] = 0;
		}
	}
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int x;
		cin>>x;
		cout<<"Case "<<i<<": ";
		if(a[x]){
			 cout<< a[x] <<"\n";
		}else{
			cout<<"Not Cube Free\n";
		}
	}
	
	
	return 0;
}
