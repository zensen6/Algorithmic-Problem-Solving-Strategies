#include<bits/stdc++.h>
#include<memory.h>
#define MOD 10000000LL

using namespace std;
typedef long long ll;
ll d[101][101];

ll proc(int n, int m){

    ll& ret = d[n][m];
    if(ret != 0) return ret;
    if(n==1 || n==m) return 1LL;
    ll sum = 0;
    for(int start=1; start<=n-m; start++){
        sum += ((proc(n-m,start)%MOD)*(m+start-1))%MOD;
    }
    sum%=MOD;
    return ret = sum;
}
int main(){

    memset(d,0,sizeof(d));
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        ll sum = 0;
        for(int i=1;i<=n;i++){
            sum += proc(n,i)%MOD;
        }
        cout<<sum%MOD<<'\n';
    }

    return 0;
}