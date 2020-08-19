#include <stdio.h>
#define col 3
#define row 3

int main() {
	int board[col][row];
	int turn = 1;
	int n;

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			board[i][j] = 0;
		
	while (1){
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (board[i][j]) {
					if (board[i][j] == 1)printf("[¡Û]");
					if (board[i][j] == 2)printf("[¡Ü]");
				}
				else	printf("[ %d]", i * 3 + j + 1);	
			}
			printf("\n");
		}
		printf("Enter the number : ");
		scanf_s("%d", &n);
		if (n > 0 && n < 10) {
			switch (turn)
			{
			case 1:
				board[(n-1) / col][(n-1) % row] = 1;
				turn += 1;
				break;
			case 2:
				board[(n-1) / col][(n-1) % row] = 2;
				turn -= 1;
				break;
			default:
				break;
			}
		}
		if ((board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) ||
			(board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) ||
			(board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) ||

			(board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) ||
			(board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) ||
			(board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) ||

			(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
			(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)) {
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (board[i][j]) {
						if (board[i][j] == 1)printf("[¡Û]");
						if (board[i][j] == 2)printf("[¡Ü]");
					}
					else	printf("[ %d]", i * 3 + j + 1);
				}
				printf("\n");
			}
			printf("player 1 win\n");
			return 1;
		}
		if ((board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) ||
			(board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) ||
			(board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) ||

			(board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) ||
			(board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) ||
			(board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) ||

			(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) ||
			(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)) {
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (board[i][j]) {
						if (board[i][j] == 1)printf("[¡Û]");
						if (board[i][j] == 2)printf("[¡Ü]");
					}
					else	printf("[ %d]", i * 3 + j + 1);
				}
				printf("\n");
			}
			printf("player 2 win\n");
			return 2;
		}
	}// while (gameover(board)!=0);
	return 0;
}