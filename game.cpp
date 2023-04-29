

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4; // the size of the grid
int grid[SIZE][SIZE]; // the grid itself

// function to print the grid
void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

// function to generate a new tile on the grid
void generate_tile() {
    // count the number of empty spaces on the grid
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                count++;
            }
        }
    }
    // if there are no empty spaces, return
    if (count == 0) {
        return;
    }
    // generate a random position for the new tile
    int pos = rand() % count;
    int x = 0, y = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                if (pos == 0) {
                    x = i;
                    y = j;
                    break;
                }
                pos--;
            }
        }
    }
    // generate a random number (either 2 or 4) for the new tile
    int num = (rand() % 2 + 1) * 2;
    // place the new tile on the grid
    grid[x][y] = num;
}


// function to move the tiles in a given direction
void move_tiles(char dir) {
    // create a temporary grid to store the new positions of the tiles
    int temp[SIZE][SIZE] = {0};
    // move the tiles in the specified direction
    switch (dir) {
        case 'U': // up
            for (int j = 0; j < SIZE; j++) {
                int index = 0;
                for (int i = 0; i < SIZE; i++) {
                    if (grid[i][j] != 0) {
                        if (temp[index][j] == 0) {
                            temp[index][j] = grid[i][j];
                        } else if (temp[index][j] == grid[i][j]) {
                            temp[index][j] *= 2;
                            index++;
                        } else {
                            index++;
                            temp[index][j] = grid[i][j];
                        }
                    }
                }
            }
            break;
        case 'D': // down
            for (int j = 0; j < SIZE; j++) {
                int index = SIZE - 1;
                for (int i = SIZE - 1; i >= 0; i--) {
                    if (grid[i][j] != 0) {
                        if (temp[index][j] == 0) {
                            temp[index][j] = grid[i][j];
                        } else if (temp[index][j] == grid[i][j]) {
                            temp[index][j] *= 2;
                            index--;
                        } else {
                            index--;
                            temp[index][j] = grid[i][j];
                        }
                    }
                }
            }
    break;
    case 'L': // left
        for (int i = 0; i < SIZE; i++) {
            int index = 0;
            for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] != 0) {
                    if (temp[i][index] == 0) {
                        temp[i][index] = grid[i][j];
                    } else if (temp[i][index] == grid[i][j]) {
                        temp[i][index] *= 2;
                        index++;
                    } else {
                        index++;
                        temp[i][index] = grid[i][j];
                    }
                }
            }
        }
        break;
    case 'R': // right
        for (int i = 0; i < SIZE; i++) {
            int index = SIZE - 1;
            for (int j = SIZE - 1; j >= 0; j--) {
                if (grid[i][j] != 0) {
                    if (temp[i][index] == 0) {
                        temp[i][index] = grid[i][j];
                    } else if (temp[i][index] == grid[i][j]) {
                        temp[i][index] *= 2;
                        index--;
                    } else {
                        index--;
                        temp[i][index] = grid[i][j];
                    }
                }
            }
        }
        break;
    }
    // copy the temporary grid back to the original grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}


bool is_valid_move(char move){

int temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp[i][j] = grid[i][j];
        }
    }
        // move the tiles in the specified direction
        move_tiles(move);
        bool valid;

        valid = false;
            for (int i = 0; i < SIZE; i++) {
              for (int j = 0; j < SIZE; j++) {
                  if(grid[i][j] != temp[i][j]){
                    valid = true;
                  }
              }
            }

                for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = temp[i][j];
        }
    }
            return valid;
}


char bot_move(){
// Define a function to make a move using the "Keep it Cornered" strategy

    char move = 'U';
    // seed the random number generator
    std::srand(std::time(nullptr));
    
    // generate a random number between 0 and 99
    int pos = std::rand() % 100;
    
    // choose the direction based on the random number
    if (pos < 50) {
        return 'U'; // up with 50% probability
    } else if (pos < 65) {
        return 'D'; // down with 15% probability
    } else if (pos < 95) {
        return 'L'; // left with 30% probability
    } else {
        return 'R'; // right with 5% probability
    }

}



// main function to play the game
int main() {
    // initialize the grid with two random tiles
    srand(time(0));
    generate_tile();
    generate_tile();
    int score = 0;

    // print the initial grid
    print_grid();
    cout << "Enter move (U/D/L/R/B): ";
    cout << endl;



    int sum = 0;
    int prev_sum = 0;

    // game loop
    while (true) {
        // get user input
        char input;

        cin >> input;
        
        if(input == 'B'){
            input = bot_move();
        }
  

    int temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp[i][j] = grid[i][j];
        }
    }
        // move the tiles in the specified direction
        move_tiles(input);
        bool valid;

        valid = false;
            for (int i = 0; i < SIZE; i++) {
              for (int j = 0; j < SIZE; j++) {
                  if(grid[i][j] != temp[i][j]){
                    valid = true;
                  }
              }
            }
        
        if (valid == true){
          
            // generate a new tile on the grid
            generate_tile();
            // print the updated grid
            print_grid();
            cout << "Enter move (U/D/L/R): ";
            cout << endl;
        }
        

        // check if the game is over
        bool game_over = true;
        bool win = false;
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] == 2048) {
                    sum = sum + grid[i][j];
                    win = true;
                    break;
                }
                if (grid[i][j] == 0) {
                    game_over = false;
                    break;
                }
                if (i > 0 && grid[i][j] == grid[i-1][j]) {
                    game_over = false;
                    break;
                }
                if (j > 0 && grid[i][j] == grid[i][j-1]) {
                    game_over = false;
                    break;
                }
            }
            if (!game_over) {
            break;
            }
        }
        score = score + sum - prev_sum;// recording only new values
        prev_sum = sum;
        if (game_over) {
          cout << "Game over!" << endl;
          cout << "Your score: "<< score << endl;
          break;
        }
        if (win) {
          cout << "You won!" << endl;
          cout << "Your score: "<< score << endl;
          break;
        }
        }
    return 0;
}
