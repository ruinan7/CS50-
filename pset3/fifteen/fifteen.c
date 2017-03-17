/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//find array location given array value
int find_row(int value);
int find_col(int value);

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(250000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{


int num = d * d - 1;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = num;
            num = num - 1;
        }
    }
    
    if (d % 2 == 0)
    {
        int temp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;
        
    }
}




/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2i ", board[i][j]);
            }

        }
        printf("\n");
    }



}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
int row;
int col;
int blank_value;
int tile_value;

    //find the location of the blank tile 
    int row_blank = find_row(0);
    int col_blank = find_col(0);

    
    //find the location of the tile you selected
    row = find_row(tile);
    col = find_col(tile);


    if(abs(row_blank - row) + abs(col_blank - col) != 1)
    {

        return false;
    }
    else if(row >= d || row < 0)
    {
        return false;
    }
    else if (col >= d || col < 0)
    {
        return false;
    }
    else
    {
        blank_value = board[row_blank][col_blank];
        tile_value = board[row][col];
        board[row_blank][col_blank] = tile_value;
        board[row][col] = blank_value;
        return true;
    }
    
}


//find the row number of an arrary given its value
int find_row(int value)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == value)
            {
                return i;
                exit(0);
            }
        }
    }
    return 0;
}

//find the col number of an arrary given its value
int find_col(int value)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == value)
            {
                return j;
                exit(0);
            }
        }
    }
    return 0;
}





/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    if (board[d-1][d-1] != 0)
    {
        //printf("error 1");
        return false;
    }
    else
    {
        //check all rows  except last row 
        for (int i = 0; i < (d - 1); i++)
        {
            for (int j = 0; j < (d - 1); j++)
            {
                if (board[i][j] >= board[i][j+1])
                {
                   //printf("i is %i and j is %i\n", i, j);
                   //printf("error 2");
                   return false;
                }
            }
        }
        
        //check everything in the last row except blank
        for (int x = 0; x <= (d - 3); x++)
        {
                if (board[d-1][x] >= board[d-1][x+1])
                {
                   //printf("row is %i and col is %i\n", d-1, x);
                   //printf("error 3");
                   return false;
                }
        }
        
        //check every col except last col
        for (int m = 0; m < (d - 2); m++)
        {
            for (int n = 0; n < (d - 1); n++)
            {
                if (board[n][m] >= board[n+1][m])
                {
                   //printf("n is %i and m is %i\n", n, m);
                   //printf("error 4");
                   return false;
                }
            }
        }
        
        return true;
    
    }
    

 return true;       
 
}

