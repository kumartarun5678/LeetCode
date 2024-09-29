class AllOne {
public:
    struct Node{
        int cnt;
        list<string>keys;
        Node* prev;
        Node*next;
        Node(int c){
            cnt = c;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<string,Node*>mp;
    Node*head;
    Node*last;
    void addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if(prevNode == last){
            last = newNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next =node->next;
        if(node->next != NULL){
            node->next->prev = node->prev;
        } 
        if(last == node){
            last = node->prev;
        }
        delete node;
    }
    AllOne() {
        head = new Node(0);
        last = head;
    }
    void inc(string key) {
       if(mp.find(key) == mp.end()){
            if(head->next == nullptr || head->next->cnt != 1){
                addNode(head,1);
            }
            head->next->keys.push_front(key);
            mp[key] = head->next;
       }
       else{
            Node* currNode = mp[key];
            int currCnt = currNode->cnt;
            if(currNode->next == nullptr || currNode->next->cnt != currCnt+1){
                addNode(currNode,currCnt+1);
            }
            currNode->next->keys.push_front(key);
            mp[key] = currNode->next;
            currNode->keys.remove(key);
            if(currNode->keys.empty()){
                removeNode(currNode);
            }
       }
    }
    
    void dec(string key) {
        Node* currNode  = mp[key];
        int currCnt = currNode->cnt;
        if(currCnt == 1){
            mp.erase(key);
        }
        else{
            if(currNode->prev->cnt != currCnt - 1){
                addNode(currNode->prev, currCnt - 1);
            }
            currNode->prev->keys.push_front(key);
            mp[key] = currNode->prev;
        }
        currNode->keys.remove(key);
        if(currNode->keys.empty()){
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        if(last == head){
            return "";
        }
        return last->keys.front();
    }
    
    string getMinKey() {
        if(head->next == nullptr){
            return "";
        }
        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */