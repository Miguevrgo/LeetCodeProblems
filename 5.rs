pub fn longest_palindrome(s: String) -> String {
    let len = s.len();

    let s: Vec<u8> = "^"
        .bytes()
        .chain(s.into_bytes())
        .flat_map(|u| [u, b'#'])
        .chain("$".bytes())
        .collect();

    let mut center = 2;
    let mut right = 3;

    let mut p = vec![0; 2 * len + 1];
    let mut longest_palindrome = 1;
    let mut longest_palindrome_index = 2;
    p[2] = 1;

    for i in 3..2 * len + 1 {
        if i < right {
            let mirror = 2 * center - i;
            p[i] = std::cmp::min(p[mirror], right - i);
        }

        while s[i + p[i] + 1] == s[i - p[i] - 1] {
            p[i] += 1;
        }

        if i + p[i] > right {
            center = i;
            right = i + p[i];
        }

        if p[i] > longest_palindrome {
            longest_palindrome = p[i];
            longest_palindrome_index = i;
        }
    }

    s.into_iter()
        .skip(longest_palindrome_index - longest_palindrome + 1)
        .take(2 * longest_palindrome - 1)
        .filter(|u| *u != b'#')
        .map(|u| u as char)
        .collect()
}
