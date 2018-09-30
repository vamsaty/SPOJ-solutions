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
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define fora(i,z,n,a) for(int i=z;i<n;i++) cin>>a[i]
#define MALL(t,n) (t*)malloc(sizeof(t)*n)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)

using namespace std;


int main(){
	IN;
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,r;
		cin>>n>>r;
		
		int val = 0,f = 1;
		set<int> spies,civils;
		while(r--){
			int r1,r2;
			cin>>r1>>r2;
			spies.insert(r1);
			civils.insert(r2);
		}
		
		vector< int >a(n);
		vector< int >::iterator it;
		it = set_intersection(all(spies),all(civils),a.begin());
		int size = it - a.begin();
		
		cout<<"Scenario #"<<k<<": ";
		if(!size){
			cout<<"spying\n";
		}else{
			cout<<"spied\n";
		}
		
		
	}




    
    return 0;
}  
