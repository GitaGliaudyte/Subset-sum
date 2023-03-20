/*
Gita Gliaudytė, 2023
*/
#include <stdio.h>

void printSubset(int subset[], int size){
    printf("{");
    for (int i = 0; i <= size; i++) {
        printf(" %d ", subset[i]);
    }
    printf("}\n");
}


int isSubsetSum(int set[], int set_size, int sum, int subset[], int subset_size)
{

    if (set_size == 0)
        return 0;

    if (sum + set[set_size - 1] == 0){
        subset[subset_size] = set[set_size - 1];
        printSubset(subset, subset_size);
        return 1;
     }
    else
        subset[subset_size] = set[set_size - 1];


    return isSubsetSum(set, set_size - 1, sum + set[set_size - 1], subset, subset_size + 1) || isSubsetSum(set, set_size - 1, sum, subset, subset_size);

}

int main()
{
    int set_size;

    printf("Enter the number of set elements:\n");
    scanf("%d", &set_size);

    if(set_size > 0){

        int set[set_size];

        printf("Enter %d elements of your set:\n", set_size);
        for(int i = 0; i < set_size; ++i){
            scanf("%d", &set[i]);
        }

        int subset[set_size];
        int subset_size = 0;

        if(isSubsetSum(set, set_size, 0, subset, subset_size))
            printf("There is a subset in which the sum is equal to 0.\n");
        else
            printf("There is no subset in which the sum is equal to 0.\n");

    }
    else if(set_size == 0)
        printf("The set is empty.\n");
    else
        printf("The set cannot have a negative number of elements.\n");

    return 0;
}


