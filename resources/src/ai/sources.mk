MAIN	:= ai_reponse.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRAI)/%.c $(HEAD)
	$(COMPIL)
