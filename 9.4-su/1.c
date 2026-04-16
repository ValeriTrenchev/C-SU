#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    printf("what exercise (1-8) would you like to try?: ");
    scanf(" %d", &choice);

    switch (choice) {
    case 1: {
        int N, M; //rows and columns
        printf("enter number of rows (N): ");
        scanf(" %d", &N);
        printf("enter number of columns (M): ");
        scanf(" %d", &M);

        if(N <= 0 || M <= 0) {
            printf("Invalid dimensions!\n");
            break;
        }
        int matrix[N][M];
        //matrix elements
        printf("enter the elements of the matrix (%d x %d):\n", N, M);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf(" %d", &matrix[i][j]);
            }
        }
        int isValid = 1;
        //row check
        for(int i = 0; i < N && isValid; i++) {
            for(int j = 0; j < M - 1; j++) {
                if(matrix[i][j] >= matrix[i][j + 1]) {
                    isValid = 0;
                    break;
                }
            }
        }
        //column check
        for(int j = 0; j < M && isValid; j ++) {
            for(int i = 0; i < N - 1; i++) {
                if(matrix[i][j] <= matrix[i + 1][j]) {
                    isValid = 0;
                    break;
                }
            }
        }
        //result
        printf("matrix:\n");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        if(isValid) {
            printf("the matrix is correct.\n");
        } else {
            printf("the matrix is wrong.\n");
        }
    break;
    }
    case 2: {
        int N, M; //rows and columns
        printf("enter number of rows (N): ");
        scanf(" %d", &N);
        printf("enter number of columns (M): ");
        scanf(" %d", &M);

        if(N <= 0 || M <= 0) {
            printf("Invalid dimensions!\n");
            break;
        }
        int matrix[N][M];
        //matrix elements
        printf("enter the elements of the matrix (%d x %d):\n", N, M);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf(" %d", &matrix[i][j]);
            }
        }
        //matrix
        printf("matrix:\n");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        int isFirst = 1;
        long maxSum = 0;
        int bestRow = 0;
        int bestCol = 0;
        int bestValue = 0;

        for(int i = 0; i< N; i++) {
            for(int j = 0; j < M; j++) {
                long currentSum = 0;
                //matrix check
                for(int r = i - 1; r <= i + 1; r++) {
                    for(int c = j - 1; c <= j + 1; c++) {
                        if(r >= 0 && r < N && c >= 0 && c < M) {
                            if(!(r == i && c == j)) {
                                currentSum += matrix[r][c];
                            }
                        }
                    }
                } //value update
                if(isFirst || currentSum > maxSum) {
                    maxSum = currentSum;
                    bestRow = i;
                    bestCol = j;
                    bestValue = matrix[i][j];
                    isFirst = 0;
                }
            }
        }
        //result
        printf("element with the max neighbor sum: %d (at row %d, col %d)\n", bestValue, bestRow, bestCol);
        printf("the max neighbor sum is: %l\n", maxSum);
    break;
    }
    case 3: {
        int N, M; //rows and columns
        printf("enter number of rows (N): ");
        scanf(" %d", &N);
        printf("enter number of columns (M): ");
        scanf(" %d", &M);

        if(N <= 0 || M <= 0) {
            printf("Invalid dimensions!\n");
            break;
        }
        int matrix[N][M];
        //matrix elements
        printf("enter the elements of the matrix (%d x %d):\n", N, M);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf(" %d", &matrix[i][j]);
            }
        }
        //matrix
        printf("matrix:\n");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        int maxVal = matrix[0][0];
        int minVal = matrix[0][0];
        int maxRow = 0;
        int minRow = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    maxRow = i;
                }
                if(matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minRow = i;
                }
            }
        }
        //row swap
        if(maxRow != minRow) {
            for(int j = 0; j < M; j++) {
                int temp = matrix[maxRow][j];
                matrix[maxRow][j] = matrix[minRow][j];
                matrix[minRow][j] = temp;
            }
            printf("swapped row %d with row %d\n", minRow, maxRow);
        } else {
            printf("no swap needed");
        }
        //result
        printf("new matrix:\n");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    break;
    }
    case 4: {
        int N, M;
        printf("enter number of people (N): ");
        scanf(" %d", &N);
        printf("enter number of friendships (M): ");
        scanf(" %d", &M);

        if(N < 1 || N > 100000 || M < 1 || M > 1000000) {
            printf("Invalid dimensions!\n");
            break;
        }
        //allocating memory
        int *friendCount = (int *)calloc(N + 1, sizeof(int));
        if(friendCount == NULL) {
            printf("memory allocation failed!\n");
            break;
        }
        //input
        printf("enter the %d friendships (p1, p2):\n", M);
        for(int i = 0; i < M; i++) {
            int p1, p2;
            scanf(" %d %d", &p1, &p2);

            if(p1 >= 1 && p1 <= N && p2 >= 1 && p2 <= N) {
                friendCount[p1]++;
                friendCount[p2]++;
            } else {
                printf("Warning: invalid person number!\n");
            }
        }
        //loop
        int queryPerson;
        printf("enter a person's number to see their friend count (0 to stop):\n");
        while(1) {
            printf("Person number: ");
            scanf(" %d", &queryPerson);

            if(queryPerson == 0) {
                printf("Exit.\n");
                break;
            }
            if(queryPerson >= 1 &&queryPerson <= N) {
                printf("Person %d has %d friend(s).\n", queryPerson, friendCount[queryPerson]);
            } else {
                printf("invalid person number, must be between 1 and %d.\n", N);
            }
        }
        free(friendCount);
    break;
    }
    case 5: {
        int capacity = 100;
        int *arr = (int *)malloc(capacity * sizeof(int));
        int size = 0;

        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            break;
        }
        printf("Naum's Software Started!\n");
        printf("Commands:\n");
        printf("  1 x  -> Add element x\n");
        printf("  2 x  -> Delete all occurrences of x\n");
        printf("  3 x  -> Print the x-th smallest element\n");
        printf("  0 0  -> Exit software\n\n");

        while (1) {
            int cmd, x;
            printf("Enter command (cmd x): ");
            scanf("%d %d", &cmd, &x);
            if (cmd == 0) {
                printf("Exiting Naum's software.\n");
                break;
            }
            if (cmd == 1) {
                if (size == capacity) {
                    capacity *= 2;
                    int *temp = (int *)realloc(arr, capacity * sizeof(int));
                    if (temp == NULL) {
                        printf("Memory reallocation failed!\n");
                        free(arr);
                        break;
                    }
                    arr = temp;
                }
                int i = size - 1;
                while (i >= 0 && arr[i] > x) {
                    arr[i + 1] = arr[i];
                    i--;
                }
                arr[i + 1] = x;
                size++;
                printf("-> Added %d. Total elements: %d\n", x, size);
            } else if (cmd == 2) {
                int newSize = 0;
                int deletedCount = 0;
                for (int i = 0; i < size; i++) {
                    if (arr[i] != x) {
                        arr[newSize] = arr[i];
                        newSize++;
                    } else {
                        deletedCount++;
                    }
                }
                size = newSize;
                if (deletedCount > 0) {
                    printf("-> Deleted %d occurrence(s) of %d.\n", deletedCount, x);
                } else {
                    printf("-> Element %d not found.\n", x);
                }
            } else if (cmd == 3) {
                if (x > 0 && x <= size) {
                    printf("-> The %d-th smallest element is %d.\n", x, arr[x - 1]);
                } else {
                    printf("-> Error: There are currently only %d elements.\n", size);
                }
            } else {
                printf("-> Invalid command! Use 1, 2, 3, or 0.\n");
            }
        }
        free(arr);
    break;
    }
    case 6: {
        int n;
        printf("Enter the number of elements (N): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid number of elements!\n");
            break;
        }
        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));
        if (arr1 == NULL || arr2 == NULL) {
            printf("Memory allocation failed!\n");
            if (arr1) free(arr1);
            if (arr2) free(arr2);
            break;
        }
        printf("Enter the %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr1[i]);
        }
        int nonPrimeCount = 0;
        int primeCount = 0;

        for (int i = 0; i < n; i++) {
            int num = arr1[i];
            int isPrime = 1;
            if (num <= 1) {
                isPrime = 0;
            } else {
                for (int j = 2; j * j <= num; j++) {
                    if (num % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
            }
            if (isPrime) {
                arr2[primeCount] = num;
                primeCount++;
            } else {
                arr1[nonPrimeCount] = num;
                nonPrimeCount++;
            }
        }
        if (nonPrimeCount > 0) {
            arr1 = (int *)realloc(arr1, nonPrimeCount * sizeof(int));
        }
        if (primeCount > 0) {
            arr2 = (int *)realloc(arr2, primeCount * sizeof(int));
        }
        printf("\nArray 1 (Non-prime numbers): ");
        if (nonPrimeCount == 0) {
            printf("(empty)\n");
        } else {
            for (int i = 0; i < nonPrimeCount; i++) {
                printf("%d ", arr1[i]);
            }
            printf("\n");
        }
        printf("Array 2 (Prime numbers): ");
        if (primeCount == 0) {
            printf("(empty)\n");
        } else {
            for (int i = 0; i < primeCount; i++) {
                printf("%d ", arr2[i]);
            }
            printf("\n");
        }
        if (nonPrimeCount > 0) free(arr1);
        if (primeCount > 0) free(arr2);
    break;
    }
    case 7: {
        int N, M;
        printf("Enter number of rows (N): ");
        scanf("%d", &N);
        printf("Enter number of columns (M): ");
        scanf("%d", &M);
        if (N < 3 || M < 3) {
            printf("Matrix is too small! Minimum dimensions are 3x3.\n");
            break;
        }
        int matrix[N][M];
        printf("Enter the elements of the matrix (%d x %d):\n", N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        long long maxSum = 0;
        int bestRow = 0;
        int bestCol = 0;
        int isFirst = 1;

        for (int i = 0; i <= N - 3; i++) {
            for (int j = 0; j <= M - 3; j++) {
                long long currentSum = 0;
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        currentSum += matrix[r][c];
                    }
                }
                if (isFirst || currentSum > maxSum) {
                    maxSum = currentSum;
                    bestRow = i;
                    bestCol = j;
                    isFirst = 0;
                }
            }
        }
        printf("\nThe 3x3 submatrix with the maximum sum (%lld) is:\n", maxSum);
        for (int r = bestRow; r < bestRow + 3; r++) {
            for (int c = bestCol; c < bestCol + 3; c++) {
                printf("%d\t", matrix[r][c]);
            }
            printf("\n");
        }
        printf("\n");
    break;
    }
    case 8: {
        int capacity = 10;
        int size = 10;
        int *arr = (int *)malloc(capacity * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            break;
        }
        printf("Enter 10 numbers for the initial array:\n");
        for (int i = 0; i < 10; i++) {
            scanf("%d", &arr[i]);
        }
        printf("\nInitial array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        printf("--- Insert Mode ---\n");
        printf("Enter a number to insert and its index (e.g., '5 2').\n");
        printf("Enter '0' as the number to stop.\n\n");

        while (1) {
            int num, index;
            printf("Number (0 to stop): ");
            scanf("%d", &num);

            if (num == 0) {
                printf("Exiting insertion mode.\n");
                break;
            }
            printf("Index (0 to %d): ", size);
            scanf("%d", &index);
            if (index < 0 || index > size) {
                printf("Invalid index! Must be between 0 and %d.\n\n", size);
                continue;
            }
            if (size >= capacity) {
                capacity *= 2;
                int *temp = (int *)realloc(arr, capacity * sizeof(int));
                if (temp == NULL) {
                    printf("Memory reallocation failed!\n");
                    break;
                }
                arr = temp;
            }
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = num;
            size++;
            printf("-> Array: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n\n");
        }
        free(arr);
    break;
    }
    default: {
        printf("Invalid choice! Please enter a valid option from the menu.\n");
        break;
    }
    }
    return 0;
}
