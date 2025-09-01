#Compiler
CC = gcc

#Compiler flags(Wall=show all warnings, g=debug info)
CFLAGS = -Wall -g

#Executable name
TARGET = studentDB

#source files
SRCS = main.c student.c auth.c util.c

#object files
OBJS = $(SRCS:.c=.o)

#Rule to built final program
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

#Rule to build .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

#clean up (remove .o files and executable)
clean;
	rm -f $(OBJS) $(TARGET)