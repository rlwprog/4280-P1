#
# makefile
#
# Created by Ricky Wilson on 3/17/18.
# CS 4280
# Project 1
#


all: scanner 

scanner: 
	gcc -Wall token.c main.c testScanner.c scanner.c -o scanner

clean:
	rm scanner  
