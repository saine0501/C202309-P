#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "header.h"

#define MAX 10000

char password[10];

void inputStudentInfo(struct StudentInfo* students, int numStudents) {
	// 멘티의 이름을 입력받아 저장
	for (int i = 0; i < numStudents; i++) {
		students[i].name = (char*)malloc(50 * sizeof(char));
		if (students[i].name == NULL) {
			printf("메모리 할당 오류\n");
			exit(1);
		}

		printf("%d번째 멘티의 이름 : ", i + 1);
		scanf_s("%s", students[i].name, 50);
	}
}

void inputTimeInfo(struct StudentInfo* students, int numStudents) {
	// 멘티 별 수업 시간을 입력받아 저장
	for (int i = 0; i < numStudents; i++) {
		students[i].time = (char*)malloc(50 * sizeof(char));
		if (students[i].time == NULL) {
			printf("메모리 할당 오류\n");
			exit(1);
		}

		printf("%s 멘티의 수업 시간 : ", students[i].name);
		scanf_s("%s", students[i].time, 50);
	}
}

void freeStudentInfo(struct StudentInfo* students, int numStudents) {
	// 동적 메모리 할당 해제
	for (int i = 0; i < numStudents; i++) {
		free(students[i].name);
		free(students[i].time);
	}
	free(students);
}

int getPassword() {
	int tryCount = 0;

	while (1) {
		printf("비밀번호를 입력하세요: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			// 비밀번호를 맞춘 경우
			printf("맞았습니다!\n");
			printf("\n");
			return 0;
		}
		else {
			// 비밀번호를 틀린 경우
			tryCount++;
			printf("틀렸습니다. 다시 입력해주세요. 기회는 %d번 남았습니다.\n", 3 - tryCount);

			// 비밀번호를 3회 이상 틀린 경우
			if (tryCount >= 3) {
				printf("비밀번호 3회 이상 실패. 프로그램을 종료합니다.\n");
				return 1;
			}
		}
	}
}

void getMessage(struct StudentInfo* students, int numName) {
	// 수업 메세지 출력
	int situation;

	printf("상황을 선택해주세요.\n");
	printf("1. 수업 시작 전\n");
	printf("2. 멘티의 지각\n");
	printf("3. 수업 끝\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		// 수업 시작 전인 경우의 메세지 출력
		printf("%s 멘티님, 잠시 후 %s에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n",
			students[numName - 1].name, students[numName - 1].time);
	}
	else if (situation == 2) {
		// 멘티가 지각한 경우의 메세지 출력
		printf("%s 멘티님, 수업 시작 후 10분이 경과되었습니다. 수업 참여에 어려움이 있을까요?\n",
			students[numName - 1].name);
	}
	else if (situation == 3) {
		// 수업이 끝난 경우의 메세지 출력
		printf("%s 멘티님, 오늘 수업도 수고하셨습니다! 다음 수업 시간에 다시 봐요 :)\n",
			students[numName - 1].name);
	}
}

void getNow(struct StudentInfo* students, int numStudents) {
	// 수업 진행 현황 출력
	FILE* fp;
	fopen_s(&fp, "./mentoring.txt", "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return;
	}

	char line[MAX];
	int zeroCount = 0;
	int fortyFiveCount = 0;

	// 수업 진행 횟수와 결석 횟수 계산을 위한 동적 메모리 할당
	int* sessionCounts = (int*)calloc(numStudents, sizeof(int));
	int* absentCounts = (int*)calloc(numStudents, sizeof(int));

	while (fgets(line, MAX, fp) != NULL) {
		// 급여 계산을 위해 수업이 진행된 횟수 계산
		if (strstr(line, "0분") != NULL) {
			zeroCount++;
		}
		if (strstr(line, "45분") != NULL) {
			fortyFiveCount++;
		}

		// 멘티의 수업 진행 횟수와 결석 횟수 계산
		for (int i = 0; i < numStudents; i++) {
			if (strstr(line, students[i].name) != NULL) {
				// 수업이 진행된 총 횟수
				sessionCounts[i]++;
			}
			if (strstr(line, students[i].name) != NULL && strstr(line, "0분") != NULL) {
				// 멘티가 결석한 횟수
				absentCounts[i]++;
			}
		}
	}

	fclose(fp);

	// 총 급여 계산
	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	// 수업 정보와 총 급여 출력
	printf("\n");
	for (int i = 0; i < numStudents; i++) {
		printf("%s 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", students[i].name,
			sessionCounts[i], 20 - sessionCounts[i]);
		printf("%s 멘티의 결석 횟수 : %d\n", students[i].name, absentCounts[i]);
	}
	printf("총 급여 : %d원\n", money);
	
	// 동적 메모리 할당 해제
	free(sessionCounts);
	free(absentCounts);
}

void testVocabulary() {
	// 단어 퀴즈
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

	// 입력한 파일에서 영어 단어와 한국어 뜻 저장
	while (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word,
		(unsigned int)sizeof(kor_word)) != EOF) 
	{
		lineCount++;
	}

	rewind(fp);

	// 파일에 저장된 line의 수만큼 단어 퀴즈 출제
	for (int i = 0; i < lineCount; i++) {
		if (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word,
			(unsigned int)sizeof(kor_word)) != EOF) 
		{
			printf("\n'%s'의 한국어 뜻은? ", eng_word);
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

void stopWatch() {
	// 스톱워치 기능
	clock_t start = 0, now = 0;
	clock_t duration = 0, sec = 0, min = 0, hour = 0, milsec = 0;

	printf("바로 시작, 키보드를 누르면 종료\n");

	start = clock();

	while (1) {

		now = clock();
		duration = now - start;

		sec = duration / CLOCKS_PER_SEC;
		milsec = duration % CLOCKS_PER_SEC;
		hour = sec / 3600;
		min = (sec % 3600) / 60;
		sec = sec % 60;

		printf("%d:%02d:%02d.%03d\r", hour, min, sec, milsec);

		if (_kbhit()) {
			break;
		}
	}
	printf("\n");
}