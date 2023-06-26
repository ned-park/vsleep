#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

const int daytos = 86400;
const int hourtos = 3600;
const int minutetos = 60;
const int stos = 1;

int print_usage(char** argv) {
    printf("%s %ds %dm %dh\n", argv[0], 37, 1, 5);
}

void print_remaining_time(int s) {
    int d = s / daytos;
    s -= d * daytos;
    int h = s / hourtos;
    s -= h * hourtos;
    int m = s / minutetos;
    s -= m * minutetos;

    printf("%d days, %02d:%02d:%02d", d,h,m,s);
}

int main(int argc, char** argv) {
    double seconds = 0;

    if (argc < 2) {
        print_usage(argv);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        const unsigned int len = strlen(argv[i]);
        char last = argv[i][len-1];
        int conversion_factor = 0;

        if (last == 'd') conversion_factor = daytos;
        else if (last == 'h') conversion_factor = hourtos;
        else if (last == 'm') conversion_factor = minutetos;
        else if (last == 's') conversion_factor = stos;
        
        if (conversion_factor && (len > 0 && argv[i][len-1] == '&')) {
            argv[i][len-1] = '\0'; 
        } 

        if (!conversion_factor && (last < '0' || last > '9' || strlen(argv[i]) < 1)) {
            print_usage(argv);
            exit(1);
        } 

        char* pEnd;
        double num = strtod(argv[i], &pEnd);
                
        if (errno != 0) {
            print_usage(argv);
            exit(1);
        }


        if (!conversion_factor) conversion_factor = 1;
        seconds += num * conversion_factor; 
    }

    while (seconds > 0) {
        printf("\33[2K\r");
        fflush(stdout);
        print_remaining_time(seconds);
        fflush(stdout);
        seconds--;
        sleep(1);
    }

    printf("\33[2K\r");
    return 0;
}
