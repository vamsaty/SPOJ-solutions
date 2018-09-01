#include<bits/stdc++.h>
#define pi pair<int,int>
#include<deque>
#define all(x) x.begin(),x.end(	)
using namespace std;

class comp{
	
	public:
	
		bool operator()(pi a,pi b){
			if(a.second > b.second){
				return 1;
			}else if(b.second > a.second){
				return 0;
			}else{
				if(a.first < b.first){
					return 1;
				}else{
					return 0;
				}
			}
		}

};
int cmp(pi a,pi b){
			if(a.second < b.second){
				return 1;
			}else if(b.second < a.second){
				return 0;
			}else{
				if(a.first > b.first){
					return 1;
				}else{
					return 0;
				}
			}
}


int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pi> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].first;
		}
		for(int i=0;i<n;i++){
			cin>>a[i].second;
		}
		
		sort(all(a),cmp);
		
//		priority_queue<pi,vector<pi> ,comp> pq;
//		
//		for(int i=0;i<n;i++){
//			pq.push(a[i]);
//		}
		
		deque<pi> ans;
		deque<pi>::iterator pos;
		
		int cnt = 0;
		int iter = 0;
//		while(!pq.empty()){
		while(iter < n){
			if(ans.empty()){
				ans.push_back(a[iter]);
				iter++;
			}else{
				pos = ans.begin();
				if((*pos).second == a[iter].second){
					ans.push_front(a[iter]);
					iter++;
				}else{
					
					while( pos != ans.end() && a[iter].second ){
						if((*pos).first > a[iter].first){
							a[iter].second--;
						}
						pos++;
					}
					
					while(pos != ans.end() && a[iter].first > (*pos).first){
						pos++;
					}
					
					if(pos == ans.end()){
						ans.push_back(a[iter]);
					}else{
						ans.insert(pos,a[iter]);
					}
					iter++;
					
				}
				
			}
			
		}
		for(auto x:ans){
			cout<<x.first<<" ";
		}
		
		
	}
	
	
	return 0;
}
