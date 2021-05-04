#include <stdio.h>
#include <stdlib.h>

#define PRN_COUNT 80
const int RECORD_COUNT = 5;

const char *FILENAME = "students";
const char *STUDENT_FORMAT_OUT = "Name: %s, PRN: %lli\n";
int INDEX[PRN_COUNT];

typedef struct {
    char name[20];
    long long int prn;
} Student;

const int SIZE_OF_STUDENT = sizeof (Student);
int FILE_POINTER = 0;

void search();
void initIndex() {
	int i; 
    for (i = 0; i < PRN_COUNT; ++i) {
        INDEX[i] = -1;
    }
}

int main(void) {
int i;
    initIndex();

    FILE *out;
    out = fopen(FILENAME, "w");

    if (out == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < RECORD_COUNT; ++i) {

        Student st;

        printf("Enter record: ");
        scanf("%s %lli", &st.name, &st.prn);

        int key = st.prn % 100;

        if (INDEX[key] == -1) {

            INDEX[key] = FILE_POINTER;
            fwrite(&st, SIZE_OF_STUDENT, 1, out);
            FILE_POINTER += SIZE_OF_STUDENT;
        }
        else {
            printf("The key already exists!\n");
        }
    }

    fclose(out);
    printf("\nTesting search record functionality.\n");
    search();
    search();
    search();

    return 0;
}

void search() {
    
    long long int prn;

    printf("Enter PRN: ");
    scanf("%lli", &prn);

    int key = prn % 100;

    int position = INDEX[key];

    if (position == -1) {
        printf("The record does not exist!\n");
    }
    else {

        FILE *in = fopen(FILENAME, "r");
        if (in == NULL) {
            exit(EXIT_FAILURE);
        }

        Student st;

        fseek(in, position, SEEK_SET);
        fread(&st, SIZE_OF_STUDENT, 1, in);
        fclose(in);
        
        printf(STUDENT_FORMAT_OUT, st.name, st.prn);
    }
}
