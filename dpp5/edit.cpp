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



int edit(int i ,int j , string s ,string t ,vector<vector<int>>&dp){
        if(i<0) return j+1 ;
        if(j<0) return i+1 ;
         
        if(dp[i][j] != -1 ) return dp[i][j] ;

        if(s[i]==s[j]){
            return  dp[i][j] = edit(i-1 ,j-1 ,s ,t,dp) ;
        }

        return dp[i][j] = (1 + min(edit(i-1 ,j ,s, t,dp) ,min(edit(i ,j-1 ,s,t,dp) ,edit(i-1 ,j-1 ,s,t,dp)))) ;
    }
   void solve(){
    string s; 
    string t ;
    cin>>s; 
    cin>>t ;
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>>dp(n+1 ,vector<int>(m+1 ,-1)) ;
    int z = edit(n-1 ,m-1 ,s,t ,dp) ;
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
