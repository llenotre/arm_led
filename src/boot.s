.set STACK_SIZE,	0x8000
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
	bl main
	bl halt

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
	wfi
	b halt

.section .bss

.skip STACK_SIZE

stack_top:

heap:
