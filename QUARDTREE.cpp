#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<pair<int,int>> v;
    int x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
    auto& p = v.front();
    cout<<p.first<<'\n';
}


