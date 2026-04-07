#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EDGE_PER_COLOR 100
#define EPSILON 1e-9

// -----------------------------------------------------------------------------
// Struct definitions
// -----------------------------------------------------------------------------

typedef struct {
    // your code here
    int x, y;
    int dice;
} Hex;

typedef struct {
    Hex h1;
    Hex h2;
} Edge;

typedef struct {
    // your code here
    Hex h1;
    Hex h2;
    Hex h3;
} Intersection;

typedef struct {
    Edge red[MAX_EDGE_PER_COLOR];
    Edge blue[MAX_EDGE_PER_COLOR];
    Edge green[MAX_EDGE_PER_COLOR];
    Edge orange[MAX_EDGE_PER_COLOR];
} road_occupation;


// -----------------------------------------------------------------------------
// Helper print functions (already implemented for testing / debugging)
// -----------------------------------------------------------------------------

void printHex(Hex h) {
    printf("(%d,%d,%d)", h.x, h.y, h.dice);
}

void printEdge(Edge e) {
    printf("[(%d,%d),(%d,%d)]",
           e.h1.x, e.h1.y,
           e.h2.x, e.h2.y);
}

void printIntersection(Intersection in) {
    printf("[(%d,%d),(%d,%d),(%d,%d)]",
           in.h1.x, in.h1.y,
           in.h2.x, in.h2.y,
           in.h3.x, in.h3.y);
}

// -----------------------------------------------------------------------------
// Task 1
// -----------------------------------------------------------------------------

void action(char *action_sequence, char *inventory) {
    // ----- Begin: Student Answer -----
    int inv[256] = {0}; //tổng tài nguyên hiện có
    int acts[256] = {0}; //tổng hành động yêu cầu
    int req[256] = {0}; //tổng tài nguyên yêu cầu

    int i = 0;
    int qty = 0;
    while(inventory[i]!='\0'){
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
            printf("Nuoc di khong hop le");
            return;
        }
    
    if(acts['C']>acts['S']){
        printf("Nuoc di khong hop le");
        return;
    }

    inv['B'] -= req['B'];
    inv['W'] -= req['W'];
    inv['M'] -= req['M'];
    inv['S'] -= req['S'];
    inv['O'] -= req['O'];

    printf("%dW%dO%dM%dB%dS", inv['W'],inv['O'],inv['M'],
    inv['B'],inv['S']);
    

    // ----- End: Student Answer -----
}

// -----------------------------------------------------------------------------
// Task 2
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
// Task 3
// -----------------------------------------------------------------------------

/*
    Task 3 asks students to implement the structs. They are already declared above
    in this base file so the later tasks can compile against them.
*/

// -----------------------------------------------------------------------------
// Task 4
// -----------------------------------------------------------------------------

/*
    Suggested corrected signature for C:
    - resource_hexes: array of Hex
    - n: number of valid elements in that array
*/
const int PROB[13] = {0, 0, 1, 2, 3, 4, 5, 0, 5, 4, 3, 2, 1};
int get_dice(int x, int y, Hex hexes[], int n){
    for(int i = 0; i<n; i++){
        if(x==hexes[i].x && y==hexes[i].y)
            return hexes[i].dice;
    }
    return 7;
}
int cal_prob(int d1, int d2, int d3){
    int total = PROB[d1];
    if(d2!=d1){
        total +=PROB[d2];
    }
    if(d3!=d2 && d3!=d1){
        total += PROB[d3];
    }
    return total;
}
void best_intersection(Hex resource_hexes[], int n) {
    // ----- Begin: Student Answer -----
    // students must implement this function
    
    // ----- End: Student Answer -----
}

// -----------------------------------------------------------------------------
// Task 5
// -----------------------------------------------------------------------------

/*
    Notes for the provided skeleton:
    - Each color stores occupied roads only.
    - If a color has no roads, tests may represent it with one "empty" edge:
          {0,0, 0,0}
    - Students may create any helper functions they need to count / traverse edges.
*/

const char* longest_road(road_occupation ro) {
    // ----- Begin: Student Answer -----
    // students must change return value

    return "";
    // ----- End: Student Answer -----
}

// -----------------------------------------------------------------------------
// Optional helper prototypes students may implement (no need if you are not using)
// -----------------------------------------------------------------------------

int dice_probability_numerator(int dice) {
    // ----- Begin: Student Answer -----
    // return numerator over denominator 36
    // examples: 6 -> 5, 8 -> 5, 7 -> 0
    return 0;
    // ----- End: Student Answer -----
}

int same_hex(Hex a, Hex b) {
    // ----- Begin: Student Answer -----

    return 0;
    // ----- End: Student Answer -----
}

int same_edge(Edge a, Edge b) {
    // ----- Begin: Student Answer -----

    return 0;
    // ----- End: Student Answer -----
}

int is_empty_edge(Edge e) {
    // ----- Begin: Student Answer -----

    return 0;
    // ----- End: Student Answer -----
}

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

int main(void) {
    /*
        You may write your own tests here.
        This file is only a starter skeleton in the same spirit as bkar.c.
    */

    return 0;
}