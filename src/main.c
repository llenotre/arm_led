typedef unsigned char uint8_t;
typedef unsigned long uint32_t;

typedef unsigned long size_t;

static volatile uint8_t *const gpio_a = (uint8_t *) 0x40020000;
static const int LED_pin = 21;

static const size_t gpio_mode_offset = 0x00;
// TODO
static const size_t gpio_output_offset = 0x14;

__attribute__((noreturn))
extern void halt(void);

void set_GPIO_mode(volatile uint8_t *gpio_addr, int io_id, int mode)
{
	uint32_t *addr;

	addr = (uint32_t *) (gpio_addr + gpio_mode_offset);
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

	addr = (uint32_t *) (gpio_addr + gpio_output_offset);
	*addr &= ~(1 << io_id);
	*addr |= val << io_id;
}

// TODO GPIO bit set/reset
// TODO GPIO lock

// TODO GPIO Alternate function

void main(void)
{
	set_GPIO_mode(gpio_a, LED_pin, 0b01);
	set_GPIO_out(gpio_a, LED_pin, 1);
	halt();
}
