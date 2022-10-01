class Solution {
public:
    char parent[200];
  
    void make(char c)
    {
      parent[c]=c;
    }
    
    char find(char c)
    {
      if(parent[c]==c)
      return c;
      return find(parent[c]);
    
    }
    
    void unite(char c,char d)
    {
      c=find(c);
      d=find(d);
      if(c!=d)
      parent[c]=d;
    }
  
    bool equationsPossible(vector<string>& equations)
    {
        for(auto val:equations)
        {
            char x=val[0];
            char y=val[3];
            if(parent[x]==0)
            make(x);
            if(parent[y]==0)
            make(y);
            if(val[1]=='=')
            unite(x,y);
        }
        int flag=0;
        for(auto val:equations)
        {
          if(val[1]=='!')
          {
            if(find(val[0])==find(val[3]))flag++;
          }
        }
        if(flag==0)
        return 1;
        else
        return 0;
    }
};