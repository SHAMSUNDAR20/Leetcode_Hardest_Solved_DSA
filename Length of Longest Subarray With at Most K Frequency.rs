impl Solution {
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        use std::collections::HashMap;
        let mut count = HashMap::new();
        let mut left = 0;
        let mut max_len = 0;
        for right in 0..nums.len() {
            let count_entry = count.entry(nums[right]).or_insert(0);
            *count_entry += 1;
            while *count.get(&nums[right]).unwrap() > k {
                *count.get_mut(&nums[left]).unwrap() -= 1;
                left += 1;
            }
            max_len = max_len.max(right - left + 1);
        }
        max_len as i32
    }
}