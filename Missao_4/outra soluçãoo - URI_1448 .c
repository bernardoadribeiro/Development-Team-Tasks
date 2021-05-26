#include <stdio.h>

void solve_this_problem(const char *original, const char *time1, const char *time2){
    int cont_time1, cont_time2, time_1_primeiro = 1, time_2_primeiro = 1, talvez_tenhamos_um_ganhador, i;
    talvez_tenhamos_um_ganhador = cont_time1 = cont_time2 = 0;
    
    for (i = 0; original[i] != '\0'; ++i) {
        if (time1[i] == original[i]){
            cont_time1++;
        }
        if (time2[i] == original[i]){
            cont_time2++;
        }
        if ((cont_time1 > cont_time2) && (!talvez_tenhamos_um_ganhador)){
            time_2_primeiro = 0;
            talvez_tenhamos_um_ganhador = 1;
        } else if ((cont_time1 < cont_time2) && (!talvez_tenhamos_um_ganhador)){
            time_1_primeiro = 0;
            talvez_tenhamos_um_ganhador = 1;
        }
    }
    
    if (cont_time1 > cont_time2){
        printf("time 1\n");
    } else if (cont_time1 < cont_time2){
        printf("time 2\n");
    } else if(time_1_primeiro && !time_2_primeiro){
        printf("time 1\n");
    } else if (!time_1_primeiro && time_2_primeiro){
        printf("time 2\n");
    }else{
        printf("empate\n");
    }
}

int main(){
    int t, i;
    char original[101], time1[101], time2[101];
    scanf("%d", &t);
    for (i = 0; i < t; ++i) {
        scanf(" %[^\n]s", original);
        scanf(" %[^\n]s", time1);
        scanf(" %[^\n]s", time2);
        if (i >= 1 && i < t){
            printf("\n");
        }
        printf("Instancia %d\n", i + 1);
        solve_this_problem(original, time1, time2);
    }
    return 0;
}
