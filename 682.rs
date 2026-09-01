pub fn cal_points(operations: Vec<String>) -> i32 {
    let mut stack = VecDeque::new();

    for str in operations {
        match str.as_str() {
            "+" => {
                let top: i32 = stack.pop_front().unwrap();
                let new_top = stack.front().unwrap() + top;
                stack.push_front(top);
                stack.push_front(new_top);
            }
            "D" => stack.push_front(stack.front().unwrap() * 2),
            "C" => {
                let _ = stack.pop_front();
            }
            _ => stack.push_front(str.parse::<i32>().unwrap()),
        }
    }

    stack.iter().sum()
}
