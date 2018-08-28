#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		
		string msg,decode,rev,code;
		cin>>rev>>msg;
		
		reverse(rev.begin(),rev.end());
		int clen = rev.length();
		int len = msg.length();
		for(int i=0;i<len;i++){			
			int ind = i%clen;
			if(ind == 0){
				reverse(rev.begin(),rev.end());
			}
			
			if(msg[i]-rev[ind]+'0' < 'a'){
				decode.push_back('z' - rev[ind]+'1' + msg[i]-'a');
			}else{
				decode.push_back(msg[i]-rev[ind]+'0');
			}
		}
		cout<<decode<<"\n";
	}	
	
	return 0;
}
