function setZeroes(matrix){
    let rows=[];
    let cols=[];
    const n=matrix.length;
    const m=matrix[0].length;
    
    for(let i =0;i<n;i++){
        for(let j=0;j<m;j++){
            if(matrix[i][j]===0){
                rows.push(i);
                cols.push(j);
            }
        }
    }

    for(let i of rows){
        for(let j=0;j<m;j++){
            matrix[i][j]=0;
        }
    }

    for(let j of cols){
        for(let i=0;j<n;j++){
            matrix[i][j]=0;
        }
    }
}


function main() {
    let mat = [[1,1,1],[1,0,1],[1,1,1]];
    setZeroes(mat);
    console.log(mat); // Should print [[1,0,1],[0,0,0],[1,0,1]]
}

main();
