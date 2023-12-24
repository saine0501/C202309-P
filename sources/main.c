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

	// ��Ƽ���� �̸��� �谡��, �̳���, �ڴٴ�, �ֶ��
	// ���� �ð��� 18:00, 19:30, 20:30, 21:00
	struct StudentInfo* students = (struct StudentInfo*)malloc(numStudents * sizeof(struct StudentInfo));
	if (students == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	printf("���丵 �ڵ� ���� ���α׷�\n\n");
	printf("��Ƽ�� �̸��� �Է����ּ���!\n");
	inputStudentInfo(students, numStudents);

	printf("\n��Ƽ�� �����ð��� �Է����ּ���!\n");
	printf("�Է� ������ 00:00 �Դϴ�.\n");
	inputTimeInfo(students, numStudents);

	printf("----------------------\n");
	printf("�޴��� �������ּ���.\n");
	printf("1. ���� �޽��� ���\n");
	printf("2. ���� ���� ��Ȳ\n");
	printf("3. �ܾ� ����\n");
	printf("4. �����ġ\n");
	printf("5. ���α׷� ����\n");
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
					students[0].name, students[1].name, students[2].name, students[3].name);
				printf("��Ƽ�� �̸��� �������ּ��� : ");
				scanf_s("%d", &numName);

				getMessage(students, numName);
			}
			break;

		case 2:
			// ���� ���� ��Ȳ ���
			if (getPassword() == 1) {
				return 0;
			}
			else {
				printf("���� ���� ��Ȳ ��� ���α׷��Դϴ�!\n");
				getNow(students);
			}
			break;

		case 3:
			// �ܾ� ����
			printf("�ܾ� ���� ���α׷��Դϴ�!\n");
			testVocabulary();
			break;

		case 4:
			// �����ġ ���α׷�
			printf("�����ġ ���α׷��Դϴ�!\n\n");
			stopWatch();
			break;

		case 5:
			// ����
			terminate = 1;
			break;

		default: // ����ڰ� 1~5�� �ƴ� �ٸ� ���� �Է��� ���
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.");
			freeStudentInfo(students, numStudents);
			break;
		}

		// ���� ���� ������ �޴� ���� ��� �ݺ� ���
		printf("\n");
		printf("----------------------\n");
		printf("�޴��� �������ּ���.\n");
		printf("1. ���� �޽��� ���\n");
		printf("2. ���� ���� ��Ȳ\n");
		printf("3. �ܾ� ����\n");
		printf("4. �����ġ\n");
		printf("5. ���α׷� ����\n");
		printf("----------------------\n");
	}
	return 0;
}
