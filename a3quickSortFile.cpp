#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

/*
    ESTE PROGRAMA IMPLEMENTA EL ALGORITMO DE ORGANIZACION QUICKSORT
    USANDO RECURSIVIDAD.

*/


void quicksort (std::vector<int> &vec, int start, int finish);
int partition (std::vector<int> &vec,  int start, int finish);

void fillingVector(std::vector<int> & vec);

int main () {
        
        std::cout <<"\n\n<------------------ INICIAL ----------------------->";

        std::cout <<"\n\n<-- quicSort  Algorithm -->";

  

        std::vector<int> vectorData;

    //  FILLING A VECTOR WITH DATA FROM A FILE
        fillingVector(vectorData);

    //  GETING STARTING TIME
        int tstart = clock();


    //  SHOWING THE ORIGINAL VECTOR
        // std::cout << "\nOutput of begin and end: \n"; 
        // for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
        //     std::cout << *i << " "; 

        std::cout << "\n\n";
    

    //  APPLYING quickSort ALGORITHM FOR SORTING THE VECTOR
        quicksort (vectorData, 0,  vectorData.size() -1 );



 //  SHOWING THE TIME ELAPSED AFTER APPLY MERGE SORT
        int endTime = clock();
        double etime = (endTime - tstart) / (double) CLOCKS_PER_SEC;
        std::cout << "TIME ELAPSED : "<< etime ;

    //  SHOWING THE VECTOR AFTER APPLY THE ALGORITHM
        // std::cout << "\nOutput after mergeSort : \n"; 
        // for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
        //     std::cout << *i << " "; 

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





void fillingVector(std::vector<int> & vec) {

    std::cout <<"<------ FILLING A VECTOR ------> \n";

    // NAME OF THE FILES TO LOAD
    
   // std::string fileName1= "Numbers1000.txt";
    std::string fileName1= "Numbers50mil.txt";           // 0.013364 seg
    // std::string fileName1= "Numbers100mil.txt";       // 0.027 seg
    // std::string fileName1= "Numbers1million.txt";     // 0.308 seg
    // std::string fileName1= "Numbers10million.txt";    // 4 seg



    std::ifstream inFile;
    inFile.open(fileName1);

    if(inFile.fail()){
        std::cout << "\nCould not open the file." << std::endl;
        return ;
    }

    int number =0;

    while ( inFile >> number )
    {   
        vec.push_back(number);
       // std::cout <<number << std::endl;
    }

}