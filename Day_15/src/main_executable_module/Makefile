CC=gcc
FLAGS=-c -Wall -Wextra -Werror
SRC=main_executable_module.c ../yet_another_decision_module/decision.c ../data_module/data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_libs/sort.c
OBJ=$(SRC:.c=.o)
QUEST_3=../../build/Quest_3
QUEST_5=../../build/Quest_5
QUEST_6=../../build/Quest_6
LIBSTATIC=data_stat.a
O_FILE=../data_libs/data_stat.o

all: $(OBJ) $(LIBSTATIC) data_process.so
	$(CC) $(OBJ) -o $(QUEST_3)
	$(CC) $(OBJ) $(LIBSTATIC) -o $(QUEST_5)
	$(CC) $(OBJ) ../main_executable_module/data_process.so -o $(QUEST_6)

$(QUEST_3): $(OBJ)
	$(CC) $(OBJ) -o $(QUEST_3)

$(QUEST_5): $(OBJ)
	$(CC) $(OBJ) $(LIBSTATIC) -o $(QUEST_5)

$(QUEST_6): $(OBJ) ../main_executable_module/data_process.so
	$(CC) $(OBJ) data_process.so -o $(QUEST_6)

build_with_static : $(LIBSTATIC) $(OBJ)
	$(CC) $(OBJ) $(LIBSTATIC) -o $(QUEST_5)

build_with_dybamic : ../main_executable_module/data_process.so $(OBJ)
	$(CC) $(OBJ) ../main_executable_module/data_process.so -o $(QUEST_6)

data_process.so : 
	$(CC)  -c -fPIC ../data_libs/data_stat.c ../data_module/data_process.c
	$(CC)  -shared -o /Users/lukeshir/T09D15-0/src/main_executable_module/data_process.so data_process.o data_stat.o

$(LIBSTATIC) : $(O_FILE)
	ar cr $(LIBSTATIC) $(O_FILE)

.o.c:
	$(CC) $(FLAGS) $< -o $@
clean : 
	-rm $(OBJ) $(LIBSTATIC) $(QUEST_3) $(QUEST_5) $(QUEST_6) data_process.so data_stat.o data_process.o
rebuild :
	-rm $(OBJ) $(LIBSTATIC) -rm $(OBJ) $(LIBSTATIC) data_process.so data_stat.o data_process.o
	all
