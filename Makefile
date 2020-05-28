NAME = led
CC = arm-none-eabi-gcc
CFLAGS = -nostdlib -ffreestanding -fpic -mcpu=cortex-m4 -mthumb -fno-pie -no-pie -Wall -Wextra -Werror -ggdb

OBJCOPY = arm-none-eabi-objcopy

SRC_DIR = src/
SRC := $(shell find $(SRC_DIR) -type f -name "*.[cs]")
HDR := $(shell find $(SRC_DIR) -type f -name "*.h")
DIR := $(shell find $(SRC_DIR) -type d)

LINKER = linker.ld

OBJ_DIR = obj/
OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
OBJ_DIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(DIR))

INCLUDES = -I $(SRC_DIR)
LIBS = -lgcc

all: $(NAME).bin tags

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(NAME).bin: $(NAME).elf
	$(OBJCOPY) -O binary $< $@

$(NAME).elf: $(OBJ_DIRS) $(OBJ) $(LINKER) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -T $(LINKER) -o $@ $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)%.o: $(SRC_DIR)%.s Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

tags: $(SRC) $(HDR)
	ctags $(SRC) $(HDR)

flash: $(NAME).bin
	sudo st-flash write $< 0x8000000 || sudo st-flash write $< 0x8000000

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME).elf $(NAME).bin
	rm tags

re: fclean all

.PHONY: all flash clean fclean re
