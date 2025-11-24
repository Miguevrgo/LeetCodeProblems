pub fn range_bitwise_and(mut left: i32, mut right: i32) -> i32 {
    if left == right {
        return left;
    }

    let mut cnt = 0;
    while left != right {
        left >>= 1;
        right >>= 1;
        cnt += 1;
    }

    right << cnt
}

fn main() {
    println!("{}", range_bitwise_and(1, 2))
}
