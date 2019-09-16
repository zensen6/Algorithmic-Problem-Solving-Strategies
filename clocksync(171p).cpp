#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16, MAXSW = 4;
char linked[SWITCHES][CLOCKS+1] = {

    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks){

    bool aligned = true;
    for(auto &p : clocks){

        if(p != 12) aligned = false;

    } 
    return aligned;
}

void push(vector<int>& clocks, int swtch){

    for(int i=0;i<CLOCKS; i++){
        if(linked[swtch][i] == 'x'){

            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;

        }
    }
    return;
}

int solve(vector<int>& clocks, int swtch){

    int ans = INF;
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF; // 탈출조건처리 중요
    for(int i=0; i < MAXSW ; i++){

        ans = min(ans, i + solve(clocks,swtch+1));
        push(clocks, swtch);

    }
    return ans;
}


int main(){

    vector<int> clock0;
    int T, x;
    cin>>T;
    while(T--){

        clock0.clear();
        for(int i=0;i<CLOCKS;i++){

            cin>>x;
            clock0.push_back(x);

        }
        cout<<solve(clock0,0)<<'\n';

    }

    return 0;
}
