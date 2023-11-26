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
	char studentNames[STUDENTS][CHARNUM] = {"가가", "나나", "다다", "라라"};
	char studentTimes[STUDENTS][CHARNUM] = {"6시", "7시 30분", "8시 30분", "9시"};

	printf("멘토링 자동 관리 프로그램\n");
	printf("----------------------\n");
	printf("메뉴를 선택해주세요.\n");
	printf("1. 수업 메세지 출력\n");
	printf("2. 수업 진행 현황\n");
	printf("3. 단어장\n");
	printf("4. 프로그램 종료\n");
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
				printf("멘티의 이름을 선택해주세요 : ");
				scanf_s("%d", &numName);

				getMessage(numName);
			}
			break;

		case 2:
			if (getPassword() == 1) {
				return 0;
			}
			else {
				printf("수업 진행 현황 출력 기능 구현 예정");
			}
			break;

		case 3:

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
				printf("비밀번호 3회 이상 실패. 프로그램을 종료합니다.\n");
				return 1;
			}

			// 입력 버퍼 비우기
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}

void getMessage(int numName) {
	int situation;
	char studentNames[STUDENTS][CHARNUM] = { "가가", "나나", "다다", "라라" };
	char studentTimes[STUDENTS][CHARNUM] = { "6시", "7시 30분", "8시 30분", "9시" };

	printf("상황을 선택해주세요.\n");
	printf("1. 수업 시작 전\n");
	printf("2. 멘티의 지각\n");
	printf("3. 수업 끝\n");
	scanf_s("%d", &situation);

	if (situation == 1) {
		printf("%s 멘티님, 잠시 후 오후 %s에 멘토링이 진행될 예정입니다~! 교재와 함께 시간 맞춰 접속해주세요 :)\n",
			studentNames[numName - 1], studentTimes[numName - 1]);
	}
	else if (situation == 2) {
		printf("%s 멘티님, 수업 시작 후 10분이 경과되었습니다. 수업 참여에 어려움이 있을까요?\n",
			studentNames[numName - 1]);
	}
	else if (situation == 3) {
		printf("%s 멘티님, 오늘 수업도 수고하셨습니다! 다음 수업 시간에 다시 봐요 :)\n",
			studentNames[numName - 1]);
	}
}