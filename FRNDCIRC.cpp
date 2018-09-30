#include<bits/stdc++.h>

using namespace std;

struct rec{
	int par,size;
};

rec data[200002];

int parent(int x){
	while(data[x].par != x)
		x = data[x].par;
	
	return x;
}

void unite(int x,int y){
	int px = parent(x);
	int py = parent(y);
//	cout<<px<<"\t"<<py<<"\n";
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

int get_size(int x){
	int px = parent(x);
//	cout<<"parent = "<<px<<"\t"<<data[px].size<<"\n";
	return data[px].size;
}

int main(){
	freopen("in.txt","r",stdin);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<string,int> index;
		string d,e;
		for(int i=1;i<=2*n+1;i++){
			data[i].size = 1;
			data[i].par = i;
		}
		int pos = 1;
		while(n--){
			cin>>d>>e;
			if(index.find(d) == index.end())
				index[d] = pos++;
				
			if( index.find(e) == index.end())
				index[e] = pos++;
				
			unite(index[d],index[e]);
//			cout<<d<<"\t"<<e<<"\n";
			cout<<get_size(index[d])<<"\n";
			
		}
		
//		for(auto x:index){
//			cout<<x.first<<"\t"<<x.second<<"\n";
//		}
		
		
	}
	
	
	return 0;
}
