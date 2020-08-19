#include <stdio.h>
#define col 3
#define row 3

int main() {
	char board[3][3];   // ���带 ��Ÿ���� 2���� �迭
	int x,count=0;
	int invalid_input;	// �Է��� �߸��Ǿ��� ���� = flag
	int decided = 0;		// ���� �º� ���� ���� = flag
	char turn = 'O';		// ������ ���� 'X' �Ǵ� 'O' ���� ������ ����
	char r ='y';			
		
	while (r == 'y' && !decided){
		for (int i = 0; i < 9; i++)   // ���� �ʱ�ȭ
			board[i / 3][i % 3] = ' ';
		count = 0;
		for (int i = 0; i < col * row; i++) {
			if (board[i / 3][i % 3] != ' ')
				printf("[%c]", board[i / 3][i % 3]);
			else printf("[%d]", i + 1);
			if (i % 3 == 2)printf("\n");
		}
		while (count++ < 9 && !decided) {	// �º� �� ������ �ݺ�
			do {				
				invalid_input = 0;	// �Է��� �߸����� ���� ���·� ����

				printf("���� �� ĭ �Է� : ");
				scanf_s("%d", &x);

				if (x < 1 || x > 9) {
					printf("������ ���� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					invalid_input = 1;	// �Է¿� ������ ������ ǥ��
				}
				else if (board[(x - 1) / 3][(x - 1) % 3] != ' ') {
					printf("���� �ڸ��� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					invalid_input = 1;	// �Է¿� ������ ������ ǥ��	
				}
			} while (invalid_input);	// �߸��Ǿ����� �ٽ� �Է� ����

			turn = (count % 2) == 0 ? 'X' : 'O';// ������ ���� 'X' �Ǵ� 'O' ��
			board[(x - 1) / 3][(x - 1) % 3] = turn;

			// board ���
			for (int i = 0; i < col * row; i++) {
				if (board[i / 3][i % 3] != ' ')
					printf("[%c]", board[i / 3][i % 3]);
				else printf("[%d]", i + 1);
				if (i % 3 == 2)printf("\n");
			}

			// �̹��� ����(turn) ���ڷ� ���� �º� Ȯ�� : �밢�� 2��
			if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn
				|| board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
				decided = 1;	// �º� ����
			else	// �밢�� ������ ����, ���� �� 3�� �˻�
				for (x = 0; x < 3; x++)
					if (board[x][0] == turn && board[x][1] == turn && board[x][2] == turn
						|| board[0][x] == turn && board[1][x] == turn && board[2][x] == turn)
						decided = 1;	// �º� ����
		}
		
		if (decided)	// �ºΰ� ������
			printf("%c�� �¸�!!\n", turn);
		else {
			printf("���º�\n");
			printf("�ٽ� �����Ͻðڽ��ϱ�?(y/n) :");
			getchar();
			scanf_s("%c", &r);			
		}
	}
	return 0;
}