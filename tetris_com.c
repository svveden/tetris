#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

void create_board(char a[SIZE][SIZE]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			a[i][j] = '.';
		}
	}
}

void print_board(char a[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
}


int row_checker(char a[10][10]){
	int row = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(a[i][j] == '@'){
				row++;
			}
			if(row == 10){
				return i;
			}
		}
		row = 0;
	}
	return 0;
}

int bottom_row(int row){
	return row+1 == 10;
}

int hit_marker(char a[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(a[i+1][j] == '@' && a[i][j] == 'a'){
			 	return 1;
			 }
		}
	}
	return 0;
}

void shape_solidify(char a[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(a[i][j] == 'a'){
				a[i][j] = '@';
			}
		}
	}
	shape_pos_y = 0;
	shape_pos_x = 5;
	return;
}

void shape_eraser(char a[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(a[i][j] == 'a'){
				a[i][j] = '.';
			}
		}
	}
}

int move_shape_2(char a[10][10]){
	while(row_checker(a) > 0){
		printf("\a");
		for(int i = 9; i > 0; i--){
			for(int j = 0; j < 10; j++){
				a[i+1][j] = a[i][j];
			}
		}
	}
	if(upright == 1){
		if(bottom_row(shape_pos_y-1) || hit_marker(a)){
			shape_solidify(a);
			return 0;
		}
	} else {
		if(bottom_row(shape_pos_y) || hit_marker(a)){
			shape_solidify(a);
			return 0;
		}
	}
	shape_eraser(a);

	if(upright == 0){
		a[shape_pos_y+1][shape_pos_x] = shape;
		a[shape_pos_y][shape_pos_x] = shape;
		a[shape_pos_y+1][shape_pos_x+1] = shape;
	}
	if(upright == 1){
		a[shape_pos_y][shape_pos_x+1] = shape;
		a[shape_pos_y-1][shape_pos_x] = shape;
		a[shape_pos_y-1][shape_pos_x+1] = shape;
	}
	return 1;
}

int move_shape(char a[10][10]){
	while(row_checker(a) > 0){
		printf("\a");
		for(int i = 9; i > 0; i--){
			for(int j = 0; j < 10; j++){
				a[i+1][j] = a[i][j];
			}
		}
	}
	if(upright == 1){
		if(bottom_row(shape_pos_y-1)|| hit_marker(a)) {
			upright = 0;
			shape_solidify(a);
			return 1;
		}
	}

	if(upright == 0){
		if(bottom_row(shape_pos_y)|| hit_marker(a)) {
			shape_solidify(a);
			return 1;
		}
	}
	shape_eraser(a);
	if(upright == 0){
		a[shape_pos_y+1][shape_pos_x] = shape;
		a[shape_pos_y+1][shape_pos_x-1] = shape;
	}
	if(upright == 1){
		a[shape_pos_y][shape_pos_x] = shape;
		a[shape_pos_y-1][shape_pos_x] = shape;
	}
	return 0;
}

