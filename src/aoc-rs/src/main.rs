mod day1;
mod day2;

fn main() {
    let input1 = include_str!("../../../res/day1.txt");
    print!("Day 1 Part 1: {}\n", day1::part1(input1));
    print!("Day 1 Part 2: {}\n\n", day1::part2(input1));

    let input2 = include_str!("../../../res/day2.txt");
    print!("Day 2 Part 1: {}\n", day2::part1(input2));
    print!("Day 2 Part 2: {}\n\n", day2::part2(input2));
}
