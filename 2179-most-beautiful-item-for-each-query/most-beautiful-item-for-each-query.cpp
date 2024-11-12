class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       
        sort(items.begin(), items.end());
        
     
        vector<int> prices;
        vector<int> max_beauty;
        int current_max_beauty = 0;
        
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            if (!prices.empty() && prices.back() == price) {
                
                current_max_beauty = max(current_max_beauty, beauty);
                max_beauty.back() = current_max_beauty;
            } else {
               
                prices.push_back(price);
                current_max_beauty = max(current_max_beauty, beauty);
                max_beauty.push_back(current_max_beauty);
            }
        }
        
        vector<int> answer;
        for (int query : queries) {
           
            auto it = upper_bound(prices.begin(), prices.end(), query);
            if (it == prices.begin()) {
               
                answer.push_back(0);
            } else {
                
                int idx = it - prices.begin() - 1;
                answer.push_back(max_beauty[idx]);
            }
        }
        
        return answer;
    }
};
