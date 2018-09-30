#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	while(1){
		cin>>t;
		if(!t)break;
		int k = 0,n = 0;
		do{
			k++;
			n = 0;
			for(int i=2;i<n;i++){
				n = (n+k)%i;
			}
			n+=2;
		}while(n != 13);
		
		cout<<k<<"\n";
	}
	
	
	return 0;
}
