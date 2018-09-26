#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ARRAY_SIZE 10

double mean_of_judge(int n, double judge[]){
    double sum = 0.0;
    int i;
    for(i = 0; i < n; i++){
        sum+=judge[i];
    }
    return(sum/n);
    
}

double stdeviation_judge(int n, double mean, double judge[]){
    double sum = 0.0;
    double variance, stdeviation;
    int i;
    for(i=0; i < n; i++){
        sum += (judge[i]-mean)*(judge[i]-mean);
    }
    variance = sum/(n-1);
    stdeviation = sqrt(variance);
    return stdeviation;
}

int main(void){
    int n;
    double a, b, c;
    int line = 0;
    double mean1, mean2, mean3;
    double stdev1, stdev2, stdev3;

    double judge1[ARRAY_SIZE];
    double judge2[ARRAY_SIZE];
    double judge3[ARRAY_SIZE];
    while(4 ==  scanf("%d%lg%lg%lg", &n, &a, &b, &c)){
        judge1[line] = a;
        judge2[line] = b;
        judge3[line] = c;
        line++;
    }
    mean1 = mean_of_judge(line, judge1);
    mean2 = mean_of_judge(line, judge2);
    mean3 = mean_of_judge(line, judge3);
    stdev1 = stdeviation_judge(line, mean1, judge1);
    stdev2 = stdeviation_judge(line, mean2, judge2);
    stdev3 = stdeviation_judge(line, mean3, judge3);
    printf("          Average  SD\n");
    printf("Judge 1 : %1.1f %8.1f\n", mean1, stdev1);
    printf("Judge 2 : %1.1f %8.1f\n", mean2, stdev2);
    printf("Judge 3 : %1.1f %8.1f\n", mean3, stdev3);

    
    return EXIT_SUCCESS;
}
