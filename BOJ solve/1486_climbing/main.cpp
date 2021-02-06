#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
 
vector<ll> num;
ll dis[1010][1010];
ll arr[101][101];
ll arr2[1010];
string s;
ll inf =1e9+7;
ll di[4]={0,1,0,-1};
ll dj[4]={1,0,-1,0};
 
int main(){
    ll i,j,k,l,m,n,t,d;
    cin>>n>>m>>t>>d;
    for(i=1;i<=n;i++){
        cin>>s;
        for(j=1;j<=m;j++){
            num.pb(i*m+j);
            if('a'<=s[j-1]&&s[j-1]<='z')
                arr[i][j]=s[j-1]-'a'+26;
            else arr[i][j]=s[j-1]-'A';
            arr2[i*m+j]=arr[i][j];
        }
    }
 
    for(i=1;i<=1000;i++)
        for(j=1;j<=1000;j++)
            if(i!=j)
                dis[i][j]=inf;
 
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)    
                for(ll x=0;x<=4;x++){
                    k=i+di[x];
                    l=j+dj[x];
                    if(k<1||l<1||k>n||l>m) continue;
                    ll a=i*m+j;
                    ll b=k*m+l;
                    if(abs(arr[i][j]-arr[k][l])>t) continue;
                    if(arr[i][j]>=arr[k][l]) dis[a][b]=1;
                    else dis[a][b]=(arr[i][j]-arr[k][l])*(arr[i][j]-arr[k][l]);
                }
 
    for(auto k:num)
        for(auto i:num)
            for(auto j:num)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
 
    ll ans=0;
    for(auto k:num){
        //cout<<k<<' '<<dis[m+1][k]<<' '<<dis[k][m+1]<<'\n';
        if(dis[m+1][k]+dis[k][m+1]<=d) ans=max(ans,arr2[k]);
    }
    cout<<ans;
}
