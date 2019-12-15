#include<bits/stdc++.h>

using namespace std;

vector<string> correct;

bool match(string& W, string &S, int w_index, int p_index, int wsize, int psize){

    while(w_index < wsize && p_index < psize){  // 이 조건문이 매우 중요하다. 문자열문제에선 암기
        if(W[w_index] == S[p_index] || W[w_index] == '?'){
            w_index++;
            p_index++;
        }
        else break;
    }
    // while문이 끝난경우에는 둘중하나가 끝에 도달했거나 둘다 도달했거나 아니면 '*' 만난경우이다.
    if(w_index==wsize){
        return p_index==psize;
    }
    if(W[w_index]=='*'){

        for(int skip=0; p_index+skip<=psize; skip++){
            if(match(W,S,w_index+1,p_index+skip,wsize,psize)){
                return true;
            }

        }

    }
    return false;

}


int main(){

    int T,n;
    string W,Pattern;
    cin>>T;
    while(T--){
        cin>>W;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>Pattern;
            if(match(W,Pattern,0,0,W.length(),Pattern.length())){
                correct.push_back(Pattern);
            }
        }
        sort(correct.begin(),correct.end());
        for(auto& p: correct) cout<<p<<'\n';

    }



    return 0;
}