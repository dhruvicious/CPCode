function merge(intervals: number[][]): number[][] {
    if(intervals.length===0){
        return [];
    }
    intervals.sort((a: number[], b: number[]) => {
        return a[0] - b[0];
    });
    const mergedIntervals:number[][]=[intervals[0]];

    for (let i: number = 1; i < intervals.length; i++) {
        const lastMergedInterval:number[]=mergedIntervals[mergedIntervals.length-1];

        if(intervals[i][0]<=lastMergedInterval[1]){
            lastMergedInterval[1]=Math.max(lastMergedInterval[1], intervals[i][1]);
        }else{
            mergedIntervals.push(intervals[i]);
        }
    }
    return mergedIntervals;
}

