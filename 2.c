#include <stdio.h>

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindex2(char source[], char searchfor[]);

char pattern[] = "ould";

const int MAXLINE = 1000;

main() {
    char line[MAXLINE];
    int l = 0;

    while ( getline(line, MAXLINE) )
        if ( (l = strindex2(line, pattern)) >= 0 ) {
            printf("%s\n", line);
            printf("%d\n", l);
        }
}

// getline: read line and store it in line[]
// return index of the last char read
int getline(char line[], int max) {
    int c, i = 0;

    while ( --max > 0 && (c = getchar()) != '\n' && c != EOF )
        line[i++] = c;

    if ( c == '\n' )
        line[i++] = c;

    line[i] = '\0';

    return i;
}


// strindex: return first index of pattern in line, -1 if pattern is not in line
int strindex(char line[], char pattern[]) {
    int i, j, k;
    for ( i = 0; line[i] != '\0'; ++i ) {
        for ( j = 0, k = i; pattern[j] != '\0' && line[k] == pattern[j] ; ++j, ++k );

        if ( j > 0 && pattern[j] == '\0' )
            return i;
    }
    return -1;

}

// strindex2: return last index of pattern in line, -1 if pattern is not in line
int strindex2(char line[], char pattern[]) {
    int i, j, k;
    int lastposition = -1;
    for ( i = 0; line[i] != '\0'; ++i ) {
        for ( j = 0, k = i; pattern[j] != '\0' && line[k] == pattern[j] ; ++j, ++k );

        if ( j > 0 && pattern[j] == '\0' )
            lastposition = i;
    }
    return lastposition;

}
