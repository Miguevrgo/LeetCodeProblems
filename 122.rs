fn max_profit(prices: Vec<i32>) -> i32 {
    prices.windows(2).map(|a| (a[1] - a[0]).max(0)).sum()
}

// First accepted solution: (Algorithmically its the best but
// it can be further simplified like above getting the same result)
// pub fn max_profit(prices: Vec<i32>) -> i32 {
//     if prices.is_empty() {
//         return 0;
//     }
//     let mut min_curr = prices[0];
//     let mut max_curr = prices[0];
//     let mut money = 0;
//     let mut buying = true;
//
//     for price in prices {
//         if buying {
//             if price <= min_curr {
//                 min_curr = price;
//             } else {
//                 buying = false;
//                 max_curr = price;
//             }
//         }
//
//         if !buying {
//             if price >= max_curr {
//                 max_curr = price;
//             } else {
//                 money += max_curr - min_curr;
//                 buying = true;
//                 min_curr = price;
//             }
//         }
//     }
//
//     if !buying {
//         money += max_curr - min_curr;
//     }
//
//     money
// }
