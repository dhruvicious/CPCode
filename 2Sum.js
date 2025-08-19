'use strict';

const fs = require('fs');
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

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

var twoSum = function(nums, target) {
    for(let i=0;i<nums.length;i++){
        var target2=target-nums[i];
        for(let j=0;j<nums.length;j++){
            if(num[j]===target2 && i!=j){
                retrun [i,j];
            }
        }
    }
};

var twoSumOpt = function(nums, target){
    let map={};
    for(let i =0;i<nums.length;i++){
        let complement = target-nums[i];
        if(map.hasOwnProperty(complement)){
            return [i, map[complement]]
        }else{
            map[nums[i]]=i;
        }
    }
}

function main() {

}