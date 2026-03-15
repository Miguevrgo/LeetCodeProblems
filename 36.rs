pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
    let mut rows = vec![HashSet::new(); 9];
    let mut cols = vec![HashSet::new(); 9];
    let mut boxes = vec![HashSet::new(); 9];

    for row in 0..board.len() {
        for col in 0..board.len() {
            if board[row][col] != '.' {
                if !rows[row].insert(board[row][col]) {
                    return false;
                }
                if !cols[col].insert(board[row][col]) {
                    return false;
                }
                if !boxes[3 * (row / 3) + (col / 3)].insert(board[row][col]) {
                    return false;
                }
            }
        }
    }

    true
}

pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        const BOARD_SIZE: usize = 9;
        let mut rows = [0u16; BOARD_SIZE];
        let mut cols = [0u16; BOARD_SIZE];
        let mut boxes = [0u16; BOARD_SIZE];

        for row in 0..BOARD_SIZE {
            for col in 0..BOARD_SIZE {
                let val = board[row][col];
                if val != '.' {
                    let bit = 1 << (val as u8 - b'1');
                    let box_idx = (row / 3) * 3 + (col / 3);

                    if (rows[row] & bit) != 0 || (cols[col] & bit) != 0 || (boxes[box_idx] & bit) != 0 {
                        return false;
                    }

                    rows[row] |= bit;
                    cols[col] |= bit;
                    boxes[box_idx] |= bit;
                }
            }
        }

        true
    }
