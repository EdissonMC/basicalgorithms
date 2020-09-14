#include<iostream>
#include<fstream>
#include<set>

template <typename InputIterator, typename Type> inline Type accumulate(InputIterator start, InputIterator stop, Type initial); 

int main(){

    std::ifstream input("data.txt");
    std::multiset<int> values;

    int currValue;
    /* Read the data from the file */
    while (input>> currValue) {
        values.insert(currValue);
    }
    
    
    std::cout<< "promedio general"<<std::endl;
    std::cout << accumulate(values.begin(),   values.end(),  0.0 ) / values.size() << std::endl;

    
    std::cout<< "suma de numeros en el rango (40 70) "<<std::endl;
    std::cout << accumulate(values.lower_bound(40),   values.upper_bound(70),  0.0 )  << std::endl;


}





template <typename InputIterator, typename Type> inline
Type accumulate(InputIterator start, InputIterator stop, Type initial) {
    while(start != stop) { 
        initial += *start;
        ++start; 
    }
        return initial;
}
