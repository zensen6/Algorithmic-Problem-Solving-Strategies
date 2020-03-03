#include<bits/stdc++.h>
#include<memory.h>
using namespace std;
const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[501];

int lis(int start){

    int &ret = cacheLen[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next<n; next++){
        if(start == -1 || S[start] < S[next]){
            ret = max(ret,lis(next)+1);
        }
    }
    return ret;
}

int count(int start){

    if(lis(start) == 1) return 1;
    int &ret = cacheCnt[start+1];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = start+1; next<n; next++){
        if((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1){
            ret = min<long long>(MAX,(long long)ret + count(next));
        }
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int>& lis_v){

    if(start != -1) lis_v.push_back(S[start]);
    vector<pair<int,int>> followers;
    for(int next = start+1; next<n; next++){
        if((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1){
            followers.push_back({S[next],next});
        }
    }
    sort(followers.begin(),followers.end());
    for(int i=0;i<followers.size();i++){
        if(skip - count(followers[i].second)>0){
            skip -= count(followers[i].second);
        }else{
            reconstruct(followers[i].second, skip, lis_v);
            break;
        }
    }
}

int main(){

    int T,k;
    cin>>T;
    while(T--){
        vector<int> ans;
        memset(S,-1,sizeof(S));
        memset(cacheLen,-1,sizeof(cacheLen));
        memset(cacheCnt,-1,sizeof(cacheCnt));
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        lis(-1);
        count(-1);
        reconstruct(-1,k,ans);
        cout<<ans.size()<<'\n';
        for(auto &p: ans){
            cout<<p<<" ";
        }cout<<"\n";
    }

    return 0;
}