#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "header.h"

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

void inputStudentInfo(struct StudentInfo* students, int numStudents) {
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
	for (int i = 0; i < numStudents; i++) {
		free(students[i].name);
		free(students[i].time);
	}
	free(students);
}

void getMessage(struct StudentInfo* students, int numName) {
	int situation;

	printf("상황을 선택해주세요.\n");
	printf("1. 수업 시작 전\n");
	printf("2. 멘티의 지각\n");
	printf("3. 수업 끝\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		printf("%s 멘티님, 잠시 후 %s 에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n",
			students[numName - 1].name, students[numName - 1].time);
	}
	else if (situation == 2) {
		printf("%s 멘티님, 수업 시작 후 10분이 경과되었습니다. 수업 참여에 어려움이 있을까요?\n",
			students[numName - 1].name);
	}
	else if (situation == 3) {
		printf("%s 멘티님, 오늘 수업도 수고하셨습니다! 다음 수업 시간에 다시 봐요 :)\n",
			students[numName - 1].name);
	}
}

void getNow(struct StudentInfo* students) {
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
		if (strstr(line, students[0].name) != NULL) {
			one++;
		}
		if (strstr(line, students[1].name) != NULL) {
			two++;
		}
		if (strstr(line, students[2].name) != NULL) {
			three++;
		}
		if (strstr(line, students[3].name) != NULL) {
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

	printf("%s 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", students[0].name, one, 20 - one);
	printf("%s 멘티의 결석 횟수 : %d\n", students[0].name, oneNo);
	printf("%s 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", students[1].name, two, 20 - two);
	printf("%s 멘티의 결석 횟수 : %d\n", students[1].name, twoNo);
	printf("%s 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", students[2].name, three, 20 - three);
	printf("%s 멘티의 결석 횟수 : %d\n", students[2].name, threeNo);
	printf("%s 멘티의 수업 진행 회차 : 총 %d회 / 남은 회차 : %d회\n", students[3].name, four, 20 - four);
	printf("%s 멘티의 결석 횟수 : %d\n", students[3].name, fourNo);
	printf("총 급여 : %d원\n", money);
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

void stopWatch() {
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