CFLAGS = -Wall -Wextra -g -std=c99
CPPFLAGS = -I ../include -DDEBUG
LDFLAGS =
EXE = poker
DEBUG = 0

all : $(EXE)

$(EXE) : main.o card.o chance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.o : %.c %.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<


.PHONY : clean all help


clean :
	@rm -f *.o *.gch \#*\# *~ *.txt $(EXE)

help :
	@echo ""
	@echo "make		- builds poker"
	@echo "make clean	- remove *.o files and poker exe"
	@echo "make help	- this info"
	@echo ""
