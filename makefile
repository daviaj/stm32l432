CC  = arm-none-eabi-gcc
AS  = arm-none-eabi-as
LD  = arm-none-eabi-ld
BIN = arm-none-eabi-objcopy
 
BIN_FOLDER ?= ./bin
OBJ_FOLDER ?= ./obj
SRC_FOLDER ?= ./src
INC_FOLDER ?= ./include
 
SRC ?=
SRC += $(SRC_FOLDER)/*.c
 
CFLAGS = -I$(INC_FOLDER) -mthumb -mcpu=cortex-m4 -std=c99

main.bin: main.elf
	$(BIN) -O binary main.elf main.bin
main.elf: linker.ld startup.o main.o
	$(LD) -T linker.ld -o main.elf startup.o main.o
startup.o: startup.s
	$(AS) -o startup.o startup.s
main.o: $(SRC_FOLDER)/main.c
	$(CC) $(CFLAGS) -c -o main.o $(SRC_FOLDER)/main.c -g
clean:
	rm -f *.o *.elf *.bin
flash:
	st-flash write main.elf 0x8000000