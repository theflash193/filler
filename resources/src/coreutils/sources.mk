MAIN	:= core_message.c core_put_array.c core_suppresion_entite.c math.c \

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
