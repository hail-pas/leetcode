#define true 1;
#define false 0;
typedef short bool;

bool isMatch(char * s, char * p){
    if (*p == '\0') return *s == '\0';
    bool head_match = *s != '\0' && (*s == *p || *p == '.');
    if (*(p+1) != '\0' && *(p + 1) == '*') {
        return isMatch(s, p + 2) || head_match && isMatch(++s, p);
    }
    return head_match && isMatch(++s, ++p);
}
