#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <algorithm>

//write to csv helper class (handles formatting output to csv)
#include "csv.hpp"

//comparison counter and array access counter
static int comp_count = 0;
static int arr_access_count = 0;

//Int class to replace int. Allows overloading operators to count operations done
//------------------------------------
struct Int{
    Int(int val = 0){value = val;};
    void operator=(const int val){value = val;};
    bool operator<=(const Int& b){
    //    std::cout << "comparing " << value << " <= " << b << "\n";
        ++comp_count;
        return value <= b.value;
    }
    bool operator<(const Int& b) const {
    //    std::cout << "comparing " << value << " < " << b << "\n";
        ++comp_count;
        return value < b.value;
    }
    bool operator<(const int b) const {
    //    std::cout << "comparing " << value << " < " << b << "\n";
        ++comp_count;
        return value < b;
    }
    bool operator>=(const Int& b) const {
    //    std::cout << "comparing " << value << " >= " << b << "\n";
        ++comp_count;
        return value >= b.value;
    }
    bool operator>=(const int b) const {
    //    std::cout << "comparing " << value << " >= " << b << "\n";
        ++comp_count;
        return value >= b;
    }
    bool operator>(const Int& b) const {
    //    std::cout << "comparing " << value << " > " << b << "\n";
        ++comp_count;
        return value > b.value;
    }
    Int operator++(){
        return Int(++value);
    }
    Int operator--(){
        return Int(--value);
    }
    Int operator+(const Int& b){
        return Int(value + b.value);
    }
    Int operator-(const Int& b){
        return Int(value - b.value);
    }
    Int operator+(const int b){
        return Int(value + b);
    }
    Int operator-(const int b){
        return Int(value - b);
    }
    Int operator%(const Int& b){
        return Int(value % b.value);
    }
    operator int() { // when Int is implicitly converted to int (only done during array accessing)
        arr_access_count++;
        return value;
    }
    friend std::ostream& operator<<(std::ostream& os, const Int& val);
    private:
        int value;
};
//----------------------------
//Helper functions
//----------------------------
std::ostream& operator<<(std::ostream& os, const Int& val){os << val.value; return os;};

inline void swap(Int& a, Int& b){
    Int t = a;
    a = b;
    b = t;
}
void PrintArray(Int* a, Int n){
    std::cout << "Arr: \n";
    for(int i = 0; i < n; ++i){
        std::cout << a[i] << " ";
    }
}
bool sorted(Int* a, int n){
    for(Int i = 0; i < n-1; ++i)
        if(a[i] > a[i+1])
            return false;
    return true;
}
//-------------------------------

