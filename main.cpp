// Question 1 Install g tests and add to cmakes lists
#include "gtest/gtest.h"
#include <thread>
#include <cmath> 
#include <mutex>

std::mutex myMutex;
const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof values / sizeof(int);
void function(char(*ptr)[4]);
void fn(const int** pp);

template <typename T>
struct ptr_holder {
    static_assert(std::is_same_v<T, std::remove_pointer<T>>); 
    //if T is not a pointer, remove_pointer returns exactly the same as T
};

int total = 0;

class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0) {}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
        //use lock_guard to avoid multiple thread accessing this function at the same time
        std::lock_guard<std::mutex> guard(myMutex);
        mMoney += money;       //instead of doing multiple steps, reduce the duplicated operation loops
    }
};

class Foo {
    int A;
    Wallet* B;
public:
    Foo(int a, Wallet* b = NULL){
        A = a;
        B = b;
    };
};


struct person{
    int age;
    float weight;
};

int testerFunction()
{
    Wallet walletObject;
    std::vector<std::thread> threads; //create a vector of threads
    for (int i = 0; i < 5; ++i) { // create a series of threads of walletObject and push to threads
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }//do multiple operations together to catch the race condition
    for (long unsigned int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}


int main()
{
    // Question 2
    int x = 10;
    int y = 15;
    std::cout << " (" << x <<','<< y <<")" << std::endl;//missed one std::, but the (x,y) is not an ideal way to print x and y
                                            //so I adapted that too

    // Question 3 Get the function to run
    char arr[6][4] = { "ant", "bat", "cat", "dog", "egg", "fly" };
    char(*arr_ptr)[4] = arr;      //a pointer pointing to 6 * (arrays of 4 char)
    function(arr_ptr);


    // Question 4 Insert in map
    typedef std::map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++)
        m.insert(std::make_pair(values[i], pow(values[i], .5)));
    /*valmap::iterator it = 100;
    valmap::iterator it2(100);*/

    //I just assume this idea is initializing two iterators and call insert(InputIterator first, InputIterator last)
    valmap::iterator it = m.begin();         
    valmap::iterator it2(m.end());
    //m.insert(1, 2);
    m.insert(it, it2);

    // Question 5
    int i = 1, j = 1;
    if ((i != 3) && (j == 1))       //solved syntax error = ! to !=
    {
        std::cout << "inside if statement\n";
    }

    // Question 6 Store a char * pointer in template
    ptr_holder<char *> *p;

    // Question 7 Fix the compiler errors and race conditions
    // Convert the testerFunction() into a google test
    int val = 0;
    for (int k = 0; k < 1000; k++)        //changed iteration times to 5000, to easier catch race condition
    {
        if ((val = testerFunction()) != 5000)
        {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
            return 1;
        }
    }
    // Question 8
    const int n = 1;
    const int* p_ptr = &n;    //solved the collision of variable name (p -> p_ptr)
    fn(&p_ptr);

    // Question 9
    struct person* ptr;
    ptr = (struct person*)malloc(sizeof(struct person));  //ptr = (struct person*)malloc(sizeof(struct person));
    ptr->age = 10;
    ptr->weight = 55.5;

    // Question 10 Initialise foo
    Wallet wallet;
    Foo foo(1,NULL);    //since this instance is not used in the program, there's no need to create a wallet instance

    // Question 11
    /*char c;
    while (c = getchar() == EOF)
    {
        putchar(c);
    }*/
    char c;
    //assume this loop is to print all the character get until reaching end of file
    c = getchar();
    while (c != EOF)
    {
        c = getchar();
        putchar(c);
    }

    delete ptr;
    return 0;

}

// Do not change anything besides the ptr variable
void function(char(*ptr)[4])
{
    char* ptr1;
    ptr1 = (ptr += sizeof(int))[-2]; //size of int is 4 times size of char, equal to ptr[2], the pointer pointing to first element of "cat"
    printf("%s\n", ptr1);
}

void fn(const int** pp)
{
    printf("%p : %p : %d", (void *)pp, (void *)*pp, **pp);
}

// Fix any compilation error
/*class Foo {
public:
    Foo(int a, Wallet* b = NULL);
};*/
