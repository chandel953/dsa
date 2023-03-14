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
    void st(int n ,int k){
        cout<<(n|(1<<(k-1)) );

    }
    // int lcs(int i ,int j ,string s ,string l ,vector<vector<int>>&dp){
    //     if(i<0 || j<0){
    //         return 0 ;
    //     }
    //     // if(dp[i][j] != -1) return dp[i][j] ;
    //     if(s[i]==l[j]){
    //     return (1 + lcs(i-1 ,j-1 ,s ,l,dp) ) ;
    //     }
    
    // return  (0 + max(lcs(i ,j-1 ,s ,l,dp) ,lcs(i-1 ,j ,s ,l,dp)) ) ;


    // }
    int mcm(int i ,int j , vector<int>&arr, vector<vector<int>>&dp){

        if(i>=j) return 0 ;
        int mini = 1e8;
        int steps = 1 ;
        if(dp[i][j] !=-1) return dp[i][j] ;
        for(int k = i ;k<=j-1 ; k++){
            steps = arr[i-1]*arr[k]*arr[j] + mcm(i ,k ,arr,dp) +mcm(k+1 ,j ,arr,dp) ;
            mini = min(mini ,steps) ;
        }
        return  dp[i][j] =  mini;
    }

    int lcs(string s ,string k ,int i ,int j ,vector<vector<int>>&dp){
       
        if(i<0 || j<0) return 0 ;
        if(dp[i][j] != -1 ) return dp[i][j]  ;
        if(s[i]==k[j]){
            return dp[i][j] = lcs(s ,k ,i-1 ,j-1,dp) + 1 ;
        }
        return dp[i][j] = (max(lcs(s,k ,i-1 ,j ,dp) , lcs(s,k ,i ,j-1,dp) )+ 0) ;
    }
    int egg(int i ,int j){
        if(i==1 || j==0 || j==1) return j ;
        int mini = INT_MAX ;
        for(int k = i ;k<=j-1 ;k++){
            int temp = max(egg(i-1 ,j-1) ,egg(i,j-k))+1;
            mini = min(mini ,temp) ;
        }
        return mini ;
    }
    int knap(vector<int>&wt ,vector<int>&v ,int i ,int w ,vector<vector<int>>&dp){
        if(i<0 || w==0){
            return 0 ;
        }
        if(dp[i][w] != -1) return dp[i][w] ;
        int pick= 0 ;
        if(w>=wt[i]){
            pick = knap(wt ,v ,i-1 ,w- wt[i],dp) + v[i];
        }
        int npick = knap(wt ,v,i-1,w,dp) ;

        return dp[i][w] = max(pick ,npick) ;
    }
   void solve(){
    string s ;
    string k ;
    cin>>s ;
    cin>>k ;
    int n = s.size()-1 ;
    vector<vector<int>>dp(n+1 ,vector<int>(n+1 ,-1)) ;

    int z = lcs(s ,k ,n ,n ,dp) ;
    cout<<z<<endl ;

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
    // int n ;
    // int k ;
    // cin>>n ;
    // cin>>k ;
    //     st( n , k) ;

        solve() ;

    return 0;

   

}
