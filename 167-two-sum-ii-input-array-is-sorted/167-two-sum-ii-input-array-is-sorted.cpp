class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
      int front=0;
      int back=numbers.size()-1;
      vector<int> ans;
      while(front<back)
      {
        if(numbers[front]+numbers[back]==target)
        {
          ans.push_back(front+1);
          ans.push_back(back+1);
          return ans;
        }
        if(numbers[front]+numbers[back]>target)
        {
          back--;
        }
        else
          front++;
      }
      return ans;
    }
};