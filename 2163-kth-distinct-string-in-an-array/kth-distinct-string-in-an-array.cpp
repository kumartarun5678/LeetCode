class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mpp;
        for(const auto& str : arr){
            mpp[str]++;
        }

        int cnt =0;
        for(const auto& str:arr){
            if(mpp[str] == 1){
                cnt++;
                if(cnt == k){
                    return str;
                }
            }
        }
        return "";
    }
};