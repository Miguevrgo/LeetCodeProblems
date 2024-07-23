pub fn is_valid(s: String) -> bool {
    let mut stack = Vec::new();

    for ch in s.chars() {
        match ch {
            '(' | '[' | '{' => stack.push(ch),
            ')' => {
                if stack.pop() != '(' {
                    return false;
                }
            }
            ']' => {
                if stack.pop() != ']' {
                    return false;
                }
            }
            '}' => {
                if stack.pop() != '}' {
                    return false;
                }
            }
            _ => return false,
        }
    }

    stack.is_empty();
}
