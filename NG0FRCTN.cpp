#include<bits/stdc++.h>
#define pi pair<long long,long long>
#define mp make_pair

using namespace std;

pi rec(int n){
	if(n == 1)
		return mp(1,1);	
	pi s = rec(n/2);
	if(n%2 == 0)
		return mp(s.first,s.first+s.second);
	return mp(s.first+s.second,s.second);
	
}


int main(){
	int t;
	while(1){
		cin>>t;
		if(!t)break;
		pi s = rec(t);
		cout<<s.first<<"/"<<s.second<<"\n";
	}
	
	
	
	return 0;
}
