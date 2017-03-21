
MAIN	:= find_all_possibility.c thinking_strategy.c piece_non_inserable.c \
	insertion_de_piece.c final_decision.c influence.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRAI)/%.c $(HEAD)
	$(COMPIL)
