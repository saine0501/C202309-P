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
			// 멘티에게 보낼 메세지 출력 + 멘토 기능, 비밀번호
			printf("학생의 이름을 입력해주세요. ");
			printf("잠시 후 오후 6시에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
			printf("잠시 후 오후 7시 30분에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
			printf("잠시 후 오후 8시 30분에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
			printf("잠시 후 오후 9시에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");

			break;


		case 2:
			// 입력받은 파일을 통해 멘티의 수업 차시와 급여 계산 + 멘토 기능, 비밀번호

			break;

		case 3:
			terminate = getPassword();
			break;

		case 4:
			terminate = 1;
			break;
		}

		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.");
			break;
		}
	}

	return 0;
}

int getPassword() {
	int try = 0;

	while (1) {
		printf("비밀번호를 입력하세요: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("맞았습니다!\n");
			return 0;
			break;
		}
		else {
			try++;
			printf("틀렸습니다. 다시 입력해주세요. 기회는 %d번 남았습니다.\n", 3 - try);

			if (try >= 3) {
				printf("3회 이상 틀리셨습니다!\n");
				return 1;
			}
		}
	}
}