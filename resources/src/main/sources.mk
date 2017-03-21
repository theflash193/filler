MAIN	:= main.c utils.c \

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
