.global enter_protected
.type enter_protected @function
enter_protected:
    call initGDT # located in gdt.h and gdt.c initializes the gdt and loads it

    # segmentation
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    # setup the stack
    mov $0x10, %ax
    mov %ax, %ss
    push $0x08  # push the code segment value to the stack
    push $_protected_start  # push the address of '_protected_start' label to the stack
    retf
