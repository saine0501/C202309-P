#include <stdio.h>
#include <string.h>

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