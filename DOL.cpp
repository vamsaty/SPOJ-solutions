#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		long long int n;
		cin>>n;	
		while(n%2 == 0){
			n = n/2;
		}
		cout<<"Case "<<T<<": ";
		cout<<n<<"\n";
	}
	
	return 0;
}
