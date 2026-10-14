fn rob(nums: Vec<i32>) -> i32 {
    let mut memory = vec![0; nums.len()];
    dfs(&nums, 0, &mut memory)
}

fn dfs(nums: &[i32], i: usize, memory: &mut Vec<i32>) -> i32 {
    if i >= nums.len() {
        return 0;
    }

    if memory[i] == 0 {
        memory[i] = dfs(nums, i + 1, memory).max(dfs(nums, i + 2, memory) + nums[i]);
    }

    memory[i]
}
