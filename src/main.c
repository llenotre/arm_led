#include <gpio.h>
#include <assert.h>

void main(void)
{
	set_GPIO_mode(GPIO_B, 13, GPIO_MODE_OUTPUT);
	set_GPIO_out(GPIO_B, 13, 1);
	halt();
}
