#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

int shape_pos_y = 0;
int shape_pos_x = 5;
char shape = 'a';
int upright = 0;

int main(void){
	char a[SIZE][SIZE]; //create array for board
	create_board(a); //set up board to be all '.'
	int count = 0;
	while(1){
		if(!count){
			count = move_shape(a);
		}
		if(count){
			count = move_shape_2(a);
		}

		print_board(a);
		//sleep(1);
		char c = getc(stdin);

		switch(c){
			case 'a':
				if(shape_pos_x >= 1){ //if not upright >= 2 
					shape_pos_y -= 1;
					shape_pos_x -= 1;
				}
				break;
			case 'd':
				if(shape_pos_x < 9){
					shape_pos_y -= 1;
					shape_pos_x += 1;
				}
				break;
			case 'w':
				if(upright == 0){
					upright = 1;
				}
				break;
			case 's':
				if(upright == 1){
					shape_pos_y -=2;
					upright = 0;
				}
		}
		shape_pos_y += 1; //move down one
		system("clear");
	}
	return 0;
}
