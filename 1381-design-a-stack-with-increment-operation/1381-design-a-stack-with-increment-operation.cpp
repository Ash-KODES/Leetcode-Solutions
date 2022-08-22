class CustomStack {
public:
    vector<int> v;
    int m;
    CustomStack(int maxSize) 
    {
        m=maxSize;
    }
    void push(int x)
    {
        if(v.size()!=m)
        {
            v.push_back(x);
        }      
    }
    
    int pop() 
    {
        if(v.size()>0)
        {
            int el=v[v.size()-1];
            v.pop_back();
            return el;
        }
        else
        return -1;
    }
    
    void increment(int k, int val)
    {
        for(int i=0;i<k;i++)
        {
            if(i==v.size())
            break;
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */