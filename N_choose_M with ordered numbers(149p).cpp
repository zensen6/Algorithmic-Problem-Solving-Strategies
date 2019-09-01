#include<bits/stdc++.h>

using namespace std;

// M = toPick
void pick(int n, vector<int>& picked, int toPick){
    if(toPick == 0){
        for(auto& p :picked){
            cout<<p<<' ';
        }
        cout<<'\n';
        return;
    }
    int back = (picked.size() == 0? 0 : picked.back()+1);
    for(int i = back; i<n; i++){

        picked.push_back(i);
        pick(n,picked,toPick-1);
        picked.pop_back();

    }
}

int main(){

    int n,m;
    vector<int> v;
    cin>>n>>m;
    pick(n,v,m);
    
    return 0;
}
