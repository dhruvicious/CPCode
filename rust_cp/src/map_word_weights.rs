pub struct SolutionMapWordWeights;

impl SolutionMapWordWeights {
    pub fn map_word_weights(words: Vec<String>, weights: Vec<i32>) -> String {
        let mut res: String = String::new();

        for word in words {
            let mut word_sum: i32 = 0;

            for byte in word.bytes() {
                word_sum += weights[(byte - b'a') as usize];
            }
            let target_byte = b'z' - ((word_sum % 26) as u8);

            res.push(target_byte as char);
        }
        res
    }

    pub fn map_word_weights_itrIMPL(words: Vec<String>, weights: Vec<i32>) -> String {
        words
            .iter()
            .map(|word| {
                let word_sum: i32 = word
                    .bytes()
                    .map(|byte| weights[(byte - b'a') as usize])
                    .sum();
                (b'z'-((word_sum%26) as u8)) as char
            })
            .collect()
    }
}
