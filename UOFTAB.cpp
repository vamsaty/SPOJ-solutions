#include<bits/stdc++.h>

using  namespace std;

struct fox{
	int a,s,o;
	int high,low;
	value(int v){
		high = v*(a+s)-o-1;
		low = v*(a+s)-o-s;
	}
	show(){
		cout<<a<<" "<<s<<" "<<o<<"\t"<<low<<" "<<high<<"\n";
	}
};

struct tab{
	int time;
	int low,high;
};

int comp(fox a,fox b){
	if(a.high-a.low < b.high-b.low){
		return 1;
	}else if(a.high-a.low == b.high-b.low){
		if(a.high < b.high){
			return 1;
		}else if(a.high == b.high){
			if(a.low < b.low){
				return 1;
			}else{
				return 0;
			}
		}
	}else{
		return 0;
	}
}

int main(){
	freopen("in.txt","r",stdin);
	
	int t;
	cin>>t;
	while(t--){
		
		int n;
		long long int v = 1;
		cin>>n;
		fox f[n];
		for(int i=0;i<n;i++){
			cin>>f[i].a>>f[i].s>>f[i].o;
			f[i].value(v);
		}
		
		sort(f,f+n,comp);
		
		v = 1;
		for(v=2;v<4;v++){
			for(int i=0;i<n-1;i++){
				f[i].value(v);
				f[i+1].value(v-1);
				cout<<i<<"\n";
				if(f[i].high <= f[i+1].high && f[i].high >= f[i+1].low){
					f[i].show();					
//					cout<<"here\n";
				}else{
					f[i].show();
					f[i+1].show();
				}
			}
			cout<<"\n";
		}
		
		cout<<"\n\n";
	}
	
	
	
	return 0;
}
