section .data
        fmt: db '%d %d %d', 0
        yes: db 'Yes', 0
        no : db 'No', 0

section .bss
        a: resd 1
        b: resd 1
        c: resd 1

section .text
        global main

extern scanf, printf

main:
        sub rsp, 8

        lea rdi, [fmt]
        lea rsi, [a]
        lea rdx, [b]
        lea rcx, [c]
        call scanf

        mov eax, [b]
        cmp eax, [a]
        jb f1  ; b < a
        jmp f2

f1:
        lea rdi, yes
        jmp finish
f2:
        lea rdi, no

finish:
        call printf
        xor rax, rax
        add rsp, 8
        ret
