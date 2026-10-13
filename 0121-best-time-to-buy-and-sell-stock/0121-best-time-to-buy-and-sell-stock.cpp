class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];
        int mp=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]>bestbuy)
            {
                mp=max(mp,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
        return mp;
    }
};