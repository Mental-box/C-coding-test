#include <stdio.h>

void my_print(int arr[]) {
	int num = 0;
	printf("1000������ �Ҽ��� \n");
	for (int i = 1; i < 1000; i++) {
		if (arr[i] != NULL) {
			printf("%4d\t", arr[i]);
			num++;
		}
	}
	printf("�̸� �� %d�� �Դϴ�.\n", num);
}

int main() {	
	int arr[1001];

	for (int i = 0; i <= 1000; i++) {
		arr[i] = i;
	}
	
	arr[1] = NULL;

	for (int i = 2; i * i <= 1000; i++) {
		if (arr[i] != NULL) {
			for (int j = 2; j * i <= 1000; j++) {
				arr[j * i] = NULL;
			}
		}
	}

	my_print(arr);

	return 0;
}