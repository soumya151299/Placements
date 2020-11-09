#include<bits/stdc++.h>
using namespace std;
int min(int a,int b){
    return a>b?b:a;
}
int backtrack(vector <int> &B,int ind,int N){
    if(N == 0){
        return 1;
    }
    if(ind == B.size() && N > 0){
        return 0;
    }
    if(B.size() - 1 == ind && N <= B[ind]){
        return 1;
    }
    if(B.size() - 1 == ind && N > B[ind]){
        return 0;
    }
    int s = 0;
    for(int i=0;i<min(B[ind]+1,N+1);i++){
        s += backtrack(B,ind+1,N - i);
    }
    return s;
}
int solve(vector <int> &B,int N){
    return backtrack(B,0,N);
}
int main() {
    int N,M;
    std::cin >> M >> N;
    vector <int> A;
    vector <int> B;
    int s = 0;
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        A.push_back(x);
        s += x;
        B.push_back(y - x);
    }
    if(N < s){
        std::cout << 0 << std::endl;
    }
    else{
        if(N == s){
            cout << 1 ;
        }
        else{
            int x = solve(B,N - s);
            cout << x;
        }
    }
	return 0;
}
