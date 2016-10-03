lab06_1: lab06_2
	gcc -o lab06_client lab06_client.o
	gcc -o lab06_server lab06_server.o
lab06_2: 
	gcc -c lab06_client.c	
	gcc -c lab06_server.c
clean:
	rm *.o lab06_client
	rm *.o lab06_server
