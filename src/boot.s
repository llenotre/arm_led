.section .init

.org 0x0

IVT:
	.word stack_top
	.word _start + 1
	.word nmi + 1
	.word hard_fault + 1
	.word memory_fault + 1
	.word bus_fault + 1
	.word usage_fault + 1
	.word 0
	.word 0
	.word 0
	.word 0
	.word svcall + 1
	.word 0
	.word 0
	.word pendsv + 1
	.word systick + 1

.global halt
.extern main

_start:
	blx main
	blx halt

nmi:
	b nmi

hard_fault:
	b hard_fault

memory_fault:
	b memory_fault

bus_fault:
	b bus_fault

usage_fault:
	b usage_fault

svcall:
	b svcall

pendsv:
	b pendsv

systick:
	b systick

halt:
	wfe
	b halt

.section .bss

.org 0x20000 + 0x8000

stack_top:
