class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++){
            board[i] = s;
        }
        helper(0,board,ans,n);
        return ans;
    }
    void helper(int i, vector<string>&board,vector<vector<string>>&ans,int n){
        if(i == n){
            ans.push_back(board);
            return;
        }
        for(int j = 0;j<n;j++){
            if(isSafe(j,i,board,n)){
                board[j][i] = 'Q';
                helper(i+1,board,ans,n);
                board[j][i] = '.';
            }
        }
    }
    bool isSafe(int i,int j, vector<string>&board,int n){
        int row = i;
        int col = j;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i = row;
        j = col;
        while(j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            j--;
        }
        i = row;
        j = col;
        while(j>=0 && i<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};