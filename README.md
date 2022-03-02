# Movie Theater Seating Challenge
Given a list of reservations in order, output a seating that seats groups at least 3 seats apart or in different rows and gives maximum customer satisfaction
## Language
C++
## Assumptions
We assume that the inputs will be correctly formatted in the form R#### NumberOfTickets.

If all the seats are filled, we just ignore any reservations afterwards.

You have a C and C++ compiler installed and can compile the code from the command line using something like g++
## Defining Customer Satisfaction
We prioritize the reservations in order and we will not assign seats for reservations if there are not enough available seats for the entire party. 

If there are enough seats to fit the reservation, they are more satisfied being able to go then not being able to go. 

If there are enough seats for a reservation to sit next to each other, they prioritize sitting next to each other rather than location.

People prefer sitting in rows that are farther back.

## Algorithm
If the number of seats they are trying to reserve is bigger than the total number of seats, we say there are not enough seats in the output file for this reservation and skip it. 

The algorithm goes through reservations sequentially and tries to sit the parties in the same row, going down the rows until it either sits the entire party in a row or finds out it can't. 

If it can't sit the party all in the same row, it starts sitting them from the best available seats(the farthest back that are free) next to each other and goes down row by row until the entire party is seated. 

## How to run
Download the all of the files 

Go into that folder through the command line.

Make the executable for the cpp file with the command g++ -std=c++17 -o main main.cpp

To run the file, depending on the OS do main [inputfilepath] or ./main [inputfilepath]

The program will make the output file in the same place as your executable called output.txt as wellas print the path

If you are not using windows and using something like cygwin to run it like me, the absolute path will put stuff like \cygdrive\c\Users... to get the absolute path from this, just get rid of the \cygdrive and turn the c into whatever disk it's supposed to be on.
## How to test

Run the code with test input files given. You should be able to run each one by doing main [tests\test[testnumber].txt] given you are in the correct directory as your executable as outlined above

Each time, use the command diff -w OptimalSeatings.txt tests\test[test#]solution.txt. EX: After running it for test1.txt, run diff -w OptimalSeatings.txt tests\test1solution.txt
It will output the difference if there is any difference and will output nothing if there are no differences.
