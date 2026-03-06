const EMPTY: i32 = -1;
const DELETED: i32 = -2;
const INITIAL_CAPACITY: usize = 16;

struct MyHashSet {
    numbers: Vec<i32>,
    count: usize,
}

const fn xorshift32(mut s: u32) -> u32 {
    s ^= s << 13;
    s ^= s >> 17;
    s ^= s << 5;
    s
}

impl MyHashSet {
    pub fn new() -> Self {
        Self {
            numbers: vec![EMPTY; INITIAL_CAPACITY],
            count: 0,
        }
    }

    pub fn add(&mut self, key: i32) {
        if self.contains(key) {
            return;
        }

        if self.count * 2 >= self.numbers.len() {
            self.resize();
        }

        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;

        loop {
            let index = hash % capacity;
            if self.numbers[index] == EMPTY || self.numbers[index] == DELETED {
                self.numbers[index] = key;
                self.count += 1;
                return;
            }
            hash += 1;
        }
    }

    pub fn remove(&mut self, key: i32) {
        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;

        loop {
            let index = hash % capacity;
            if self.numbers[index] == EMPTY {
                return;
            }
            if self.numbers[index] == key {
                self.numbers[index] = DELETED;
                self.count -= 1;
                return;
            }
            hash += 1;
        }
    }

    pub fn contains(&self, key: i32) -> bool {
        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;

        loop {
            let index = hash % capacity;
            if self.numbers[index] == EMPTY {
                return false;
            }
            if self.numbers[index] == key {
                return true;
            }
            hash += 1;
        }
    }

    fn resize(&mut self) {
        let new_capacity = self.numbers.len() * 2;
        let old_numbers = std::mem::replace(&mut self.numbers, vec![EMPTY; new_capacity]);
        self.count = 0;
        for &key in &old_numbers {
            if key != EMPTY && key != DELETED {
                self.add(key);
            }
        }
    }
}

fn main() {
    println!("Hello, world!");
}
