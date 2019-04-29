#include <stdio.h>
#include <stdlib.h>


void draw_board();
char take_input();
void process_input(char ch);
void go_left();
void go_up();
void go_down();
void go_right();
void clear_board();
void swap(int x1, int y1, int x2, int y2);
int check_win();

// Initial board , change the values and zero indexes for various boards
int board[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14, 15};

// Initially zero positions, first and second indexes, if 0 is at (1,3) first index will be 1 and second will be 3
int zero_pos_first_index = 3;
int zero_pos_seond_index = 0;

// Initial move count
int move_count = 0;

int main() {
    // Initially draw the board

    // Loop till check_win is not equal to 1

        // Take input and store in ch
        // Process input (ch)
        // Clear the board
        // Draw the board again
        // Increase move count

    // End Loop
    // Print You have won with ___ Moves
    draw_board();
    do{
        take_input();
        clear_board();
        draw_board();
        ++move_count;
    }while(!check_win());
    printf("You have won with %d Moves \n",move_count);
}

void draw_board() {
/*
    Print the current board like
     1  2  3  4
     5  6  7  8
     9 10 11 12
    13 14  0 15

    ----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
*/
fflush(stdin);
int i,j;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf("%d ",board[i][j]);
    }
    printf("\n");
}
printf("----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------\n");
}

void clear_board() {
    // Clear the board
    system("cls");
}

char take_input() {
/*
    Take input and return it, Use fflush() if scanf() is being used
*/
char ch;
scanf("%c",&ch);
fflush(stdin);
process_input(ch);
}

void process_input(char ch) {
/*
    Handle the input char ch, which is either w, a, s, d, for up, left, down and right
    Use a switch case and call go_left(), go_right() etc respectively
*/
switch(ch){
case 'w': go_up();
          break;
case 'a': go_left();
          break;
case 's': go_down();
          break;
case 'd': go_right();
          break;
}
}

void go_left() {
// Move 0 tile left
int temp;
temp=zero_pos_seond_index-1;
if(temp>=0){
    swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index,temp);
    zero_pos_seond_index=temp;
}
else{

}
}

void go_right() {
// Move 0 tile right
int temp;
temp=zero_pos_seond_index+1;
if(temp<=3){
    swap(zero_pos_first_index,zero_pos_seond_index,zero_pos_first_index,temp);
    zero_pos_seond_index=temp;
}
else{

}
}

void go_up() {
// Move 0 tile up
int temp;
temp=zero_pos_first_index-1;
if(temp>=0){
    swap(zero_pos_first_index,zero_pos_seond_index,temp,zero_pos_seond_index);
    zero_pos_first_index=temp;
}
else{

}
}

void go_down() {
// Move 0 tile down
int temp;
temp=zero_pos_first_index+1;
if(temp<=3){
    swap(zero_pos_first_index,zero_pos_seond_index,temp,zero_pos_seond_index);
    zero_pos_first_index=temp;
}
else{

}
}

void swap(int x1, int y1, int x2, int y2) {
// Swap board[x1][y1] and board[x2][y2];
int temp;
temp=board[x1][y1];
board[x1][y1]=board[x2][y2];
board[x2][y2]=temp;
}

int check_win() {
// Return 1 , if current board has all tiles perfectly places ,or 0 otherwise
int i,j,a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0},c=0;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        if(a[i][j]==board[i][j])
            c++;
    }
}
if(c==16)
    return 1;
else
    return 0;
}
