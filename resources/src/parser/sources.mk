MAIN	:= parser_numero_joueur.c parser_iteration_ligne.c parser_plateau.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
