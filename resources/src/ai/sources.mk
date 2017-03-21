
MAIN	:= find_all_possibility.c thinking_strategy.c piece_non_inserable.c \
	insertion_de_piece.c final_decision.c influence.c calcul_influence.c \
	influence_horizntal.c influence_vertical.c marquage_influence.c \
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRAI)/%.c $(HEAD)
	$(COMPIL)
