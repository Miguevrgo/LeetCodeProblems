pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
    let mut count = 0;
    let mut current_sum = 0;
    let mut sums = HashMap::new();
    sums.insert(0, 1);

    for num in nums {
        current_sum += num;
        if let Some(&freq) = sums.get(&(current_sum - k)) {
            count += freq;
        }

        *sums.entry(current_sum).or_default() += 1;
    }

    count
}
