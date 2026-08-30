pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    let seq: HashSet<i32> = HashSet::from_iter(nums);
    let mut longest = 0;

    for num in &seq {
        if !seq.contains(&(num - 1)) {
            let mut length = 1;
            while seq.contains(&(num + length)) {
                length += 1;
            }

            longest = longest.max(length);
        }
    }

    longest
}
