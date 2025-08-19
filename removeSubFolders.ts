function removeSubFolders(folder: string[]): string[] {
    let auxArr: string[] = [];
    folder.sort();
    for(let f of folder){
        let last: string = auxArr[auxArr.length-1];
        if(f.startsWith(last) && f[last.length]=='/'){
            continue;
        }else{
            auxArr.push(f);
        }
    }
    return auxArr;
}
const testCases = [
    ["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"],
    ["/x", "/x/y", "/x/y/z", "/w", "/w/x"],
    ["/home", "/home/user", "/home/user/docs", "/var", "/var/log"],
    ["/alpha", "/alpha/beta", "/gamma", "/delta"],
    ["/a/b/c", "/a/b", "/a"],
    ["/p/q/r", "/p/q", "/p"],
    ["/z", "/z1", "/z/z1", "/z/z2", "/z1/z2"],
    ["/data", "/data1", "/data2", "/data/backup", "/data2/archive"],
    ["/abc", "/abcd", "/abc/def", "/abcd/efg", "/abc/ghi"],
    ["/r", "/r/s", "/r/s/t", "/r/s/t/u", "/r2", "/r3"]
];
for(let testcase of testCases){
    removeSubFolders(testcase);
}