MAIN	:= map.c player_number.c piece.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPARSER)/%.c $(HEAD)
	$(COMPIL)
