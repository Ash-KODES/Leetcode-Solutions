class MedianFinder
{
    public:
        priority_queue<int> maxi;
    priority_queue<int, vector < int>, greater < int>> mini;
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxi.empty() || maxi.top() > num)
            maxi.push(num);
        else
            mini.push(num);
        if (maxi.size() > mini.size() + 1)
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        else if (maxi.size() + 1 < mini.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian()
    {
        if (maxi.size() > mini.size())
            return maxi.top();
        if (maxi.size() < mini.size())
            return mini.top();
        return (1.0 *maxi.top() + mini.top()) / 2;
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */