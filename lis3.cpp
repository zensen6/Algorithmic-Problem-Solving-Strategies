#include<bits/stdc++.h>
#include<memory.h>

using namespace std;

vector<int> v;
int n;
int cache[101];
int stack0[101];

int lis3(int start){ // lis3(start) = lis2(start) 이다.
    int &ret = cache[start+1];
    if(ret!=-1) return ret;
    ret = 1;
    for(int next = start+1; next<n; next++){
        if(start==-1 || (v[next] > v[start])){
            int max = lis3(next)+1;  // 맨처음 lis3(0) 이 lis2(0)과 같기때문에 lis3(-1) 는 lis3(0) + 1이다. cout<<lis3(-1)-1<<'\n';
            if(max > ret){
                ret = max;
                stack0[start+1] = next;
            }
        }
    }
    return ret;
}

void recurse(int start){
    if(stack0[start+1]!=-1){
        cout<<v[stack0[start+1]]<<" ";
        recurse(stack0[start+1]);
    }
    else return;
}

int main(){

    memset(cache,-1,sizeof(cache));
    memset(stack0,-1,sizeof(stack0));
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    cout<<lis3(-1)-1<<'\n';
    //for(int i =0;i<n;i++) cout<<stack0[i]<<' ';
    recurse(-1);

    return 0;
}