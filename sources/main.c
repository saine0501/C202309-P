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
	char studentNames[STUDENTS][CHARNUM] = {"�谡��", "�̳���", "�ڴٴ�", "�ֶ��"};
	char studentTimes[STUDENTS][CHARNUM] = {"6��", "7�� 30��", "8�� 30��", "9��"};

	printf("���丵 �ڵ� ���� ���α׷�\n");
	printf("----------------------\n");
	printf("�޴��� �������ּ���.\n");
	printf("1. ���� �޽��� ���\n");
	printf("2. ���� ���� ��Ȳ\n");
	printf("3. �ܾ���\n");
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
				getNow();
			}
			break;

		case 3:
			// �ܾ���

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
		printf("3. �ܾ���\n");
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

void getNow() {
	FILE* fp;
	fopen_s(&fp, "./mentoring.txt", "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
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

	// ���Ͽ��� �� �پ� �о����
	while (fgets(line, MAX, fp) != NULL) {
		// "0��"�̶�� ���ڿ��� ���ԵǾ� �ִ��� Ȯ��
		if (strstr(line, "0��") != NULL) {
			zeroCount++;
		}

		// "45��"�̶�� ���ڿ��� ���ԵǾ� �ִ��� Ȯ��
		if (strstr(line, "45��") != NULL) {
			fortyFiveCount++;
		}

		if (strstr(line, "�谡��") != NULL) {
			one++;
		}

		if (strstr(line, "�̳���") != NULL) {
			two++;
		}

		if (strstr(line, "�ڴٴ�") != NULL) {
			three++;
		}

		if (strstr(line, "�ֶ��") != NULL) {
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

	// ���� �ݱ�
	fclose(fp);

	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	// ��� ���
	printf("�谡�� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", one, 20-one);
	printf("�谡�� ��Ƽ�� �Ἦ Ƚ�� : %d\n", oneNo);
	printf("�̳��� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", two, 20 - two);
	printf("�̳��� ��Ƽ�� �Ἦ Ƚ�� : %d\n", twoNo);
	printf("�ڴٴ� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", three, 20 - three);
	printf("�ڴٴ� ��Ƽ�� �Ἦ Ƚ�� : %d\n", threeNo);
	printf("�ֶ�� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", four, 20 - four);
	printf("�ֶ�� ��Ƽ�� �Ἦ Ƚ�� : %d\n", fourNo);
	printf("�� �޿� : %d��\n", money);
}
