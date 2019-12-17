#include<bits/stdc++.h>
#include<cstring>
#include<memory.h>

using namespace std;

const int MAX = 987654321;

int cache[101];
string x;

int classify(int start, int end){ //[start,end]

    //string M = x.substr(start,end-start+1);
    //if(M == string(M.size(),M[0])) return 1;
    bool same = true;
    auto boolfunc = [](char a, char b){ if(a!=b) return false; else return true;};
    auto funczero = [](bool bow){ return bow; };
    for(int cur = start+1;cur<=end; cur++){
        if(!boolfunc(x[cur-1],x[cur])) same = false;
    }
    if(funczero(same)) return 1;

    bool progressive = true;
    int d = int(x[start+1]-'0') - int(x[start]-'0');
    for(int cur = start+1; cur<=end; cur++){
        if((int(x[cur]-'0') - int(x[cur-1]-'0')) != d) progressive = false;
    }
    if(funczero(progressive)){
        if(d == 1) return 2;
        else return 5;
    }

    bool alternating = true;
    for(int cur = start; cur<=end; cur++){
        if((cur%2) == (start%2)){
            if(x[cur] != x[start]) alternating = false;
        }else{
            if(x[cur]!=x[start+1]) alternating = false;
        }
    }
    if(funczero(alternating)) return 4;
    return 10;
}

int go(int index, int len){

    if(index == len) return 0;
    int &ret = cache[index];
    if(ret!=-1) return ret;
    ret = MAX;
    for(int slen = 3; slen<=5; slen++){
        int plus = classify(index, index+slen-1);
        ret = min(ret, [](int a,int b){return a+b;}(plus,go(index+slen,len)));
    }

    return ret;
}

int main(){

    int n;
    cin>>n;
    while(n--){

        memset(cache,-1,sizeof(cache));
        cin>>x;
        int len = x.length();
        cout<<go(0,len)<<'\n';

    }

    return 0;
}