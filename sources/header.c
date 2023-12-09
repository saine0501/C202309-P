#include <stdio.h>
#include <string.h>

char password[10];

int getPassword() {
	int tryCount = 0;

	while (1) {
		printf("비밀번호를 입력하세요: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("맞았습니다!\n");
			printf("\n");
			return 0;
		}
		else {
			tryCount++;
			printf("틀렸습니다. 다시 입력해주세요. 기회는 %d번 남았습니다.\n", 3 - tryCount);

			if (tryCount >= 3) {
				printf("비밀번호 3회 이상 실패. 프로그램을 종료합니다.\n");
				return 1;
			}
		}
	}
}