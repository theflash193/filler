MAIN	:= ai_reponse.c ai.c ai_recuperation_list_coups.c ai_recherche_piece.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRAI)/%.c $(HEAD)
	$(COMPIL)
