impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        if n == 0 { return vec![0]; }
        if n == 1 { return vec![0, 1]; }
        let mut dp: Vec<i32> = vec![1; n as usize + 1 as usize];
        let mut k: usize = 2;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for i in 3 ..= n as usize {
            if i - k == k {
                k = i;
            } else {
                dp[i] += dp[i - k];
            }
        }
        
        dp
    }
}