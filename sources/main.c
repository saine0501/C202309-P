#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "header.h"

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000

int main() {
	int numStudents = 4;
	int terminate = 0;
	int tryCount = 0;

	// 멘티들의 이름은 김가가, 이나나, 박다다, 최라라
	// 수업 시간은 18:00, 19:30, 20:30, 21:00
	struct StudentInfo* students = (struct StudentInfo*)malloc(numStudents * sizeof(struct StudentInfo));
	if (students == NULL) {
		printf("메모리 할당 오류\n");
		return 1;
	}

	printf("멘토링 자동 관리 프로그램\n\n");
	printf("멘티의 이름을 입력해주세요!\n");
	inputStudentInfo(students, numStudents);

	printf("\n멘티별 수업시간을 입력해주세요!\n");
	printf("입력 형식은 00:00 입니다.\n");
	inputTimeInfo(students, numStudents);

	printf("----------------------\n");
	printf("메뉴를 선택해주세요.\n");
	printf("1. 수업 메시지 출력\n");
	printf("2. 수업 진행 현황\n");
	printf("3. 단어 퀴즈\n");
	printf("4. 스톱워치\n");
	printf("5. 프로그램 종료\n");
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

				printf("수업 메시지 출력 프로그램입니다!\n");
				printf("1: %s 2: %s 3: %s 4: %s\n",
					students[0].name, students[1].name, students[2].name, students[3].name);
				printf("멘티의 이름을 선택해주세요 : ");
				scanf_s("%d", &numName);

				getMessage(students, numName);
			}
			break;

		case 2:
			// 수업 진행 현황 출력
			if (getPassword() == 1) {
				return 0;
			}
			else {
				printf("수업 진행 현황 출력 프로그램입니다!\n");
				getNow(students);
			}
			break;

		case 3:
			// 단어 퀴즈
			printf("단어 퀴즈 프로그램입니다!\n");
			testVocabulary();
			break;

		case 4:
			// 스톱워치 프로그램
			printf("스톱워치 프로그램입니다!\n\n");
			stopWatch();
			break;

		case 5:
			// 종료
			terminate = 1;
			break;

		default: // 사용자가 1~5가 아닌 다른 값을 입력할 경우
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.");
			freeStudentInfo(students, numStudents);
			break;
		}

		// 종료 선택 전까지 메뉴 선택 목록 반복 출력
		printf("\n");
		printf("----------------------\n");
		printf("메뉴를 선택해주세요.\n");
		printf("1. 수업 메시지 출력\n");
		printf("2. 수업 진행 현황\n");
		printf("3. 단어 퀴즈\n");
		printf("4. 스톱워치\n");
		printf("5. 프로그램 종료\n");
		printf("----------------------\n");
	}
	return 0;
}
