mod bitwise_complement;
use bitwise_complement::Solution;

fn main() {
    let res: i32 = Solution::bitwise_complement(5);
    println!("Result: {}", res);
}
