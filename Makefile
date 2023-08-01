export C_COMPILER=$(PREFIX)/bin/i686-elf-gcc
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

export ASM_COMPILER=$(PREFIX)/bin/i686-elf-as

export LINKER=$(PREFIX)/bin/i686-elf-gcc

SRC_DIR=src
BUILD_DIR=build

SRC_C:=$(shell find $(ROOT_DIR) -type f -name "*.c")
SRC_ASM:=$(shell find $(ROOT_DIR) -type f -name "*.s")

OBJ_ASM=$(patsubst $(SRC_DIR)/%.s,$(BUILD_DIR)/%.o,$(SRC_ASM))
OBJ_C=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_C))

BUILD_OBJ=$(OBJ_C) $(OBJ_ASM)

build: $(BUILD_DIR)/OS.bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s
	mkdir -p $(dir $@)
	$(ASM_COMPILER) $< -o $@

$(BUILD_DIR)/OS.bin: $(BUILD_OBJ)
	mkdir -p $(BUILD_DIR)/isodir/boot/grub
	$(LINKER) -T src/linker.ld -o $(BUILD_DIR)/isodir/boot/OS.bin $(BUILD_OBJ) -nostdlib -lgcc
	echo 'menuentry "0x7D8 Operating System" {\n	multiboot /boot/OS.bin\n}' > $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(BUILD_DIR)/cookieOS.iso $(BUILD_DIR)/isodir

run:
	qemu-system-i386 -cdrom build/cookieOS.iso

clean:
	rm -rf $(BUILD_DIR)/*