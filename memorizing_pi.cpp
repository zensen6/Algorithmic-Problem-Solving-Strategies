#include<bits/stdc++.h>
#include<memory.h>

using namespace std;

const int MAX = 987654321;

int cache[101];

int classify(int start, int end, string &x){ //[start,end]

    bool althesame = true;
    for(int cur = start+1; cur<=end; cur++){
        if(x[cur] != x[cur-1]) althesame = false;
    }
    if(althesame) return 1;

    bool progressive = true;
    int d = int(x[start+1]-'0') - int(x[start]-'0');
    for(int cur = start+1; cur<=end; cur++){
        if((int(x[cur]-'0') - int(x[cur-1]-'0')) != d) progressive = false;
    }
    if(progressive){
        if(d == 1) return 2;
        else return 5;
    }

    bool alternating = true;
    for(int cur = start; cur<=end; cur++){
        if((cur%2) == (start%2)){
            if(x[cur]!=x[start]){
                alternating = false;
            }
        }
        else{
            if(x[cur]!=x[start+1]){
                alternating = false;
            }

        }
    }
    if(alternating) return 4;

    return 10;
}

int go(int index, int len, string& x){

    if(index == len) return 0;
    int &ret = cache[index];
    if(ret!=-1) return ret;
    ret = MAX;
    for(int slen = 3; slen<=5; slen++){
        int plus = classify(index, index+slen-1, x);
        ret = min(ret, plus+go(index+slen,len,x));
    }

    return ret;
}


int main(){

    int n;
    string x;
    cin>>n;
    while(n--){

        memset(cache,-1,sizeof(cache));
        cin>>x;
        int len = x.length();
        cout<<go(0,len,x)<<'\n';

    }

    return 0;
}