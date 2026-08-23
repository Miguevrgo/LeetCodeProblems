use std::collections::HashMap;

pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
    let mut elems: HashMap<i32, u16> = HashMap::new();

    for num in &nums {
        *elems.entry(*num).or_insert(0) += 1;
    }

    let mut top_elements = Vec::new();
    let len = nums.len();
    for (num, count) in elems {
        if count > len as u16 / 3 {
            top_elements.push(num);
        }
    }

    top_elements
}

pub fn majority_element_2(nums: Vec<i32>) -> Vec<i32> {
    let mut cand1 = 0;
    let mut cand2 = 0;
    let mut count1 = 0;
    let mut count2 = 0;

    for &num in &nums {
        if num == cand1 {
            count1 += 1;
        } else if num == cand2 {
            count2 += 1;
        } else if count1 == 0 {
            cand1 = num;
            count1 = 1;
        } else if count2 == 0 {
            cand2 = num;
            count2 = 1;
        } else {
            count1 -= 1;
            count2 -= 1;
        }
    }

    let threshold = nums.len() / 3;
    let mut result = Vec::new();

    let actual_count1 = nums.iter().filter(|&&x| x == cand1).count();
    if actual_count1 > threshold {
        result.push(cand1);
    }

    if cand1 != cand2 {
        let actual_count2 = nums.iter().filter(|&&x| x == cand2).count();
        if actual_count2 > threshold {
            result.push(cand2);
        }
    }

    result
}
