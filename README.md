# Movie Theater Seating Challenge
Given a list of reservations in order, output a seating that seats groups at least 3 seats apart or in different rows and gives maximum customer satisfaction
## Language
C++
## Assumptions
We prioritize the reservations in order and we will not assign seats for reservations if there are not enough available seats for the entire party. 

If there are enough seats to fit the reservation, they are more satisfied being able to go then not being able to go. 

If there are enough seats for a reservation to sit next to each other, they prioritize sitting next to each other rather than location.

People prefer sitting in rows that are farther back.
