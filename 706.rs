const EMPTY: i32 = -1;
const DELETED: i32 = -2;
const INITIAL_CAPACITY: usize = 16;

pub struct MyHashMap {
    numbers: Vec<(i32, i32)>,
    count: usize,
}

const fn xorshift32(mut s: u32) -> u32 {
    s ^= s << 13;
    s ^= s >> 17;
    s ^= s << 5;
    s
}

impl MyHashMap {
    pub fn new() -> Self {
        Self {
            numbers: vec![(EMPTY, EMPTY); INITIAL_CAPACITY],
            count: 0,
        }
    }

    pub fn put(&mut self, key: i32, value: i32) {
        if self.count * 2 >= self.numbers.len() {
            self.resize();
        }

        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;
        let mut insert_index = capacity;

        loop {
            let index = hash % capacity;
            let current_key = self.numbers[index].0;

            if current_key == key {
                self.numbers[index].1 = value;
                return;
            }

            if current_key == EMPTY {
                if insert_index == capacity {
                    insert_index = index;
                }
                break;
            }

            if current_key == DELETED && insert_index == capacity {
                insert_index = index;
            }

            hash += 1;
        }

        self.numbers[insert_index] = (key, value);
        self.count += 1;
    }

    pub fn remove(&mut self, key: i32) {
        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;

        loop {
            let index = hash % capacity;
            let current_key = self.numbers[index].0;

            if current_key == EMPTY {
                return;
            }
            if current_key == key {
                self.numbers[index].0 = DELETED;
                self.count -= 1;
                return;
            }
            hash += 1;
        }
    }

    pub fn get(&self, key: i32) -> i32 {
        let capacity = self.numbers.len();
        let mut hash = xorshift32(key as u32) as usize;

        loop {
            let index = hash % capacity;
            let current_key = self.numbers[index].0;

            if current_key == EMPTY {
                return -1;
            }
            if current_key == key {
                return self.numbers[index].1;
            }
            hash += 1;
        }
    }

    fn resize(&mut self) {
        let new_capacity = self.numbers.len() * 2;
        let old_numbers = std::mem::replace(&mut self.numbers, vec![(EMPTY, EMPTY); new_capacity]);
        self.count = 0;

        for (k, v) in old_numbers {
            if k != EMPTY && k != DELETED {
                self.put(k, v);
            }
        }
    }
}
