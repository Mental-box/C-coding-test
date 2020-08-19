#include <stdio.h>
#define col 3
#define row 3

int main() {
	char board[3][3];   // 보드를 나타내는 2차원 배열
	int x,count=0;
	int invalid_input;	// 입력이 잘못되었지 여부 = flag
	int decided = 0;		// 게임 승부 결정 여부 = flag
	char turn = 'O';		// 순번에 따라 'X' 또는 'O' 값을 가지는 문자
	char r ='y';			
		
	while (r == 'y' && !decided){
		for (int i = 0; i < 9; i++)   // 보드 초기화
			board[i / 3][i % 3] = ' ';
		count = 0;
		for (int i = 0; i < col * row; i++) {
			if (board[i / 3][i % 3] != ' ')
				printf("[%c]", board[i / 3][i % 3]);
			else printf("[%d]", i + 1);
			if (i % 3 == 2)printf("\n");
		}
		while (count++ < 9 && !decided) {	// 승부 안 났으면 반복
			do {				
				invalid_input = 0;	// 입력이 잘못되지 않은 상태로 시작

				printf("수를 둘 칸 입력 : ");
				scanf_s("%d", &x);

				if (x < 1 || x > 9) {
					printf("범위를 벗어 났습니다. 다시 입력하세요.\n");
					invalid_input = 1;	// 입력에 문제가 있음을 표시
				}
				else if (board[(x - 1) / 3][(x - 1) % 3] != ' ') {
					printf("같은 자리에 놓을 수 없습니다. 다시 입력하세요.\n");
					invalid_input = 1;	// 입력에 문제가 있음을 표시	
				}
			} while (invalid_input);	// 잘못되었으면 다시 입력 받음

			turn = (count % 2) == 0 ? 'X' : 'O';// 순번에 따라 'X' 또는 'O' 값
			board[(x - 1) / 3][(x - 1) % 3] = turn;

			// board 출력
			for (int i = 0; i < col * row; i++) {
				if (board[i / 3][i % 3] != ' ')
					printf("[%c]", board[i / 3][i % 3]);
				else printf("[%d]", i + 1);
				if (i % 3 == 2)printf("\n");
			}

			// 이번에 놓은(turn) 문자로 게임 승부 확인 : 대각선 2개
			if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn
				|| board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
				decided = 1;	// 승부 결정
			else	// 대각선 없으면 가로, 세로 각 3개 검사
				for (x = 0; x < 3; x++)
					if (board[x][0] == turn && board[x][1] == turn && board[x][2] == turn
						|| board[0][x] == turn && board[1][x] == turn && board[2][x] == turn)
						decided = 1;	// 승부 결정
		}
		
		if (decided)	// 승부가 났으면
			printf("%c의 승리!!\n", turn);
		else {
			printf("무승부\n");
			printf("다시 시작하시겠습니까?(y/n) :");
			getchar();
			scanf_s("%c", &r);			
		}
	}
	return 0;
}