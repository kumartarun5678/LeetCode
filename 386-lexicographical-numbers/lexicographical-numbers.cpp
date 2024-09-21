class Solution {
public:
    void helper(int curr, int n, vector<int>&ans){
        if(curr>n){
            return;
        }
        ans.push_back(curr);
        for(int i =0;i<=9;i++){
            int newnum  = curr*10+i;

            if(newnum>n){
                return;
            }
            helper(newnum,n,ans);
        }
        
    } 
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
            helper(i,n,ans);
         return ans;
    }
};