#include<bits/stdc++.h>
#include<memory.h>
using namespace std;

int d[101][1001];
pair<int,int> volume_weight[101];
string surp[101];
vector<string> ans;

int proc(int index, int v, int n){

    int &ret = d[index][v];
    if(ret != -1) return ret;
    if(index > n) return 0;
    ret = 0;
    int con = 0; int ncon = 0;
    if(v - volume_weight[index].first >= 0){
        con = volume_weight[index].second + proc(index+1,v - volume_weight[index].first, n);
    }
    ncon = proc(index+1,v,n);
    return ret = max(con, ncon);
}

void pack(int index, int v, int n){

    if(index >= n) return;
    if(d[index][v] != d[index+1][v]){
        ans.push_back(surp[index]);
        pack(index+1,v-volume_weight[index].first,n);
    }
    else{
        pack(index+1,v,n);
    }
    return;
}

int main(){
    
    int T,n,tot,v,w;
    string x;
    cin>>T;
    while(T--){
        ans = vector<string>();
        memset(d,-1,sizeof(d));
        for(int i=0;i<=100;i++) volume_weight[i] = {0,0};
        cin>>n>>tot;
        for(int i=1;i<=n;i++){
            cin>>x>>v>>w;
            volume_weight[i] = {v,w}; 
            surp[i] = x;
        }
        cout<<proc(1,tot,n)<<" ";
        pack(1,tot,n);
        cout<<ans.size()<<"\n";
        for(auto &p:ans){
            cout<<p<<"\n";
        }
    }
    return 0;
}