//***************************************************************************
//                          Project #1 - Simple Genetic Algorithm
//                              Name:  Samuel Weems
//                           Course:  CMPS 5463, Fall 2018
//                         Professor: Dr. Richard P. Simpson
//                              Date: September 10 2018
//***************************************************************************
//                                  Introduction
//
//  In this project we wrote a simple genetic algorithm to evolve a string
//  of all ones using the standard template library bitset to hold the
//  bits of the chromoroms. The chromosome crossover was performed with a
//  one point crossover algorithm and a roulette proportional selection
//  algorithm was used for selecting parents. Fitness of each generation
//  is the sum of the bits in the chromosome with the optimal fitness
//  being all ones and thus the sum of those or the length of the chromosome.
//  1000 iterations or generations are run or the program stops earlier
//  if the optimal fitness is found in a generation
//
//***************************************************************************
//                              Program Complexity
//                                  O(n) or O(n^2)
//
//  The program's overall complexity is based on the most complex section
//  of code which is the mutation which has a nested loop. The outer loop
//  is the number of chromosomes and the inner loop is the length of each
//  chromosome. In a worst case of both number of chromosomes and the
//  the length of each chromosome increasing the complexity is O(n^2).
//  In the case that just the length of the chromosome is increasing as
//  in the assignment then the complexity is just O(n).
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************

#include <iostream>
#include <bitset>
#include <time.h>

#define CHROMOSOME_POPULATION_SIZE 50   // Must be an Even Number
#define CHROMOSOME_LENGTH 60
#define OPTIMAL_FITNESS 60
#define NUMBER_ITERATIONS 100000
#define CROSSOVER_PROBABILITY 0.5
#define MUTATION_PROBABILITY 0.001

using namespace std;

