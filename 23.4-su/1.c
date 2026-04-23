#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//task 2
typedef struct {
    char name[50];
    double price;
    int id;
    int is_sold;
} Product;
typedef struct {
    char address[100];
    int product_id;
    int is_fulfilled;
} Order;
//task 6
int is_anagram(char str1[], char str2[]) {
    int char_counts[256] = {0};
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char_counts[(unsigned char)str1[i]]++;
        char_counts[(unsigned char)str2[i]]--;
        i++;
    }
    // If strings are of different lengths, they cannot be anagrams
    if (str1[i] != '\0' || str2[i] != '\0') {
        return 0;
    }
    // Check if all counts are zero
    for (i = 0; i < 256; i++) {
        if (char_counts[i] != 0) {
            return 0;
        }
    }
    return 1;
}
//task 7
typedef struct {
    int id;
    double hourly_rate;
    double hours_worked;
    double weekly_salary;
} Employee;


int main() {
    int choice;
     printf("Enter task number (1-7): ");
     scanf(" %d", &choice);

     switch(choice) {
        case 1: {
            int guests;
            char item[20];

            int bought_tables = 0;
            int bought_chairs = 0;
            int bought_cups = 0;
            int bought_dishes = 0;
            double total_spent = 0.0;

            scanf(" %d", &guests);
            //reading items
            while(1) {
                scanf(" %19s", item);

                if(strcmp(item, "PARTY!") == 0) {
                    break;
                }
                if(strcmp(item, "Table") == 0) {
                    bought_tables++;
                    total_spent += 42.00;
                } else if(strcmp(item, "Chair") == 0) {
                    bought_chairs++;
                    total_spent += 13.99;
                } else if(strcmp(item, "Cups") == 0) {
                    bought_cups++;
                    total_spent += 5.98;
                } else if(strcmp(item, "Dishes") == 0) {
                    bought_dishes++;
                    total_spent += 21.02;
                }
            }
            //calculating required amount
            //(guest + capacity - 1) / capacity
            int needed_tables = (guests + 7) / 8;   // 1 table = 8 people
            int needed_chairs = guests;             // 1 chair = 1 person
            int needed_cups = (guests + 5) / 6;     // 1 set = 6 people
            int needed_dishes = (guests + 5) / 6;   // 1 set = 6 people
            //calculate how many more to buy
            int buy_more_tables = needed_tables - bought_tables;
            int buy_more_chairs = needed_chairs - bought_chairs;
            int buy_more_cups = needed_cups - bought_cups;
            int buy_more_dishes = needed_dishes - bought_dishes;
            //preventing from negatives
            if(buy_more_tables < 0) {
                buy_more_tables = 0;
            }
            if(buy_more_chairs < 0) {
                buy_more_chairs = 0;
            }
            if(buy_more_cups < 0) {
                buy_more_cups = 0;
            }
            if(buy_more_tables < 0) {
                buy_more_dishes = 0;
            }
            //results
            printf("%.2f\n", total_spent);
            if(buy_more_tables > 0) {
                printf("%d Tables\n", buy_more_tables);
            }
            if(buy_more_chairs > 0) {
                printf("%d Chairs\n", buy_more_chairs);
            }
            if(buy_more_cups > 0) {
                printf("%d Cups\n", buy_more_cups);
            }
            if(buy_more_dishes > 0) {
                printf("%d Dishes\n", buy_more_dishes);
            }
            break;
        }
        case 2: {
            Product products[1000];
            Order orders[1000];

            int product_count = 0;
            int order_count = 0;
            char command[20];

            while(1) {
                scanf(" %19s", command);

                if(strcmp(command, "END") ==0) {
                    break;
                } else if(strcmp(command, "Product") == 0) {
                    scanf(" %49s %lf %d",
                        products[product_count].name,
                        &products[product_count].price,
                        &products[product_count].id);

                for(int i = 0; i < order_count; i++) {
                    if(orders[i].is_fulfilled == 0 && orders[i].product_id == products[product_count].id) {
                        printf("client %s ordered %s\n", orders[i].address, products[product_count].name);
                        orders[i].is_fulfilled = 1;
                        products[product_count].is_sold = 1;
                        break;
                    }
                }
                product_count++;
                } else if(strcmp(command, "Order") == 0) {
                    scanf(" %99s %d",
                        orders[order_count].address,
                        &orders[order_count].product_id);
                        orders[order_count].is_fulfilled = 0;

                    for(int i = 0; i < product_count; i++) {
                        if(products[i].is_sold == 0 && products[i].id == orders[order_count].product_id) {
                            printf("client %s ordered %s\n", orders[order_count].address, products[i].name);
                            products[i].is_sold = 1;
                            orders[order_count].is_fulfilled = 1;
                            break;
                        }
                    }
                    order_count++;
                }
            }
            break;
        }
        case 3: {
            FILE *in_file = fopen("input.txt", "r");
            if(in_file == NULL) {
                printf("Error: cannot open input.txt. Make sure the file exists.\n");
                break;
            }
            char **words_array = NULL;
            int words_count =0;

            char current_word[51];
            char target_char = '\0';

            while(fscanf(in_file, " %50s", current_word) == 1) {
                //checking
                if(words_count == 0 || current_word[0] == target_char) {
                    //reallocating memory to add 1 more string poiner
                    words_array = realloc(words_array, (words_count + 1) * sizeof(char *));
                    //allocating memory for the specific word based on length
                    words_array[words_count] = malloc((strlen(current_word) + 1) * sizeof(char));
                    //copy the word into dynamic array
                    strcpy(words_array[words_count], current_word);
                    //update target character for next iteration
                    target_char = current_word[strlen(current_word) - 1];
                    words_count++;
                }
            }
            fclose(in_file);
            //dynamic array
            FILE *bin_out = fopen("output.bin", "wb");
            if(bin_out == NULL) {
                printf("Error: cannot create output.bins\n");
                break;
            }
            for(int i = 0; i < words_count; i++) {
                //write string characters
                fwrite(words_array[i], sizeof(char), strlen(words_array[i]), bin_out);
                //write a space as separator
                char space = ' ';
                fwrite(&space, sizeof(char), 1, bin_out);
            }
            fclose(bin_out);
            printf("Data successfully written to output.bin\n");
            //reading from bin file (char by char) and display
            printf("reading from binary file.\n");
            FILE *bin_in = fopen("output.bin", "rb");
            if(bin_in != NULL) {
                int ch;

                while((ch = fgetc(bin_in)) != EOF) {
                    if(ch == ' ') {
                        putchar(' ');
                    } else {
                        putchar(ch);
                    }
                }
                putchar('\n');
                fclose(bin_in);
            }
            for(int i = 0; i < words_count; i++) {
                free(words_array[i]);
            }
            free(words_array);
            break;
        }
        case 4: {
            char input_filename[100];
            int key;
            //get file name
            printf("Enter the name of the file to encode: ");
            scanf(" %d", &key);
            //get and validate encoding key
            printf("Enter an encryption key (2-10): ");
            scanf(" %d", &key);

            if(key < 2 || key > 10) {
                printf("Error: Invalid key. (2-10).\n");
                break;
            }
            //open input file for reading
            FILE *in_file = fopen(input_filename, "r");
            if(in_file == NULL) {
                printf("Error: cannot open %s. make sure file exists.\n", input_filename);
                break;
            }
            //open output file for writing
            FILE *out_file = fopen("encoded.txt", "w");
            if(out_file == NULL) {
                printf("Error: cannot create encoded.txt\n");
                break;
            }
            //read, encode and write char by char
            int ch;
            while((ch = fgetc(in_file)) != EOF) {
                //encode by ASCII value
                int encoded_ch = ch + key;
                //write encoded char to the new file
                fputc(encoded_ch, out_file);
            }
            //closing files
            fclose(in_file);
            fclose(out_file);
            printf("File %s has been successfully encoded and saved as encoded.txt\n", input_filename);
            break;
        }
        case 5: {
            //hangman
            char secret_word[] = "concatenation";
            int word_len = strlen(secret_word);
            char current_state[50]; //stores underscores and guessed letters
            //rules
            int max_attempts = word_len + 2;
            int attempts = 0;
            char guess;
            int is_word_guessed = 0; // 0/1
            //word display
            for(int i = 0; i < word_len; i++) {
                current_state[i] = '_';
            }
            current_state[word_len] = '\0';

            printf("\n---Welcome to hangman---\n");
            printf("The word has %d letters.\n", word_len);
            printf("You have a maximum of %d attempts to win.\n", max_attempts);
            //game loop
            while(attempts < max_attempts) {
                printf("\nCurrent word: %s\n", current_state);
                printf("Attempt %d / %d. Enter a letter: ", attempts + 1, max_attempts);
                scanf(" %c", &guess);
                attempts++;
                //checking letter
                for(int i = 0; i < word_len; i++) {
                    if(secret_word[i] == guess) {
                        current_state[i] = guess;
                    }
                }
                //checking if word is guessed
                is_word_guessed = 1;
                for(int i = 0; i < word_len; i++) {
                    if(current_state[i] == '_') {
                        is_word_guessed = 0;
                        break;
                    }
                }
                //if fully guessed
                if(is_word_guessed == 1) {
                    break;
                }
            }
            //game over
            printf("\n--Game Over---\n");
            if(is_word_guessed == 1) {
                printf("congrats. you guessed '%s in %d attampts.\n", secret_word, attempts);
            } else {
                printf("YOU LOSE. The word was '%s'.\n", secret_word);
            }
            break;
        }
        case 6: {
            char word1[100];
            char word2[100];

            printf("\n--- Anagram Checker ---\n");
            printf("Enter the first word: ");
            scanf("%99s", word1);
            printf("Enter the second word: ");
            scanf("%99s", word2);
            //result
            if (is_anagram(word1, word2) == 1) {
                printf("Result: 1 (The words '%s' and '%s' are anagrams)\n", word1, word2);
            } else {
                printf("Result: 0 (The words '%s' and '%s' are NOT anagrams)\n", word1, word2);
            }
            break;
        }
        case 7: {
            int emp_choice;
            char filename[] = "employees.bin";
            do {
                printf("\n--- Employee Payroll Menu ---\n");
                printf("1. Add new employee record\n");
                printf("2. Display all employee salaries\n");
                printf("0. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &emp_choice);

                if (emp_choice == 1) {
                    //open file
                    FILE *file = fopen(filename, "ab+");
                    if (file == NULL) {
                        printf("Error opening file.\n");
                        continue;
                    }
                    //Check employee limit
                    fseek(file, 0, SEEK_END);
                    long file_size = ftell(file);
                    int current_count = file_size / sizeof(Employee);

                    if (current_count >= 30) {
                        printf("Error: Maximum capacity of 30 employees reached.\n");
                        fclose(file);
                        continue;
                    }
                    //Create new employee and read data
                    Employee new_emp;
                    printf("Enter Employee ID: ");
                    scanf("%d", &new_emp.id);
                    printf("Enter Hourly Wage: ");
                    scanf("%lf", &new_emp.hourly_rate);
                    printf("Enter Hours Worked this week: ");
                    scanf("%lf", &new_emp.hours_worked);
                    //Salary calculation
                    double gross_salary;
                    if (new_emp.hours_worked <= 40.0) {
                        //Standard
                        gross_salary = new_emp.hours_worked * new_emp.hourly_rate;
                    } else {
                        // Standard pay for 40 hours + 150% pay for overtime
                        double overtime_hours = new_emp.hours_worked - 40.0;
                        double overtime_rate = new_emp.hourly_rate * 1.5;
                        gross_salary = (40.0 * new_emp.hourly_rate) + (overtime_hours * overtime_rate);
                    }
                    // Deduct 3.65% taxes
                    double taxes = gross_salary * 0.0365;
                    new_emp.weekly_salary = gross_salary - taxes;
                    // Write to the binary file
                    fwrite(&new_emp, sizeof(Employee), 1, file);
                    fclose(file);
                    printf("Record added! Net Weekly Salary for ID %d is: %.2f\n", new_emp.id, new_emp.weekly_salary);
                } else if (emp_choice == 2) {
                    //Open file
                    FILE *file = fopen(filename, "rb");
                    if (file == NULL) {
                        printf("No records found. Please add an employee first.\n");
                        continue;
                    }
                    Employee temp_emp;
                    printf("\n--- Employee Salary Report ---\n");
                    printf("ID\tRate\tHours\tNet Salary\n");
                    printf("----------------------------------------\n");
                    while (fread(&temp_emp, sizeof(Employee), 1, file) == 1) {
                        printf("%d\t%.2f\t%.2f\t%.2f\n",
                               temp_emp.id, temp_emp.hourly_rate,
                               temp_emp.hours_worked, temp_emp.weekly_salary);
                    }
                    fclose(file);
                }
            } while (emp_choice != 0);
            break;
        }
        default:
            printf("Invalid task.\n");
            break;
     }
     return 0;
}
