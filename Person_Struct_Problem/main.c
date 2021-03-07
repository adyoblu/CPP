#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Person.h"

char* fillString(char* s, int l){
    int len = strlen(s);
    while (len < l){
        s[len++] = ' ';
    }
    s[l] = '\0';
    return s;
}
/**/

int main()
{
    FILE *fp = fopen("testc.ini", "r");
    if (fp == NULL){
        perror("Eroare la deschiderea fisierului test.ini!\n");
        return 42;
    }
    char line[255], input[100], output[100];
    int k = 0;
    while(fgets(line, sizeof(line), fp) != NULL){
        if ( strstr(line, "in=" ) ) { sscanf(line, "in=%s", input); k++;} //numele fisierului de input
        if ( strstr(line, "out=") ) { sscanf(line, "out=%s", output); k++;} //numele fisierului de output
        if ( k == 2 ) break;
    }
    fclose(fp);

    fp = fopen(input, "rb"); //fp pentru citire binara din .dat
    if (fp == NULL){
        perror("Eroare la deschiderea fisierului de input!\n");
        return 42;
    }

    struct PersonTmpl p;
    FILE *fo = fopen(output, "w"); //fo pentru scriere in .ascii

    if (fo == NULL){
        perror("Eroare la deschiderea fisierului de output!\n");
        return 42;
    }
    char str[32];
    //int yyyy, mm, d;
    while( fread(&p, sizeof(p),1, fp) ){
        //PersonId
        fprintf(fo, "%s", fillString(itoa( p.nPersonID, str, 10), 4));
        //RecordType
        fprintf(fo, "%d", p.chRecordType);

        switch(p.chRecordType){
            case REC_TYPE_PERSONAL:
                #define pdp p.Details.PersonalInfo
                // YYYY/MM/DD -> DD-MM-YYYY
                strcpy(line, pdp.sBirthdate);

                sscanf (line+8, "%d", &k);  //citeste ziua (citeste dupa YYYY/MM/
                sprintf(str, "%.2d", k);

                sscanf (line+5, "%d/", &k); //citeste luna (citeste dupa YYYY/)
                sprintf(str+2, "-%.2d", k); //lasa spatiu pentru ZZ

                sscanf (line, "%d/", &k);   //citeste anul
                sprintf(str+5, "-%.2d",k);  //lasa spatiu pentru ZZ-LL

//                sscanf(pdp.sBirthdate, "%d/%d/%d", &yyyy, &mm, &d);
//                sprintf(str, "%.2d-%.2d-%d", d, mm, yyyy);


                fprintf(fo, "%s%s%s%c\n", fillString(pdp.sLastName, 30), fillString(pdp.sFirstName, 30), str, pdp.theGender == 1? 'M' : 'F' );
                break;

            case REC_TYPE_HOME:
                #define pdh p.Details.HomeDetails
                fprintf(fo, "%s%s%s%s%s\n", fillString(pdh.homeAddress.sStreet, 30), fillString(pdh.homeAddress.sCity, 30), fillString(pdh.homeAddress.sCountry, 30), fillString(pdh.sPhone, 15), fillString(pdh.sEmail, 30));
                break;
            case REC_TYPE_WORK:
                #define pdw p.Details.WorkDetails
                fprintf(fo, "%s%s%s%s%s%s%s\n", fillString(pdw.sCompany, 30), fillString(pdw.workAddress.sStreet, 30), fillString(pdw.workAddress.sCity, 30), fillString(pdw.workAddress.sCountry, 30), fillString(pdw.sPhone, 15), fillString(pdw.sFax, 15), fillString(pdw.sEmail, 30));
                break;
        }

    }
    fclose(fp);
    fclose(fo);
    return 0;
}
/**/
