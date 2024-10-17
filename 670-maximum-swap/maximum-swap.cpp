class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>hash(10,-1);
        for(int i=0;i<n;i++){
            int ind=s[i]-'0';
            hash[ind] = i;
        }

        for(int i= 0;i<n;i++){
            char curr = s[i] ;
            int currd = curr-'0';
            for(int j = 9;j>currd;j--){
                if(hash[j]>i){
                    swap(s[i],s[hash[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};