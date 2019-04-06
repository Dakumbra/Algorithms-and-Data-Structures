//***************************************************************************
//                        Project #2 - Particle Swarm Optimization
//                              Name:  Samuel Weems
//                           Course:  CMPS 5463, Fall 2018
//                         Professor: Dr. Richard P. Simpson
//                              Date: October 08, 2018
//***************************************************************************
//                                  Introduction
//
// In this project we wrote a particle swarm algorithm to optimize the
// Schwefel function. A full description of the function can be found
// at https://www.sfu.ca/~ssurjano/schwef.html. The answer to this complex
// function is located at ~420.9687 for each dimension. This algorithm creates
// particles (20) with various dimension values ranging from -500 to 500 and
// random velocities in the range of -1 to 1. The particles new velocities
// are calculated based on their best locations and the group's overall best
// location. The best locations, or best fitness, are the ones that yield
// a result to the Schwefel function closest to 0. This algorithm is run
// for 1000 interations or generations.
//
//***************************************************************************
//                              Program Complexity
//                            O(n) or O(n^2) or O(n^3)
//
//  The program's overall complexity is based on the most complex section
//  of code which is the reoccuring nested looping that goes through
//  each generation, particle, and dimensions of those particles. The more
//  generations, particles, and dimensions the more time complexity increases.
//  If one of these factors are changed, for example increasing the number of
//  particles each run, then the complexity would only increase by O(n).
//  If two of these factors are increased each time then the complexity would
//  increase by O(n^2). If all three factors were increased each time the
//  program was run then the complexity is O(n^3).
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************


#define NUMBER_DIMENSIONS 2
#define NUMBER_GENERATIONS 1000
#define NUMBER_PARTICLES 40
#define C0 1
#define C1 2
#define C2 2
#define INITIAL_VELOCITY_RANGE 1
#define LOCATION_RANGE 500
#define VELOCITY_RANGE 20

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>

using namespace std;

// Function Prototype

double calculateParticleFitness(const vector<double> &location);

// Main Program Function

int main() {
    
// Program Data Structures
// 1. Particle Velocities holds current velocity of particle
// 2. Particle Locations holds current position of particle in matrix
// 3. Particle Best Location holds local particle best personal location in matrix
// 4. Particle Best Fitness holds local particle best personal fitness value
// 5. Generation Global Best Fitness holds global best fitness for each generation
// 6. Generation Global Best Location holds best fitness location for each generation in matrix
    
vector<vector<double>> particle_velocities(NUMBER_PARTICLES, vector<double>(NUMBER_DIMENSIONS));
vector<vector<double>> particle_locations(NUMBER_PARTICLES, vector<double>(NUMBER_DIMENSIONS));
vector<vector<double>> particle_best_location(NUMBER_PARTICLES, vector<double>(NUMBER_DIMENSIONS));
vector<double> particle_best_fitness(NUMBER_PARTICLES);
vector<double> generation_global_best_fitness(NUMBER_GENERATIONS);
vector<vector<double>> generation_global_best_location(NUMBER_GENERATIONS, vector<double>(NUMBER_DIMENSIONS));
    
// Random Number Generation Setup
    
default_random_engine random_number_generator;
random_device randomDevice{}; // Used to obtain seed for generator
random_number_generator.seed(randomDevice()); // Generates random sets of random numbers each run
    
// Random Number Distribution ranges
    
uniform_real_distribution<double> random_velocity_range{-INITIAL_VELOCITY_RANGE, INITIAL_VELOCITY_RANGE};
uniform_real_distribution<double> random_location_range{-LOCATION_RANGE, LOCATION_RANGE};
uniform_real_distribution<double> random_weight_range{0,1};
    
// Initialize Particles
    
for (int particle_number = 0; particle_number < NUMBER_PARTICLES; ++particle_number){
    for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
    
        // 1. Set initial velocity to random value in initial velocity range
        particle_velocities[particle_number][dimension] = random_velocity_range(random_number_generator);
        
        // 2. Set initial location to random value in initial location range
        // 3. Set initial location as particle personal best location
        particle_locations[particle_number][dimension] = particle_best_location[particle_number][dimension] = random_location_range(random_number_generator);
    }
        
    // 4. Calculate and set initial particle personal best fitness
    particle_best_fitness[particle_number] = calculateParticleFitness(particle_locations[particle_number]);
}
    
// 5. Find and set current global best fitness
    
auto global_best_pointer = min_element(particle_best_fitness.begin(), particle_best_fitness.end());
generation_global_best_fitness[0] = *global_best_pointer;
    
// 6. Set global best location
    
int global_best_index = distance(particle_best_fitness.begin(), global_best_pointer);
for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
    generation_global_best_location[0][dimension] = particle_locations[global_best_index][dimension];
}
    
    
// Run algorithm for set number of iterations/generations
    
