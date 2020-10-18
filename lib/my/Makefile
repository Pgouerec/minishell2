##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile and create libmy
##

SRC     =       my_putchar.c                    \
		my_swap.c                       \
		my_isneg.c                      \
		my_putnbr.c                     \
		my_putstr.c                     \
		my_strlen.c                     \
		is_alphanum.c					\
		my_getnbr.c                     \
		my_compute_power_rec.c          \
		my_compute_square_root.c        \
		my_is_prime.c                   \
		my_find_prime_sup.c             \
		my_strcpy.c                     \
		my_strncpy.c                    \
		my_strcmp.c                     \
		my_strncmp.c                    \
		my_strstr.c                     \
		my_strcat.c                     \
		my_strncat.c                    \
		my_strupcase.c                  \
		my_strlowcase.c                 \
		my_strcapitalize.c              \
		my_str_isalpha.c                \
		my_str_isnum.c                  \
		my_str_isupper.c                \
		my_str_islower.c                \
		my_str_isprintable.c            \
		my_showstr.c                    \
		my_revstr.c						\
		my_sort_in_array.c				\
		my_getchar.c					\
		my_showmem.c                    \
		my_puterror.c                   \
		my_printf.c                     \
		printf_str.c                    \
		printf_int.c                    \
		printf_case.c                   \
		my_realloc.c                    \
		my_dec_to_oct.c                 \
		my_dec_to_hex.c                 \
		my_dec_to_bin.c                 \
		my_strerror.c					\
		my_str_to_word_array.c

OBJ		=	$(SRC:.c=.o)

NAME_LIB	=	libmy.a

NAME_H		=	my.h

all:		$(NAME_LIB)

$(NAME_LIB):	$(OBJ)
	@ar rc $(NAME_LIB) *.o
	@cp $(NAME_LIB) ../
	@cp $(NAME_H) ../../include/
	make -C . clean

clean:
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME_LIB)
	@rm -f ../$(NAME_LIB)