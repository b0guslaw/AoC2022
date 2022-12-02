use criterion::{black_box, criterion_group, criterion_main, Criterion};

use aoc_rs::day1;
use aoc_rs::day2;

fn criterion_benchmark(c: &mut Criterion) {
    c.bench_function("Day 1 P1", |b| b.iter(|| day1::part1(black_box(include_str!("../../../res/day1.txt")))));
    c.bench_function("Day 1 P2", |b| b.iter(|| day1::part2(black_box(include_str!("../../../res/day1.txt")))));

    c.bench_function("Day 2 P1", |b| b.iter(|| day2::part1(black_box(include_str!("../../../res/day2.txt")))));
    c.bench_function("Day 2 P2", |b| b.iter(|| day2::part2(black_box(include_str!("../../../res/day2.txt")))));
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);