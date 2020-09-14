#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

/*
    
    ESTE PROGRAMA IMPLEMENTA EL ALGORITMO MERGE SORT HACIENDO USO DE LA RECURSIVIDAD
    THIS PROGRAM IMPLEMENTS THE MERGE SORT ALGORITHM MAKING USE OF RESURSIVITY

*/



void sort(std::vector<int> & vec );
void merge(std::vector<int> &vec,   std::vector<int> & v1,  std::vector<int> & v2);
void fillingVector(std::vector<int> & vec);


int main () {
   
    
    std::cout <<"\n\n<------------------ INICIAL ----------------------->";

    std::cout <<"\n\n<-- merge sort  Algorithm -->";

    std::vector<int> vectorData{56,25,37,58,95,19,75,30,7,15};
    fillingVector(vectorData); 



    //  Initialitation a clock
        int tstart = clock();

    //  SHOWING THE ORIGINAL VECTOR
        // std::cout << "\nOutput of begin and end: \n"; 
        // for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
        //     std::cout << *i << " "; 

        std::cout << "\n\n";
    

    //  SORTING VECTOR
        sort(vectorData);

    //  SHOWING THE TIME ELAPSED AFTER APPLY MERGE SORT
        int endTime = clock();
        double etime = (endTime - tstart) / (double) CLOCKS_PER_SEC;
        std::cout << "TIME ELAPSED : "<< etime ;

    //  SHOWING THE VECTOR AFTER APPLY THE ALGORITHM
        // std::cout << "\nOutput after mergeSort : \n"; 
        // for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
        //     std::cout << *i << " "; 

        std::cout << "\n\n";

    return 0;
}






/*

    This function sorts the elements of the vector into increasing order using the merge sort algorithm ,
    which consists of the follogin steps:

    1. Divide the vector into two halves
    2. Sort each of these smaller vectors recursively.
    3. Merge the two vectors back into the original one.

*/
    int contador=0 ;    
    void sort(std::vector<int> & vec ) {

        contador++;

        int n = vec.size();
        if(n <= 1) return ;

        std::vector<int> v1;
        std::vector<int> v2;
        
        for(int i= 0; i < n; i++) {

            if(i < n/2) {
                v1.push_back(vec[i]);
            }else {
                v2.push_back(vec[i]);
            }

        }

        sort(v1);
        sort(v2);
        vec.clear();
        merge(vec, v1, v2);

    }
//  End sort(std::vector<int> & vec ) 







/*
    FUNCTION : MERGE
    ________________
    This function merges two sorted vectors, v1 and v2,  into  the vector vec,
    wich should be empty before this operation. Because the input vectors are sorted, 
    the implementation can always select the first unused element in one of the input vectors to fill the next position.

*/
//  MERGE
    void merge(std::vector<int> &vec,   std::vector<int> & v1,  std::vector<int> & v2) {

        int n1 = v1.size();
        int n2 = v2.size();

        int p1 = 0;
        int p2 = 0;

        while (p1 < n1 && p2 <n2) {
            if(v1[p1] < v2[p2]) {
                vec.push_back(v1[p1++]);
            }else {
                vec.push_back(v2[p2++]);
            }
        } 

        while(p1 < n1) vec.push_back(v1[p1++]);
        while(p2 < n2) vec.push_back(v2[p2++]);

    }
//  END MERGE






void fillingVector(std::vector<int> & vec) {

    std::cout <<"<------ FILLING A VECTOR ------> \n";

    // NAME OF THE FILES TO LOAD
    
    //std::string fileName1= "Numbers50mil.txt";
    //std::string fileName1= "Numbers100mil.txt";
    std::string fileName1= "Numbers1million.txt";


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