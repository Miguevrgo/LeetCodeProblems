fn longest_common_prefix(strs: Vec<String>) -> String {
    let first = strs.first().unwrap();
    let mut length = first.len();

    for s in strs.iter().skip(1) {
        length = first
            .bytes()
            .zip(s.bytes())
            .take(length)
            .take_while(|(a, b)| a == b)
            .count();

        if length == 0 {
            break;
        }
    }

    first[..length].to_string()
}
