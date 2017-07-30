MAIN	:= ai_reponse.c ai.c ai_recuperation_list_coups.c ai_recherche_piece.c \
			ai_bubble_sort.c ai_blocage_bas_droite.c ai_recherche_joueur.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRAI)/%.c $(HEAD)
	$(COMPIL)
