SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
PRINTF_DIR = printf

OBJ_SERVER        = $(SRC_DIR)/$(SERVER).o
OBJ_CLIENT        = $(SRC_DIR)/$(CLIENT).o
OBJ_SERVER_BONUS  = $(SRC_DIR)/$(SERVER_BONUS).o
OBJ_CLIENT_BONUS  = $(SRC_DIR)/$(CLIENT_BONUS).o

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC = cc
COPY = cp
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/$(INC_DIR)

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#make libft.a
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

#make libftprintf.a
$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

$(SERVER): $(OBJ_SERVER) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(OBJ_SERVER) $(LIBFT_A) $(PRINTF_A) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(OBJ_CLIENT) $(LIBFT_A) $(PRINTF_A) $(INCLUDES) -o $(CLIENT)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(OBJ_SERVER_BONUS) $(LIBFT_A) $(PRINTF_A) $(INCLUDES) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(OBJ_CLIENT_BONUS) $(LIBFT_A) $(PRINTF_A) $(INCLUDES) -o $(CLIENT_BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(OBJ_SERVER) $(SERVER) $(OBJ_CLIENT) $(CLIENT) $(SERVER_BONUS) $(OBJ_SERVER_BONUS) $(CLIENT_BONUS) $(OBJ_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
