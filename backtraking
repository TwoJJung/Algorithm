#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * void backtracking(node v){
 * 	if(promsing(v))
 * 		if(there is a solution at v)
 * 			write the solution;
 * 		else
 * 			for(each child u of v)
 * 				backtracking(u)
 * }
 */

/*
 * void expand (node v) {
 * 	for(each child u of f)
 * 		if(promising(u))
 * 			if(there is a solution at u)
 * 				write the solution;
 * 			else
 * 				expand(u);
 * }
 */

bool promising(int queen_index, int* columns){
	/*
	 * Condition for promising at queen_index
	 * 	1. columns[queen_index] != columns[passed_queen_index];
	 * 	2. queen_index - passed_queen_index != 
	 * 		abs(columns[queen_index] - columns[passed_queen_index]);  
	 */
		
	for(int i = 1; i < queen_index; ++i){
		if(columns[queen_index] == columns[i]) return false;
		if((queen_index - i) == abs(columns[queen_index] - columns[i])) return false;
	}

	return true;
}

void n_queens_problem(int queen_index, int num_queens, int* columns){
	if(promising(queen_index, columns)){
		//if queen_index == num_queens, every queen is on chessboard(finish).
		if(queen_index == num_queens){
			for(int i = 1; i <= num_queens; ++i){
				printf("(%d, %d)\n", i, columns[i]);
			}
			printf("\n");
		}
		else { //queen_index != num_queens
			for(int j = 1; j <= num_queens; ++j){
				columns[queen_index + 1] = j;
				n_queens_problem(queen_index + 1, num_queens, columns);
			}
		}

	}
}

void n_queens_problem_expand(int queen_index, int num_queens, int* columns){
	for(int i = 1; i <= num_queens; ++i){
		columns[queen_index+1] = i;
		if(promising(queen_index+1, columns)){
			if(queen_index+1 == num_queens){
				for(int i = 1; i <= num_queens; ++i){
					printf("(%d, %d)\n", i, columns[i]);
				}
				printf("\n");
			}	
			else{
				n_queens_problem_expand(queen_index+1, num_queens, columns);
			}
		}
	}
}

int main(void) {
	int columns[5];
	
	printf("solution of original version\n");	
	for(int i = 1; i <= 4; ++i){
		columns[1] = i;
		n_queens_problem(1, 4, columns);
	}

	printf("solution of expand version\n");
	for(int i = 1; i <= 4; ++i){
		columns[1] = i;
		n_queens_problem_expand(1,4,columns);
	}

	return 0;
}
