#include<bits/stdc++.h>

using namespace std;

bool arefriends[10][10] = {false,};

int countParings(bool taken[10], int n){

    int ret = 0;
    int start = -1;
    for(int i = 0; i < n; i++){
        if(!taken[i]){
            start = i;
            break;
        }
    }
    if(start == -1) return 1;
    for(int i = start+1; i < n; i++){

        if(!taken[i] && arefriends[start][i] == true){

            taken[i] = taken[start] = true;
            ret+=countParings(taken, n);
            taken[i] = taken[start] = false;

        }

    }
    return ret;

}

int main(){

    int T,n,m,x,y;
    bool taken[10] = {false};
    cin>>T;
    while(T--){
        memset(arefriends,false,sizeof(arefriends));
        memset(taken,false,sizeof(taken));

        cin>>n>>m;
        while(m--){

            cin>>x>>y;
            arefriends[x][y] = true;
            arefriends[y][x] = true;

        }
        cout<<countParings(taken, n)<<'\n';
        
    }

    return 0;
}
