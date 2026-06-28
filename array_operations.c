/*
 * ============================================
 *   ARRAY INSERTION AND DELETION OPERATIONS
 *   Author  : [Gimbert Ludovice]
 *   Course  : Bachelor of Science in Information Technology
 *   Subject : DTSTRUC LAB
 * ============================================
 */

#include <stdio.h>

#define MAX_SIZE 100

/* ----------- Function to Display Array ----------- */
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* ----------- Function: Insert Element ----------- */
void insertElement(int arr[], int *size, int position, int value)
{
    if (*size >= MAX_SIZE)
    {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (position < 0 || position > *size)
    {
        printf("Invalid position! Must be between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
}

/* ----------- Function: Delete Element ----------- */
void deleteElement(int arr[], int *size, int position)
{
    if (*size == 0)
    {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    if (position < 0 || position >= *size)
    {
        printf("Invalid position! Must be between 0 and %d.\n", *size - 1);
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

/* ==================== MAIN ==================== */
int main()
{
    int arr[MAX_SIZE];
    int size;

    printf("============================================\n");
    printf("   ARRAY INSERTION AND DELETION PROGRAM    \n");
    printf("============================================\n\n");

    /* ----- Input Array ----- */
    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
    {
        printf("Invalid size! Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("  Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    /* ----- Display Original Array ----- */
    printf("\n--------------------------------------------\n");
    printf("Original Array: ");
    displayArray(arr, size);
    printf("--------------------------------------------\n");

    /* ========== INSERTION OPERATION ========== */
    printf("\n* - Insertion Operation ---\n");

    int insertPos, insertVal;

    printf("Enter position to insert (0 to %d): ", size);
    scanf("%d", &insertPos);

    printf("Enter value to insert: ");
    scanf("%d", &insertVal);

    insertElement(arr, &size, insertPos, insertVal);

    printf("Array after insertion: ");
    displayArray(arr, size);
    printf("--------------------------------------------\n");

    /* ========== DELETION OPERATION ========== */
    printf("\n* - Deletion Operation ---\n");

    int deletePos;

    printf("Enter position to delete (0 to %d): ", size - 1);
    scanf("%d", &deletePos);

    deleteElement(arr, &size, deletePos);

    printf("Array after deletion: ");
    displayArray(arr, size);
    printf("--------------------------------------------\n");

    printf("\nProgram completed successfully!\n");

    return 0;
}
