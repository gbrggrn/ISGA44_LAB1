#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototyper nedan
void randNmbrs(int *arr);
void sortArr(int *arr, int size);
void printArr(int *arr, int size, int row, int col);
void valArr(int *arr, int size);
void binSrch(int *arr, int size, int row, int col);
void sumsArr(int *arr, int size, int row, int col);

//Main innehåller meny-funktionen. Inser att jag kunde gjort det mer modulärt genom att placera även den i en separat funktion.
int main(){
    srand(time(NULL));
    system("chcp 1252");
    system("cls");

    int choice[6]={0}, nmbrarr[100];

    printf("Det här programmet genererar och manipulerar en slumptalsmatris!\n\n");

    while(1){

        printf("1) Generera en slumptalsmatris\n");
        printf("2) Sortera matrisen från lägst till högst\n");
        printf("3) Beräkna medelvärde/median/min- och maxvärde i matrisen\n");
        printf("4) Sök efter valfritt tal i matrisen för att se dess position\n");
        printf("5) Beräkna summan av raderna, kolumnerna och totalt\n");
        printf("6) Avsluta programmet\n\n");
        printf("Gör ett val: ");
        scanf("%i", &choice[0]);

    switch(choice[0]){
        case 1:
                choice[1]=1;
                randNmbrs(nmbrarr);
                printf("Genererad slumptalsmatris:\n");
                printArr(nmbrarr, 100, 10, 10);
                break;
        case 2:
            if(choice[1]==1){
                choice[2]=1;
                sortArr(nmbrarr, 100);
                printf("Slumptalsmatrisen har sorterats från lägst till högst:\n");
                printArr(nmbrarr, 100, 10, 10);
                }
                else{
                    system("cls");
                    printf("\n\nDu måste generera en slumptalsmatris först!\n\n");
                }
                break;
        case 3:
               if((choice[1]==1)&&(choice[2]==1)){
                    choice[3]=1;
                    system("cls");
                    printArr(nmbrarr, 100, 10, 10);
                    valArr(nmbrarr, 100);
               }
                else{
                    system("cls");
                    printf("\n\nDu måste generera en slumptalsmatris och sortera talen först!\n\n");
                }
               break;

        case 4:
                if((choice[1]==1)&&(choice[2]==1)){
                    choice[4]=1;
                    system("cls");
                    printArr(nmbrarr, 100, 10, 10);
                    binSrch(nmbrarr, 100, 10, 10);
                }
                else{
                    system("cls");
                    printf("\n\nDu måste generera en slumptalsmatris och sortera talen först!\n\n");
                 }
                break;

        case 5:
                if(choice[1]==1){
                    choice[5]=1;
                    sumsArr(nmbrarr, 100, 10, 10);
                }
                else{
                    system("cls");
                    printf("\n\nDu måste generera en slumptalsmatris först!\n\n");
                 }
                break;

        case 6:
                exit(0);
        default:
                system("cls");
                printf("Det finns bara sex stycken val!\n\n");
                break;



    }
    }
}

//Funktioner nedan

void randNmbrs(int *arr){
    system("cls");
    int i=0, used=0, nmbr=0;

        for(i=0;i<100;i++)
            arr[i]=i;
        for(i=0;i<100;i++){
            arr[nmbr]=rand()%(901);
            used=arr[i];
            arr[i]=arr[nmbr];
            arr[nmbr]=used;
            }
}

void sortArr(int *arr, int size){
    system("cls");
    int i=0, j=0, used;

    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                used=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=used;
            }
        }
    }
}

void printArr(int *arr, int size, int row, int col){
    int i=0;

    printf("\n\n");
    for(i=0;i<size;i++){
        printf("%4i", arr[i]);
        if((i+1)%col==0)
            printf("\n");
    }
    printf("\n\n");

}

void valArr(int *arr, int size){
    int i=0, sum=0;

    for(i=0;i<size;i++)
        sum+=arr[i];

    printf("Medelvärde: %d\n", sum/size);
    printf("Median: %d\n", arr[49]);
    printf("Maxvärde: %d\n", arr[99]);
    printf("Minvärde: %d\n\n", arr[0]);
}

void binSrch(int *arr, int size, int row, int col){
    int i=0, mid=0, srchNmbr;

    printf("\n\nVänligen ange ett tal du vill söka efter i matrisen: ");
    scanf("%i", &srchNmbr);

    while((size-i)>1){
        mid=(i+size)/2;
        if(srchNmbr>=arr[mid])
            i=mid;
        else
            size=mid;
    }
    if(srchNmbr==arr[i]){
        row=(i/col)+1;
        col=(i%col)+1;
        printf("\nTalet finns på rad: %i och kolumn %i\n\n", row, col);
    }
    else{
        printf("Talet finns ej\n\n");
    }
}

void sumsArr(int *arr, int size, int row, int col){
    system("cls");
    int i=0, rowsum=0, colsum[col], totsum=0;

    printf("Radsummor, kolumnsummor och totalt:");
    printf("\n\n");
    for(i=0;i<col;i++)
        colsum[i]=0;
    for(i=0;i<size;i++){
        printf("%8i", arr[i]);
        rowsum+=arr[i];
        if((i+1)%row==0){
            printf(" = %i\n", rowsum);
            //totsum+=rowsum;
            rowsum=0;
        }
            colsum[i%col]+=arr[i];
    }
    for(i=0;i<col;i++){
        printf("%8i", colsum[i]);
        totsum+=colsum[i];
    }
    printf(" = %4i", totsum);
    printf("\n\n");

}
