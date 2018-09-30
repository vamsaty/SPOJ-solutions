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

int main(){
	IN;
	int n;
	while(1){
		cin>>n;
		//		cout<<"n = "<<n<<"\n";
		if(!n)
			break;
		
		stack<int>x,t;
		int data;
		for(int i=0;i<n;i++){
			cin>>data;
			t.push(data);
		}
		while(!t.empty()){
			x.push(t.top());
			t.pop();
		}
		int pos = 1;
		while(1){
			while(!x.empty()){
				if(x.top() == pos){
					x.pop();
					pos++;
				}else{
					if(!t.empty() && t.top() == pos){
						t.pop();
						pos++;
					}else{
						t.push(x.top());
						x.pop();
					}
				}
			}
			if(x.empty()){
				while(!t.empty()){
					if(t.top() != pos)
						break;
						
					t.pop();
					pos++;
				}
				break;
			}
		}
		if(pos == n+1){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}

	}
	
    
    return 0;
    
}



