section .data
	digit db 0,10
	textSuma db "Suma: ",-1
	textResta db "Resta: ",0
	textMult db "Multiplicacion: ",0
	textDivi db "Division: ",0

section .text
	global _start

_start:
	; ejemplo division
	;mov rax, textDivi
	;call _print
	; esto no funca
	mov rax, 6		; como rax es 0(48) en _printRaxDigit y aca le estamos poniedo 6 el va aquedar con un valor de 54 que en la tabla ASCII es igual a 6 
	mov rcx, 2
	div rcx			; division de RAX / RBX que en este caso es = 3
	call _printRaxDigit
	
	; ejemplo suma	
	mov rax, textSuma
	call _print
	mov rax, 7	
	add rax, 1		; RECORDAR VALORES DE TABLAS ASCII!!
	call _printRaxDigit

	; ejemplo resta
	mov rax, textResta
	call _print
	mov rax, 5
	sub rax, 3	
	call _printRaxDigit

	; ejemplo multiplicacion
	mov rax, textMult
	call _print
	mov rax, 2
	mov rbx, 4
	mul rbx
	call _printRaxDigit

	mov rax, 60
	mov rdi, 0
	syscall

_printRaxDigit:
	add rax, 48		; Esto lo saca en base a la tabla ASCII donde el valor 48 es 0
	mov [digit], al		; al toma el bit mas bajo del registrador RAX ej: digit tiene dos bits 0 y 10 tomara el primer bit que es 0
	mov rax, 1
	mov rdi, 1
	mov rsi, digit
	mov rdx, 2
	syscall
	ret

; input: rax apuntador a string
; output: print string rax
_print:
	push rax
	mov rbx, 0

_printLoop:
	inc rax
	inc rbx
	mov cl, [rax]
	cmp cl, 0
	jne _printLoop

	mov rax, 1
	mov rdi, 1
	pop rsi
	mov rdx, rbx
	syscall
	ret
