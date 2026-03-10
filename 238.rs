pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len();

    let mut solution = vec![1; n];

    let mut prefix = 1;
    for i in 0..n {
        solution[i] = prefix;
        prefix *= nums[i];
    }

    let mut suffix = 1;
    for i in (0..n).rev() {
        solution[i] *= suffix;
        suffix *= nums[i];
    }

    solution
}
