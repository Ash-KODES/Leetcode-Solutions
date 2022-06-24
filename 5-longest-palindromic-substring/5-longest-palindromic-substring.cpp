class Solution {
public:
    string longestPalindrome(string s) 
    {
      int ans=1;
      pair<int,int> p={0,0};
      for(int i=0;i<s.size();i++)
      {
        int j=1;
        int len=1;
        while(i+j<s.size()&&i-j>=0)
        {
          if(s[i+j]==s[i-j])
          {
            len+=2;
            if(len>ans)
            {
              p={i-j,i+j};    
              ans=len;
            }
            j++;
          }
          else
          break;
        }
        int x=i+1;
        int y=i;
        while(x<s.size()&&y>=0)
        {
          if(s[x]==s[y])
          {
            if(x-y+1>ans)
            {
              p={y,x};    
              ans=x-y+1;
            }
            x++;
            y--; 
          }
          else
          break;
        }   
      }
      string temp="";
      for(int i=p.first;i<=p.second;i++)
      temp.push_back(s[i]);
      cout<<endl;
      return temp;
    }
};