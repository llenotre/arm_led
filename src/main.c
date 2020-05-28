#include <gpio.h>

#define LED_PIN	21

__attribute__((noreturn))
extern void halt(void);

void main(void)
{
	set_GPIO_mode(GPIO_A, LED_PIN, 0b01);
	set_GPIO_out(GPIO_A, LED_PIN, 1);
	halt();
}
