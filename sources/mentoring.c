#include <stdio.h>
#include <string.h>

int choice = -1;
char password[10];

int getPassword();

int main() {
	int terminate = 0;
	int try = 0;

	scanf_s("%d", &choice);

	while (1) {
		switch (choice) {
		case 1:
			// ��Ƽ���� ���� �޼��� ��� + ���� ���, ��й�ȣ
			printf("�л��� �̸��� �Է����ּ���. ");
			printf("��� �� ���� 6�ÿ� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
			printf("��� �� ���� 7�� 30�п� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
			printf("��� �� ���� 8�� 30�п� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");
			printf("��� �� ���� 9�ÿ� ���丵�� ����� �����Դϴ�~! ����� �Բ� �ð� ���� �������ּ��� :)\n");

			break;


		case 2:
			// �Է¹��� ������ ���� ��Ƽ�� ���� ���ÿ� �޿� ��� + ���� ���, ��й�ȣ

			break;

		case 3:
			terminate = getPassword();
			break;

		case 4:
			terminate = 1;
			break;
		}

		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.");
			break;
		}
	}

	return 0;
}

int getPassword() {
	int try = 0;

	while (1) {
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("�¾ҽ��ϴ�!\n");
			return 0;
			break;
		}
		else {
			try++;
			printf("Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���. ��ȸ�� %d�� ���ҽ��ϴ�.\n", 3 - try);

			if (try >= 3) {
				printf("3ȸ �̻� Ʋ���̽��ϴ�!\n");
				return 1;
			}
		}
	}
}