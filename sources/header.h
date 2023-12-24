struct StudentInfo {
	char* name;
	char* time;
};

int getPassword();

void inputStudentInfo(struct StudentInfo* students, int numStudents);

void inputTimeInfo(struct StudentInfo* students, int numStudents);

void freeStudentInfo(struct StudentInfo* students, int numStudents);

void getMessage(struct StudentInfo* students, int numName);

void getNow(struct StudentInfo* students);

void testVocabulary();

void stopWatch();