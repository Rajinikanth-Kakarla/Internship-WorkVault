.include "m328pdef.inc"

.def A_pins = R16
.def R13 =R17
.def LED = R18
.def Option = R19
.def R1 = R20
.def R2 = R21
.def R11 = R22
.def R12 = R23

ldi A_pins, 0b0000  

ldi R11,0b0001
ldi R12,0b0001

ldi R13,0b0001

ldi LED, 0b11110000

ldi Option, 1
ldi R1, 0b0000 
ldi R2, 0b0000  
eor R1, R2 
call Gate_function 

ldi Option, 2  
ldi R1, 0b0000  
ldi R2, 0b0001
and R1, R2
call Gate_function 

ldi Option, 3   
ldi R1, 0b0000   
ldi R2, 0b0001   
eor R1, R2
call Gate_function 

ldi Option, 4  
ldi R1, 0b0001   
call Gate_function 

rjmp $ 

Gate_function:
  out PORTD, A_pins
  
  and R11, R12
  and R13, R12
  com R11
  com R13
  eor R11, R13

  cp R11, R1    
  
  breq ledON

  out PORTD, A_pins

  ret


ledON:
  
  out PORTD, LED
  ret