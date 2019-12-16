#include<bits/stdc++.h>
#include<memory.h>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int A[101];
int B[101];
int cache[101][101];

int jlis(int indexA, int indexB, int n, int m){

    int &ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;
    ret = 2;
    long long a = (indexA == -1? NEGINF : A[indexA]);
    long long b = (indexB == -1? NEGINF : B[indexB]);
    long long maxElement = max(a,b);
    for(int nextA = indexA+1; nextA<n; nextA++){
        if(A[nextA] > maxElement){
            ret = max(ret,1+jlis(nextA,indexB,n,m));
        }
    }
    for(int nextB = indexB+1; nextB<m; nextB++){
        if(B[nextB] > maxElement){
            ret = max(ret,1+jlis(indexA,nextB,n,m));
        }
    }
    return ret;

}

int main(){

    int T;
    cin>>T;
    while(T--){

        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(cache,-1,sizeof(cache));

        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int j=0;j<m;j++){
            cin>>B[j];
        }
        cout<<jlis(-1,-1,n,m)-2<<'\n';

    }

    return 0;
}