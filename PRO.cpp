#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <math.h>
#include <sstream>
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()	// all the elements of the container
#define tr(container,it)\
for(typeof(container.begin()) it=container.begin();it!=container.end();it++)	// iterator
#define msearch(cont,ele) (cont.find(ele)!=cont.end())	//search for map
#define vsearch(cont,ele) (cont.find(all(x),ele)!=cont.end())	//search for vector
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi pair< int,int >
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define fora(i,z,n,a) for(int i=z;i<n;i++) cin>>a[i]
#define MALL(t,n) (t*)malloc(sizeof(t)*n)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)

using namespace std;


class lesser{
	public:
		bool operator()(int a,int b){
			if(a <= b)return 1;
			return 0;
		}
};


int main(){
	IN;
	int n;
	cin>>n;
	multiset<int> values;
	long long sum = 0,data;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>data;
			values.insert(data);
		}
		sum += (*(--values.end()))-(*(values.begin()));
		values.erase(values.begin());
		values.erase(--values.end());
		
	}
    
	cout<<sum<<"\n";
    
    
    return 0;
}  
