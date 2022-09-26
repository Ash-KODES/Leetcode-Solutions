class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int hi=tokens.size()-1;
        int lo=0;
        while(hi>=lo)
        {
            if(power>=tokens[lo])
            {
                score++;
                power-=tokens[lo];
                lo++;
            }
            else
            {
                if(score==0||hi==lo)
                break;
                score--;
                power+=tokens[hi];
                hi--;
            }   
        }
        return score;
    }
};