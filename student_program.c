#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    int marks[3];
    long ph_no;
    char address[100];
    int total;
    double percentage;
} student;


int main(int argc ,char** argv) {
    int n;
    int class_total = 0; 
    double class_average; 
    scanf("%d",&n);
    student s[n];
    printf("please enter your id\nname\nmaths\nscience\nenglish\nph_no\naddress\nin order\n");
    for(int i=0;i<n;i++){
        printf("give the student info\n");
        scanf("%d %s %d %d %d %ld %s", &s[i].id, s[i].name, &s[i].marks[0], &s[i].marks[1], &s[i].marks[2], &s[i].ph_no, s[i].address);
        s[i].total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2];
        s[i].percentage = s[i].total / 3.0;
        class_total += s[i].total;
    }
    class_average = class_total / ( 3.0 * n );
    for(int i=0;i<n;i++){
        printf("id: %d\nname: %s\nmaths: %d\nscience: %d\nenglis: %d\nph_no: %ld\naddress: %s\n", s[i].id, s[i].name, s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].ph_no, s[i].address);
    }
    printf("class_average: %lf\n", class_average);
    return 0;
}


/*
 * please enter your id
 * name
 * maths
 * science
 * english
 * ph_no
 * address
 * in order
 * give the student info
 * 1
 * shanks
 * 10
 * 20
 * 30
 * 12345
 * home
 * id: 1
 * name: shanks
 * maths: 10
 * science: 20
 * englis: 30
 * ph_no: 12345
 * address: home
 * class_average: 20.000000
 */
