function findTheDifference(s: string, t: string): string {
    let n = s.length;
    let m = t.length;
    let ln = 0;
    let lm = 0;
    let ans = "";
    let sArr = s.split('').sort();
    let tArr = t.split('').sort();

    while(m>=0 || n>=0){
        if(sArr[ln] == tArr[lm]){
            ln++;
            lm++;
        }
        else{
            ans = tArr[lm];
            break;
        }
    }

    return ans;
};