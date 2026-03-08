fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut freqs = HashMap::with_capacity(nums.len());
    let mut freq_buckets = vec![vec![]; nums.len()];

    nums.iter()
        .for_each(|&num| *freqs.entry(num).or_insert(0) += 1);

    freqs
        .iter()
        .for_each(|(&num, &count)| freq_buckets[count - 1].push(num));

    freq_buckets
        .into_iter()
        .rev()
        .flatten()
        .take(k as usize)
        .collect()
}
