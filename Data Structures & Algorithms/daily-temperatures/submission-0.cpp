class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>ans(temperatures.size(),0);
        for(int i=0; i<temperatures.size(); ++i){
            if(st.empty()){
                st.push({temperatures[i],i});
                continue;
            }
            while(!st.empty() and temperatures[i]>st.top().first){
                pair<int,int>x=st.top();
                st.pop();
                ans[x.second]=i-x.second;
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
