#include <iostream>
#include <stddef.h>
#include <vector>

/*

   <@
   (KU//
    "
BY LUCAS FRIAS
3195413 
EECS 210
LAB 06
TITLE: BINOMIAL THEOREM
DESC: IMPLEMENT THE BINOMIAL EXPANSION
OF EVERY TERM IN A STATEMENT IN THE FORMAT
(X+Y)^N.

EXAMPLE: 

(x+y)^3:
    x^3 + 3x^2y + 3xy^2 + y^3

*/


//tldr, we just gonna calculate pascal triangle
//this is badly commented and coded


//https://www.geeksforgeeks.org/cpp/cpp-program-to-find-factorial-of-a-number/
// ^^ this is what i used to do the factorial


int factorial (int n){

    //factorial function
    
    int res = 1, i;
    //return this bull i understand but like come on dawg
    //we're just trying to be fancy
    //multiply x many times iteratvely
    //we start at 2 so that we can go and get the value
    //from each loop
    for (i = 2; i <= n; i++) res *= i;
    return res;

}

static inline int nk_permutation(int n, int k){
        //nk_permutation: given a n/k, calculates the 
        //factorial combination:
        //   n!
        // ------
        // k!(n-k)!
        //assumes good input

        //juyst the equation given from the user input
        return ( factorial(n) ) / (factorial(k) * factorial(n-k));
} 


class PascalTriangle{
    public:

        std::vector<int> rung;            
        std::size_t length;
        PascalTriangle(std::size_t n) {
            //in our initaliser, we need to make
            //our array the size of pascals triangle
            //just on that row we need to
            length = n + 1;

            //a cleverer lucas would use an array
            //but a safer lucas (me) will use a vec
            for (std::size_t k = 0; k < n; k++){
                rung.push_back(nk_permutation(n, k));
            } 
            //for some reason, this loop doesn't calculate the 
            //last element in the rung but it's always 1 so

            rung.push_back(1);
        }

        void display(){
            //just a debug display function
            for (size_t i = 0; i < length; i++){
                std::cout << rung[i] << " ";
            }
            std::cout << std::endl;

        }
        
        int get_coefficient(size_t i){
            //public method for public data to just get the rung
            return rung[i];
        }

};

int main(){
   
    //declare out expansion size and user input 
    std::size_t expansion_size;    
    std::string user_in;
    std::cout << "Input your polynomial: ";
    //input into the polynomail
    std::cin >> user_in;
   
    //c++ messing around with this string parsing
    //stuff sucks so we will do it ourself
    const char * user_in_cstr = user_in.c_str();
    bool found_match = false; //if the string is bad this will be false
 
    while (*user_in_cstr != '\0'){
        //if the user_in_cstr is ^ then we know the next char will be it
        if (*user_in_cstr == '^'){
            found_match = true;
            user_in_cstr++;
            //increment up

            //magic number, just converting a string to a number
            //first we have to check if in range and err out if not
            if (*user_in_cstr < '2' || *user_in_cstr > '8'){std::cout << "Bad input\n2 <= n <= 8\n"; exit(1);}
            expansion_size = *user_in_cstr - 48; //we subtract with '0' (48) to get the size
            break;
        }
        user_in_cstr++; //increment the piinter
    }

    if (!found_match){std::cout << "\nError bad string\n"; exit(1);} //err out with bad str

    //lets make a triangle based off of user input
    PascalTriangle my_triangle = PascalTriangle(expansion_size);

    //time to calculate every single thingamijig
    std::cout << std::endl;

    //now we iterate through the triangle
    for (size_t i = 0; i < my_triangle.length; i++){
        //calculate the interger coeff by accessing its value 
        int coeff = my_triangle.get_coefficient(i);

        //if the coeff is 1 we don't need to display it
        if (coeff != 1) std::cout << coeff;
        //if the power is 0 then x^0 = 1 and we don't need to show it
        if (my_triangle.length - i -1 != 0) std::cout << "x";
        //same with the power if it's ^1 because it's pretty useless
        if (my_triangle.length - i -1 > 1) std::cout << "^" << my_triangle.length-i-1;
    
        //and this is the same thing but with the y power in the expansion
        if (i != 0) std::cout << "y";
        if (i > 1) std::cout << "^" << i;
        
        //display + charcaters for every one except for the last and then error out
        if (i != my_triangle.length-1) std::cout << " + ";
        else std::cout << std::endl;
    }  
    return 0;
}
