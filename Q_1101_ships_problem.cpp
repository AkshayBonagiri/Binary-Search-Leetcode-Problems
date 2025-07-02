#include <iostream>
#include <vector>

int main(){
    
    
    std::vector<int> weights = {1,2,3,4,5,6,7,8,9,10};          //INPUT
    int days = 5;                                               //INPUT


    int min = INT_MIN;                                          //minimum weight required 
    int max = 0;                                                //maximum weight required
    int size = weights.size();
    int capacity;
    for(int i : weights){                                       //finding min and max using a for loop
        if(i > min){
            min = i;
        }
        max = max + i;
    }
    while(min<=max){                                            //Binary search
        int days_no = 1;
        int current_weight = 0;
        int capacity = min + (max - min)/2;
        for(int w : weights){
            if(current_weight + w <= capacity){
            current_weight = current_weight + w;
            }
            else{
            days_no++;
            current_weight = w;
        }

        }
            
        if(days_no > days){
            min = capacity + 1;
        } else {

            max = capacity - 1;
        }
    }
    std::cout << "Answer: " << min << std::endl;            //displaying the answer
    return 0;
}