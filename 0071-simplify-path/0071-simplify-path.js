
var simplifyPath = function(path) {

    let stack = [];
    let tokens = path.split("/");

    for(let ch of tokens){
        if(ch==='' || ch==='.') continue;
        else if (ch ==='..' && stack.length>0) stack.pop();
        else if (ch !== '..')  stack.push(ch);
    }

    return "/" + stack.join("/");
};