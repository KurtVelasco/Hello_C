#include <stdio.h>


char operatorName[20];
double opAttackInterval;
int totalASPDBuff;
int finalASPD;


void GetOperatorName(){
    printf("Input the name of your Operatior [20]: ");
        fgets(operatorName,sizeof(operatorName),stdin);
        //printf("%d", strlen(operatorName));
        if (operatorName[strlen(operatorName) - 1] != '\n') {
            //apparently the excess char is still in the  the input buffer and we need to clear iitt
            int c;
            while((c = getchar()) != '\n');
            printf("\nError: Input exceeds the maximum allowed length.\n");
            GetOperatorName();
        }

        //Ok I already hae this fcking /n at the end ff(getsss)
        if (strlen(operatorName) > 0 && operatorName[strlen(operatorName) - 1] == '\n') {
            operatorName[strlen(operatorName) - 1] = '\0';
        }
}
void GetAttackInterval(){
    printf("Input Operator Attack Interval: ");
    if (scanf("%lf", &opAttackInterval) == 1) {
        printf("%s's Attack Interval: %.2lf\n", operatorName, opAttackInterval);
    } else {
        printf("Not a valid numeric input.\n");
        while (getchar() != '\n'); // Clear the input buffer
        GetAttackInterval();
    }
    
    GetASPD();
}
void GetASPD(){
        printf("Input ASPD Buffs: ");
    if (scanf("%d", &totalASPDBuff) == 1) {
        printf("%s's Total ASPD Buff : %d\n",operatorName,totalASPDBuff);
    } else {
        printf("Not a valid integer input.\n");
        while (getchar() != '\n'); // Again we need to clear the input buffer
                                    // get segmentation fault again FUCK
        GetASPD();
    }
    calculateASPD(opAttackInterval,totalASPDBuff);
}

int calculateASPD(double interval, int buff){
    double result;
    double finalResult;
    result = (100.0 + buff) / (interval + 0.7) / 100.0;
    finalResult = 1/result;
    printf("Result: %.2f\n", finalResult);   
}
int main(){
    GetOperatorName();
    GetAttackInterval();
    printf("My name is %s\n", operatorName);
    printf("Interval %d ASPD Buff %d",opAttackInterval,totalASPDBuff);
    return 0;
}
