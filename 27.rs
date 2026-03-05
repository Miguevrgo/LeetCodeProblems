pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|&elem| elem != val);
    nums.len() as i32
}
