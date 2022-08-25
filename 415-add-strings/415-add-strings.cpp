class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int n1=num1.size();
        int n2=num2.size();
        int diff=abs(n1-n2);
        string add="";
        while(diff>0)
        {
            add.push_back('0');
            diff--;
        }
        if(n1>n2)
        num2=add+num2;
        else
        num1=add+num1;
        string ans="";
        int carry=0;
        int res=0;
        int loop=max(n1,n2);
        int ind=max(n1,n2)-1;
        while(loop--)
        {
            res=(num1[ind]-'0')+(num2[ind]-'0')+carry;
            ans.push_back(res%10+'0');
            carry=res/10;
            ind--;
        }
        if(carry!=0)
        ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};