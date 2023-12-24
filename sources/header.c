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
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("�¾ҽ��ϴ�!\n");
			printf("\n");
			return 0;
		}
		else {
			tryCount++;
			printf("Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���. ��ȸ�� %d�� ���ҽ��ϴ�.\n", 3 - tryCount);

			if (tryCount >= 3) {
				printf("��й�ȣ 3ȸ �̻� ����. ���α׷��� �����մϴ�.\n");
				return 1;
			}
		}
	}
}

void inputStudentInfo(struct StudentInfo* students, int numStudents) {
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
	for (int i = 0; i < numStudents; i++) {
		free(students[i].name);
		free(students[i].time);
	}
	free(students);
}

void getMessage(struct StudentInfo* students, int numName) {
	int situation;

	printf("��Ȳ�� �������ּ���.\n");
	printf("1. ���� ���� ��\n");
	printf("2. ��Ƽ�� ����\n");
	printf("3. ���� ��\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		printf("%s ��Ƽ��, ��� �� %s �� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n",
			students[numName - 1].name, students[numName - 1].time);
	}
	else if (situation == 2) {
		printf("%s ��Ƽ��, ���� ���� �� 10���� ����Ǿ����ϴ�. ���� ������ ������� �������?\n",
			students[numName - 1].name);
	}
	else if (situation == 3) {
		printf("%s ��Ƽ��, ���� ������ �����ϼ̽��ϴ�! ���� ���� �ð��� �ٽ� ���� :)\n",
			students[numName - 1].name);
	}
}

void getNow(struct StudentInfo* students) {
	FILE* fp;
	fopen_s(&fp, "./mentoring.txt", "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return;
	}

	char line[MAX];
	int zeroCount = 0;
	int fortyFiveCount = 0;
	int one = 0, two = 0, three = 0, four = 0;
	int oneNo = 0, twoNo = 0, threeNo = 0, fourNo = 0;

	while (fgets(line, MAX, fp) != NULL) {
		if (strstr(line, "0��") != NULL) {
			zeroCount++;
		}
		if (strstr(line, "45��") != NULL) {
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
		if (strstr(line, "�谡�� 0��") != NULL) {
			oneNo++;
		}
		if (strstr(line, "�̳��� 0��") != NULL) {
			twoNo++;
		}
		if (strstr(line, "�ڴٴ� 0��") != NULL) {
			threeNo++;
		}
		if (strstr(line, "�ֶ�� 0��") != NULL) {
			fourNo++;
		}
	}

	fclose(fp);
	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	printf("%s ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", students[0].name, one, 20 - one);
	printf("%s ��Ƽ�� �Ἦ Ƚ�� : %d\n", students[0].name, oneNo);
	printf("%s ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", students[1].name, two, 20 - two);
	printf("%s ��Ƽ�� �Ἦ Ƚ�� : %d\n", students[1].name, twoNo);
	printf("%s ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", students[2].name, three, 20 - three);
	printf("%s ��Ƽ�� �Ἦ Ƚ�� : %d\n", students[2].name, threeNo);
	printf("%s ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", students[3].name, four, 20 - four);
	printf("%s ��Ƽ�� �Ἦ Ƚ�� : %d\n", students[3].name, fourNo);
	printf("�� �޿� : %d��\n", money);
}

void testVocabulary() {
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

	while (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word, (unsigned int)sizeof(kor_word)) != EOF) {
		lineCount++;
	}

	rewind(fp);

	for (int i = 0; i < lineCount; i++) {
		if (fscanf_s(fp, "%s %s", eng_word, (unsigned int)sizeof(eng_word), kor_word, (unsigned int)sizeof(kor_word)) != EOF) {
			printf("'%s'�� �ѱ��� ����? ", eng_word);
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