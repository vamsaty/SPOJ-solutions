#include<bits/stdc++.h>

using namespace std;

struct rec{
	int par,size;
};

rec data[200002];
map<int,int> mac;

int parent(int x){
	while(data[x].par != x)
		x = data[x].par;
	
	return x;
}

void unite(int x,int y){
	int px = parent(x);
	int py = parent(y);

	if(px != py){
	
		if(data[px].size <= data[py].size){
			data[px].par = py;
			data[py].size += data[px].size;
		}else{
			data[py].par = px;
			data[px].size += data[py].size;
		}
		
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	
	long int n,m,pos = 0;
	cin>>n>>m;
	
	for(int i=1;i<=2*m+1;i++){
		data[i].size = 1;
		data[i].par = i;
	}

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
			
		if(mac.find(a) == mac.end())
			mac[a] = pos++;
			
		if(mac.find(b) == mac.end())
			mac[b] = pos++;
		
		unite(mac[a],mac[b]);

	}
	
	set<int> finite;
	for(auto x:mac)
		finite.insert(parent(x.second));
	
//	cout<<n<<" "<<pos<<" "<<finite.size()<<"\n";
	cout<<n-pos+finite.size()<<"\n";
	
	return 0;
}