for (int generation = 1; generation < NUMBER_GENERATIONS; ++generation){
    
    // Calculate fitness value for each particle
 
    for (int particle_number = 0; particle_number < NUMBER_PARTICLES; ++particle_number){
        double current_particle_fitness = calculateParticleFitness(particle_locations[particle_number]);
        
        // If current new fitness is better set as new personal best
        if (current_particle_fitness < particle_best_fitness[particle_number]){
            particle_best_fitness[particle_number] = current_particle_fitness;
        // Set new personal best location
            for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
                particle_best_location[particle_number][dimension] = particle_locations[particle_number][dimension];
            }
        }
    }

    // Update global best fitness

    auto global_best_pointer = min_element(particle_best_fitness.begin(), particle_best_fitness.end());
    generation_global_best_fitness[generation] = *global_best_pointer;

    // Update global best location

    int global_best_index = distance(particle_best_fitness.begin(), global_best_pointer);
    for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
            generation_global_best_location[generation][dimension] = particle_locations[global_best_index][dimension];
    }
    
    // Calculate new velocities for each particle
    // Formula used for velocity calculations:
    // v[] = c0 * v[] + c1 * rand() * (pbest[] - present[]) + c2 * rand() * (gbest[] - present[])
    // c values are defined, pbest is the particle's best location, gbest is the global best location
    
    for (int particle_number = 0; particle_number < NUMBER_PARTICLES; ++particle_number){
        for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
            particle_velocities[particle_number][dimension] =
                  (C0 * particle_velocities[particle_number][dimension])
                + (C1 * random_weight_range(random_number_generator) * (particle_best_location[particle_number][dimension] - particle_locations[particle_number][dimension]))
                + (C2 * random_weight_range(random_number_generator) * (generation_global_best_location[generation][dimension] - particle_locations[particle_number][dimension]));
        
        // Enforce Velocity Boundaries
            if (particle_velocities[particle_number][dimension] > VELOCITY_RANGE) particle_velocities[particle_number][dimension] = VELOCITY_RANGE;
            else if (particle_velocities[particle_number][dimension] < -VELOCITY_RANGE) particle_velocities[particle_number][dimension] = -VELOCITY_RANGE;
        }
    }
    
    // Update particle positions
    // Position is present location + velocity
    
    for (int particle_number = 0; particle_number < NUMBER_PARTICLES; ++particle_number){
        for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
            particle_locations[particle_number][dimension] = (particle_locations[particle_number][dimension] + particle_velocities[particle_number][dimension]);
            // Enforce Position Boundaries
            if (particle_locations[particle_number][dimension] > LOCATION_RANGE) particle_locations[particle_number][dimension] = LOCATION_RANGE;
            else if (particle_locations[particle_number][dimension] < -LOCATION_RANGE) particle_locations[particle_number][dimension] = -LOCATION_RANGE;
        }
    }
}
    
    // Output
    // Displays Global Best Fitness and Global Best Location for each generation

//    for (int generation = 0; generation < NUMBER_GENERATIONS; ++generation){
//        cout << "Generation " << generation << " Results: " << endl;
//        cout << "Global Best Fitness: " << generation_global_best_fitness[generation] << endl;
//        cout << "Global Best Location: " << endl;
//        for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++dimension){
//            cout << "      Dimension " << dimension << ": " << generation_global_best_location[generation][dimension] << endl;
//        }
//        cout << endl;
//    }
    
// Output formatted to facilitate copy and paste  of data for chart generation
    
    cout << "Global Best Fitness for each Generation: " << endl;
    for (int generation = 0; generation < NUMBER_GENERATIONS; ++generation){
        cout << generation_global_best_fitness[generation] << endl;}
   
    cout << "Global Best Location for each Generation X: " << endl;
    for (int generation = 0; generation < NUMBER_GENERATIONS; ++generation){
        cout << generation_global_best_location[generation][0] << endl;}
    cout << "Global Best Location for each Generation Y: " << endl;
    for (int generation = 0; generation < NUMBER_GENERATIONS; ++generation){
        cout << generation_global_best_location[generation][1] << endl;}

    return 0;
}

//***************************************************************************
//                        Function: calculateParticleFitness
//                    Parameters: Vector of doubles passed by reference
//                         Returns: Double fitness value
//                               Complexity: O(n)
//***************************************************************************
//                                  Description
//
// This function calculates the fitness for a particle with a location that
// is passed in a vector which contains the location for the particle in n
// dimensions. The function evaluates the fitness by plugging the values into
// the Schwefel function (https://www.sfu.ca/~ssurjano/schwef.html) which is
// f(x) = 418.9829d - (SUM from 1 to d of) xi * sin (sqrt of abs(xi))
// where d is the number of dimensions, and xi is the value for the current
// dimension. Since the goal is to find which dimension values will evaluate
// the expression closest to 0. The absolute value of the result is returned
// for comparisons in the main program. The complexity of this function is
// based on the number of dimensions since there is a sum loop based on the
// number of dimensions, making the complexity O(n) where n is the number
// of dimensions. The dimensions are passed in a vector by reference for
// efficiency but is declared constant since the function should not alter
// dimensional location information contained in the vector.
//
//***************************************************************************



double calculateParticleFitness(const vector<double> &location){
    double fitness = 0;
    
    for (int dimension = 0; dimension < NUMBER_DIMENSIONS; ++ dimension){
        fitness += location[dimension] * sin (sqrt(abs(location[dimension])));
    }
    
    fitness = (418.9829 * NUMBER_DIMENSIONS) - fitness;
    
    return abs(fitness);
}

