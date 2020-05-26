typedef unsigned long uint32_t;

static volatile uint32_t *gpio_a = (uint32_t *) 0x40020000;
static int LED_pin = 21;

__attribute__((noreturn))
extern void halt(void);

void main(void)
{
	// TODO Enable clock on GPIO
	gpio_a[LED_pin] = 0xffffffff; // TODO Fix
}
