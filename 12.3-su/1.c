#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(){
    int choice;
    printf("what exersice (1-12) would you like to try?: ");
    scanf(" %d", &choice);

    switch(choice){
        case 1:{
            printf("\n-------zadacha. 1--------\n");

            int get_max(int a, int b){
                return (a > b) ? a : b;
            }
            int get_min(int a, int b){
                return (a < b) ? a : b;
            }
            int num;
            int max_val = INT_MIN;
            int min_val = INT_MAX;
            int count = 0;

            printf("input number until 0:\n");

            while (1) {
                printf("Number: ");
                scanf(" %d", &num);
                if (num == 0){
                    break;
            }
            max_val = get_max(max_val, num);
            min_val = get_min(min_val, num);
            count++;
            }
            if (count > 0) {
                printf("biggest num: %d\n", max_val);
                printf("smallest num: %d\n", min_val);
            } else {
                printf("you haven't input numbers\n");
            }
            break;
        }
        case 2:{
            printf("\n-------zadacha. 2--------\n");

            int hours, minutes;

            printf("input hours and minutes (with intervals): ");
            scanf(" %d %d", &hours, &minutes);

            minutes += 15;

            if (minutes >= 60) {
                minutes -= 60;
                hours += 1;
            }
            if (hours > 24) {
                hours = 0;
            }
            printf("time after 15 minutes: %d:%02d\n", hours, minutes);
            break;
        }
        case 3: {
            printf("\n-------zadacha. 3--------\n");

            int num1, num2, num3;

            printf("input 3 numbers (intervals): ");
            scanf(" %d %d %d", &num1, &num2, &num3);

            if (num1 == num2 && num2 == num3) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
            break;
        }
        case 4: {
            printf("\n-------zadacha. 4--------\n");

            int score;
            double bonus = 0.0;

            printf("input a score: ");
            scanf(" %d", &score);

            if (score <= 100){
                bonus = 5.0;
            } else if (score >100) {
                bonus = score * 0.10;
            } else {
                bonus = score * 0.20;
            }
            if (score %2 == 0) {
                bonus += 1.0;
            } else if (score % 10 == 5) {
                bonus += 2.0;
            }
            printf("bonus poits: %g\n", bonus);
            printf("total points: %g", score + bonus);
            break;
        }
        case 5: {
            printf("\n-------zadacha. 5--------\n");

            int time1, time2, time3;

            printf("input the times of the 3 runners: ");
            scanf(" %d %d %d", &time1, &time2, &time3);

            int total_seconds = time1 + time2 + time3;

            int minutes = total_seconds / 60;
            int seconds = total_seconds % 60;

            printf("%d:%02d\n", minutes, seconds);
            break;
        }
        case 6: {
            printf("\n-------zadacha. 6--------\n");

            double x1, y1, x2, y2, x, y;

            printf("input x1, y1, x2, y2, x, y: \n");
            scanf(" %lf", &x1);
            scanf(" %lf", &y1);
            scanf(" %lf", &x2);
            scanf(" %lf", &y2);
            scanf(" %lf", &x);
            scanf(" %lf", &y);

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
                printf("Inside\n");
            } else {
                printf("Outside");
            }
            break;
        }
        case 7: {
            printf("\n-------zadacha. 7--------\n");

            int n;
            char time;
            double min_price = 0.0;

            printf("input distance and time you want to travel (D - day, N - night): ");
            scanf(" %d %c", &n, &time);

            double taxi_price = 0.70;
            if (time == 'D' || time == 'd') {
                taxi_price += n * 0.79;
            } else if (time == 'N' || time == 'n') {
                taxi_price += n * 0.90;
            }
            min_price = taxi_price;

            if (n >= 20) {
                double bus_price = n * 0.09;
                if (bus_price< min_price) {
                    min_price = bus_price;
                }
            }
            if (n >= 100) {
                double train_price = n * 0.06;
                if (train_price < min_price) {
                    min_price = train_price;
                }
            }
            printf("%.2f\n", min_price);
            break;
        }
        case 8: {
            printf("\n-------zadacha. 8--------\n");

            double v_cubes, p1, p2, hours;

            printf("input volume, pipe 1 debit, pipe 2 debit and hours: ");
            scanf(" %lf %lf %lf %lf", &v_cubes, &p1, &p2, &hours);

            double v_liters = v_cubes * 1000.0;

            double water_p1 = p1 * hours;
            double water_p2 = p2 * hours;
            double total_water = water_p1 + water_p2;

            if (total_water <= v_liters) {
                int percent_full = (int)((total_water / v_liters) * 100);
                int percent_p1 = (int)((water_p1 / total_water) * 100);
                int percent_p2 = (int)((water_p2 / total_water) * 100);

                printf("pool is %d%% full. pipe 1: %d%%. pipe 2: %d%%.\n", percent_full, percent_p1, percent_p2);
            } else {
                double overflows = total_water - v_liters;
                printf("for %.2f hours, the pool overflowed with %.2f liters\n", hours, overflows);
            }
            break;
        }
        case 9: {
            printf("\n-------zadacha. 9--------\n");

            int area, needed_wine, workers;
            double grapes_per_sqm;

            printf("input: area, grapes, needed wine and workers");
            scanf(" %d %lf %d %d", &area, &grapes_per_sqm, &needed_wine, & workers);

            double total_grapes = area * grapes_per_sqm;

            double grapes_for_wine = total_grapes * 0.40;

            double produced_wine = grapes_for_wine / 2.5;

            if (produced_wine >= needed_wine) {
                int wine_floor = (int)floor(produced_wine);

                double left_wine = produced_wine - needed_wine;
                int left_ceil = (int)ceil(left_wine);

                int wine_per_worker = (int)ceil(left_wine/workers);

                printf("produced wine: %d liters\n", wine_floor);
                printf("leftover wine: %d. for workers: %d\n", left_ceil, wine_per_worker);
            } else {
                double missing_wine = needed_wine - produced_wine;
                int missing_floor = (int)floor(missing_wine);

                printf("wine missing: %d\n", missing_floor);
            }
            break;
        }
        case 10: {
            int n;
            printf("input n: ");
            scanf("%d", &n);

            int count_p1 = 0;
            int count_p2 = 0;
            int count_p3 = 0;
            int count_p4 = 0;
            int count_p5 = 0;

            for (int i = 0; i < n; i++) {
                int current_number;
                printf("input number between 1 and 1000: ");
                scanf(" %d", &current_number);

                if (current_number < 200) {
                    count_p1++;
                } else if (current_number >= 200 && current_number <= 399) {
                    count_p2++;
                } else if (current_number >= 400 && current_number <= 599) {
                    count_p3++;
                } else if (current_number >= 600 && current_number <= 799) {
                    count_p4++;
                } else if (current_number >= 800) {
                    count_p5++;
                }
            }
            double p1 = (double)count_p1 / n * 100;
            double p2 = (double)count_p2 / n * 100;
            double p3 = (double)count_p3 / n * 100;
            double p4 = (double)count_p4 / n * 100;
            double p5 = (double)count_p5 / n * 100;

            printf("%.2f%%\n", p1);
            printf("%.2f%%\n", p2);
            printf("%.2f%%\n", p3);
            printf("%.2f%%\n", p4);
            printf("%.2f%%\n", p5);
            break;
        }
        case 11: {
            int n;
            printf("input size of castle: ");
            scanf(" %d", &n);

            int colSize = n / 2;
            int midSize = 2 * n - 2 * colSize - 4;

            printf("/");
            for (int j = 0; j < colSize; j++) printf("^");
            printf("\\");
            for (int j = 0; j < midSize; j++) printf("_");
            printf("/");
            for (int j = 0; j < colSize; j++) printf("^");
            printf("\\\n");

            for (int i = 1; i <= n - 2; i++) {
                if (i == n - 2) {
                    printf("|");
                    for (int j = 0; j < colSize + 1; j++) printf(" ");
                    for (int j = 0; j < midSize; j++) printf("_");
                    for (int j = 0; j < colSize + 1; j++) printf(" ");
                    printf("|\n");
                }
                else {
                    printf("|");
                    for (int j = 0; j < 2 * n - 2; j++) printf(" ");
                    printf("|\n");
                }
            }
            printf("\\");
            for (int j = 0; j < colSize; j++) printf("_");
            printf("/");
            for (int j = 0; j < midSize; j++) printf(" ");
            printf("\\");
            for (int j = 0; j < colSize; j++) printf("_");
            printf("/\n");
            break;
        }
        case 12: {
            int n;
            printf("input size of butterfly: ");
            scanf("%d", &n);
            int halfRowSize = n - 2;

            for (int i = 1; i <= n - 2; i++) {
                char symbol;
                if (i % 2 != 0) {
                    symbol = '*';
                } else {
                    symbol = '-';
                }

                for (int j = 0; j < halfRowSize; j++) printf("%c", symbol);
                printf("\\ /");

                for (int j = 0; j < halfRowSize; j++) printf("%c", symbol);
                printf("\n");
            }
            for (int j = 0; j < n - 1; j++) printf(" ");
            printf("@\n");

            for (int i = 1; i <= n - 2; i++) {
                char symbol;
                if (i % 2 != 0) {
                    symbol = '*';
                } else {
                    symbol = '-';
                }

                for (int j = 0; j < halfRowSize; j++) printf("%c", symbol);
                printf("/ \\");

                for (int j = 0; j < halfRowSize; j++) printf("%c", symbol);
                printf("\n");
            }
            break;
        }
        default:{
            printf("Invalid choice.\n");
            break;
        }









































    }
    return 0;
}








