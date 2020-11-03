NAME = wolf3d
SRCS = main.c valid.c dda.c draw.c draw1.c hooks.c init.c
OBJS = main.o valid.o dda.o draw.o draw1.o hooks.o init.o

all: $(NAME)

$(OBJS): %.o: %.c
	gcc -c -g $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	gcc $(SRCS) -lmlx -framework OpenGl -framework AppKit -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all