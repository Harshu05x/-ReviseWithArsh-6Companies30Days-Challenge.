// GFF Run Length Encoding

// Given a string, Your task is to  complete the function encode 
// that returns the run length encoded string for the given string.
// eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
// You are required to complete the function encode that 
// takes only one argument the string which is to be encoded and returns the encoded string.

// Example 1.
//   Input: str = aaaabbbccc
//   Output: a4b3c3
//   Explanation: a repeated 4 times consecutively b 3 times, c also 3 times.

// Example 2.
//   Input: str = abbbcdddd
//   Output: a1b3c1d4


string encode(string src)
{     
    char ch = src[0];
    int len = 1;
    string output = "";
    for(int i = 1; i < src.size(); i++){
        if(src[i] != ch){
            output += ch;
            output += char(len+48);
            len = 0;
            ch = src[i];
        }
        len++;
    }
    output += ch;
    output += char(len+48);
    return output;
} 
