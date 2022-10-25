class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      string string1="";
      string string2="";
      for(auto val:word1)
      string1+=val;
      for(auto val:word2)
      string2+=val;
      return string1==string2;
    }
};