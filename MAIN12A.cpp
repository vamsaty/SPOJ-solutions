#include<bits/stdc++.h>
#define all(b) b.begin(),b.end()

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
		
	//precomputing	
		
	long long int vals[1000001];
	vals[1] = 1;
	vals[2] = 2;
	int x = 3;
	int ind = 3,step = vals[2];
	
	int n = 1000001;
	for(int i=2;i<n;i++){
		
		for(int j=0;j<vals[i];j++){
			vals[ind] = x;
			ind++;
			if(ind > 1000001)break;
		}
		if(ind > 1000001)break;
		x++;
		
	}
	
	
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		int n;
		cin>>n;
		cout<<"Case #"<<T<<": "<<vals[n]<<"\n";
	}	
	
	return 0;
}
