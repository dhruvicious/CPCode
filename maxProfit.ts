function maxProfit(prices: number[]): number {
    let minPrice: number = Number.MAX_VALUE;
    let maxProfit: number = 0;
    for (let p of prices) {
        minPrice = Math.min(minPrice, p);
        maxProfit = Math.max(maxProfit, p - minPrice);
    }
    return maxProfit;
}