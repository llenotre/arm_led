NAME = led
CC = arm-none-eabi-gcc
CFLAGS = -nostdlib -ffreestanding -fpic -mcpu=cortex-m4 -mthumb -mthumb-interwork -mlittle-endian -flto -fno-pie -no-pie -Wall -Wextra -Werror -ggdb -Os

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

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)%.o: $(SRC_DIR)%.s $(HDR) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

tags: $(SRC) $(HDR)
	ctags $(SRC) $(HDR)

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME).elf $(NAME).bin
	rm tags

re: fclean all

flash: $(NAME).bin
	sudo kill `pidof st-util` || true
	sudo st-flash reset
	sudo st-flash write $< 0x8000000

debug: flash
	arm-none-eabi-gdb $(NAME).elf -ex "tar ext :4242"

reset:
	sudo st-flash reset

.PHONY: all flash clean fclean re
