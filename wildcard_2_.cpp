#include<bits/stdc++.h>

using namespace std;

vector<string> correct;

bool match(string& W, string &S, int w_index, int p_index, int wsize, int psize){

    if(((w_index < wsize) && (p_index < psize)) && ((W[w_index] == S[p_index]) || (W[w_index] == '?'))){
        if(match(W,S,w_index+1,p_index+1,wsize,psize)) return true;
    }
    // while문이 끝난경우에는 둘중하나가 끝에 도달했거나 둘다 도달했거나 아니면 '*' 만난경우이다.
    if(w_index==wsize){
        return p_index==psize;
    }
    if(W[w_index]=='*'){
        if(((p_index<psize) && match(W,S,w_index,p_index+1,wsize,psize)) || match(W,S,w_index+1,p_index,wsize,psize)){ //p_index+1 = psize 까지 허용하는 이유는 첫 if문 충족시키기위해
            return true;
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