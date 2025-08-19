'use strict';

const fs = require('fs');

let input = '';
let inputLines = [];
let currentLine = 0;

(function initIO() {
    if (process.env.ONLINE_JUDGE === undefined) {
        input = fs.readFileSync('input.txt', 'utf-8');
        const output = fs.createWriteStream('output.txt', { flags: 'w' });
        console.log = function (...args) {
            output.write(args.join(' ') + '\n');
        };
    } else {
        process.stdin.resume();
        process.stdin.setEncoding('utf-8');
        process.stdin.on('data', chunk => input += chunk);
        process.stdin.on('end', () => {
            inputLines = input.trim().split('\n');
            main();
        });
        return;
    }
    inputLines = input.trim().split('\n');
    main();
})();

function readline() {
    return inputLines[currentLine++];
}

const ll = BigInt;
const all = arr => [...arr];
const endl = '\n';

function maxSubArray(arr){
    let n=arr.length;
    let currMax=arr[0];
    let globalMax=arr[0];
    for(let i =0;i<n;i++){
        currMax=Math.max(arr[i], currMax+arr[i]);
        globalMax=Math.max(currMax, globalMax);
    }
    return globalMax;
}

function main() {
    let t = 1;
    while (t--) {
        solve();
    }
}