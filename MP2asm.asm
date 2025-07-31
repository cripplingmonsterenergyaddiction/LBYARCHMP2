

section .text
    global imgCvtGrayDoubleToInt
    default rel

imgCvtGrayDoubleToInt:
    
    push    rsi
    push    rdi
    push    rbx

    mov     rsi, rcx        
    mov     rdi, rdx        
    mov     rcx, r8         

    mov     rax, 0x406FE00000000000 ;255
    movq    xmm0, rax

loop1:
    test    rcx, rcx
    jz      FINISH

    movsd   xmm1, [rsi]     
    mulsd   xmm1, xmm0      
    cvttsd2si eax, xmm1     
    mov     [rdi], al       

    add     rsi, 8          
    add     rdi, 1          
    dec     rcx
    jmp     loop1

FINISH:
    pop     rbx
    pop     rdi
    pop     rsi
    ret
