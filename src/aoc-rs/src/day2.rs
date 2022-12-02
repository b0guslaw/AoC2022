pub fn part1(input: &str) -> u64 {
    let res = input
        .lines()
        .map(|x| x.split_once(" ").unwrap())
        .fold(0, |score: u64, (elf, me)| match (elf, me) {
            ("A","X") => score + 4,
            ("A","Y") => score + 8,
            ("A","Z") => score + 3,
            ("B","X") => score + 1,
            ("B","Y") => score + 5,
            ("B","Z") => score + 9,
            ("C","X") => score + 7,
            ("C","Y") => score + 2,
            ("C","Z") => score + 6,
            _ => unreachable!(),
        });
    res
}

pub fn part2(input: &str) -> u64 {
    let res = input
        .lines()
        .map(|x| x.split_once(" ").unwrap())
        .fold(0, |score: u64, (elf, me)| match (elf, me) {
            ("A","X") => score + 3,
            ("A","Y") => score + 4,
            ("A","Z") => score + 8,
            ("B","X") => score + 1,
            ("B","Y") => score + 5,
            ("B","Z") => score + 9,
            ("C","X") => score + 2,
            ("C","Y") => score + 6,
            ("C","Z") => score + 7,
            _ => unreachable!(),
        });
    res
}