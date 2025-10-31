# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source, bonus and object files
SRCS = ft_printf.c ft_putchar_pf.c ft_putnbr_base_pf.c \
			ft_putnbr_pf.c ft_putptr_pf.c ft_putstr_pf.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

# Library
NAME = libftprintf.a

# Build Library
all: $(NAME)

$(OBJS) : %.o: %.c
	$(CC) $(CFLAGS) -c $<

# Build library (mandatory)
$(NAME): $(OBJS)
	ar rcs $@ $^

# Clean object files
clean:
	rm -f $(OBJS)

# Full clean (objects + library)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
