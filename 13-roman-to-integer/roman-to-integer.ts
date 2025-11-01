function romanToInt(s: string): number {
    let n = s.length;
    let left = 0;
    let ans = 0;

    while (left < n) {
        let two = s[left] + s[left + 1];

        if (two === 'IV') {
            ans += 4;
            left += 2;
        } else if (two === 'IX') {
            ans += 9;
            left += 2;
        } else if (two === 'XL') {
            ans += 40;
            left += 2;
        } else if (two === 'XC') {
            ans += 90;
            left += 2;
        } else if (two === 'CD') {
            ans += 400;
            left += 2;
        } else if (two === 'CM') {
            ans += 900;
            left += 2;
        } else {
            switch (s[left]) {
                case 'I': ans += 1; break;
                case 'V': ans += 5; break;
                case 'X': ans += 10; break;
                case 'L': ans += 50; break;
                case 'C': ans += 100; break;
                case 'D': ans += 500; break;
                case 'M': ans += 1000; break;
            }
            left++;
        }
    }
    return ans;
}
