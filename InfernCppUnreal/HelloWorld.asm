%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    push 1
    push 2
    push 3
    
    pop rax
    pop rbx
    pop rcx
    
    xor rax, rax
    ret
    
;section .data
;

;초기화 된 데이터
;[변수이름] [크기] [초기값]
;[크기] db(1byte) dw(2byte word) dd(4) dq(8)
;section .data
    ; - 리틀 엔디언 : 캐스팅에 유리함
    ; - 빅 엔디언 : 숫자 비교에 유리 앞자리가 큰 숫자부터 나오기 때문?
;초기화 되지 않은 데이터
;[변수 이름] [크기] [개수]
;[크기] resb(1) resb(2) resd(4) resq(8)
section .bss
    num resb 1