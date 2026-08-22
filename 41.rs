pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
    let n = nums.len();

    let mut i = 0;
    while i < n {
        let val = nums[i];
        if val > 0 && (val as usize) <= n {
            let target = (val - 1) as usize;
            if nums[i] != nums[target] {
                nums.swap(i, target);
                continue;
            }
        }
        i += 1;
    }

    nums.iter()
        .copied()
        .enumerate()
        .find_map(|(idx, val)| {
            let expected = (idx + 1) as i32;
            (val != expected).then_some(expected)
        })
        .unwrap_or((n + 1) as i32)
}
