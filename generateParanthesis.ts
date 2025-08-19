let backtrack = (
	start: number,
	end: number,
	n: number,
	curr: string,
	result: Array<string>
): void => {
    if(start>n || end>n) return;
    if(start===n && end===n){
        result.push(curr);
        return;
    }

    if(start<n){
        backtrack(start+1, end, n, curr+'(', result);
    }
    if(end<start){
        backtrack(start, end+1, n, curr+')', result);
    }
};

let generateParenthesis = (n: number): Array<string> => {
	let result: Array<string> = [];
	backtrack(0, 0, n, "", result);
	return result;
};
