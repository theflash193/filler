MAIN	:= message.c\

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
