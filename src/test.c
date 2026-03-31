#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void action(char *action_sequence, char *inventory) {
    // ----- Begin: Student Answer -----
    int inv[256] = {0};
    int acts[256] = {0};
    int req[256] = {0};

    int i = 0;
    int qty = 0;
    
    while(inventory[i] != '\0'){
        qty = 0;

        while(isdigit(inventory[i])){
            qty = qty*10 + (inventory[i]-'0');
            i++;
        }
        if(inventory[i]!='\0'){
            inv[(unsigned char)inventory[i]] += qty;
            i++;
        }
    }
    printf("%d\n",inv['W']);
    i = 0;
    while(action_sequence[i]!='\0'){
        qty = 0;
        while(isdigit(action_sequence[i])){
            qty = qty*10 +(action_sequence[i]-'0');
            i++;
        }
        if(action_sequence[i]!='\0'){
            acts[(unsigned char)action_sequence[i]] += qty;
            i++;
        }
    }

    printf("%d",acts['R']);
    // ----- End: Student Answer -----
}
int main(){
    char* s = "3B30W";
    char* a = "27R";
    int inv[256] = {0};
    action(a,s);
    
    return 0;
}