#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int h[100001];

ll solve(int low, int high){         //in range of [low,high]

    ll ret = 0;
    if(low == high) return ll(h[low]);
    int mid = (low+high)/2;
    ret = max(solve(low,mid) , solve(mid+1,high));
    int lo = mid; int hi = mid+1;
    int minheight = min(h[lo], h[hi]);

    ret = max(ret, ll(2*minheight)); //important
    while(lo > low || hi < high){

        if(hi < high && ((lo == low) || h[lo-1] < h[hi+1])){

            ++hi;
            minheight = min(minheight,h[hi]);

        }
        else{

            --lo;
            minheight = min(minheight,h[lo]);

        }
        ret = max(ret, ll(minheight * (hi - lo + 1)));

    }
    return ret;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    do{

        cin>>T;
        if(T==0) break; 
        memset(h,0,sizeof(h));
        for(int i=0;i<T;i++){
            cin>>h[i];
        }
        cout<<solve(0,T-1)<<'\n';

    }while(T>0);


    return 0;
}
