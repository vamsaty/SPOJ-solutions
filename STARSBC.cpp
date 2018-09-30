#include<bits/stdc++.h>

using namespace std;
const long long int n = pow(2,31)+1;

long long int phi(long long int n){
	long long int sq = sqrt(n);
	long long int res = n,p = 2;
	if(n%2==0){
		while(n%2==0){
			n/=2;
		}
		res = res-(res/2);
	}
	
	
	for(p = 3;p<=sq;p+=2){
		if(n%p == 0){
				
			while(n%p == 0){
				n = n/p;
			}
			res = res-(res/p);
		}
	}
	if(n>1){
		res = res-(res/n);
	}
	return res/2;
}

int main(){

	long long int t;
	freopen("in.txt","r",stdin);
	while(cin>>t && t != EOF){
		cout<<phi(t)<<"\n";
	}
	
	
	return 0;
}
