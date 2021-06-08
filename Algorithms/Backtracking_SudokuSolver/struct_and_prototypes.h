typedef struct
{
    int y_coordinate;
    int x_coordinate;
    int completed;
} Coordinate;

//function prototypes

void Print_board(int (*board)[9], int array_length);
Coordinate Find_first_empty_square(int (*board)[9], int array_length);
int Validate_value(int (*board)[9], int value, Coordinate coordinate, int array_length);
int Solve(int (*board)[9], int array_length);