function hammingWeight(n: number): number {
    let str = n.toString(2);
    let cnt = 0;
    for(let i= 0; i<str.length; i++){
        if(str[i] === "1"){
            cnt++;
        }
    } 
    return cnt;
};