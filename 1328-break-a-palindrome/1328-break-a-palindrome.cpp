class Solution {
public:
    string breakPalindrome(string palindrome)
    {
      string ans="";
      int n=palindrome.size();
      if(n==1)
      return ans;
      int flag=0;
      for(int i=0;i<n;i++)
      {
        if(n%2==1&&palindrome[i]!='a'&&i!=n/2)
        {
          palindrome[i]='a';
          flag++;
          break;
        }
        else if(palindrome[i]!='a'&&n%2==0)
        {
          palindrome[i]='a';
          flag++;
          break;
        }
      }
      if(flag==0)
      palindrome[n-1]='b';
      return palindrome;
    }
};