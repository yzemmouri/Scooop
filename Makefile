NAME = scop

CC = gcc

LIBFT = libft

SOURCES = main.c mathematics.c glad.c parcing.c shader.c init.c events_keyboard.c

FLAGS = -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl `sdl2-config --cflags --libs` -lSDL2_image -lm

DIR_S = src

DIR_O = obj

HEADER = include

_DEPS = scop.h mathematics.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all : obj $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS)  libft/libft.a $(FLAGS)

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all