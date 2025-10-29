/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var sort = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums.length - 1; j++) {
            if (nums[j].value > nums[j + 1].value) {
                let curr = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = curr;
            }
        }
    }
    return nums;
};

var twoSum = function (nums, target) {
    let ans = [];
    
    // Step 1: Pair each number with its original index
    let arr = nums.map((num, idx) => ({ value: num, index: idx }));

    // Step 2: Sort by value
    arr = sort(arr);

    // Step 3: Compare all pairs (keep your logic)
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i].value + arr[j].value === target) {
                // Step 4: Return original indices
                ans = [arr[i].index, arr[j].index];
                break;
            }
        }
        if (ans.length) break;
    }

    return ans;
};
