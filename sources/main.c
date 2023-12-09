#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define CHARNUM 20
#define STUDENTS 4
#define MAX 10000

char password[10];

int getPassword();
void getMessage(int numName);
void getNow();

int main() {
	int terminate = 0;
	int tryCount = 0;
	char studentNames[STUDENTS][CHARNUM] = {"김가가", "이나나", "박다다", "최라라"};
	char studentTimes[STUDENTS][CHARNUM] = {"6시", "7시 30분", "8시 30분", "9시"};

	printf("멘토링 자동 관리 프로그램\n");
	printf("----------------------\n");
	printf("메뉴를 선택해주세요.\n");
	printf("1. 수업 메시지 출력\n");
	printf("2. 수업 진행 현황\n");
	printf("3. 단어장\n");
	printf("4. 프로그램 종료\n");
	printf("----------------------\n");

	while (1) {
		int choiceA = -1;
		scanf_s("%d", &choiceA);

		switch (choiceA) {

		case 1:
			// 수업 메시지 출력
			if (getPassword() == 1) {
				return 0;
			}
			else {
				int numName = -1;

				printf("1: %s 2: %s 3: %s 4: %s\n",
					studentNames[0], studentNames[1], studentNames[2], studentNames[3]);
				printf("멘티의 이름을 선택해주세요 : ");
				scanf_s("%d", &numName);

				getMessage(numName);
			}
			break;

		case 2:
			// 수업 진행 현황 출력
			if (getPassword() == 1) {
				return 0;
			}
			else {
				getNow();
			}
			break;

		case 3:
			// 단어장

			break;

		case 4:
			// 종료
			terminate = 1;
			break;

		default: // 사용자가 1~4가 아닌 다른 값을 입력할 경우
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.");
			break;
		}

		printf("\n");
		printf("----------------------\n");
		printf("메뉴를 선택해주세요.\n");
		printf("1. 수업 메시지 출력\n");
		printf("2. 수업 진행 현황\n");
		printf("3. 단어장\n");
		printf("4. 프로그램 종료\n");
		printf("----------------------\n");

	}
	return 0;
}

void getMessage(int numName) {
	int situation;
	char studentNames[STUDENTS][CHARNUM] = { "김가가", "이나나", "박다다", "최라라" };
	char studentTimes[STUDENTS][CHARNUM] = { "6시", "7시 30분", "8시 30분", "9시" };

	printf("상황을 선택해주세요.\n");
	printf("1. 수업 시작 전\n");
	printf("2. 멘티의 지각\n");
	printf("3. 수업 끝\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		printf("%s 멘티님, 잠시 후 오후 %s에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n",
			studentNames[numName - 1], studentTimes[numName - 1]);
	}
	else if (situation == 2) {
		printf("%s 멘티님, 수업 시작 후 10분이 경과되었습니다. 수업 참여에 어려움이 있을까요?\n",
			studentNames[numName - 1]);
	}
	else if (situation == 3) {
		printf("%s 멘티님, 오늘 수업도 수고하셨습니다! 다음 수업 시간에 다시 봐요 :)\n",
			studentNames[numName - 1]);
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
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int oneNo = 0;
	int twoNo = 0;
	int threeNo = 0;
	int fourNo = 0;

	// 파일에서 한 줄씩 읽어오기
	while (fgets(line, MAX, fp) != NULL) {
		// "0분"이라는 문자열이 포함되어 있는지 확인
		if (strstr(line, "0분") != NULL) {
			zeroCount++;
		}

		// "45분"이라는 문자열이 포함되어 있는지 확인
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

	// 파일 닫기
	fclose(fp);

	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	// 결과 출력
	printf("김가가 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", one, 20-one);
	printf("김가가 멘티의 결석 횟수 : %d\n", oneNo);
	printf("이나나 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", two, 20 - two);
	printf("이나나 멘티의 결석 횟수 : %d\n", twoNo);
	printf("박다다 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", three, 20 - three);
	printf("박다다 멘티의 결석 횟수 : %d\n", threeNo);
	printf("최라라 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", four, 20 - four);
	printf("최라라 멘티의 결석 횟수 : %d\n", fourNo);
	printf("총 급여 : %d원\n", money);
}
