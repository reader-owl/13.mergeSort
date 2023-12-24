#include <iostream>

using namespace std;

/*
                        Merge Sort -  it is much more optimised sorting algorithm
                                    Divide & Merge
                                    we will dividing arrays into two parts, untill single digit array remains
                                    and we will sort the single digit array in a order, then we are going to 
                                    merge all of the divided arrays step by step in the form arrays

                TC -  it is working as          [N]
                                               |---|
                                              n/2 n/2
                                           |---|   |---|
                                         n/2  n/2 n/2  n/2 manner

                        we already know that when it is going in n/2 manner, then there Time
                        Complexity is 'log2 (N)' (log base 2 (N))

                        so the TC - N.log2 (N)      // <- best, avg and worst case

                SC -  O(N)
                                      

                lets take an exa- {3, 1, 2, 4, 1, 5, 2, 6, 4}, it contains 9 elements
                                    we can divide this array in two type- 5 & 4 or 4 & 5, it doesn't matter how we divide it
                            we will divide it into 5 & 4
                            i.e  {3, 1, 2, 4, 1}  &  {5, 2, 6, 4}
                            lets further divide the left part into two
                                 {3, 1, 2}  &  {4, 1}                       {5, 2}  &  {6, 4}
                            then again              for right side
                                 {3, 1}  &  {2}         {4} & {1}           {5} & {2}       {6} & {4}
                            again
                                 {3}  &  {1}            
                            now merge these two but in a sorted way
                                 {1, 3}                 {1,  4}             {2} & {5}       {4} & {6}

                            now moving in reverse order
                            take {1, 3} & {2}, merge it                     {2, 5} & {4, 6}, merge it
                                 {1, 2, 3}                                  {2, 4, 5, 6}
                            take {1, 2, 3} & {1, 4}
                                 {1, 1, 2, 3, 4}

                            now take {1, 1, 2, 3, 4}  &  {2, 4, 5, 6}
                                     {1, 1, 2, 2, 3, 4, 4, 5, 6}


        Pseudo code
mergeSort(arr, low, high)               // low for first index(i.e '0'), high for last index(i.e length of the array)
{
    if(low >= high)                     // base case,  it says if low(index '0') is greater than or equals to high(index 'last') then return,
        return;                         //  which is pointing to the single element array,  in single element array we want it to return

    mid = (low + high) / 2              // to find middle of the array
    mergeSort(arr, low, mid)            // sorting for the first half of the array
    mergeSort(arr, mid + 1, high)       // sorting for the second half of the array
    merge(arr, low, mid, high)          // merging of the two above arrays
}


        Dry Run the above code
                with arr- {3, 2, 4, 1, 3}

mergeSort(arr, 0, 4)         -> mergeSort(arr, 0, 2)         -> mergeSort(arr, 0, 1)         -> mergeSort(arr, 0, 0)
{                            |  {                            |  {                            |  {
    not                      |      not                      |      not                      |      if(0 >= 0)
        exec..               |          exec..               |          exec..               |          return;
                             |                               |                               |
    mid = 2                  |      mid = 1                  |      mid = 0                  |
    mergeSort(arr, 0, 2)    -       mergeSort(arr, 0, 1)    -       mergeSort(arr, 0, 0)    -
    mergeSort(arr, 3, 4)    -       mergeSort(arr, 2, 2)    -       mergeSort(arr, 1, 1)    --> mergeSort(arr, 1, 1)
    merge(arr, 0, 2, 4)      |      merge(arr, 0, 1, 2)      |      merge(arr, 0, 1, 1)         {
    //above line will merge  |      //above line will merge  |      //above line will merge         if(1 >= 1)
    //the whole array in     |      //in sorted order bcz    |      //in sorted order                   return;
    //sorted order           |      //merge is cmplted       |                                  }
                             |                               |->    mergeSort(arr, 2, 2)
                             |-> mergeSort(arr, 3, 4)               {
                                 {                                      if(2 >= 2)
                                     not                                    return;
                                         exec..                     }

                                     mid = 3
                                     mergeSort(arr, 3, 4)       <- it will return (3, 3)
                                     mergeSort(arr, 4, 4)       <- it will return (4, 4)
                                     merge(arr, 3, 4, 4)
                                     // above line will merge
                                     //in sorted order
}


        pseudo code for merge
merge(arr, low, mid, high)
{
    temp -> []
    left = low              // we are appointing left to the '0' index 
    right = mid + 1         //and right to the first index of second part of the array
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])     //by this if-else conditions we are moving the pointer
        {                               //to right after adding it to the array
            temp.add(arr[left])
            left++
        }
        else
        {
            temp.add(arr[right])
            right++
        }
    }
    while(left <= mid)              //this condition is used when all the elements on the left are pointed in the array
    {
        temp.add(arr[left])
        left++
    }
    while(right <= high)            //similarly for the right
    {
        temp.add(arr[right])
        right++
    }

    //all the elements are putted into temp array, so now we have to put it into the original array
    for(i = low -> high)                    //bcz original array goes from low to high
    {
        arr[i] = temp[i - low]              //when i=low then, temp[low - low] = 0
                                            // i=low+1, temp[low+1 - low] = 0
    }
}


        Actual Code
void merge(vector<int> &arr, int low, int, mid, int high)
{
    vector<int> temp;
    int left = low;             // low to mid
    int right = mid + 1;        // mid+1 to high

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)                  //if there is still elements left then feed it to left
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high)
{
    if(low == high)
        return;

    int mid = (low + high) / 2; 
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    ms(arr, 0, n - 1);          // <-original starting and end position of the array
}

*/

int main()
{
    std::cout << "Hello World!\n";
}