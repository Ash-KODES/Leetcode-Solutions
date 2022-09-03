class Solution {
public:
    void Helper(int cur_len,int k,vector<int>& ans,int curr,int number,int size)
    {
        if(cur_len==size)
        {
            ans.push_back(number);
            return;
        }
        for(int i=0;i<10;i++)
        {
            if(abs(i-curr)==k)
            {
                Helper(cur_len+1,k,ans,i,number*10+i,size);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        for(int i=1;i<10;i++)
        {
            int number=i;
            Helper(1,k,ans,i,number,n);
        }
        return ans;
        
    }
};