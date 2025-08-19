const mapkey: { [key: string]: string } = {
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
};

let backtrack = (currAns: string, index: number, digits: string, res:string[]): any => {
	if (index === digits.length) {
		res.push(currAns);
		return;
	}

    for(let c of mapkey[digits[index]]){
        currAns=currAns.concat(c);
        backtrack(currAns, index+1, digits, res);
        currAns=currAns.substring(0,currAns.length-1);
    }
};

let letterCombinations = (digits:string):string[]=>{
    if(digits.length===0) return [];
    let res: string[]=[];
    let path:string='';
    backtrack(path,0,digits, res);
    return res;
}

console.log(letterCombinations("2"));