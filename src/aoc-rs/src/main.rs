fn day1_part1(input: &str) {
    let mut max: u64 = 0;
    let mut sum: u64 = 0;
    for line in input.lines() {
        if !line.is_empty() {
            sum += line.parse::<u64>().unwrap();
        } else {
            if sum > max {
                max = sum;
            }
            sum = 0;
        }
    }
    println!("Day 1 Part 1: {}", max);
}

fn day1_part2(input: &str) {
    let mut max: Vec<u64> = Vec::new();
    let mut sum: u64 = 0;
    for line in input.lines() {
        if !line.is_empty() {
            sum += line.parse::<u64>().unwrap();
        } else {
            max.push(sum);
            sum = 0;
        }
    }
    max.push(sum);
    max.sort();
    let sum: u64 = max.iter().skip(max.len() - 3).sum();
    println!("Day 1 Part 2: {}", sum);
}

fn main() {
    let input = include_str!("../../../res/day1.txt");
    day1_part1(input);
    day1_part2(input);
}
