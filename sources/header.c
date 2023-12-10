#include <stdio.h>
#include <string.h>
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
	int one = 0, two = 0, three = 0, four = 0;
	int oneNo = 0, twoNo = 0, threeNo = 0, fourNo = 0;

	while (fgets(line, MAX, fp) != NULL) {
		if (strstr(line, "0��") != NULL) {
			zeroCount++;
		}
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

	fclose(fp);
	int money = 6000 * zeroCount + 12000 * fortyFiveCount;

	printf("�谡�� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", one, 20 - one);
	printf("�谡�� ��Ƽ�� �Ἦ Ƚ�� : %d\n", oneNo);
	printf("�̳��� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", two, 20 - two);
	printf("�̳��� ��Ƽ�� �Ἦ Ƚ�� : %d\n", twoNo);
	printf("�ڴٴ� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", three, 20 - three);
	printf("�ڴٴ� ��Ƽ�� �Ἦ Ƚ�� : %d\n", threeNo);
	printf("�ֶ�� ��Ƽ�� ���� ���� ȸ�� : �� %dȸ / ���� ȸ�� : %dȸ\n", four, 20 - four);
	printf("�ֶ�� ��Ƽ�� �Ἦ Ƚ�� : %d\n", fourNo);
	printf("�� �޿� : %d��\n", money);
}