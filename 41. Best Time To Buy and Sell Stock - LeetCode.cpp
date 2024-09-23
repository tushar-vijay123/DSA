class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestBuy = prices[0];
        int maxProfit = 0;

        // best selling day
        for(int i=1; i<n; i++)
        {
            int sellPrice = prices[i] - bestBuy;
            if(sellPrice > maxProfit)
            {
                maxProfit = sellPrice;
            }

            if(prices[i] < bestBuy)
            {
                bestBuy = prices[i];
            }
        }

        return maxProfit;
    }
};
