let sentence="";
let words=sentence.toLowerCase().replace(/[,.;"']/g, "").split(" ");

let wordFreq={};
let maxFreq=Number.MIN_VALUE;
let maxFreqWord="";

for(let word of words){
    if(word==="") continue;
    wordFreq[word]=(wordFreq[word]||0) +1;
}

for(let [c,f] in Object.entries(wordFreq)){
    if(f>maxFreq){
        maxFreq=f;
        maxFreqWord=c;
    }
}

console.log(maxFreq, maxFreqWord);