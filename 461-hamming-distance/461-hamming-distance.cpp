class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        bitset<32> a(x);
        bitset<32> b(y);
        int count=0;
        for(int i=0;i<32;i++)
        {
            count+=a[i]^b[i];
        }
        return count;
    }
};