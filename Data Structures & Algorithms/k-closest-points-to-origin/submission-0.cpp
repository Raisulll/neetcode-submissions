class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int, int>>> ans;
        for (auto &p : points) {
            int a=p[0], b=p[1];
            int dis= a*a+b*b;
            ans.push_back({dis,{a,b}});
        }
        sort(ans.begin(), ans.end(),
             [](const pair<int, pair<int, int>> x, const pair<int, pair<int, int>> y) {
                 return x.first < y.first;
             });
        int i=0;
        vector<vector<int>> ret;
        while(k--){
            ret.push_back({ans[i].second.first, ans[i].second.second});
            i++;
        }
        return ret;
    }
};
