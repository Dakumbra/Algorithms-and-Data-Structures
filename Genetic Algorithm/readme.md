In this project we wrote a simple genetic algorithm to evolve a string
of all ones using the standard template library bitset to hold the
bits of the chromoroms. The chromosome crossover was performed with a
one point crossover algorithm and a roulette proportional selection
algorithm was used for selecting parents. Fitness of each generation
is the sum of the bits in the chromosome with the optimal fitness
being all ones and thus the sum of those or the length of the chromosome.
1000 iterations or generations are run or the program stops earlier
if the optimal fitness is found in a generation
