#include <iostream>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int j = 0;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];

    arr[j++] = arr[n - 1];

    return j;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    std::cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}