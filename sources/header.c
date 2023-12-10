#include <stdio.h>
#include <string.h>
#define MAX 10000

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

void getNow() {
	FILE* fp;
	fopen_s(&fp, "./mentoring.txt", "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	char line[MAX];
	int zeroCount = 0;
	int fortyFiveCount = 0;
	int one = 0, two = 0, three = 0, four = 0;
	int oneNo = 0, twoNo = 0, threeNo = 0, fourNo = 0;

	while (fgets(line, MAX, fp) != NULL) {
		if (strstr(line, "0분") != NULL) {
			zeroCount++;
		}
		if (strstr(line, "45분") != NULL) {
			fortyFiveCount++;
		}
		if (strstr(line, "김가가") != NULL) {
			one++;
		}
		if (strstr(line, "이나나") != NULL) {
			two++;
		}
		if (strstr(line, "박다다") != NULL) {
			three++;
		}
		if (strstr(line, "최라라") != NULL) {
			four++;
		}
		if (strstr(line, "김가가 0분") != NULL) {
			oneNo++;
		}
		if (strstr(line, "이나나 0분") != NULL) {
			twoNo++;
		}
		if (strstr(line, "박다다 0분") != NULL) {
			threeNo++;
		}
		if (strstr(line, "최라라 0분") != NULL) {
			fourNo++;
		}
	}

	fclose(fp);
	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	printf("김가가 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", one, 20 - one);
	printf("김가가 멘티의 결석 횟수 : %d\n", oneNo);
	printf("이나나 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", two, 20 - two);
	printf("이나나 멘티의 결석 횟수 : %d\n", twoNo);
	printf("박다다 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", three, 20 - three);
	printf("박다다 멘티의 결석 횟수 : %d\n", threeNo);
	printf("최라라 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", four, 20 - four);
	printf("최라라 멘티의 결석 횟수 : %d\n", fourNo);
	printf("총 급여 : %d원\n", money);
}