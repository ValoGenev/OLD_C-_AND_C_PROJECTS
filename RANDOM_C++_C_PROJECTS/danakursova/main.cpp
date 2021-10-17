#include <iostream>
#include <cstdlib>

using namespace std;
void heapSort(int arr[], int n, int root)
{
    int largest = root; // Initialize largest as root
    int left = 2*root + 1; // left = 2*i + 1
    int right = 2*root + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root )
    {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapSort(arr, n, largest);
    }
}

class heap{
private:
    int* arr;
    int size;
    int capacity;

    void resize()
    {
        capacity*= 2;
        int * newArr= new int[capacity];

        for (int i=0; i< size; ++i)
        {
            newArr[i]= arr[i];

        }
        delete []arr;
        arr= newArr;
    }
public:
    heap()

    {
        capacity = 8;
        size =0;
        arr = new int [capacity];

    }

    heap(const heap& other) = delete;

    heap& operator= (const heap& other) = delete;

    ~heap() {
        delete [] arr;
    }

    void top()
    {

     if(arr[0]==NULL) cout << "error\n";

     else cout << arr[0] << " \n ";

    }

    void insert(int element)
    {

        if (size == capacity){
            resize();
        }
        arr[size]= element;
        ++size;
        heapSort(arr,size, 0);
        cout << size;

    }

    int  popTop()
    {
        int toReturn= arr[0];
        swap(arr[0], arr [size-1]);
        --size;
        heapSort(arr,size, 0);
        return toReturn;
    }
};

int main()
{
    int a,b;
    heap hp;
    do {


        cout << " To insert press 1   \n";
        cout << " To see the top press 2    \n";
        cout << " To pop the top press 3    \n";
        cout << " To exit ress 4      \n";
        cout <<" Please choose an option  1,2,3 or 4:     ";
        cin >> a;
        system("CLS");


        switch (a) {

    case 1:
        cout << " Write the element you want to insert     ";
        cin >>b;
        hp.insert(b);
         break;

    case 2:
        hp.top();
        break;

    case 3:
       cout << hp.popTop();
        break;

    case 4:
        break;


    default:
        cout << " Please enter another option \n" ;

    }
    } while (a != 4);


    return 0;
}
