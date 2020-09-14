#include <iostream>
#include <vector>



void sort (std::vector<int> & vec);



int main() {
    std::cout <<"\n\n<------------------ INICIAL ----------------------->";

    std::cout <<"\n\n<-- sort Algorithm -->";
    std::vector vectorData{57,78,34,45};

     //  GETING STARTING TIME
        int tstart = clock();


    //  SHOWING THE ORIGINAL VECTOR
        std::cout << "\nOutput of begin and end: \n"; 
        for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
            std::cout << *i << " "; 

        std::cout << "\n\n";
    

    //  APPLYING quickSort ALGORITHM FOR SORTING THE VECTOR
        sort(vectorData);


    //  SHOWING THE TIME ELAPSED AFTER APPLY MERGE SORT
        int endTime = clock();
        double etime = (endTime - tstart) / (double) CLOCKS_PER_SEC;
        std::cout << "TIME ELAPSED : "<< etime ;

    //  SHOWING THE VECTOR AFTER APPLY THE ALGORITHM
        std::cout << "\nOutput after sort Algorithms was apply : \n"; 
        for (auto i = vectorData.begin();  i != vectorData.end();  ++i) 
            std::cout << *i << " "; 

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