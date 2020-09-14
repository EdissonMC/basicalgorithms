#include <iostream>
#include <vector>

/*
    ESTE PROGRAMA IMPLEMENTA EL ALGORITMO DE ORGANIZACION QUICKSORT
    USANDO RECURSIVIDAD.

*/

int main () {
    std::vector vec{57,78,34,45};
    quicksort (vec, 0,  vec.size() -1 );
    return 0;
}




/*

    Function : sort
    _______________
    This function sorts the elements of the vector into
    increasing numerical order using the Quicksort algorithm
    In this implementation, sort is a wrapper function that
    calls quicksort to do all the work.

*/

void quicksort (std::vector<int> &vec, int start, int finish) {

    if(start >= finish)  return;

    int boundary = partition (vec, start, finish);

    quicksort (vec,  start,         boundary -1);
    quicksort (vec,  boundary +1 ,  finish);


}


int partition (std::vector<int> &vec,  int start, int finish) {

    int pivot  = vec[start];   // SELECTING THE PIVOT NUMBER

    int ln = start  + 1 ;      // LEFT NUMBER
    int rn = finish;           // RIGHT NUMBER

    while (true) {

        while (ln < rn  &&  vec[rn] >= pivot)  rn--;
        while (ln < rn  &&  vec[ln] <  pivot)  ln++;
        
        if(ln == rn) break;

        int tmp = vec[ln];
        
        vec[ln] = vec[rn];
        vec[rn] = tmp;
    }

    if (vec[ln] >= pivot) return start;
    vec[start] = vec[ln];
    vec[ln] = pivot;

    return ln;
}