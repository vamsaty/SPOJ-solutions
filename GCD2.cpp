#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
			
		ll a;
		string data;
		cin>>a>>data;
		int n = ceil((double)log(a)/(log(10)));
		data.assign(data.end()-n,data.end());
		ll b = stoi(data);
		
		cout<<__gcd(a,b)<<"\n";
	}
	return 0;
}
