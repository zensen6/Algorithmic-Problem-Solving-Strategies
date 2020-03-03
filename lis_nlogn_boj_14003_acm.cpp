#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> ans;
vector<pair<int,int>> track;

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!ans.size() || ans[ans.size()-1] < v[i]){
            ans.push_back(v[i]);
            track.push_back({ans.size()-1,v[i]});
        }else{
            ans[lower_bound(ans.begin(),ans.end(),v[i])-ans.begin()] = v[i];
            track.push_back({lower_bound(ans.begin(),ans.end(),v[i])-ans.begin(),v[i]});
        }
    }
    int idx = ans.size()-1;
    stack<int> st;
    for(int i=track.size()-1 ; i>=0 ; i--){
        if(idx == track[i].first){
            st.push(track[i].second);
            idx--;
        }   
    }
    cout<<ans.size()<<'\n';
    /*
    for(int i=0;i<n;i++){
        cout<<track[i].first<<" "<<track[i].second<<'\n';
    }*/
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
   
    return 0;
}