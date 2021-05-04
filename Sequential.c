#include <stdio.h>
#include <stdlib.h>

const int RECORD_COUNT = 5;
const char *FILENAME = "students";

const char *STUDENT_FORMAT_IN = " %[^,], %lli";   

const char *FILE_READ_FORMAT = " Name: %[^,], PRN: %lli";
const char *FILE_WRITE_FORMAT = "Name: %s, PRN: %lli\n";


typedef struct {
    char name[20];
    long long int prn;
} Student;

void search();

int main(void) {
	int i;

    FILE *out = fopen(FILENAME, "w");

    if (out == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < RECORD_COUNT; ++i) {

        Student st;
        printf("Enter record: ");
        scanf(STUDENT_FORMAT_IN, &st.name, &st.prn);

        fprintf(out, FILE_WRITE_FORMAT, st.name, st.prn);
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

    FILE *in = fopen(FILENAME, "r");

    if (in == NULL) {
        exit(EXIT_FAILURE);
    }

    Student st;
    while (fscanf(in, FILE_READ_FORMAT, &st.name, &st.prn) != EOF) {

        if (prn == st.prn) {
            printf("Match has been found!\n");
            printf(FILE_WRITE_FORMAT, st.name, st.prn);
            fclose(in);
            return;
        }
    }

    fclose(in);
    printf("Match not found!\n");
}