//Sorting Algorithms
//-------------------------------
void InsertionSort(Int* a, Int n){
    Int key, i;
    for(Int j = 1; j < n; ++j){
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }
}
//--------------------------------
void SelectionSort(Int* a, Int n){
    Int smallest;
    for(Int j = 0; j < n-1; ++j){
        smallest = j;
        for(Int i = j+1; i < n; ++i){
            if(a[i] < a[smallest]){
                smallest = i;
            }
        }
        swap(a[j], a[smallest]);
    }
}
//---------------------------------------------
void BubbleSort(Int* a, Int n){
    for(Int i = 0; i < n; ++i){
        for(Int j = n-1; j > i; --j){
            if(a[j] < a[j-1]) swap(a[j], a[j-1]);
        }
    }
}
//--------------------------------------------
void merge(Int arr[], Int l, Int m, Int r) { 
    Int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;
    Int L[n1], R[n2]; 
    for (i = 0; i < n1; ++i) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; ++j) 
        R[j] = arr[m + 1+ j]; 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            ++i; 
        } 
        else{ 
            arr[k] = R[j]; 
            ++j; 
        } 
        ++k; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        ++i; 
        ++k; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        ++j; 
        ++k; 
    } 
} 
void MergeSort(Int* a, Int lo, Int hi){
    if(lo < hi){
        Int m = lo+(hi-lo)/2;
        MergeSort(a, lo, m);
        MergeSort(a, m+1, hi);
        merge(a, lo, m, hi);
    }
}
//-----------------------------------
Int Partition(Int* a, Int p, Int r) { 
    Int pivot = a[r];
    Int i = (p - 1);
    for (Int j = p; j < r; ++j) {
        if (a[j] <= pivot) { 
            ++i;
            swap(a[i], a[j]); 
        } 
    } 
    swap(a[i + 1], a[r]); 
    return (i + 1); 
}
Int R_Partition(Int* a, Int p, Int r){
    Int i = (Int(rand()) % (r-p)) + p;
    swap(a[i], a[p]);
    return Partition(a, p, r);
}
Int median_partition(Int a[], Int lo, Int hi){
    swap(a[(hi-lo)/2 + lo], a[lo]);
    return Partition(a, lo, hi);
}
Int min_partition(Int a[], Int lo, Int hi){
    return Partition(a, lo, hi);
}
void min_QSort(Int* a, Int p, Int r){
    if(p < r){
        Int q = min_partition(a, p, r);
        min_QSort(a, p, q - 1);
        min_QSort(a, q + 1, r);
    }
}
void med_QSort(Int* a, Int p, Int r){
    if(p < r){
        Int q = median_partition(a, p, r);
        med_QSort(a, p, q - 1);
        med_QSort(a, q + 1, r);
    }
}
void rand_QSort(Int* a, Int p, Int r){
    if(p < r){
        Int q = R_Partition(a, p, r);
        rand_QSort(a, p, q - 1);
        rand_QSort(a, q + 1, r);
    }
}
void QuickSort(Int* a, Int p, Int r, const char* type){
    if(type == "min")
        min_QSort(a, p, r);
    else if(type == "med")
        med_QSort(a, p, r);
    else if(type == "rand")
        rand_QSort(a, p, r);
    else exit(-1);
}
//--------------------------------------
void Max_Heapify(Int* a, Int i, Int n){
    Int l = 2*i+1;
    Int r = 2*i+2;
    Int largest = i;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i) {
        swap(a[i], a[largest]);
        Max_Heapify(a, largest, n);
    }
}
void HeapSort(Int* a, Int n){
   for(Int i = n/2 -1; i >= 0; --i){
       Max_Heapify(a, i, n);
   }
   for(Int i = n-1; i >= 0; --i){
       swap(a[0], a[i]);
       Max_Heapify(a, 0, i);
   }
}
//-------------------------------------
void Run_All(csvfile& outFile, int n, char op){
    srand(time(0));
    Int a[n], b[n];

    for(int i = 0; i < n; ++i)
        a[i] = rand() % 100 + 1; // fill a with random values

    switch(op){
        int i;
        case 'b':
            std::sort(a, a+n, [&](Int& a, Int& b){return a > b;}); // backwards sort
            break;
        case 's':
            std::sort(a, a+n); // regular sort
            break;
        case 'r':
            break; // keep randomized
        default:
            std::cout << "invalid argument passed\n";
            exit(-1);
    }

    //copy a to b so we can reuse a for all algorithms
    std::copy(a, a+n, b);

    comp_count = 0; // reset to zero since above setup will rack up some comparisons for insertionsort
    arr_access_count = 0;

    //Do Sorts and count Comparisons and record Time
    clock_t total;
    clock_t time = clock();
    InsertionSort(b, n);
    total = clock() - time;
    outFile << "InsertionSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    SelectionSort(b, n);
    total = clock() - time;
    outFile << "SelectionSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    BubbleSort(b, n);
    total = clock() - time;
    outFile << "BubbleSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    MergeSort(b, 0, n);
    total = clock() - time;
    outFile << "MergeSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    QuickSort(b, 0, n, "min");
    total = clock() - time;
    outFile << "Min_QuickSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    QuickSort(b, 0, n, "med");
    total = clock() - time;
    outFile << "Median_QuickSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    QuickSort(b, 0, n, "rand");
    total = clock() - time;
    outFile << "Random_QuickSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    std::copy(a, a+n, b);
    comp_count = 0;
    arr_access_count = 0;

    time = clock();
    HeapSort(b, n);
    total = clock() - time;
    outFile << "HeapSort" << n << comp_count << arr_access_count << (total * 1000 / CLOCKS_PER_SEC) << endrow;
    comp_count = 0;
    arr_access_count = 0;
}
int main(int argc, char** argv){

    //initialize csv file for output
    csvfile outFile("out.csv");
    std::string input = "r";
    char op;
    const int n = 5000;

    if(argc > 1){
        input = argv[1];
        op = input.c_str()[0];
    } else if(argc > 2){
        std::cout << "too many arguments\n";
        exit(-1);
    } else {
        std::cout << "choose input type (r=random, s=sorted, b=backwards):";
        std::cin >> op;
    }
    try{
        Int t[5] = {1,2,3,4,5};
        outFile << "Algorithm" << "Number" << "Comparisons" << "Accesses" << "Time(ms)" << endrow; // csv file column names
        for(int i = 100; i <= n; i+=100){
            Run_All(outFile, i, op);    // run all sorts, collecting efficiency data
        }
    } catch(std::exception& e){ // error handling
        std::cout << "error opening file " << e.what();
        return -1;
    }

    return 0;
}