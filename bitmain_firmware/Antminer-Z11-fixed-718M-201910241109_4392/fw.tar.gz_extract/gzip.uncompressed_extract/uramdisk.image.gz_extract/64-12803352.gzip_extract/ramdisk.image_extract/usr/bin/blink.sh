#!/bin/sh
printf "starting finder...\n"
for i in `seq 1 500`; 
  do usleep 300000; 
  echo high > /sys/class/gpio/gpio941/direction; 
  echo high > /sys/class/gpio/gpio942/direction;
  usleep 300000;  
  echo low > /sys/class/gpio/gpio941/direction; 
  echo low > /sys/class/gpio/gpio942/direction;  
done
echo low > /sys/class/gpio/gpio941/direction && echo low > /sys/class/gpio/gpio942/direction
printf "finder stopped...\n"
exit
