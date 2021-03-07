#include <stdio.h>
#include "Person.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
char* rand_string(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyz";
    static char charset1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString = "";
    if(length){
        randomString = malloc(length +1);

        if(randomString){
            int l = (int)(sizeof(charset) -1);
            int key = rand() % (int)(sizeof(charset) -2);
            randomString[0] = charset1[key];
            for (int n = 1; n < length; ++n) {
                key = rand() % l;
                randomString[n] = charset[key];
            }
        randomString[length] = '\0';
        }
    }
    return randomString;
}

char* mail(size_t length){
    static char charset[] = "abcdefghijklmnopqrstuvwxyz";
    static char charset1[] = "@yahoo.com";
    char *randomString = malloc(length +1);

    if(randomString){
        int l = (int)(sizeof(charset) -1);
        int key;
        for (int n = 0; n < length-11; ++n) {
            key = rand() % l;
            randomString[n] = charset[key];
        }
        for (int n = length-11, i = 0; n < length; ++n, ++i) {
            randomString[n] = charset1[i];
        }
    randomString[length] = '\0';
    }

    return randomString;
}


char* phone(){
    static char charset[] = "0123456789";
    char *randomString = malloc(11);
    int key;
    if(randomString){
        int l = (int)(sizeof(charset) - 1);
        randomString[0] = '0';
        for (int n = 1; n < 10; ++n) {
            key = rand() % l;
            randomString[n] = charset[key];
        }
    randomString[10] = '\0';
    }
    return randomString;
}


int randRange(int low, int high){
    while(1){
        int rand_result = rand();
        if(rand_result >= low && rand_result <= high)  return rand_result;
    }
}

int main(){
    struct PersonTmpl p;
    srand(time(NULL));
    char line[255], input[100];
    FILE *fc = fopen("testc.ini", "r");
    while(fgets(line, sizeof(line), fc) != NULL){
        if ( strstr(line, "in=" ) ) { sscanf(line, "in=%s", input); break;} //numele fisierului de input
    }
    FILE* fp = fopen(input ,"wb");

    int i = 100; //numar inregistrari

    while(i--){
        int n = rand()%3 + 1; //numar inregistrare
        switch(n){
            case REC_TYPE_PERSONAL:
                #define pdp p.Details.PersonalInfo
                p.chRecordType = REC_TYPE_PERSONAL;
                p.nPersonID = rand()%10000;
                sprintf(pdp.sFirstName, rand_string(randRange(1, 30)));
                sprintf(pdp.sLastName, rand_string(randRange(1, 30)));

                int mm = randRange(1, 12), d = randRange(1, 30);
                if(mm < 10 && d < 10) sprintf(pdp.sBirthdate, "%d/%.2d/%.2d", randRange(1900, 2021), mm, d);
                else if(mm > 10 && d > 10) sprintf(pdp.sBirthdate, "%d/%d/%d", randRange(1900, 2021), mm, d);
                else if(mm < 10 && d > 10) sprintf(pdp.sBirthdate, "%d/%.2d/%d", randRange(1900, 2021), mm, d);
                else if(mm > 10 && d < 10) sprintf(pdp.sBirthdate, "%d/%d/%.2d", randRange(1900, 2021), mm, d);

                pdp.theGender = rand()%2 + 1;
                fwrite(&p, sizeof(p), 1, fp);
                break;
            case REC_TYPE_HOME:
                #define pdh p.Details.HomeDetails
                p.chRecordType = REC_TYPE_HOME;
                p.nPersonID = rand()%10000;
                sprintf(pdh.homeAddress.sStreet, rand_string(randRange(1, 50)));
                sprintf(pdh.homeAddress.sCity, rand_string(randRange(1, 50)));
                sprintf(pdh.homeAddress.sCountry, rand_string(randRange(1, 50)));
                sprintf(pdh.sPhone, phone());
                sprintf(pdh.sEmail, mail(randRange(12, 30)));

                fwrite(&p, sizeof(p), 1, fp);
                break;
            case REC_TYPE_WORK:
                #define pdw p.Details.WorkDetails
                p.chRecordType = REC_TYPE_WORK;
                p.nPersonID = rand()%10000;
                sprintf(pdw.sCompany, rand_string(randRange(1, 30)));
                sprintf(pdw.workAddress.sStreet, rand_string(randRange(1, 50)));
                sprintf(pdw.workAddress.sCity, rand_string(randRange(1, 50)));
                sprintf(pdw.workAddress.sCountry, rand_string(randRange(1, 50)));
                sprintf(pdw.sPhone, phone());
                sprintf(pdw.sFax, phone());
                sprintf(pdw.sEmail, mail(randRange(12, 30)));

                fwrite(&p, sizeof(p), 1, fp);
                break;
        }
    }
    fclose(fp);
    return 0;
}
*/
