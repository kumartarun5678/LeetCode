struct trieNode{
    int pcnt = 0;
    trieNode* child[26];
};
class Solution {
public:
    trieNode* getTrieNode(){
        trieNode* NewNode = new trieNode();

        for(int i=0;i<26;i++){
            NewNode->child[i] = nullptr;
        }
        NewNode->pcnt = 0;
        return  NewNode;
    }

    void insert(string &word, trieNode* root){
        trieNode* ans = root;
        for(auto & ch:word){
            int  i = ch - 'a';

            if(!ans->child[i]){
                ans->child[i] = getTrieNode();
            }
            ans->child[i]->pcnt+=1;
            ans = ans->child[i];
        }
    }

    int getScore(string& word,trieNode* root){
        trieNode* ans = root;
        int score = 0;
        for(char &ch : word){
            int i = ch - 'a';
            score += ans->child[i]->pcnt;
            ans = ans->child[i];
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode *node=  getTrieNode(); 
        for(auto &word:words){
            insert(word,node);
        }
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i] = getScore(words[i],node);
        }
        return ans;
    }
};