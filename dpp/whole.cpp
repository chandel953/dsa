#include <bits/stdc++.h>
using namespace std;

	void dfs(int i ,vector<int>&vis ,vector<int>adj[]){
        vis[i] = 1 ;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it ,vis,adj) ;
                cout<<it<<" "  ;

            }
        }
    }
    
    bool bipar(int i,int p ,vector<int>adj[],vector<int>&col){
        col[i] = p ;
        for(auto it : adj[i] ){
            if(col[it]!=-1){
                if(bipar(it ,!p ,adj ,col)==false ) return false ;
            }
            else if(col[it]==p){
                return false ;
            }
        }
        return true  ;
    }

    bool cycle(int i ,int p ,vector<int>&s ,vector<int>adj[]){
        s[i] = 1 ;
        for(auto it :adj[i] ){
            if(!s[it]){
                if(cycle(it ,i,s ,adj)==true) return true  ;
            }
            else if(it != p){
                return true ;
            }
        }
        return false ;
    }
    int main(){
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m ;
    cin>>n ;
    cin>>m  ;
     vector<int>adj[n+1] ;
    // cout<<n<<m<<endl ;
    for(int i = 0 ; i<m ;i++){
    	int u ,v ;
    	cin>>u;
    cin>>v ;
    // cout<<m<<endl ;
    	adj[u].push_back(v) ;
    	adj[v].push_back(u) ;
    }
    // cout<<n<<" " <<m<<endl ;

    // for(int i = 0 ;i<n;i++){
    //     for(int j = 0;j<adj[i].size() ;j++){
    //         cout<<adj[i][j]<<" " ;
    //     }
    //     cout<<endl ;
    // }
        cout<<"bfs"<<endl ;

    queue<int>q ;
    vector<int>vis(n ,0) ;
    	for(int i = 0 ;i<n ;i++){
    		if(!vis[i]){
    			q.push(i) ;
    		}
            while(!q.empty()){
                vis[i] = 1 ;
                int p = q.front() ;
                q.pop() ;
                cout<<p<<" " ;
                for(auto it:adj[p]){
                    if(!vis[it]){
                        cout<<it<<" " ;
                        vis[it] = 1 ;
                    }
                }
            }
    	}
        cout<<endl ;
        cout<<"dfs"<<endl ;
        vector<int>v(n+1 ,0) ;
        dfs(0 ,v ,adj) ;
        cout<<0<<endl  ;

        cout<<"connected graph"<<endl ;
        vector<int>vi(n+1 ,0) ;
        int cnt = 0 ;
        for(int i = 0 ;i<n ;i++){
            if(!vi[i]){
                cnt++ ;
                dfs(0 ,vi,adj) ;
            }
        }
        cout<<0<<endl  ;

        if(cnt>1){
            cout<<"graph not connected"<<endl ;
        }else{
            cout<<"graph connected"<<endl ;
        }
        // dfs(0 ,vi) ;

        cout<<"bipartite or not"<<endl ;
        // vector<int>p(n+1 ,0) ;
        vector<int>col(n+1 ,-1) ;
        col[0] = 0 ;
        int z = bipar(0 ,0 ,adj ,col) ;
        cout<<z<<endl;
        vector<int>s(n+1 ,0) ;
        cout<<"check for cycle"<<endl ;
        cout<<cycle(0 ,-1,s,adj) ;
        cout<<endl;
        cout<<"in degrre "<<endl;
        vector<int>in(n,0);
        for(int i)
    return 0;

   

}
