use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();

    let (mut a, mut b) = (0, 0);
    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let tmp: i32 = input.trim().parse().unwrap();
        a = (a + tmp) % 239;
    }

    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let tmp: i32 = input.trim().parse().unwrap();
        b = (b + tmp) % 239;
    }

    if a == b {
        println!("YES");
    } else {
        println!("NO");
    }
}
