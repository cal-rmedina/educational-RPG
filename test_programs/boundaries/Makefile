
CC = gcc

CFLAGS = -lm -pedantic 
#TOPTION = -D
#TFLAG = conf_SO_grid_vert_2D_CPU_TEST
NAME = boundaries

$(NAME).exe:
	$(CC) $(NAME).c $(CFLAGS) $(TOPTION)$(TFLAG) -o $@

.PHONY: clean

clean:
	rm -f $(NAME).exe

.PHONY: run

run: $(NAME).exe
	./$<
