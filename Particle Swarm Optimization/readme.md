In this project we wrote a particle swarm algorithm to optimize the
Schwefel function. A full description of the function can be found
at https://www.sfu.ca/~ssurjano/schwef.html. The answer to this complex
function is located at ~420.9687 for each dimension. This algorithm creates
particles (20) with various dimension values ranging from -500 to 500 and
random velocities in the range of -1 to 1. The particles new velocities
are calculated based on their best locations and the group's overall best
location. The best locations, or best fitness, are the ones that yield
a result to the Schwefel function closest to 0. This algorithm is run
for 1000 interations or generations.
