#include <stdio.h>

// function prototype for Tower movements
void tower(int n);

// function prototype for Queen movements 
void queen(int n);

// function prototype for Knights movements
void knight();

// function prototype for Bishop movements 
void bishop(int n);

int main(){

    //declaring variables
    char piece, returnGame; //variables to choose what piece will move and to return game
    int menuChoice; //menu choice
    int movTower, movQueen, movBishop; //how many movements for pieces

    //introduction
    printf("\t*** CHESS GAME SIMULATION ***\n");
    //main menu with switch structure and do_while
    do{
        printf("Welcome to the Chess Game Simulation.\nMain Menu: \n1 - Rules\n2 - Play\n3 - Quit\n"); scanf("%d", &menuChoice);
    
        switch(menuChoice){
        case 1: printf("\tRULES ***\n"); //game rules
                printf("Tower moves straight to the right\n");
                printf("Bishop move diagonally, up and right\n");
                printf("Queen moves straight to the left\n");
                printf("Knight moves like an L: 2 straight up and 1 laterally right\n\n"); 
                //choose to play again or quit
                printf("Do you want to play again?: Y/N\n"); scanf(" %c", &returnGame);
                if(returnGame == 'n' || returnGame == 'N'){
                    menuChoice = 3; printf("Thank you for playing!\nSee you next time!\nQuitting game...\n");
                } else if(returnGame == 'y' || returnGame == 'Y'){
                    menuChoice = 2;
                }else{
                    printf("Invalid choice\n");
                }
                break;
        case 2: printf("Choose the piece you want to move: \nT - Tower\nB - Bishop\nQ - Queen\nK - Knight\n"); scanf(" %c", &piece); printf("\n"); //piece to move
                switch(piece){
                    //Tower
                    case 't':
                    case 'T': printf("You choose: Tower\n\n"); printf("How many moves do you want to perform?: \n"); scanf("%d", &movTower); 
                    printf("\t****Tower's movements:\n"); 
                    //Tower function
                    tower(movTower);
                    printf("Total: %d cases to the right\n\n", movTower);
                    break;
                    //Bishop
                    case 'b':
                    case 'B': printf("You choose: Bishop\n\n"); printf("How many moves do you want to perform?: \n"); scanf("%d", &movBishop);
                    printf("\t****Bishop's movements:\n");
                    //Bishop function
                    bishop(movBishop);
                    printf("Total: %d cases diagonally up and right\n\n", movBishop);
                    break;
                    //Queen
                    case 'q':
                    case 'Q': printf("You choose: Queen\n\n"); printf("How many moves do you want to perform?: \n"); scanf("%d", &movQueen);
                     printf("\t****Queen's movements:\n");
                    //Queen function
                    queen(movQueen);
                    printf("Total: %d cases to the left\n\n", movQueen);
                    break;
                    //Knight
                    case 'k':
                    case 'K': printf("You choose: Knight\n\n");  
                    printf("\t****Knight's movements:\n");
                    //Knight function
                    knight();
                    break;
                    default: printf("Invalid choice\n");
                } break;
        case 3: printf("Thank you for playing!\nSee you next time!\nQuitting game...\n"); break;
        default: printf("Please enter a number between 1 and 3\n\n");
        } 
    } while(menuChoice != 3);
    
    return 0;
}

//Tower recursive function 
void tower(int n){
    if(n <= 0) return; //recursive base case
    for(int i = 1; i < 2; i++){
        printf("Right\n");
    } tower(n -1);
}

//Queen recursive function
void queen(int n){
    if(n <= 0) return;
    for(int i = 1; i < 2; i++){
        printf("Left\n");
    } queen(n - 1);
}

//Knight function with complex for loop (2 variables)
void knight(){
    for(int i = 1, j = 0; j < 2; i++, j++){
        printf("Up\n"); if(j == 0) continue; printf("Right\n");
    } 
}     

//Bihop recursive function with nested for loops
void bishop(int n){
    if(n <= 0) return; { 
        for(int i = 1; i < 2; i++){ //extrenal loop showing Up movements
            for(int j = 1; j == i; j++){ //internal loops showing Right movements
                printf("Right\n");
            } printf("Up\n");
        }
    } bishop(n - 1);// recursion
} 
