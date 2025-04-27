// Custom Comparator

// It is a function or an object that is used to compare element
// Used to decide the order of elements inside a data structure(vector, set, map, heap)

// They can be implemented using:

// 1. Function Pointer : A function that that implements the logic of comparision.
// 2. Function Object(Functor) : An object that can be teated as a function.
// 3. Lambda expresion



/* ********************************************************************
01. Function Pointer
*********************************************************************** */

// example: sort();
// vector<int> vec = {3, 2, 1, 6}
// sort(vec.begin(), vec.end());
// {1, 2, 3, 6}

sort(vec.begin(), vec.end(), myComp);

// Ascending Order Sort
bool myComp(int a, int b)
{
    if(a < b)       // first element < second element
        return true;
    return false;
}

// Descending Order Sort
bool myComp(int a, int b)
{
    if(a > b)       // first element > second element
        return true;
    return false;
}

vector<pair<int, int>> vec = {{2, 3}, {2, 4}, {5, 4}, {3, 1}}

sort(vec.begin(), vec.end());

// Sort the pair in ascending order of first element,
// If first element is equal then accoeding to second
{{2, 3}, {2, 4}, {3, 1}, {5, 4}}


vector<pair<int, int>> arr = {{2, 3}, {2, 4}, {5, 4}, {3, 1}}

sort(arr.begin(), arr.end(), myComp)

// Sort in Descending Order of first element,
// If first element is same then desceding sort according to first descending
bool myComp(pair<int, int> p1,
            pair<int, int> p2)
{
    if(p1.first == p2.first) {
        if(p1.second > p2.second) {
            return true;
        }
        return false;
    }
    if(p1.first > p2.first) // Descending order of first element
        return true;
    return false;
}


/* ********************************************************************
02. Function Object (Functors)
*********************************************************************** */

vector<int> vec ={3, 2, 1, 6}

sort(vec.begin(), vec,end(), myComp())

class myComp {
    bool operator()(int a, int b) {
        if(a > b) 
            return true;
        return false;
    }
}



/* ********************************************************************
01. Function Pointer
*********************************************************************** */

vector<int> vec ={3, 2, 1, 6}

sort(vec.begin(), vec,end(), [](int a, int b){ 
                                     return a < b; //ascending order
                                }
);


[](int a, int b) {
    return a>b; // descending order
}










