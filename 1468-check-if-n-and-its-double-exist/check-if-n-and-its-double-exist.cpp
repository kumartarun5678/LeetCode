class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        unordered_set<int> st;
        for (int num : arr) {
            if (st.count(2 * num) || (num % 2 == 0 && st.count(num / 2))) {
                return true;
            }
            st.insert(num);
        }
        return false;
    }
};