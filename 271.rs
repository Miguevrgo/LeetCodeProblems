const SEPARATOR: char = '.';
impl Solution {
    fn encode(strs: Vec<String>) -> String {
        let mut encoded = String::new();

        for s in strs {
            encoded.push_str(&s.len().to_string());
            encoded.push(SEPARATOR);
            encoded.push_str(&s);
        }

        encoded
    }

    fn decode(s: String) -> Vec<String> {
        let mut result = Vec::new();
        let mut current_pos = 0;
        let bytes = s.as_bytes();

        while current_pos < bytes.len() {
            let mut sep_pos = current_pos;

            while sep_pos < bytes.len() && bytes[sep_pos] as char != SEPARATOR {
                sep_pos += 1;
            }

            let len_str = std::str::from_utf8(&bytes[current_pos..sep_pos]).unwrap();
            let len: usize = len_str.parse().unwrap();

            let start = sep_pos + 1;
            let end = start + len;

            let target_str = std::str::from_utf8(&bytes[start..end]).unwrap();
            result.push(target_str.to_string());

            current_pos = end;
        }

        result
    }
}
