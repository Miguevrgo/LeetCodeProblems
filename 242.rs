pub fn is_anagram(s: String, t: String) -> bool {
    let mut freqs = [0; 26];

    for ch in s.chars() {
        freqs[(ch as u8 - b'a') as usize] += 1;
    }

    for ch in t.chars() {
        freqs[(ch as u8 - b'a') as usize] -= 1;
    }

    freqs.iter().all(|&elem| elem == 0)
}
