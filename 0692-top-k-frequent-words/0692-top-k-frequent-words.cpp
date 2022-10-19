struct Compare
{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};
class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {

            unordered_map<string, int> m;
            for (string str: words)
            {
                m[str] += 1;
            }

            priority_queue<pair<int, string>, vector< pair<int, string>>, Compare> pq;
            for (auto &it: m)
            {
                pq.push({ it.second,
                    it.first });
            }

            vector<string> res;
            while (k--)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
            return res;
        }
};