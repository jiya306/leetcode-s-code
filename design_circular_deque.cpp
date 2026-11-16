class MyCircularDeque {
public:
    vector<int> arr;
    int size;
    int front;
    int rear;
    

    MyCircularDeque(int k) {
        size=k;
        arr.resize(k);
        rear=-1;
        front=-1;
    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            front =0;
            rear=0;
        }
        else
        {
            front=(front - 1 + size) % size;
        }
        arr[front]=value;

        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=value;
        return true;

    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front + 1)%size;
        }

        return true;

        
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
           rear=(rear-1  + size ) % size;
        }

        return true;
        
    }
    
    int getFront() {
        if(front == -1)
        {
            return -1;
        }

        return arr[front];
        
    }
    
    int getRear() {
        if(front == -1)
        {
            return -1;
        }

        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
        
    }
    
    bool isFull() {

        return (rear +1) % size == front;
        
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
