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

    req['B'] = acts['R']*1 + acts['S']*1;
    req['W'] = acts['R']*1 + acts['S']*1;
    req['M'] = acts['S']*1 + acts['C']*2;
    req['S'] = acts['S']*1 + acts['D']*1;
    req['O'] = acts['C']*3 + acts['D']*1;

    if(req['B']>inv['B'] || req['W']>inv['W'] || req['M']>inv['M']
        || req['S']>inv['S'] || req['O']>inv['O']){
            printf("Nuoc di khong hop le\n");
            return;
        }
    
    if(acts['C']>acts['S']){
        printf("Nuoc di khong hop le\n");
        return;
    }

    inv['B'] -= req['B'];
    inv['W'] -= req['W'];
    inv['M'] -= req['M'];
    inv['S'] -= req['S'];
    inv['O'] -= req['O'];

    printf("%dW%dO%dM%dB%dS\n", inv['W'],inv['O'],inv['M'],
    inv['B'],inv['S']);
    
    // ----- End: Student Answer -----
}
void penalty_7(char *inventory) {
    // ----- Begin: Student Answer -----
    int sum = 0;
    int i = 0;
    int qty = 0;
    while(inventory[i]!='\0'){
        qty = 0;
        while(isdigit(inventory[i])){
            qty = qty*10 + (inventory[i]-'0');
            i++;
        }
        sum += qty;
        i++;
    }
    if(sum>=7){
        if(sum%2==0)
            printf("Ban can bo %d la tai nguyen. Siuuu\n", (sum/2));
        else printf("Ban can bo %d la tai nguyen. Siuuu\n", (sum/2)+1);
    }
    else printf("Ban an toan\n");

    // ----- End: Student Answer -----
}
int main(){
    char* s = "1B1W";
    char* a = "1S";
    action(a,s);
    penalty_7("1B1W1M");
    return 0;
}