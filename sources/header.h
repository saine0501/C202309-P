struct StudentInfo {
	char* name;
	char* time;
};

void inputStudentInfo(struct StudentInfo* students, int numStudents);

void inputTimeInfo(struct StudentInfo* students, int numStudents);

void freeStudentInfo(struct StudentInfo* students, int numStudents);

int getPassword();

void getMessage(struct StudentInfo* students, int numName);

void getNow(struct StudentInfo* students, int numStudents);

void testVocabulary();

void stopWatch();