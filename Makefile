#Definition
CC          		=   gcc
NAME        		=   philo
NAME_BONUS       	=   philo_bonus
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra -g 
RM					=	rm

#Directory
OBJ_DIR				=	obj/
SRC_DIR				= 	src/
SRC_COMMON			= 	philo/
SRC_COMMON_BONUS	= 	philo_bonus/
SRC_LIBFT			=	libft/

#Files
COMMON				= 	main initialize philosophers routine  \
						time tools died meals  \
						action action_handler \
						exception exception_handler \

COMMON_BONUS		= 	main initialize philosophers routine  \
						time tools died meals  \
						action action_handler \
						exception exception_handler \

LIBFT				= 	ft_atoi ft_atoi_long ft_strcmp

#FileCreate
SRC_FILES			+=	$(addprefix $(SRC_COMMON), $(COMMON))
SRC_FILES			+=	$(addprefix $(SRC_LIBFT), $(LIBFT))

SRC_BONUS_FILES		+=	$(addprefix $(SRC_COMMON_BONUS), $(COMMON_BONUS))
SRC_BONUS_FILES		+=	$(addprefix $(SRC_LIBFT), $(LIBFT))

SRC 				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ_BONUS 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BONUS_FILES)))

OBJF				=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMON)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMON_BONUS)
			@mkdir -p $(OBJ_DIR)$(SRC_LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception

norm_bonus:
			@norminette $(SRC_BONUS) | grep -v Norme -B1 || true
			@echo Norminatte exception


$(NAME):	$(OBJ) $(OBJ_BONUS)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
			@echo $(NAME) compiled!

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)const
			@echo Objects files cleaned!

fclean:		clean
			@$(RM) $(NAME)
			@echo $(NAME) executable files cleaned!
			@$(RM) $(NAME_BONUS)
			@echo $(NAME_BONUS) executable files cleaned!
			
re:			fclean clean all
			@echo Cleaned and rebuilt

welcome:
			@echo " ______   _    _  _____  _        ______   ______   ______   ______   _    _   ______  ______   ______"
			@echo "| |  | \ | |  | |  | |  | |      / |  | \ / |      / |  | \ | |  | \ | |  | | | |     | |  | \ / |    "
			@echo "| |__|_/ | |--| |  | |  | |   _  | |  | | '------. | |  | | | |__|_/ | |--| | | |---- | |__| | '------."
			@echo "|_|      |_|  |_| _|_|_ |_|__|_| \_|__|_/  ____|_/ \_|__|_/ |_|      |_|  |_| |_|____ |_|  \_\  ____|_/"
			@echo "\n"

.PHONY:		all clean fclean re bonus norm