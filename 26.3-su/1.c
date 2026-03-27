#include <stdio.h>

int main() {
    int choice;
    printf("what exersice (1-9) would you like to try?: ");
    scanf(" %d", &choice);

    switch (choice) {
    case 1: {
        int N;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d coordinates into the row of elements:\n", N);
        for(int i = 0; i < N; i++){
            scanf(" %d", &arr[i]);
        }
        int max_len = 1;
        int best_start = 0;
        int current_len = 1;
        int current_start = 0;

        for(int i = 1; i < N; i++) {
            if(arr[i] == arr[i - 1]) {
                current_len++;
            } else {
            if(current_len > max_len) {
                max_len = current_len;
                best_start = current_start;
            }
            current_len = 1;
            current_start = 1;
            }
        }
        if(current_len > max_len) {
            max_len = current_len;
            best_start = current_start;
        }
        printf("\nResult:\n");
        printf(" longest array starts with index: %d\n", best_start);
        printf("longest array: %d\n", max_len);
        printf("element of array: %d\n", arr[best_start]);
        break;
        }
    case 2: {
        int N;
        printf("input N amount of elements: ");
        if(scanf(" %d",&N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        if(N < 2) {
            printf("need more than 2 elements.\n");
            break;
        }
        int arr[N];
        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        int is_valid = 1;

        for(int i = 1; i < N; i++) {
            if(i % 2 != 0) {
                if(arr[i - 1] >= arr[i]) {
                    is_valid = 0;
                    break;
                }
            }
        }
        printf("\nResults: ");
        if(is_valid) {
            printf("the relations (a0 < a1 > a2 < a3) are complete");
        } else {
            printf("the relations are not complete\n");
        }
        break;
    }
    case 3: {
        int N;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        for(int i = 0; i < N / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[N - 1 - i];
            arr[N - 1 - i] = temp;
        }
        printf("\nReversed array is:\n");
        for(int i = 0; i < N; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        break;
    }
    case 4: {
        int N, K;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        printf("input displacement spaces (K): ");
        scanf(" %d", &K);
        K = K % N;

        if(K < 0) {
            K = K + N;
        }
        if(K > 0) {
            int tempArr[N];
            for(int i = 0; i < N; i++) {
                int new_index = (i + K) % N;
                tempArr[new_index] = arr[i];
            }
            for(int i = 0; i < N; i++) {
                arr[i] = tempArr[i];
            }
        }
        printf("\Displaced array: ");
        for(int i = 0; i < N; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        break;
    }
    case 5: {
        int N, K;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        printf("input which element you are looking for by size: ");
        if(scanf(" %d", &K) != 1 || K <= 0 || K > N) {
            printf("invalid. K must be between 1 and %d\n", N);
            break;
        }
        for(int i = 0; i < N - 1; i++) {
            for(int j = 0; j < N - i - 1; j++) {
                if(arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("\n%d-st/nd/rd/th element by size is: %d\n", K, arr[K - 1]);
        printf("sorted array (descending) is: ");
        for(int i = 0; i < N; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        break;
    }
    case 6: {
        int N;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        if(N==1) {
            printf("\nLongest row has the length of 1: %d\n", arr[0]);
            break;
        }
        int max_len = 1;
        int best_start = 0;
        int inc_len = 1;
        int inc_start = 0;
        int dec_len = 1;
        int dec_start = 0;

        for(int i = 1; i < N; i++) {
            if(arr[i] > arr[i - 1]) {
                inc_len++;
                dec_len = 1;
                dec_start = i;
            }
            else if(arr[i] < arr[i - 1]) {
                dec_len++;
                inc_len = 1;
                inc_start = i;
            }
            else {
                inc_len = 1;
                inc_start = i;
                dec_len = 1;
                dec_start = i;
            }
            if(inc_len > max_len) {
                max_len = inc_len;
                best_start = inc_start;
            }
            if(dec_len > max_len) {
                max_len = dec_len;
                best_start = dec_start;
            }
        }
        printf("\nResults:\n");
        printf("longest sequence: %d", max_len);
        printf("elements are: ");

        for(int i = best_start; i < best_start + max_len; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        break;
    }
    case 7: {
        int N, target_sum;
        printf("input amount of N elements: ");
        if(scanf(" %d", &N) != 1 || N <= 0) {
            printf("invalid amount of elements. N must be a positive number.\n");
            break;
        }
        int arr[N];

        printf("input %d elements: \n", N);
        for(int i = 0; i < N; i++) {
            scanf(" %d",&arr[i]);
        }
        int found = 0;
        int start_idx = -1;
        int end_idx = -1;

        for(int i = 0; i < N; i++) {
            int current_sum = 0;

            for(int j = i; j < N; j++) {
                current_sum += arr[j];

                if(current_sum == target_sum) {
                    start_idx = i;
                    end_idx = j;
                    found = 1;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        printf("\nResults\n");
        if(found) {
            printf("sum found is: %d", target_sum);
            printf("elements are from index %d to %d", start_idx, end_idx);

            for(int i = start_idx; i <= end_idx; i++) {
                printf("%d", arr[i]);
            }
            printf("\n");
        } else {
            printf("there is no sum\n");
        }
        break;
    }
    case 8: {
        int arr[20];
        int current_size = 0;
        printf("input 10 numbers:\n");
        for (int i = 0; i < 10; i++) {
            printf("arr[%d] = ", i);
            scanf(" %d", &arr[i]);
            current_size++;
        }
        printf("input 0 to stop.\n");

        while (current_size < 20) {
            int new_value, target_index;
            printf("\ninput number: ");
            scanf(" %d", &new_value);

            if (new_value == 0) {
                printf("o has been input.\n");
                break;
            }
            printf("input index (between 0 and %d): ", current_size);
            scanf(" %d", &target_index);

            if (target_index < 0 || target_index > current_size) {
                printf("Error. invalid index\n");
                continue;
            }
            for (int i = current_size; i > target_index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[target_index] = new_value;
            current_size++;

            if (current_size == 20) {
                printf("finished!\n");
            }
        }
        printf("\nResult:\n");
        for (int i = 0; i < current_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    }
    case 9: {
        int n;

        printf("Enter number of elements: ");
        if (scanf(" %d", &n) != 1 || n <= 0) {
            return 0;
        }
        int arr[n];
        printf("Enter %d numbers: ", n);
        for (int i = 0; i < n; i++) {
            scanf(" %d", &arr[i]);
        }
        int current_len = 1;
        int current_start = 0;

        int max_len = 1;
        int best_start = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                current_len++;
            } else {
                if (current_len > max_len) {
                    max_len = current_len;
                    best_start = current_start;
                }
                current_len = 1;
                current_start = i;
            }
        }
        if (current_len > max_len) {
            max_len = current_len;
            best_start = current_start;
        }
        printf("Output: ");
        for (int i = 0; i < max_len; i++) {
            printf("%d ", arr[best_start]);
        }
        printf("\n");
        break;
    }
    default:{
        printf("invalid choice\n");
        break;
        }
    }
    return 0;
}
