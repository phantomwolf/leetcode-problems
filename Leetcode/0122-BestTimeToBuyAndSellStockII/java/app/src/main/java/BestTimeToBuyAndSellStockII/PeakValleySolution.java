package BestTimeToBuyAndSellStockII;

public class PeakValleySolution {
    public int maxProfit(int[] prices) {
        int totalProfit = 0;
        int N = prices.length;
        int valley = 0, peak = 0;
        int i = 0;
        while (i + 1 < N) {
            // Find valley
            while (i + 1 < N && prices[i] >= prices[i + 1]) {
                i++;
            }
            valley = prices[i];
            // Find peak
            while (i + 1 < N && prices[i] <= prices[i + 1]) {
                i++;
            }
            peak = prices[i];
            // Profit of this transaction
            totalProfit += peak - valley;
        }
        return totalProfit;
    }
}
