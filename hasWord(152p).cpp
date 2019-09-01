#include<bits/stdc++.h>

using namespace std;

char board[100][100];
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
int height;
int width;

bool inrange(int y, int x){

    if(y>=height || y<0 || x>=width || x<0) return false;
    return true;

}

bool hasWord(int y, int x, const string& word){

    if(!inrange(y,x)) return false;
    if(board[y][x] != word[0]) return false;
    if(word.length() == 1) return true;
    int ny,nx;
    for(int dir = 0; dir<8; ++dir){

        ny = y + dy[dir];
        nx = x + dx[dir];
        if(hasWord(ny, nx, word.substr(1))) return true;  // structing here is the most important part
        
    }
    return false; // also important
}

int main(){

    string str;

    cin>>height>>width;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            cin>>board[i][j];

        }
    }  
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            cout<<board[i][j];

        }
        cout<<'\n';
    }
    cout<<"input string:";
    cin>>str;
    bool ithasword = false;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            if(hasWord(i,j,str)) ithasword = true;

        }
    }
    if(ithasword) cout<<"YES"<< '\n';
    else cout<<"NO"<<'\n';

    return 0;
}
