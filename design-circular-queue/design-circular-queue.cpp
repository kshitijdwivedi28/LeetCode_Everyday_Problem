class MyCircularQueue {
private:
    vector<int> data;
    int size = 0;
    int s = -1, e = -1;
    
public:
    
    MyCircularQueue(int k) {

        size = k;
        data.resize(k, INT_MIN);
    }
    
    bool enQueue(int value) 
    {
        if (isFull())   return false;
        
        else
        {
            e = (e == size - 1) ? 0 : ++e;
            
            if (s == -1) s++;
            
            data[e] = value;
            
            return true;
        }
    }
    
    bool deQueue() 
    {
        if (isEmpty())  return false;
        
        else
        {
            data[s] = INT_MIN;
            
            if (s == e)
                s = e = -1;
            else
                s = (s == size-1) ? 0 : ++s;

            return true;
        }
    }
    
    int Front() 
    {
        return s == -1 ? s : data[s];
    }
    
    int Rear() 
    {
        return e == -1 ? e : data[e];
    }
    
    bool isEmpty() 
    {
        if ((s == -1 and e == -1) or (data[s] == INT_MIN))  return true;
        else return false;
    }
    
    bool isFull() 
    {
        if ((e == size-1 and s == 0) or (e+1 == s))     return true;
        else    return false;
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