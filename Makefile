IDIR =include/
SDIR =src/
ODIR =obj/
CC=g++
CFLAGS=-I $(IDIR) 
LFLAGS=-lncurses 



SRC = $(wildcard $(SDIR)*.cpp)
OBJ = $(SRC:$(SDIR)%.cpp=$(SDIR)$(ODIR)%.o)




ClashCalc: $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

$(SDIR)$(ODIR)%.o: $(SDIR)%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) 



	





