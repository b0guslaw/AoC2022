mod day1;
mod day2;

fn main() {
    let input1 = include_str!("../../../res/day1.txt");
    print!("Day 1 Part 1: {}\n", day1::part1(input1));
    print!("Day 1 Part 2: {}\n\n", day1::part2(input1));
}
