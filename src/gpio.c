#include <gpio.h>
#include <assert.h>

void set_GPIO_mode(volatile gpio_t *gpio, unsigned pin, unsigned mode)
{
	assert(gpio && pin <= 16 && mode <= 0b11);
	gpio->mode &= ~(0b11 << (pin * 2));
	gpio->mode |= mode << (pin * 2);
}

// TODO Set GPIO output type
// TODO Set GPIO speed
// TODO Set GPIO pull-up/pull-down

// TODO GPIO Input
void set_GPIO_out(volatile gpio_t *gpio, unsigned pin, unsigned val)
{
	assert(gpio && pin <= 16 && val <= 1);
	gpio->output &= ~(1 << pin);
	gpio->output |= val << pin;
}

// TODO GPIO bit set/reset
// TODO GPIO lock

// TODO GPIO Alternate function
