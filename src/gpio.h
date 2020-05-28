#ifndef GPIO_H
# define GPIO_H

# include <stdint.h>

# define GPIO_A	((volatile uint8_t *) 0x40020000)
// TODO

# define GPIO_OFFSET_MODE	0x0
// TODO
# define GPIO_OFFSET_OUTPUT	0x14

void set_GPIO_mode(volatile uint8_t *gpio_addr, int io_id, int mode);
void set_GPIO_out(volatile uint8_t *gpio_addr, int io_id, int val);

#endif
