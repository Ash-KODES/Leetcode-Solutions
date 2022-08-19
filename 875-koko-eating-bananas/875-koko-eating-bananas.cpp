class Solution {
public:
    //k->increase
    //FFFF"T"TTTTTT
    bool isvalid(vector<int>& piles, int h,long int k)
    {
        int time_required=0;
        for(auto val:piles)
        {
            time_required+=ceil((val*1.0)/k);
        }
        return (time_required<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long int lo=1;
        long int hi=1e9;
        while(hi-lo>1)
        {
            long int mid=(hi+lo)/2;
            if(isvalid(piles,h,mid))
            hi=mid;
            else
            lo=mid+1;
        }
        if(isvalid(piles,h,lo))
        return lo;
        else
        return hi;
    }
};