pub fn sort_colors(nums: &mut Vec<i32>) {
    let mut colors = [0; 3];

    nums.iter().for_each(|&elem| colors[elem as usize] += 1);

    nums[0..colors[0]].fill(0);
    nums[colors[0]..(colors[0] + colors[1])].fill(1);
    nums[(colors[0] + colors[1])..].fill(2);
}
