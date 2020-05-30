#include <gpio.h>
#include <assert.h>

void main(void)
{
	/*gpio_t *gpio = GPIO_A;
	unsigned pin = 5;
	unsigned mode = GPIO_MODE_OUTPUT;
	unsigned val = 1;*/

	// TODO
	uint32_t *clk_ptr = (uint32_t *) (0x40023800 + 0x30);
	*clk_ptr |= 0b01;

	/*gpio->mode &= ~(0b11 << (pin * 2));
	gpio->mode |= mode << (pin * 2);

	gpio->output &= ~(1 << pin);
	gpio->output |= val << pin;*/

	set_GPIO_mode(GPIO_A, 5, GPIO_MODE_OUTPUT);
	set_GPIO_out(GPIO_A, 5, 1);
}
