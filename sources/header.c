#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "header.h"

#define MAX 10000

char password[10];

void inputStudentInfo(struct StudentInfo* students, int numStudents) {
	// ��Ƽ�� �̸��� �Է¹޾� ����
	for (int i = 0; i < numStudents; i++) {
		students[i].name = (char*)malloc(50 * sizeof(char));
		if (students[i].name == NULL) {
			printf("�޸� �Ҵ� ����\n");
			exit(1);
		}

		printf("%d��° ��Ƽ�� �̸� : ", i + 1);
		scanf_s("%s", students[i].name, 50);
	}
}

void inputTimeInfo(struct StudentInfo* students, int numStudents) {
	// ��Ƽ �� ���� �ð��� �Է¹޾� ����
	for (int i = 0; i < numStudents; i++) {
		students[i].time = (char*)malloc(50 * sizeof(char));
		if (students[i].time == NULL) {
			printf("�޸� �Ҵ� ����\n");
			exit(1);
		}

		printf("%s ��Ƽ�� ���� �ð� : ", students[i].name);
		scanf_s("%s", students[i].time, 50);
	}
}

void freeStudentInfo(struct StudentInfo* students, int numStudents) {
	// ���� �޸� �Ҵ� ����
	for (int i = 0; i < numStudents; i++) {
		free(students[i].name);
		free(students[i].time);
	}
	free(students);
}

int getPassword() {
	int tryCount = 0;

	while (1) {
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			// ��й�ȣ�� ���� ���
			printf("�¾ҽ��ϴ�!\n");
			printf("\n");
			return 0;
		}
		else {
			// ��й�ȣ�� Ʋ�� ���
			tryCount++;
			printf("Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���. ��ȸ�� %d�� ���ҽ��ϴ�.\n", 3 - tryCount);

			// ��й�ȣ�� 3ȸ �̻� Ʋ�� ���
			if (tryCount >= 3) {
				printf("��й�ȣ 3ȸ �̻� ����. ���α׷��� �����մϴ�.\n");
				return 1;
			}
		}
	}
}

void getMessage(struct StudentInfo* students, int numName) {
	// ���� �޼��� ���
	int situation;

	printf("��Ȳ�� �������ּ���.\n");
	printf("1. ���� ���� ��\n");
	printf("2. ��Ƽ�� ����\n");
	printf("3. ���� ��\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		// ���� ���� ���� ����� �޼��� ���
		printf("%s ��Ƽ��, ��� �� %s�� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n",
			students[numName - 1].name, students[numName - 1].time);
	}
	else if (situation == 2) {
		// ��Ƽ�� ������ ����� �޼��� ���
		printf("%s ��Ƽ��, ���� ���� �� 10���� ����Ǿ����ϴ�. ���� ������ ������� �������?\n",
			students[numName - 1].name);
	}
	else if (situation == 3) {
		// ������ ���� ����� �޼��� ���
		printf("%s ��Ƽ��, ���� ������ �����ϼ̽��ϴ�! ���� ���� �ð��� �ٽ� ���� :)\n",
			students[numName - 1].name);
	}
}

void getNow(struct StudentInfo* students, int numStudents) {
	// ���� ���� ��Ȳ ���
	FILE* fp;
	fopen_s(&fp, "./mentoring.txt", "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return;
	}

	char line[MAX];
	int zeroCount = 0;
	int fortyFiveCount = 0;

	// ���� ���� Ƚ���� �Ἦ Ƚ�� ����� ���� ���� �޸� �Ҵ�
	int* sessionCounts = (int*)calloc(numStudents, sizeof(int));
	int* absentCounts = (int*)calloc(numStudents, sizeof(int));

	while (fgets(line, MAX, fp) != NULL) {
		// �޿� ����� ���� ������ ����� Ƚ�� ���
		if (strstr(line, "0��") != NULL) {
			zeroCount++;
		}
		if (strstr(line, "45��") != NULL) {
			fortyFiveCount++;
		}

		// ��Ƽ�� ���� ���� Ƚ���� �Ἦ Ƚ�� ���
		for (int i = 0; i < numStudents; i++) {
			if (strstr(line, students[i].name) != NULL) {
				// ������ ����� �� Ƚ��
				sessionCounts[i]++;
			}
			if (strstr(line, students[i].name) != NULL && strstr(line, "0��") != NULL) {
				// ��Ƽ�� �Ἦ�� Ƚ��
				absentCounts[i]++;
			}
		}
	}

	fclose(fp);

	// �� �޿� ���
	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	// ���� ������ �� �޿� ���
	printf("\n");
	for (int i = 0; i < numStudents; i++) {
		printf("%s ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", students[i].name,
			sessionCounts[i], 20 - sessionCounts[i]);
		printf("%s ��Ƽ�� �Ἦ Ƚ�� : %d\n", students[i].name, absentCounts[i]);
	}
	printf("�� �޿� : %d��\n", money);
	
	// ���� �޸� �Ҵ� ����
	free(sessionCounts);
	free(absentCounts);
}

void testVocabulary() {
	// �ܾ� ����
	FILE* fp;
	fopen_s(&fp, "./vocabulary.txt", "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return;
	}

	char eng_word[256] = ""; // ���� �ܾ�
	char kor_word[256] = ""; // �ѱ��� ��
	char answer[256] = ""; // ��Ƽ�� ��

	int lineCount = 0;

	// �Է��� ���Ͽ��� ���� �ܾ�� �ѱ��� �� ����
	while (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word,
		(unsigned int)sizeof(kor_word)) != EOF) 
	{
		lineCount++;
	}

	rewind(fp);

	// ���Ͽ� ����� line�� ����ŭ �ܾ� ���� ����
	for (int i = 0; i < lineCount; i++) {
		if (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word,
			(unsigned int)sizeof(kor_word)) != EOF) 
		{
			printf("\n'%s'�� �ѱ��� ����? ", eng_word);
			scanf_s("%s", answer, (unsigned int)sizeof(answer));

			if (strcmp(answer, kor_word) == 0) {
				printf("%s, �����Դϴ�!\n", kor_word);
			}
			else {
				printf("Ʋ�Ƚ��ϴ�. ������ %s�Դϴ�.\n", kor_word);
			}
		}
	}
	fclose(fp);
}

void stopWatch() {
	// �����ġ ���
	clock_t start = 0, now = 0;
	clock_t duration = 0, sec = 0, min = 0, hour = 0, milsec = 0;

	printf("�ٷ� ����, Ű���带 ������ ����\n");

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