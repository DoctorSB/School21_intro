CC=gcc
FLAG=-c -Wall -Werror -Wextra


all : dmanager_module.o door_struct.o list_test.o list.o
	$(CC) dmanager_module.o door_struct.o -o ../build/Quest_1
	$(CC) door_struct.o list_test.o list.o -o ../build/Quest_2
	-rm *.o
door_struct_test.o : dmanager_module.c
	$(CC) $(FLAG) -DSTRLEN dmanager_module.c
door_struct.o : door_struct.c
	$(CC) $(FLAG) door_struct.c
list.o : list.c
	$(CC) $(FLAG) list.c
list_test.c : list_test.c
	$(CC) $(FLAG) list_test.c
.o.c:
	$(CC) $(FLAG) $< -o $@

clean :
	-rm *.o

rebuild :
	-rm *.o
	all
