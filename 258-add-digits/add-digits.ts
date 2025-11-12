function addDigits(num: number): number {
    while (num >= 10) {
        num = num.toString()
                 .split('')
                 .reduce((a, b) => a + Number(b), 0);
    }
    return num;
}
