##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my super duper makefile
##

#### CONFIG ####

EXEC_NAME		=	mysh
DEBUG			=	yes
OPT_LIB			=	
CC				=	gcc
CC_ARG			=	-o

#### SOURCES FILES ####

# Only main.c file
MAIN	=		main.c

# All project files
SRC		=		global/prompt.c						\
				global/init_global.c				\
				global/free_global.c				\
				routing/standard.c					\
				routing/utils.c						\
				env/init.c							\
				env/read.c							\
				env/cmd.c							\
				env/edit.c							\
				cd/cmd.c							\
				cd/utils.c							\
				cd/dir_to.c							\
				exec/exec.c							\
				exec/right_redir.c					\
				exec/left_redir.c					\
				exec/pipe.c							\
				exec/file_system.c					\
				exec/utils.c						\
				shell/adv_prompt.c					\
				parsing/path.c						\
				parsing/input.c						\
				parsing/args.c						\
				parsing/utils.c						\
				utils/my_arrlen.c					\
				utils/my_arrdup.c					\
				utils/my_arr_realloc.c				\
				utils/debug.c						\
				utils/my_clear_str.c				\
				utils/my_strdup.c					\
				utils/my_cat.c						\
				utils/free_array.c					\
				utils/my_isalphanum.c				\
				list/add.c							\
				list/delete.c						\
				list/print.c						\
				list/to_array.c						\
				output/usage.c						\
				output/error.c						\

# All tests files
TEST    =       standard_test.c						\
				clear_str_test.c					\
				env_test.c							\

#### PREPARE COMPILE ####

OBJ_M	=		$(MAIN:.c=.o)
OBJ		=		$(SRC:.c=.o)

### GET CONFIG ####
ifeq ($(DEBUG),yes)
	CFLAGS	+=	-I./include -L./lib/ -lmy -Wall -Wextra -g
else
	CFLAGS	+=	-I./include -L./lib/ -lmy -Wall -Wextra
endif

LDFLAGS += $(OPT_LIB)

#### MAKE STANDARD COMPILATION ####

all:	config $(EXEC_NAME)
	@echo -e "=== Done ==="

$(EXEC_NAME):		$(addprefix src/,$(OBJ))	$(addprefix src/,$(OBJ_M))
		make -C ./lib/my
		$(CC) $(CC_ARG) $(EXEC_NAME) $(addprefix src/,$(OBJ)) $(addprefix src/,$(OBJ_M)) $(CFLAGS)

clean:
	make -C ./lib/my clean
	rm -f $(addprefix src/,$(OBJ)) $(addprefix src/,$(OBJ_MAIN))

fclean: clean
	make -C ./lib/my fclean
	rm -f $(EXEC_NAME)
	rm -f unit_tests

re: fclean all
	make -C . clean

tests_run:		$(addprefix src/,$(OBJ))
				rm -f *.gcda
				rm -f *.gcno
				gcc -o unit_tests $(addprefix src/,$(OBJ)) $(addprefix tests/,$(TEST)) $(CFLAGS) --coverage -lcriterion
				make -C . clean
				-./unit_tests

cover: re tests_run
				gcovr

config:
	@echo -e "=== Configuration ==="
	@echo -e "Binary name: $(EXEC_NAME)"
	@echo -e "Debug mode: $(DEBUG)"
	@echo -e "Optional library: $(OPT_LIB)"
	@echo -e "Compilator: $(CC)"
	@echo -e "Arguments compilator: $(CC_ARG)"
	@echo -e "Cflags: $(CFLAGS)"
	@echo -e "LDflags: $(LDFLAGS)"
	@echo -e "=== End config ==="