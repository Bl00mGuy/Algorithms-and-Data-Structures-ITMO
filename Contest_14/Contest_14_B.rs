use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut str = String::new();
    stdin.lock().read_line(&mut str).unwrap();
    let str = str.trim();

    let n = str.len();
    let mut array = vec![0; n];

    let mut i = 1;
    let mut j = 0;

    while i < n {
        while j > 0 && str.as_bytes()[i] != str.as_bytes()[j] {
            j = array[j - 1];
        }

        if str.as_bytes()[i] == str.as_bytes()[j] {
            j += 1;
        }

        array[i] = j;
        i += 1;
    }

    for value in array {
        print!("{} ", value);
    }
}
