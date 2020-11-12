class Solution {
    void helper(int n, int i,vector<int> visited,int &ans){
        if(i > n){
            ans++;
        }
        for(int j = 1; j <= n; j++){
           if(visited[j] == 0 && (j%i == 0 || i %j == 0)){
               visited[j] = 1;
               helper(n,i+1,visited,ans);
               visited[j] = 0;
           }
        }
    }
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<int> visited(n+1,0);
        helper(n,1,visited,ans);
        return ans;
    }
};
