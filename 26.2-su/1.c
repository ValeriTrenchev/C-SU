#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    printf("what exersice (1-16) would you like to try?: ");
    scanf(" %d", &choice);

    switch(choice){
        case 1:{
            printf("\n-------zadacha. 1--------\n");

            for (int a = 0; a<=10; a++) {
                printf(" %d\n",a);
            }
            break;
        }
        case 2:{
            printf("\n-------zadacha. 2--------\n");

            for (int i=0; i<=10; i++) {
                for(int j = 1; j<i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        }
        case 3:{
            printf("\n-------zadacha. 3--------\n");

            char symbol;

            printf("input symbol for frame: ");
            scanf(" %c", &symbol);

            for( int i = 0; i < 5; i++) {
                for(int j = 0; j <10; j++) {
                    if (i==0 || i==4 || j==0 || j==9) {
                        printf(" %c", symbol);
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        }
        case 4:{
            printf("\n-------zadacha. 4--------\n");

            char c;
            int size =5;

            printf("input symbol for triangle: ");
            scanf(" %c", &c);

            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size - i; j++) {
                    printf(" ");
                }

                if (i == 1) {
                    printf("%c\n", c);
                } else if (i == size) {
                    printf("%c", c);
                    for (int j = 1; j < size; j++) {
                        printf(" %c", c);
                    }
                    printf("\n");
                } else {
                    printf("%c", c);
                    for (int j = 1; j <= 2 * i - 3; j++) {
                        printf(" ");
                    }
                    printf("%c\n", c);
                }
            }
            printf("\n");

            for (int i = size; i >= 1; i--) {
                for (int j = 1; j <= size - i; j++) {
                    printf(" ");
                }

                if (i == 1) {
                printf("%c\n", c);
            } else if (i == size) {
                printf("%c", c);
                for (int j = 1; j < size; j++) {
                    printf(" %c", c);
                }
                    printf("\n");
                } else {
                    printf("%c", c);
                    for (int j = 1; j <= 2 * i - 3; j++) {
                        printf(" ");
                    }
                    printf("%c\n", c);
                }
            }
            }
            break;

        case 5:{
            printf("\n-------zadacha. 5--------\n");

            float inches;

            printf("input length in inches: ");

            scanf(" %f", &inches);

            float cm = inches * 2.54;

            float mm = cm * 10.0;
            float dm = cm / 10.0;
            float m = cm / 100.0;

            printf("result in %.2f inches\n", inches);
            printf("----------\n");
            printf("result in (mm) %.2f\n", mm);
            printf("result in (cm) %.2f\n", cm);
            printf("result in (dm) %.2f\n", dm);
            printf("result in (m) %.4f\n", m);
            break;
        }
        case 6:{
            printf("\n-------zadacha. 6--------\n");

            float cel, fahr;

            printf("input celsius: ");
            scanf(" %f", &cel);

            fahr = (cel * 9.0 / 5.0) + 32.0;

            printf("%.2f celsius is equal to %.2f fahrenheit\n", cel, fahr);
            break;
        }
        case 7:{
            printf("\n-------zadacha. 7--------\n");

            float deg, rad;

            const float PI= 3.14159265;

            printf("input degree: ");
            scanf(" %f", &deg);

            rad = deg * (PI/180.0);

            printf("%.2f degrees are equal to %.4f radians\n", deg, rad);
            break;
        }
        case 8:{
            printf("\n-------zadacha. 8--------\n");

            float bgn;

            const float rate_usd = 1.80;
            const float rate_eur = 1.95583;
            const float rate_gbp = 2.25;

            printf("BGN: ");
            scanf(" %f", &bgn);

            float usd = bgn / rate_usd;
            float eur = bgn / rate_eur;
            float gbp = bgn / rate_gbp;


            printf("bgn %.2f\n", bgn);
            printf("usd %.2f\n", usd);
            printf("eur %.2f\n", eur);
            printf("gbp %.2f\n", gbp);
            break;
        }
        case 9:{
            printf("\n-------zadacha. 9--------\n");

            float a, b, h, area;

            printf("input a: ");
            scanf(" %f", &a);

            printf("input b: ");
            scanf(" %f", &b);

            printf("input h: ");
            scanf(" %f", &h);

            area = (a + b) * h / 2.0;
            printf("\nArea is: %.2f\n", area);
            break;
        }
        case 10:{
            printf("\n-------zadacha. 10--------\n");

            double degrees, radians;

            const double PI_2 =3.14159265359;

            printf("input degree: ");
            scanf(" %lf", &degrees);

            radians = degrees * (PI_2 / 180.0);

            double sin_val = sin(radians);
            double cos_val = cos(radians);
            double tan_val = tan(radians);
            double cot_val = 1.0 / tan_val;

            printf("\nResult in %.2f degrees:\n", degrees);
            printf("sin: %.4f\n", sin_val);
            printf("cos: %.4f\n", cos_val);
            printf("tan: %.4f\n", tan_val);
            printf("cot: %.4f\n", cot_val);
            break;
        }
        case 11:{
            printf("\n-------zadacha. 11--------\n");

            float x1, y1, x2, y2;

            printf("input coordinates for A - x1, y1: ");
            scanf(" %f %f", &x1, &y1);

            printf("input coordinates for B - x2, y2: ");
            scanf(" %f %f", &x2, &y2);

            float width = fabs(x1 - x2);
            float height = fabs(y1-y2);

            float area2 = width * height;

            printf("area is: %.2f\n", area2);
            break;
        }
        case 12:{
            printf("\n-------zadacha. 12--------\n");

            float X1, Y1, X2, Y2, X3, Y3;

            printf("input coordinates for A - x1, y1: ");
            scanf(" %f %f", &X1, &Y1);

            printf("input coordinates for B - x2, y2: ");
            scanf(" %f %f", &X2, &Y2);

            printf("input coordinates for C - x3, y3: ");
            scanf(" %f %f", &X3, &Y3);

            float calc = X1 * (Y2 - Y3) + X2 *(Y3 - Y1) + X3 * (Y1-Y2);
            float area3 = fabs(calc)/2.0;

            printf("\nArea is: %.2f\n", area3);
            break;
        }
        case 13:{
            printf("\n-------zadacha. 13--------\n");

            float l, w;

            printf("input length: ");
            scanf(" %f", &l);

            printf("input width: ");
            scanf(" %f", &w);

            int length_cm = l * 100;
            int width_cm = w * 100;

            int desks_per_row = (width_cm - 100) / 70;
            int rows = length_cm / 120;
            int total_desks = desks_per_row * rows;
            int final_seats = total_desks - 3;

            printf("\nAmount seats: %d\n", final_seats);
            break;
        }
        case 14:{
            printf("\n-------zadacha. 14--------\n");

            double veg_price, fruit_price;
            int veg_kg, fruit_kg;

            printf("input veg_price: ");
            scanf("%lf", &veg_price);
            printf("input fruit_price: ");
            scanf("%lf", &fruit_price);
            printf("input veg_kg: ");
            scanf("%d", &veg_kg);
            printf("input fruit_kg: ");
            scanf("%d", &fruit_kg);

            double veg_total_bgn = veg_price * veg_kg;
            double fruit_total_bgn = fruit_price * fruit_kg;
            double total_bgn = veg_total_bgn + fruit_total_bgn;
            double total_eur = total_bgn / 1.95;

            printf("%.2f\n", total_eur);
            break;
        }
        case 15: {
            printf("\n-------zadacha. 15--------\n");
            double N, W, L, M, O;

            printf("input n: ");
            scanf("%lf", &N);
            printf("input w: ");
            scanf("%lf", &W);
            printf("input l: ");
            scanf("%lf", &L);
            printf("input m: ");
            scanf("%lf", &M);
            printf("input o: ");
            scanf("%lf", &O);

            double playground_area = N * N;
            double bench_area = M * O;
            double tile_area = W * L;

            double area_to_cover = playground_area - bench_area;

            double tiles_needed = area_to_cover / tile_area;
            double total_time = tiles_needed * 0.2;

            printf("%.2f\n", tiles_needed);
            printf("%.2f\n", total_time);
            break;
        }
        case 16:{
            printf("\n-------zadacha. 16--------\n");

            int working_days;
            double daily_wage_usd, exchange_rate;

            printf("input working_days: ");
            scanf("%d", &working_days);
            printf("input daily_wage_usd: ");
            scanf("%lf", &daily_wage_usd);
            printf("input exchange_rate: ");
            scanf("%lf", &exchange_rate);

            double monthly_salary_usd = working_days * daily_wage_usd;
            double yearly_salary_usd = monthly_salary_usd * 12;
            double bonus_usd = monthly_salary_usd * 2.5;
            double total_gross_usd = yearly_salary_usd + bonus_usd;
            double total_net_usd = total_gross_usd * 0.75;
            double total_net_bgn = total_net_usd * exchange_rate;
            double average_daily_profit_bgn = total_net_bgn / 365.0;

            printf("%.2f\n", average_daily_profit_bgn);
            break;
        }
        default:{
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
