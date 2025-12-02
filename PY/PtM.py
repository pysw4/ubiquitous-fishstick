#!/usr/bin/env python3
print("PELEASE TYPE IN YOUR MARATHON PACE in there numbers, such as 400 for run 1 km in 4 minutes")
pace =int(input())
pace1 = pace % 100 + pace//100*60
time1 = 42.195*pace1
hours = time1//3600
minutes=time1%3600//60
seconds=time1%60
print(hours,"hours",minutes,"minutes",seconds,"seconds") 
