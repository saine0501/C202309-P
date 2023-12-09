#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define _CRT_SECURE_NO_WARNINGS

#define CHARNUM 20
#define STUDENTS 4
#define MAX 10000

void getMessage(int numName);
void getNow();
void testVocabulary();

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
	printf("3. 단어 퀴즈\n");
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

				printf("수업 메시지 출력 프로그램입니다!\n");
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
				printf("수업 진행 현황 출력 프로그램입니다!\n");
				getNow();
			}
			break;

		case 3:
			// 단어 퀴즈
			printf("단어 퀴즈 프로그램입니다!\n");
			testVocabulary();
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
		printf("3. 단어 퀴즈\n");
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

void testVocabulary() {
	FILE* fp;
	fopen_s(&fp, "./vocabulary.txt", "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	char eng_word[256] = ""; // 영어 단어
	char kor_word[256] = ""; // 한국어 뜻
	char answer[256] = ""; // 멘티의 답

	int lineCount = 0;

	while (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word, (unsigned int)sizeof(kor_word)) != EOF) {
		lineCount++;
	}

	rewind(fp);

	for (int i = 0; i < lineCount; i++) {
		if (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word, (unsigned int)sizeof(kor_word)) != EOF) {
			printf("'%s'의 한국어 뜻은? ", eng_word);
			scanf_s("%s", answer, (unsigned int)sizeof(answer));

			if (strcmp(answer, kor_word) == 0) {
				printf("%s, 정답입니다!\n", kor_word);
			}
			else {
				printf("틀렸습니다. 정답은 %s입니다.\n", kor_word);
			}
		}
	}

	fclose(fp);

}