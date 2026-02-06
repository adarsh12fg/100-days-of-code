//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements: ");
    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i-1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}

