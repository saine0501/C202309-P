#include <stdio.h>
#include <string.h>
#define CHARNUM 20
#define STUDENTS 4

char password[10];

int getPassword();
void getMessage(int numName);

int main() {
	int terminate = 0;
	int tryCount = 0;
	char studentNames[STUDENTS][CHARNUM] = {"����", "����", "�ٴ�", "���"};
	char studentTimes[STUDENTS][CHARNUM] = {"6��", "7�� 30��", "8�� 30��", "9��"};

	printf("���丵 �ڵ� ���� ���α׷�\n");
	printf("----------------------\n");
	printf("�޴��� �������ּ���.\n");
	printf("1. ���� �޼��� ���\n");
	printf("2. ���� ���� ��Ȳ\n");
	printf("3. �ܾ���\n");
	printf("4. ���α׷� ����\n");
	printf("----------------------\n");

	while (1) {
		int choiceA = -1;
		scanf_s("%d", &choiceA);

		switch (choiceA) {

		case 1:
			if (getPassword() == 1) {
				return 0;
			}
			else {
				int numName = -1;

				printf("\n1: %s 2: %s 3: %s 4: %s\n",
					studentNames[0], studentNames[1], studentNames[2], studentNames[3]);
				printf("��Ƽ�� �̸��� �������ּ��� : ");
				scanf_s("%d", &numName);

				getMessage(numName);
			}
			break;

		case 2:
			if (getPassword() == 1) {
				return 0;
			}
			else {
				printf("���� ���� ��Ȳ ��� ��� ���� ����");
			}
			break;

		case 3:

			break;

		case 4:
			terminate = 1;
			break;

		default: // ����ڰ� 1~4�� �ƴ� �ٸ� ���� �Է��� ���
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.");
			break;
		}
	}
	return 0;
}
		
int getPassword() {
	int tryCount = 0;

	while (1) {
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("�¾ҽ��ϴ�!\n");
			return 0;
		}
		else {
			tryCount++;
			printf("Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���. ��ȸ�� %d�� ���ҽ��ϴ�.\n", 3 - tryCount);

			if (tryCount >= 3) {
				printf("��й�ȣ 3ȸ �̻� ����. ���α׷��� �����մϴ�.\n");
				return 1;
			}

			// �Է� ���� ����
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}

void getMessage(int numName) {
	int situation;
	char studentNames[STUDENTS][CHARNUM] = { "����", "����", "�ٴ�", "���" };
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