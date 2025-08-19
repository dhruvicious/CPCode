function sortColors(arr: number[]): number[] {
    let n: number = arr.length;
    let n0: number = 0, n1: number = 0, n2: number = 0;

    for (let i of arr) {
        if (i == 0) n0++;
        if (i == 1) n1++;
        if (i == 2) n2++;
    }

    for (let i: number = 0; i < n; i++) {
        if (n0 > 0) {
            arr[i] = 0;
            n0--;
            continue;
        }
        if (n1 > 0) {
            arr[i] = 1;
            n1--;
            continue;
        }
        if (n2 > 0) {
            arr[i] = 2;
            n2--;
            continue;
        }
    }
    return arr;
}