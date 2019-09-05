# Vaccum-Project
#Requirement

Switches
--------
* 3 buttons (plus - minus - Dust sensor)
* WE will refer to DUst sensor to be a button
* Plus and minus buttons : be performed at Fallig edge 
* Dust button if pressesd :  
  1) Dust led is on
  2) Plus and minus buttons inactive
  3) for every 30 second speed will decrease by one level
                              
SSD
---
* 3 7-segments:
  
  min   -  
  mid   -  
        - -   
  max   -     
        - -     
        - - -
      
      
MOTOR
-----
* max speed = 10 Degree
*  mid speed = 90 Degree
*  min speed = 140 Degree 
* Fire signal of the triac will be every 10 ms
* Soft switching will be 1 degree every 80 ms
* Harmonics reduction will be performed using "Kurz algorithm" by 5 degrees 
      
