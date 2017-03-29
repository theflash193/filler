MAIN	:= parser_numero_joueur.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
