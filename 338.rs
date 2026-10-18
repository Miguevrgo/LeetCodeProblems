pub fn count_bits(n: i32) -> Vec<i32> {
    let mut dp = vec![0i32; (n + 1) as usize];

    for i in 1..=n as usize {
        dp[i] = dp[i >> 1] + (i as i32 & 1);
    }

    dp
}
