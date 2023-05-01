use std::io::{self, BufRead};

fn sum(array: &[i64]) -> i64 {
    let mut sum = 0;
    for &element in array {
        sum += element;
    }
    sum
}

fn max(array: &[i64]) -> i64 {
    let mut max = i64::MIN;
    for &element in array {
        if element > max {
            max = element;
        }
    }
    max
}

fn mid(array: &[i64], number_of_delimiters: i64, mid: i64) -> bool {
    let mut count = 0;
    let mut sum = 0;
    for &element in array {
        sum += element;
        if sum > mid {
            count += 1;
            sum = element;
        }
    }
    count < number_of_delimiters
}

fn bin(array: &[i64], number_of_delimiters: i64) -> i64 {
    let left = max(array);
    let right = sum(array);
    let mut answer = 0;
    let mut left = left;
    let mut right = right;
    while left <= right {
        let mid = (left + right) / 2;
        if mid(array, number_of_delimiters, mid) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    answer
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|line| line.unwrap());
    let first_line = lines.next().unwrap();
    let mut numbers = first_line.split_whitespace().map(|s| s.parse().unwrap());
    let number_of_elements = numbers.next().unwrap();
    let number_of_delimiters = numbers.next().unwrap();
    let mut array = Vec::new();
    for line in lines {
        let element = line.parse().unwrap();
        array.push(element);
    }
    let summ = bin(&array, number_of_delimiters);
    let mut arr = vec![false; number_of_elements];
    let mut counter = 0;
    let mut sum = 0;
    for (i, &element) in array.iter().enumerate() {
        sum += element;
        if sum > summ {
            arr[i] = true;
            counter += 1;
            sum = element;
        }
    }
    sum = 0;
    let mut j = 1;
    while counter != number_of_delimiters - 1 {
        if !arr[j] {
            arr[j] = true;
            counter += 1;
        }
        j += 1;
    }
    for (i, &element) in arr.iter().enumerate() {
        if element {
            print!("{} ", i);
        }
    }
}
