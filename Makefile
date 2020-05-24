RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
CYAN = \x1b[36m
NC = \033[0m
START = "${RED}Starting compilation...${NC}"
MIDDLE = "${YELLOW}Creating archive...${NC}"
END = "${GREEN}Finishing...${NC}"

NAME = ft_ls
HEADER = ft_ls.h
ERRORS = -Wall -Werror -Wextra
LIBFT = libft/

SRC = sort.c arguments.c add_node.c main.c ft_ls.c ft_ls_recursive.c ft_ls_r.c ft_ls_a.c ft_ls_l.c

$(NAME):
	@echo "${CYAN}Creating LIBFT${NC}" #prints text
	@make -C $(LIBFT) #runs Make on libft.a
	@echo ${START}
	@gcc $(ERROR) $(SRC) -o $(NAME) $(LIBFT)libft.a
	@echo ${MIDDLE}
	@sleep 1
	@echo ${END}
	@sleep 2
	@echo "${CYAN}Finished!"

all: $(NAME)

clean:
	@echo "${CYAN}Removing object files...${NC}"
	@sleep 2
	@echo "${GREEN}Finished!"
	@make -C $(LIBFT) clean #runs clean on libft removing .o

fclean:
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: fclean all
