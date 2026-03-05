pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut elems = HashSet::with_capacity(nums.len());
    for elem in nums {
        if !elems.insert(elem) {
            return true;
        };
    }
    false
}
