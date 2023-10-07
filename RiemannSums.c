#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float RiemannSum(float upperBound,float lowerBound, int num); //Riemann sum function declaration
float TaylorSeries(float input, int num); //Taylor Series function declaration
float TaylorRiemann(float upperBound, float lowerBound, int num); //Taylor Series Riemann Sum function declaration

int main(){
    //declaring variables to be used within program
    float userLowerBound; //variable to store user input lower bound
    float userUpperBound; //variable to store user input upper bound
    int intervalNum5 = 5; //variable to be used in riemann sum and Taylor Series function for 5 intervals
    int intervalNum25 = 25; //variable to be used in riemann sum function for 25 intervals
    int intervalNum100 = 100; //variable to be used in riemann sum function for 100 intervals
    int intervalNum3 = 3; //variable to be used in Taylor Series function for 3 intervals
    int intervalNum10 = 10; //variable to be used in Taylor Series function for 10 intervals

    //While loop to ask user for bound inputs and check if bounds are valid
    while(1){
        printf("Enter the bounds to compute the Riemann Sum: ");
        scanf("%f %f",&userLowerBound, &userUpperBound);

        //if bounds are valid then break the loop, otherwise the user will be asked again
        if (userUpperBound > userLowerBound)
            break;
    }

    //print statements to show the riemann sums of the function for 5, 25, and 100 intervals. The arguments are the Riemann Sum function itself.
    printf("Riemann Sum with 5 intervals: %.2f\n", RiemannSum(userUpperBound, userLowerBound, intervalNum5));
    printf("Riemann Sum with 25 intervals: %.2f\n", RiemannSum(userUpperBound, userLowerBound, intervalNum25));
    printf("Riemann Sum with 100 intervals: %.2f\n", RiemannSum(userUpperBound, userLowerBound, intervalNum100));

    //print statements to show the Taylor Series approximation of the function for 3, 5, and 10 terms. The arguments are the Taylor Series function itself.
    printf("Taylor Series Approximation at x = %.2f with 3 terms: %.2f\n", userLowerBound, TaylorSeries(userLowerBound, intervalNum3));
    printf("Taylor Series Approximation at x = %.2f with 5 terms: %.2f\n", userLowerBound, TaylorSeries(userLowerBound, intervalNum5));
    printf("Taylor Series Approximation at x = %.2f with 10 terms: %.2f\n", userLowerBound, TaylorSeries(userLowerBound, intervalNum10));

    //print statements to show the Taylor Series Riemann sum of the function for 5, 25, and 100 intervals. The argument is the function itself.
    printf("Taylor Series Riemann Sum with 5 intervals: %.2f\n", TaylorRiemann(userUpperBound, userLowerBound, intervalNum5));
    printf("Taylor Series Riemann Sum with 25 intervals: %.2f\n", TaylorRiemann(userUpperBound, userLowerBound, intervalNum25));
    printf("Taylor Series Riemann Sum with 100 intervals: %.2f\n", TaylorRiemann(userUpperBound, userLowerBound, intervalNum100));

    //print statements to show the error in the riemann sums. The calculation of the error is done within the print statement.
    printf("Error in Riemann Sums with 5 intervals: %.2f%%\n", ((TaylorRiemann(userUpperBound, userLowerBound, intervalNum5) - RiemannSum(userUpperBound, userLowerBound, intervalNum5)) / RiemannSum(userUpperBound, userLowerBound, intervalNum5))*100);
    printf("Error in Riemann Sums with 25 intervals: %.2f%%\n", ((TaylorRiemann(userUpperBound, userLowerBound, intervalNum25) - RiemannSum(userUpperBound, userLowerBound, intervalNum25)) / RiemannSum(userUpperBound, userLowerBound, intervalNum25))*100);
    printf("Error in Riemann Sums with 100 intervals: %.2f%%\n", ((TaylorRiemann(userUpperBound, userLowerBound, intervalNum100) - RiemannSum(userUpperBound, userLowerBound, intervalNum100)) / RiemannSum(userUpperBound, userLowerBound, intervalNum100))*100);
}

//Riemann sum definition
float RiemannSum(float upperBound,float lowerBound, int num){
    float width = (upperBound - lowerBound)/num; //calculating width of each rectangle
    float sum = 0; //setting sum initially to 0
    //for loop to iterate through each rectangle on the function
    for(int i = 0; i < num; i += 1){
        sum += width*(exp(pow(lowerBound+(width*(i)), 2))); //calculating the area (width*height)
    }
    return sum;
}

//Taylor Series definition
float TaylorSeries(float input, int num){
    float sum = 0; //setting sum to initially 0
    for(int i = 0; i < num; i++){ //for loop to iterate through each element of the taylor series
        int factorial = 1; //setting the factorial term initially to 1
        for(int j = i; j > 0; j--){ //for loop to calculate the factorial term
            if(j != 0) {
                factorial *= j;
            }
        }
        sum += pow(pow(input, 2), i) / factorial; //calculating the taylor series using the given equation
    }
    return sum;
}

//Taylor Series Riemann Sum definition
float TaylorRiemann(float upperBound, float lowerBound, int num){
    float width = (upperBound - lowerBound)/num; //calculating the width
    float sum = 0; //setting sum initially to 0
    for(int i = 0; i < num; i += 1){ //for loop to iterate through each rectangle
        float temp = TaylorSeries(lowerBound+(width*(i)), 10); //temp variable stores the taylor series approximation of the function at each interval
        sum += width*temp; //calculating the final sum by multiplying the temp variable by the width
    }
    return sum;
}

//I attest to the originality of my work

