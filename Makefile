SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_DIR = src
INC_DIR = includes
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
PRINTF_DIR = $(LIB_DIR)/printf

OBJ_SERVER        = $(SRC_DIR)/server.o
OBJ_CLIENT        = $(SRC_DIR)/client.o
OBJ_SERVER_BONUS  = $(SRC_DIR)/server_bonus.o
OBJ_CLIENT_BONUS  = $(SRC_DIR)/client_bonus.o

LIBFT_A   = $(LIBFT_DIR)/libft.a
PRINTF_A  = $(PRINTF_DIR)/printf.a
LIBS      = $(LIBFT_A) $(PRINTF_A)

CC        = cc
CFLAGS    = -Wall -Wextra -Werror
COPY = cp
AR = ar rcs
RM = rm -f
INCLUDES  = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/$(INC_DIR)

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

$(SERVER): $(OBJ_SERVER) $(LIBS)
	$(CC) $(OBJ_SERVER) $(LIBS) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBS)
	$(CC) $(OBJ_CLIENT) $(LIBS) $(INCLUDES) -o $(CLIENT)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBS)
	$(CC) $(OBJ_SERVER_BONUS) $(LIBS) $(INCLUDES) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBS)
	$(CC) $(OBJ_CLIENT_BONUS) $(LIBS) $(INCLUDES) -o $(CLIENT_BONUS)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean:
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_SERVER) $(SERVER) $(OBJ_CLIENT) $(CLIENT) $(SERVER_BONUS) $(OBJ_SERVER_BONUS) $(CLIENT_BONUS) $(OBJ_CLIENT_BONUS)

re: fclean all bonus

.PHONY: all bonus clean fclean re
