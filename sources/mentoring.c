#include <stdio.h>
#include <string.h>


char password[10];

int getPassword();

int main() {
	int terminate = 0;
	int tryCount = 0;

	

	while (1) {
		int choice = -1;
		scanf_s("%d", &choice);

		switch (choice) {

		case 1:
			if (getPassword() == 1) {
				printf("��й�ȣ 3ȸ �̻� ����. ���α׷��� �����մϴ�.\n");
				return 0;
			}
			else {
				// 1�� ��� ����
				printf("�л��� �̸��� �Է����ּ���. ");
				printf("��� �� ���� 6�ÿ� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
				printf("��� �� ���� 7�� 30�п� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
				printf("��� �� ���� 8�� 30�п� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
				printf("��� �� ���� 9�ÿ� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
			}
			break;


		case 2:
			if (getPassword() == 1) {
				terminate = 1; // ��й�ȣ 3ȸ �̻� ���� �� ���α׷� ����
			}
			else {
				// 2�� ��� ����
				printf("2�� ����� �����մϴ�.\n");
			}
			break;

		case 3:
			if (getPassword() == 1) {
				terminate = 1; // ��й�ȣ 3ȸ �̻� ���� �� ���α׷� ����
			}
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
				printf("3ȸ �̻� Ʋ�Ƚ��ϴ�!\n");
				return 1;
			}

			// �Է� ���� ����
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}