int main() {

// Initial Setup
    
    double generation_average_fitness[NUMBER_ITERATIONS] = {0}; // Average fitness of a generation
    bitset<CHROMOSOME_LENGTH> chromosome_array[CHROMOSOME_POPULATION_SIZE]; // Current population
   
    bool optimal_fitness_found = false;     // Flag for optimal fitness
    int number_generations = 0;             // Number of Generations counter
    int optimal_chromosome_location = -1;   // Location of optimal chromosome (set to -1 for debugging)
    
    srand(time(NULL));  // Seed Random Number Generator with time
    
    for (int i = 0; i < CHROMOSOME_POPULATION_SIZE; i++){   // Create Initial Population
        for (int j= 0; j < CHROMOSOME_LENGTH; j++){
            chromosome_array[i][j] = rand()%2;}} // Random 1 or 0 for each bit

// Perform Genetic Algorithm for set iterations or until optimal fitness found
    
    for (int i =0; i< NUMBER_ITERATIONS; ++i){
    
        int fitness_array[CHROMOSOME_POPULATION_SIZE] = {0};    // Fitness of each individual in a generation
        double generation_fitness_sum = 0; // Sum of fitness values for a generation
        ++ number_generations;   // Increment generation counter

        // Calculate the fitness of each Member

        for (int j=0; j<CHROMOSOME_POPULATION_SIZE; j++){
            fitness_array[j] = chromosome_array[j].count(); // Sum the 1 bits
            generation_fitness_sum += fitness_array[j]; // Sum for Average Fitness Calculation and Parent Selection
            if (fitness_array[j] == OPTIMAL_FITNESS){   // Set Flag if Optimum Fitness found in this generation
                optimal_fitness_found = true;
                optimal_chromosome_location = j;
            }
        }

        generation_average_fitness[i] = generation_fitness_sum/CHROMOSOME_POPULATION_SIZE; // Calculate Average Fitness of this generation
    
        if (optimal_fitness_found)  // Break out of loop if optimal fitness found
            break;
  
    
        // Select Parents from current population
        //      Probability is an increasing function of fitness
        //      Roulette Wheel Sampling aka Fitness Proportionate Selection
        //      https://en.wikipedia.org/wiki/Fitness_proportionate_selection
        
        double previous_probability = 0.0;
        int chosen_parents[CHROMOSOME_POPULATION_SIZE] = {0}; // Parents selected from Current population
        double parent_probability[CHROMOSOME_POPULATION_SIZE] = {0}; // Probabilities for selecting parents
        
        for (int j=0; j < CHROMOSOME_POPULATION_SIZE; j++){     // Determine probabilities for selection process
            parent_probability[j] = previous_probability = previous_probability + (fitness_array[j] / generation_fitness_sum);}
        
        for (int j=0; j < CHROMOSOME_POPULATION_SIZE; j++){   // Choose Parents to create next generation
            double probability = ((double) rand() / (RAND_MAX)); // Random Number between 0.0 and 1.0 for selection
        
            if ((probability >= 0) && (probability <= parent_probability[0])) // First Case Exception
                chosen_parents[j] = 0;
            else{
                for (int k =0; k < CHROMOSOME_POPULATION_SIZE-1; k++){ // Find location of given probability in parent_probability array
                    if ((probability > parent_probability[k]) && (probability <= parent_probability[k+1]))
                        chosen_parents[j] = k+1;}}}
        
        // Perform One-Point Crossover and create OffSpring
        // https://en.wikipedia.org/wiki/Crossover_%28genetic_algorithm%29
        // 80% probabilty of Crossover occuring
        // 2 Children created from every 2 Parents
        
        bitset<CHROMOSOME_LENGTH> temp_chromosome_array[CHROMOSOME_POPULATION_SIZE]; // Temporary array for children
        for (int j= 0; j<CHROMOSOME_POPULATION_SIZE; ++j){temp_chromosome_array[j] = chromosome_array[j];} // Copy array
        
        for (int j=0; j<CHROMOSOME_POPULATION_SIZE/2; ++j)
        {
            double probability = ((double) rand() / (RAND_MAX)); // Random probability for crossover
            
            if (probability <= CROSSOVER_PROBABILITY){  // Perform Crossover
            
                int crossover_point = rand() % CHROMOSOME_LENGTH; // Choose single point for crossover 0 -> chromosome size
                for (int k = 0; k < crossover_point; ++k){
                    chromosome_array[j][k] = temp_chromosome_array[chosen_parents[j]][k]; // Child 1
                    chromosome_array[j+CHROMOSOME_POPULATION_SIZE/2][k] = temp_chromosome_array[chosen_parents[j+CHROMOSOME_POPULATION_SIZE/2]][k]; // Child 2
                }
                for (int k = crossover_point; k < CHROMOSOME_LENGTH; ++k){ // Second Parent
                    chromosome_array[j][k] = temp_chromosome_array[chosen_parents[j+CHROMOSOME_POPULATION_SIZE/2]][k]; // Child 1
                    chromosome_array[j+CHROMOSOME_POPULATION_SIZE/2][k] =  temp_chromosome_array[chosen_parents[j]][k]; // Child 2
                }
            }
            else {  // If no Crossover then clone selected parents
                chromosome_array[j] = temp_chromosome_array[chosen_parents[j]]; // Child 1
                chromosome_array[j+CHROMOSOME_POPULATION_SIZE/2] = temp_chromosome_array[chosen_parents[j+CHROMOSOME_POPULATION_SIZE/2]]; // Child 2
            }
        }
        
        // Mutate the new population
        
        for (int j = 0; j < CHROMOSOME_POPULATION_SIZE; j++){
            for (int k= 0; k < CHROMOSOME_LENGTH; k++){
                double probability = ((double) rand() / (RAND_MAX)); // Random probability for mutation chance
                if (probability <= MUTATION_PROBABILITY)
                    chromosome_array[j][k].flip();
            }
            
        }
    }
    

  // Output Average Fitness for each generation used for report
//
//    for (int i=0; i < number_generations; ++i){
//        cout  << generation_average_fitness[i] << endl;
//    }
//
    // Assignment Required Output
    
    if (optimal_fitness_found){
        cout << endl << "Optimal Chromosome: " << chromosome_array[optimal_chromosome_location] << endl;
        cout << "Generation Discovered: " << number_generations << endl;}
    else cout << endl << "Optimal Chromosome Not Found" << endl ;

//    cout << "Entire Population in final generation:" << endl;
//
//    for (int i =0; i < CHROMOSOME_POPULATION_SIZE; ++i){
//        cout << chromosome_array[i] << endl;
//    }

    return 0;
    
}
