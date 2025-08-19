/**
 * @param {number} numRows
 * @return {number[][]}
 */


function generate(numRows) {
    let rows=[];
    for(let i =0;i<numRows;i++){
        let currRow=Array(i+1);
        currRow[0]=1;
        for(let j =1;j<i+1;j++){
            currRow[j]=currRow[j-1]*(i-j+1)/(j);
        }
        rows.push(currRow);
    }
    return rows;
};

function main(){
    let n =5;
    generate(5);
}

//ttyl: 