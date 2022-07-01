class MyCircularQueue {
private:
    vector<int> data;
    int size = 0;
    int s = -1, e = -1;
public:
    
    MyCircularQueue(int k) {
        
        cout << "\n\n\n";
        size = k;
        data.resize(k, INT_MIN);
    }
    
    bool enQueue(int value) {
        // cout << "ENQUE : " << s << " " << e << endl;
        if (isFull())
        {
            return false;
        }
        else
        {
            if (e == size-1)
            {
                e = 0;
            }
            else
            {
                e++;
            }
            
            if (s == -1)
                s++;
            
            data[e] = value;
            
            return true;
        }
    }
    
    bool deQueue() {
        // cout << "DEQUE : " << s << " " << e << endl;
        if (isEmpty())
        {
            return false;
        }
        else
        {
            if (s == e)
            {
                if (data[s] != INT_MIN)
                {
                    data[s] = INT_MIN;
                    s = -1;
                    e = -1;
                    return true;
                }
                
            }
            
            data[s] = INT_MIN;
            if (s == size-1)
            {
                s = 0;
            }
            else
            {
                s++;
            }
            return true;
        }
    }
    
    int Front() {
        
        if (s == -1)
            return s;
        
        return data[s];
    }
    
    int Rear() {
        
        if (e == -1)
            return e;
        
        return data[e];
    }
    
    bool isEmpty() {
        
        if ((s == -1 and e == -1) or (data[s] == INT_MIN))
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if ((e == size-1 and s == 0) or (e+1 == s))
            return true;
        else
            return false;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */