CC = arm-none-eabi-gcc
CFLAGS = --std=gnu11 -Ofast  -mlong-calls -fPIC -mno-pic-data-is-text-relative -msingle-pic-base -mpic-register=r9  -mcpu=cortex-m3 -mthumb -fno-builtin  -ffreestanding   --specs=nosys.specs --specs=nano.specs -Tkmod.ld -Wl,-N -Wl,--just-symbols=../armboy-kernel/src/kernel.elf
OBYCP = arm-none-eabi-objcopy

INCLUDE = -I ../armboy-kernel/src/ -I ../armboy-kernel/src/hardware/sam3x8eHardwareAPI/3rdParty/ATMEL -I ../armboy-kernel/src/hardware/sam3x8eHardwareAPI/3rdParty/CMSIS/Include
CFILES = input.c inputSyscall.c

input.bin : $(CFILES) kmod.S
	$(CC) $(CFLAGS) -o input.elf $(CFILES) kmod.S $(INCLUDE)
	$(OBYCP) -O binary input.elf input.bin

clean :
	rm input.elf
	rm input.bin
