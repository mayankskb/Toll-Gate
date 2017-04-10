# Toll-Gate
A toll plaza simulation

#######################################################################################


In this project the main file is toll.cpp that contains call to all pre defined headers and to some of the user defined headers 

the next important file is tollgraph,cpp that make the graphical layout of the toll plaza and is responsible for the movement of the cars accross the toll plaza. Howerver the screen flickers while doing this.  It is because I use cleardevice() along with delay of 5 milliseconds. It also shows various informations about the features of the multiserver queue such as : cummulative departure time, queue length for the servers and idle time for the servers. It is also display the arrival and service time for the vehicles that enters into the system. The arrival time is soemthing that we can say as cummulative arrival time. Both arrival time(not cummulative arrival time just arrival time i,e, the time after which the vehicle enters into the system from its predecessor) and service time are generated randomly.

It also instruct the vehicle to join which booth 

Next important file is auxil.cpp this file is the heart of the overall simulation i.e., all the decision making process is occuring or directed from this file. 


#######################################################################################



Thankyou
