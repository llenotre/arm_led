#include <gpio.h>

void set_GPIO_mode(volatile uint8_t *gpio_addr, int io_id, int mode)
{
	uint32_t *addr;

	addr = (uint32_t *) (gpio_addr + GPIO_OFFSET_MODE);
	*addr &= ~(0b11 << io_id);
	*addr |= mode << io_id;
}

// TODO Set GPIO output type
// TODO Set GPIO speed
// TODO Set GPIO pull-up/pull-down

// TODO GPIO Input
void set_GPIO_out(volatile uint8_t *gpio_addr, int io_id, int val)
{
	uint32_t *addr;

	addr = (uint32_t *) (gpio_addr + GPIO_OFFSET_OUTPUT);
	*addr &= ~(1 << io_id);
	*addr |= val << io_id;
}

// TODO GPIO bit set/reset
// TODO GPIO lock

// TODO GPIO Alternate function
