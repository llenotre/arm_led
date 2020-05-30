#ifndef _GPIO_H
# define _GPIO_H

# include <stdint.h>

# define GPIO_A					((gpio_t *) 0x40020000)
# define GPIO_B					((gpio_t *) 0x40020400)
# define GPIO_C					((gpio_t *) 0x40020800)
# define GPIO_D					((gpio_t *) 0x40020c00)
# define GPIO_E					((gpio_t *) 0x40021000)
# define GPIO_F					((gpio_t *) 0x40021400)
# define GPIO_G					((gpio_t *) 0x40021800)
# define GPIO_H					((gpio_t *) 0x40021c00)

# define GPIO_MODE_INPUT		0b00
# define GPIO_MODE_OUTPUT		0b01
# define GPIO_MODE_ALTERNATE	0b10
# define GPIO_MODE_ANALOG		0b11

# define GPIO_OUTPUT_TYPE_PUSH_PULL		0
# define GPIO_OUTPUT_TYPE_OPEN_DRAIN	1

# define GPIO_OUTPUT_SPEED_LOW		0b00
# define GPIO_OUTPUT_SPEED_MEDIUM	0b01
# define GPIO_OUTPUT_SPEED_FAST		0b10
# define GPIO_OUTPUT_SPEED_HIGH		0b11

# define GPIO_PULL_MODE_NONE		0b00
# define GPIO_PULL_MODE_UP			0b01
# define GPIO_PULL_MODE_DOWN		0b10

__attribute__((packed))
struct gpio
{
	volatile uint32_t mode;
	volatile uint32_t type;
	volatile uint32_t speed;
	volatile uint32_t pull;
	volatile const uint32_t input;
	volatile uint32_t output;
	volatile uint32_t bsr;
	volatile uint32_t lock;
	volatile uint32_t afl;
	volatile uint32_t afh;
};

typedef struct gpio gpio_t;

void set_GPIO_mode(gpio_t *gpio, unsigned pin, unsigned mode);
void set_GPIO_out(gpio_t *gpio, unsigned pin, unsigned val);

#endif
