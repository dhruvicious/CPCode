function removeSubFolders(folder) {
    var auxArr = [];
    folder.sort();
    console.log(folder);
    return auxArr;
}
var testCases = [
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
for (var _i = 0, testCases_1 = testCases; _i < testCases_1.length; _i++) {
    var testcase = testCases_1[_i];
    removeSubFolders(testcase);
}
