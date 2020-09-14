#include <iostream>
#include <vector>
#include <fstream>



void sort (std::vector<int> & vec);
void fillingVector(std::vector<int> & vec);


int main() {
    std::cout <<"\n\n<------------------ INICIAL ----------------------->";

    std::cout <<"\n\n<-- sort Algorithm -->";
        
    //  DEFFING A VECTOR
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
        sort(vectorData);


    //  SHOWING THE TIME ELAPSED AFTER APPLY MERGE SORT
        int endTime = clock();
        double etime = (endTime - tstart) / (double) CLOCKS_PER_SEC;
        std::cout << "TIME ELAPSED : "<< etime ;

    //  SHOWING THE VECTOR AFTER APPLY THE ALGORITHM
        // std::cout << "\nOutput after sort Algorithms was apply : \n"; 
        // for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
        //     std::cout << *i << " "; 

    return 0;
}

void sort (std::vector<int> & vec) {

    int n = vec.size();

    for (int ln =0; ln < n; ln++) {
        int rn = ln;

        for (int i= ln+1; i < n; i++) {
            if (vec[i] < vec[rn]) rn =i;
        }
        
        int tmp = vec[ln];
        vec[ln] = vec[rn];
        vec[rn] = tmp;
    }
}






void fillingVector(std::vector<int> & vec) {

    std::cout <<"<------ FILLING A VECTOR ------> \n";

    // NAME OF THE FILES TO LOAD
    
    //std::string fileName1= "Numbers1000.txt";       // 0.003775 seg
    std::string fileName1= "Numbers50mil.txt";         // 7.5325 seg
    // std::string fileName1= "Numbers100mil.txt";      
    // std::string fileName1= "Numbers1million.txt";    
    // std::string fileName1= "Numbers10million.txt";   



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