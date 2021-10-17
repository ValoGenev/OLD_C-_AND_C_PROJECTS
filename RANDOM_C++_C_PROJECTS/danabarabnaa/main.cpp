#include <iostream>
#include <limits>

using namespace std;


void heapSort(int arr[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapSort(arr, n, largest);
    }
}

void heapify(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapSort(arr, n, i);
}

class heap
{

private:
    int* arr;
    int size;
    int capacity;

    void resize()
    {
        capacity = capacity* 2;
        int * newArr = new int[capacity];

        for (int i = 0; i< size; ++i)
        {
            newArr[i] = arr[i];

        }
        delete[]arr;
        arr = newArr;
    }

public:

    heap()
    {
        capacity = 7;
        size = 0;
        arr = new int[capacity];
    }
    heap(const heap& other) = delete;
    heap& operator= (const heap& other) = delete;
    ~heap()
    {
        delete[] arr;
    }


    int top() const
    {
        if (size == 0) {
            cout << "Queue empty.\n";
            return 0;
        }
        else
            return arr[0];
    }

    void insert(int element)
    {
        if (size == capacity) {
            resize();
        }
        arr[size] = element;
        ++size;
        heapify(arr, size);
    }

    int popTop()
    {
        if (size == 0) {
            cout << "Queue empty.\n";
            return 0;
        }
        int toReturn = arr[0];
        swap(arr[0], arr[size-1]);
        --size;
        heapSort(arr, size, 0);
        return toReturn;
    }
};

int main()
{
    int number; long int newnum;
    heap hp;
    do {

        cout << " To insert press 1.\n";
        cout << " To see the top press 2.\n";
        cout << " To pop the top press 3.\n";
        cout << " To exit press 4.\n";
        cout << " Choose (1-4): ";
        cin >> number;
        cout << '\n';


        switch (number) {

        case 1:
            cout << " Write the element you want to insert: ";


            bool fail;
            do{

                cin>> newnum;
                fail= cin.fail();
                cin.clear();
                if (fail != true) break;
                cin.ignore(numeric_limits<streamsize>:: max(), '\n');
                cout << " Invalid input, write a number to insert:    ";
            }while (fail == true);

            hp.insert(newnum);
            break;


        case 2:
            cout << "\nThe top is:" << hp.top() << "\n";
            break;

        case 3:
            cout << "  \n " << hp.popTop() << " was popped from the queue.\n";
            break;

        case 4:
            break;

        default:
            cout << "Wrong operation. Please enter a number from 1 to 4 \n";
            break;




        }
        cout << "\n";
    } while (number != 4);

    return 0;
}
