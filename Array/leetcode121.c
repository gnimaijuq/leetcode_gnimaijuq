// int maxProfit(int* prices, int pricesSize){
//     int ret = 0;
//     int profit = 0;
//     int b_index = 0;
//     int s_index = 0;
//     int b2_index = 0;
//     for (int i = 0; i < pricesSize - 1; i ++) {
//         if (prices[i] > prices[b_index]) {
//             continue;
//         }

//         if (s_index) {
//             if (i < s_index) {
//                 profit = prices[s_index] - prices[i];
//                 if (profit > ret) {
//                     b_index = i;
//                     ret = profit;
//                 }
//                 continue;
//             } else {
//                 profit = prices[s_index] - prices[i];
//                 if (profit > ret) {
//                     b2_index = i;
//                 }
//             }
//         }

//         for (int j = pricesSize - 1; j >= i; j --) {
//             profit = prices[j] - prices[i];
//             if (profit > ret) {
//                 b_index = i;
//                 s_index = j;
//                 ret = profit;
//             }
//         }
//     }

//     if (b2_index) {
//         for (int i = pricesSize - 1; i > b2_index; i --) {
//             profit = prices[i] - prices[b2_index];
//             if (profit > ret) {
//                 ret = profit;
//             }
//         }
//     }

//     return ret;
// }

// 官方解答
int maxProfit(int* prices, int pricesSize) {
    int minPrice = 100000;
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i ++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}
