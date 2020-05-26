CC = arm-none-eabi-gcc
CFLAGS = -nostdlib -ffreestanding -fpic -mcpu=cortex-m4 -mthumb -fno-pie -no-pie -ggdb

LIBS = -lgcc

OBJCOPY = arm-none-eabi-objcopy

test.bin: test.elf
	$(OBJCOPY) -O binary $< $@

test.elf: main.o boot.o linker.ld
	$(CC) $(CFLAGS) $(LIBS) -T linker.ld -o $@ main.o boot.o

%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.s Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

flash: test.bin
	sudo st-flash write $< 0x8000000

.PHONY: flash
