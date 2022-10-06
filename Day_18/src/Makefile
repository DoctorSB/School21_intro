CC=gcc
FLAG=-c -Wall -Werror -Wextra

all: print_module

print_module: main_module_entry_point.o print_module.o
	$(CC) main_module_entry_point.o print_module.o -o ../build/Quest_1
	-rm *.o
main_module_entry_point.o : main_module_entry_point.c
	$(CC) $(FLAG) main_module_entry_point.c
print_module.o : print_module.c
	$(CC) $(FLAG) print_module.c

.o.c:
	$(CC) $(FLAG) $< -o $@

clean :
	-rm *.o

rebuild :
	-rm *.o
	all
