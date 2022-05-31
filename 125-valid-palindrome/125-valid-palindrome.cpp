class Solution {
public:
    bool isPalindrome(string s) 
    {
      string temp="";
      for(int i=0;i<s.size();i++)
      {
        if(s[i]>64&&s[i]<91)
        temp.push_back('a'+(s[i]-'A'));
        else if(s[i]>96&&s[i]<123)
        temp.push_back(s[i]);
        else if(s[i]>47&&s[i]<58)
        temp.push_back(s[i]);
      }
      string rev=temp;
      cout<<rev<<endl;
      reverse(rev.begin(),rev.end());
      return (rev==temp);
        
        
    }
};