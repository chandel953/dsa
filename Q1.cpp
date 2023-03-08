#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<long long> 
#define pr pair<long long,long long>
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define f(i,A,B) for(long long i=A;i<B;i++)
#define M 1000000007
#define input(vec) for(auto &i:vec)cin>>i
#define output(vec) for(auto &i:vec){cout<<i<<" ";}cout<<"\n"
#define outputpair(vec) for(auto &i:vec){cout<<"{"<<i.first<<" "<<i.second<<"} ";}cout<<"\n"
#define all(x) (x).begin(),(x).end()
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

    int solve(int n ,vector<int> &dp){
        if (n<=1)
        {
            return n ;
        }
        if(dp[n]!=-1)return dp[n] ;

        return dp[n] =solve(n-1 ,dp) + solve(n-2 ,dp) ;

    }

    int alld(ll n){

        ll sum = 0 ;
        while(n!=0){
            sum += n/10 ;
            n = n/10 ;
             }

             return sum ;
    }

    bool isprime(ll x){
        if(x==2){
            return true ;
        }
        if(x==1){
            return false ;
        }
        if(x%2==0){
            return false ;
        }
        for (int i = 3; i*i< x; i++)
        {
            
            if(x%i==0){

                return false ;
            }
        }
        return true ;
    }
     void reversevec(vector<int>&v ,int l ,int r){
        if(l>=r)
            return  ;
        swap(v[l] , v[r]) ;
        reversevec(v ,l+1 ,r-1) ;
    }
    
    bool issq(ll temp){
        ll s = 1 ;
        ll h = temp ;
        while(s<=h){
            ll m = s + (h-s)/2 ;
            if(m*m>temp){
                h = m -1 ;
            }else if(m*m==temp){
                return true ;
            }else{
                s=  m +1 ;
            }
        }
        return false ;
    }

    int fib(int n){
        if(n==0){
            return 0 ;
        }
        else if(n==1){
            return 1 ;
        }else{
        return fib(n-1) +fib(n-2) ; 
    }

    }
 
    ll md = 1e9+7 ;
    int power(ll x ,ll y,int m){
        int res = 1 ;
        x=x%m ;
        while(y>0){
            if(y%2==1){
                res = (res*x)%m ;
            }
            y = y>>1 ;

            x = (x*x)%m ;
        }
        return res; 
    }
    void tree(){
 int n ,m ;
    cin>>n>>m ;
    // int adj[n+1][n+1] = {0} ;
    // for(int i =0 ;i<m; i++){
    //     int u ,v ;
    //     cin>>u>>v ;
    //     adj[u][v] = 1 ;
    //     adj[v][u] = 1 ;

    // }  
    vector<int>adj[n+1] ;
    for(int i = 0 ;i<m ;i++){
        int u ,v ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    for (int i = 1; i <=n; ++i)
      {
          for (int j = 0; j <adj[i].size(); j++)
          {
              cout<<adj[i][j]<<" "; 
          }
          cout<<endl ;
      }  

    }


    int fibon(int n){
    
    if(n==0){
        return 0; 
    }   
    else if(n==1){
        return 1 ;
    }
    else{
        return fibon(n-1)+fib(n-2) ;
    }
        

       
    }
    void subseq(int idx ,vector<int>&ds ,vector<int>v ,int n){
        if (idx>=n)
        {
            for(auto it:ds){
                cout<<it<<" " ;
            }
             if (ds.size()==0)
        {
            cout<<"{}"<<" " ;
        }
            cout<<endl ;
            return ;
        }
        
        ds.push_back(v[idx]) ;
        subseq(idx+1 ,ds,v ,n) ;
        ds.pop_back() ;
        subseq(idx+1 ,ds,v ,n) ;
    }

     void subsum(int idx ,vector<int>&ds ,vector<int>v ,int n,int &s, int sum){
        if (idx<=n)
        {   
            if (s==sum)
            {for(auto it:ds){
                cout<<it<<" " ;
            }
            
            cout<<endl ;
            return ;
        }
    }
    else{
        return ;
    }
        
        ds.push_back(v[idx]) ;
        s+=v[idx] ;
        subsum(idx+1 ,ds,v ,n,s,sum) ;
        ds.pop_back() ;
        s-=v[idx] ;
        subsum(idx+1 ,ds,v ,n,s,sum) ;
    }
     bool fn(int idx ,vector<int>&nums ,int target ,vector<vector<int>>&dp){
        if(target == 0){
            return dp[idx][target] = true ;
        }
        if(idx<= 0 ){
            return dp[idx][target] = false;
        }
        // if(dp[idx][target] != 0) return dp[idx][target] ;
        int npick  = fn(idx-1 ,nums ,target ,dp) ;
        int pick = 0 ;
        if(nums[idx-1] <= target){
            pick = fn(idx-1 ,nums ,target-nums[idx-1],dp) ;
        }
        return  dp[idx][target] = pick | npick; 
    }
    
    
    // void kmp( ){//knuth moris pratt
    //     string s ,k ;
    //     cin>>s ;
    //     cin>>k ;
    //     int m = k.length() ;
    //     int n = s.length() ;
    //     int lps[m] = {0 ,0 ,1 ,2,0} ;
    //     //compute pls array 
    //     int i = 0 ;
    //     int j = 0 ;
    //     while(i<n){
    //         if(s[i]==k[j]){
    //             i++ ;j++ ;

    //         }
    //         if(j==m) cout<<"yes\n" ;
    //         else if(i<n and s[i]!=k[j]){
    //             if(j!=0) j = lps[j-1] ;
    //             else{
    //                 i= i+1 ;
    //             }
            
    //     }

    //       }

    int path(int x ,int y ,vector<vector<int>>&dp){
        
        if(x==0 and y==0){
        // cout<<"x="<<x<<"y="<<y<<endl ;

            return 1 ;
        }
        if(x<0 || y<0){
        // cout<<"x1="<<x<<"y1="<<y<<endl ;

            return 0 ;
        }
        // if(dp[x][y] !=-1) return dp[x][y] ;
        int up = path(x-1 ,y,dp) ;
        int left = path(x ,y-1,dp) ;

        return  up+left ; 
    }
   void solve(){
    int n ;
    int m ;
    cin>>n>>m;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int i=m;
    while(i!=m-1){
        cout<<v[i]<<" ";
        i = (i+1)%n;
    }
    cout<<v[i]<<" "<<endl ;
} 

    



    
   

int main(){
    // file();
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    

    
           //  ll t;
           //  cin>>t;
           // while(t--){

           //   solve() ;
           //  } 
        solve() ;

    return 0;

   

}
