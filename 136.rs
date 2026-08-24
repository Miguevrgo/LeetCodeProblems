pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut number = *nums.first().unwrap();

    for num in nums.iter().skip(1) {
        number ^= *num;
    }

    number
}
