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
				printf("비밀번호 3회 이상 실패. 프로그램을 종료합니다.\n");
				return 0;
			}
			else {
				// 1번 기능 구현
				printf("학생의 이름을 입력해주세요. ");
				printf("잠시 후 오후 6시에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
				printf("잠시 후 오후 7시 30분에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
				printf("잠시 후 오후 8시 30분에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
				printf("잠시 후 오후 9시에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n");
			}
			break;


		case 2:
			if (getPassword() == 1) {
				terminate = 1; // 비밀번호 3회 이상 실패 시 프로그램 종료
			}
			else {
				// 2번 기능 구현
				printf("2번 기능을 수행합니다.\n");
			}
			break;

		case 3:
			if (getPassword() == 1) {
				terminate = 1; // 비밀번호 3회 이상 실패 시 프로그램 종료
			}
			break;


		case 4:
			terminate = 1;
			break;

		default: // 사용자가 1~4가 아닌 다른 값을 입력할 경우
			printf("잘못된 선택입니다. 다시 선택하세요.\n");

		}


		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.");
			break;
		}
	}
	return 0;
}
		

int getPassword() {
	int tryCount = 0;

	while (1) {
		printf("비밀번호를 입력하세요: ");
		scanf_s("%s", password, (int)sizeof(password));

		if (strcmp(password, "mentoring") == 0) {
			printf("맞았습니다!\n");
			return 0;
		}
		else {
			tryCount++;
			printf("틀렸습니다. 다시 입력해주세요. 기회는 %d번 남았습니다.\n", 3 - tryCount);

			if (tryCount >= 3) {
				printf("3회 이상 틀렸습니다!\n");
				return 1;
			}

			// 입력 버퍼 비우기
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}
