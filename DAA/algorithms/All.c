/*
  Easy C Programs: Sorting & Searching
  Each section is a small, self-contained C program with clear comments
  - Very simple input/output
  - Easy-to-follow functions implementing the algorithm
  Compile: gcc program.c -o program && ./program
*/

/* === 1) Bubble Sort ===
   Idea: Repeatedly compare adjacent elements and swap if out of order.
*/
#include <stdio.h>
#include <stdlib.h>

/* Bubble Sort function */
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;                // optimization: stop if already sorted
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;
    printf("Bubble Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    bubbleSort(a, n);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* === 2) Insertion Sort ===
   Idea: Build the final sorted array one item at a time by inserting each
   new element into its correct position among the already-sorted ones.
*/

/* To compile and run this section alone, copy it to a file and compile. */

/* === 3) Selection Sort ===
   Idea: Repeatedly select the minimum element from the unsorted part and
   put it at the front.
*/

/* === 4) Heap Sort ===
   Idea: Use a binary heap (max-heap) to repeatedly extract the largest
   element and build the sorted array from back to front.
*/

/* === 5) Linear Search ===
   Idea: Scan array from left to right until you find the key.
*/

/* === 6) Binary Search ===
   Idea: For a sorted array, repeatedly cut the search interval in half.
*/

/* === 7) Quick Sort ===
   Idea: Pick a pivot, partition the array into elements smaller and larger
   than the pivot, then sort the two partitions recursively.
*/

/* === 8) Merge Sort ===
   Idea: Divide the array into halves, sort each half, then merge them.
*/

/*
  The rest of the programs (Insertion, Selection, Heap, Linear, Binary,
  Quick, Merge) are provided below as separate, small programs. You can
  copy any section into its own file to compile and run individually.
*/

/* ----------------------------------------------------------- */
/* Insertion Sort (single-file program) */
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

int main_insertion() {
    int n;
    printf("Insertion Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    insertionSort(a, n);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Selection Sort (single-file program) */
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min_idx]) min_idx = j;
        if (min_idx != i) {
            int tmp = a[i]; a[i] = a[min_idx]; a[min_idx] = tmp;
        }
    }
}

int main_selection() {
    int n;
    printf("Selection Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    selectionSort(a, n);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Heap Sort (single-file program) */
#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        int tmp = a[i]; a[i] = a[largest]; a[largest] = tmp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; --i) heapify(a, n, i);
    // One by one extract elements
    for (int i = n - 1; i > 0; --i) {
        int tmp = a[0]; a[0] = a[i]; a[i] = tmp; // move max to the end
        heapify(a, i, 0); // heapify reduced heap
    }
}

int main_heap() {
    int n;
    printf("Heap Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    heapSort(a, n);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Linear Search (single-file program) */
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; ++i)
        if (a[i] == key) return i; // return index where found
    return -1; // not found
}

int main_linear() {
    int n, key;
    printf("Linear Search\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Enter key to search: "); scanf("%d", &key);
    int idx = linearSearch(a, n, key);
    if (idx >= 0) printf("Key %d found at index %d\n", key, idx);
    else printf("Key %d not found\n", key);
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Binary Search (array must be sorted first) */
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[], int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main_binary() {
    int n, key;
    printf("Binary Search\nEnter number of elements (sorted): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d sorted integers (ascending):\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Enter key to search: "); scanf("%d", &key);
    int idx = binarySearch(a, n, key);
    if (idx >= 0) printf("Key %d found at index %d\n", key, idx);
    else printf("Key %d not found\n", key);
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Quick Sort (single-file program) */
#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int lo, int hi) {
    int pivot = a[hi]; // choose last element as pivot (simple)
    int i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j) {
        if (a[j] <= pivot) {
            ++i;
            int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        }
    }
    int tmp = a[i+1]; a[i+1] = a[hi]; a[hi] = tmp;
    return i + 1;
}

void quickSort(int a[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quickSort(a, lo, p - 1);
        quickSort(a, p + 1, hi);
    }
}

int main_quick() {
    int n;
    printf("Quick Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    quickSort(a, 0, n - 1);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Merge Sort (single-file program) */
#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main_merge() {
    int n;
    printf("Merge Sort\nEnter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("Before sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    mergeSort(a, 0, n - 1);

    printf("After sort:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}

/* ----------------------------------------------------------- */
/* Notes for use:
   - Each 'main_*' is an independent main for that algorithm. To run one
     algorithm, create a small file with the corresponding section and
     rename the intended main_* to main (or call it from a test harness).
   - The programs are purposefully simple and include comments to explain
     what is happening step-by-step.
*/
