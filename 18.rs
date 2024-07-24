pub fn four_sum(nums: Vec<i64>, target: i64) -> Vec<Vec<i64>> {
    let mut quadruplets: Vec<Vec<i64>> = Vec::new();
    let mut nums = nums;
    let len = nums.len();
    if len < 4 {
        return quadruplets;
    }

    nums.sort();

    for first in 0..len - 3 {
        if first > 0 && nums[first] == nums[first - 1] {
            continue;
        }
        for second in first + 1..len - 2 {
            if second > first + 1 && nums[second] == nums[second - 1] {
                continue;
            }

            let mut left = second + 1;
            let mut right = len - 1;

            while left < right {
                let sum = nums[first] + nums[second] + nums[left] + nums[right];

                match sum.cmp(&target) {
                    std::cmp::Ordering::Equal => {
                        quadruplets.push(vec![nums[first], nums[second], nums[left], nums[right]]);

                        while left < right && nums[left] == nums[left + 1] {
                            left += 1;
                        }

                        while left < right && nums[right] == nums[right - 1] {
                            right -= 1;
                        }

                        left += 1;
                        right -= 1;
                    }
                    std::cmp::Ordering::Less => {
                        left += 1;
                    }
                    std::cmp::Ordering::Greater => {
                        right -= 1;
                    }
                }
            }
        }
    }

    quadruplets
}
