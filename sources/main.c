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
	char studentNames[STUDENTS][CHARNUM] = {"�谡��", "�̳���", "�ڴٴ�", "�ֶ��"};
	char studentTimes[STUDENTS][CHARNUM] = {"6��", "7�� 30��", "8�� 30��", "9��"};

	printf("���丵 �ڵ� ���� ���α׷�\n");
	printf("----------------------\n");
	printf("�޴��� �������ּ���.\n");
	printf("1. ���� �޽��� ���\n");
	printf("2. ���� ���� ��Ȳ\n");
	printf("3. �ܾ� ����\n");
	printf("4. ���α׷� ����\n");
	printf("----------------------\n");

	while (1) {
		int choiceA = -1;
		scanf_s("%d", &choiceA);

		switch (choiceA) {

		case 1:
			// ���� �޽��� ���
			if (getPassword() == 1) {
				return 0;
			}
			else {
				int numName = -1;

				printf("���� �޽��� ��� ���α׷��Դϴ�!\n");
				printf("1: %s 2: %s 3: %s 4: %s\n",
					studentNames[0], studentNames[1], studentNames[2], studentNames[3]);
				printf("��Ƽ�� �̸��� �������ּ��� : ");
				scanf_s("%d", &numName);

				getMessage(numName);
			}
			break;

		case 2:
			// ���� ���� ��Ȳ ���
			if (getPassword() == 1) {
				return 0;
			}
			else {
				printf("���� ���� ��Ȳ ��� ���α׷��Դϴ�!\n");
				getNow();
			}
			break;

		case 3:
			// �ܾ� ����
			printf("�ܾ� ���� ���α׷��Դϴ�!\n");
			testVocabulary();
			break;

		case 4:
			// ����
			terminate = 1;
			break;

		default: // ����ڰ� 1~4�� �ƴ� �ٸ� ���� �Է��� ���
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.");
			break;
		}

		printf("\n");
		printf("----------------------\n");
		printf("�޴��� �������ּ���.\n");
		printf("1. ���� �޽��� ���\n");
		printf("2. ���� ���� ��Ȳ\n");
		printf("3. �ܾ� ����\n");
		printf("4. ���α׷� ����\n");
		printf("----------------------\n");
	}
	return 0;
}

void getMessage(int numName) {
	int situation;
	char studentNames[STUDENTS][CHARNUM] = { "�谡��", "�̳���", "�ڴٴ�", "�ֶ��" };
	char studentTimes[STUDENTS][CHARNUM] = { "6��", "7�� 30��", "8�� 30��", "9��" };

	printf("��Ȳ�� �������ּ���.\n");
	printf("1. ���� ���� ��\n");
	printf("2. ��Ƽ�� ����\n");
	printf("3. ���� ��\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		printf("%s ��Ƽ��, ��� �� ���� %s�� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n",
			studentNames[numName - 1], studentTimes[numName - 1]);
	}
	else if (situation == 2) {
		printf("%s ��Ƽ��, ���� ���� �� 10���� ����Ǿ����ϴ�. ���� ������ ������� �������?\n",
			studentNames[numName - 1]);
	}
	else if (situation == 3) {
		printf("%s ��Ƽ��, ���� ������ �����ϼ̽��ϴ�! ���� ���� �ð��� �ٽ� ���� :)\n",
			studentNames[numName - 1]);
	}
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