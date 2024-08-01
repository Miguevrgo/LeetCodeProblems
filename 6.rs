pub fn convert(s: String, num_rows: i32) -> String {
    if num_rows == 1 {
        return s.into();
    }
    let mut zigzag = vec![String::new(); num_rows as usize];
    let mut direction_up = false;
    let mut level = 0;

    for ch in s.chars() {
        zigzag[level as usize].push(ch);
        direction_up = direction_up == (level > 0 && level < num_rows - 1);

        level += if direction_up { 1 } else { -1 };
    }

    zigzag.concat()
}

// pub fn convert(s: String, num_rows: i32) -> String {
//     let mut zigzags: Vec<_> = (0..num_rows)
//         .chain((1..num_rows-1).rev())
//         .cycle()
//         .zip(s.chars())
//         .collect();
//     zigzags.sort_by_key(|&(row, _)| row);
//     zigzags.into_iter()
//         .map(|(_, c)| c)
//         .collect()
// }
