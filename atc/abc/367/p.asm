section .data
        a dd 77770
        form db '%#d', 10, 0

section .text
        global main

extern printf

main:
        sub rsp, 8
        xor rax, rax
        mov esi, [a]
        lea rdi, form
        call printf

        xor rax, rax
        add rsp, 8
        ret
