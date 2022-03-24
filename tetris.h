#define SIZE 10

extern int shape_pos_y;
extern int shape_pos_x;
extern char shape;
extern int upright;

void create_board(char a[SIZE][SIZE]);
void print_board(char a[SIZE][SIZE]);
int row_checker(char a[10][10]);
int move_shape_2(char a[10][10]);
int move_shape(char a[10][10]);
