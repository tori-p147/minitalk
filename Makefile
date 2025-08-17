SERVER = server
CLIENT = client

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
PRINTF_DIR = printf

SRC_SERVER = $(SRC_DIR)/server.c
SRC_CLIENT = $(SRC_DIR)/client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC = cc
COPY = cp
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/includes

all: $(SERVER) $(CLIENT)

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

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJ_SERVER)
	@$(RM) $(OBJ_CLIENT)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(OBJ_SERVER) $(SERVER)
	@$(RM) $(OBJ_CLIENT) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
