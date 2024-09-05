/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;
    void dfs(Node* node, Node* clone){
        for(Node* n:node->neighbors){
            if(mp.find(n) == mp.end()){
                Node *clone_node = new Node(n->val);
                mp[n] = clone_node;
                clone->neighbors.push_back(clone_node);
                dfs(n,clone_node);
            }
            else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }

        Node *clone_node = new Node(node->val);

        mp[node] = clone_node;

        dfs(node,clone_node);
        return clone_node;

    }
};