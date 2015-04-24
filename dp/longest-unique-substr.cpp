// http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

#include <iostream>
#define NO_OF_CHARS 256
using namespace std;

int longestUniqueSubstr(char* str, int n) {
    int visited[NO_OF_CHARS];           // array to to keep last occurence (index) of a char
    int curr_len;                       // length of curr NRCS
    int max_len;                        // length of max NRCS so far
    int last_index;                     // stores last occurence of current character

    // initialization
    curr_len = 1;
    max_len = 1;
    for (int i = 0; i < NO_OF_CHARS; i++)
        visited[i] = -1;
    visited[str[0]] = 0;

    for (int i = 1; i < n; i++) {
        last_index = visited[str[i]];
        if (last_index == -1 || i - curr_len > last_index)
            curr_len++;
        else {
            if (curr_len > max_len)
                max_len = curr_len;
            curr_len = i - last_index;
        }
        visited[str[i]] = i;
    }
    if (curr_len > max_len)
        max_len = curr_len;
    return max_len;
}

int main () {
    char str[] = "ABDEFGABEF";
    int n = sizeof(str)/sizeof(str[0])-1;
    cout<<"The input string is "<<str;
    
    cout<<endl<<"longest unique substring length: "<<longestUniqueSubstr(str, n);

    cout<<endl<<endl;
}