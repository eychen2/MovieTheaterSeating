# Movie Theater Seating Challenge
Given a list of reservations in order, output a seating that seats groups at least 3 seats apart or in different rows and gives maximum customer satisfaction
## Language
C++
## Assumptions
We prioritize the reservations in order and we will not assign seats for reservations if there are not enough available seats for the entire party. 

If there are enough seats to fit the reservation, they are more satisfied being able to go then not being able to go. 

If there are enough seats for a reservation to sit next to each other, they prioritize sitting next to each other rather than location.

People prefer sitting in rows that are farther back.

## Algorithm
If the number of seats they are trying to reserve is bigger than the total number of seats, we say there are not enough seats in the output file for this reservation and skip it. \
The algorithm goes through reservations sequentially and tries to sit the parties in the same row, going down the rows until it either sits the entire party in a row or finds out it can't. \

If it can't sit the party all in the same row, it starts sitting them from the best available seats(the farthest back that are free) next to each other and goes down row by row until the entire party is seated. 

## How to run
Download the src folder 

Make the executable for the cpp file with the command g++ -std=c++17 -o main main.cpp

To run the file, depending on the OS do main [inputfilepath] or ./main [inputfilepath]
