class MyCircularDeque {
public:
    vector<int> dq;
    int k;
    int rear;
    int front;
    int currentCount;

    MyCircularDeque(int K) {
        k = K;
        dq = vector<int>(k,0);
        rear = k-1;
        front =0;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front-1+k)%k;
        dq[front] = value;
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear+1)%k;
        dq[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front  = (front+1)%k;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear-1+k)%k;
        currentCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dq[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dq[rear];
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */