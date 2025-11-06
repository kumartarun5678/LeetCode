function titleToNumber(columnTitle: string): number {
    let ans = 0;
    let n = columnTitle.length;
    for (let i = 0; i < n; i++) {
        let val = columnTitle.charCodeAt(i) - 64;
        ans = ans * 26 + val;
    }
    return ans;
};