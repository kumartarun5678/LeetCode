class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumOfExistingRolls = 0;
        for(int i = 0; i < m; i++) {
            sumOfExistingRolls += rolls[i];
        }
        
        int totalRolls = m + n;
        int targetSum = mean * totalRolls;
        
        int sumOfMissingRolls = targetSum - sumOfExistingRolls;
    
        if (sumOfMissingRolls < n || sumOfMissingRolls > 6 * n) {
            return {};
        }
        
        vector<int> missingRolls(n, 1);
        sumOfMissingRolls -= n;
        
        for(int i = 0; i < n && sumOfMissingRolls > 0; i++) {
            int add = min(5, sumOfMissingRolls);
            missingRolls[i] += add;
            sumOfMissingRolls -= add;
        }
        
        return missingRolls;
    }
};
