#include<bits/stdc++.h>

using namespace std;

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int len = s.length();
		long long int ans = 0;
		map<char,int> storage;
		for(int i=0;i<len;i+=2){
			char c = tolower(s[i+1]);
			if(c == s[i]){
				//pass
			}else{
				if(storage.find(s[i]) == storage.end()){
					storage[s[i]] = 1;
				}else{
					storage[s[i]]++;
				}
				
				
				if(storage.find(c) != storage.end()){
					
					if(storage[c] > 0){
						storage[c]--;
					}else{
						ans++;
					}
					
				}else{
					
					storage[c] = 0;
					ans++;
					
				}
				
			}
		}
		
		cout<<ans<<"\n";
	}
	
	
	
	
	return 0;
}
