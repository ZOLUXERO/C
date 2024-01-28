section .data
	;nuevo coomiit!!!!
	text db "Hello, world",10	;db = define bytes text setea variable 10 es salto de linea
	text1 db "Inserte nombre:"	
	text2 db "Hola, "

section .bss
	name resb 16	;rsb = reservebyte

section .text 
	global _start

_start:
	call _printText 	;llama a una subrutina es parecido a una funcion
	call _printText1	;llama a una subrutina es parecido a una funcion
	call _getName		;llama a una subrutina es parecido a una funcion
	call _printText2	;llama a una subrutina es parecido a una funcion
	call _printName		;llama a una subrutina es parecido a una funcion

	mov rax, 60
	mov rdi, 0
	syscall

;rdi argumento
;0 = (standart input)
;1 = (standart output)
;2 = (standart error)
;rsi locacion de donde se encuentra el string en este caso esta alocado en (text)
;rdx largo del string 14 caracteres
;mov mueve el valor al register

;funciones ""
_getName: ;toma el input y lo mueve a apuntador name
	mov rax, 0
	mov rdi, 0
	mov rsi, name
	mov rdx, 15
	syscall
	ret

_printText: ;pinta el texto en terminal
	mov rax, 1	;argumento que llama a la funcion en este caso 1(sys_write)
	mov rdi, 1	;se usa para pasar primer argumento a funcion (1)
	mov rsi, text 	;se usa para pasar segundo argumento a funcion (1)
	mov rdx, 13	;se usa para pasar tercer argumento a funcion (1)
	syscall		;ejecuta el llamado a la funcion
	ret

_printText1:
	mov rax, 1	;argumento que llama a la funcion en este caso 1(sys_write)
	mov rdi, 1	;se usa para pasar primer argumento a funcion (1)
	mov rsi, text1 	;se usa para pasar segundo argumento a funcion (1)
	mov rdx, 15	;se usa para pasar tercer argumento a funcion (1)
	syscall		;ejecuta el llamado a la funcion
	ret

_printText2:
	mov rax, 1	;argumento que llama a la funcion en este caso 1(sys_write)
	mov rdi, 1	;se usa para pasar primer argumento a funcion (1)
	mov rsi, text2 	;se usa para pasar segundo argumento a funcion (1)
	mov rdx, 7	;se usa para pasar tercer argumento a funcion (1)
	syscall		;ejecuta el llamado a la funcion
	ret

_printName:
	mov rax, 1	;argumento que llama a la funcion en este caso 1(sys_write)
	mov rdi, 1	;se usa para pasar primer argumento a funcion (1)
	mov rsi, name 	;se usa para pasar segundo argumento a funcion (1)
	mov rdx, 20	;se usa para pasar tercer argumento a funcion (1)
	syscall		;ejecuta el llamado a la funcion
	ret
