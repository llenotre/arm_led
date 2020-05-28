#ifndef _GPIO_H
# define _GPIO_H

# include <stdint.h>

# define GPIO_A	((void *) 0x40020000)
# define GPIO_B	((void *) 0x40020400)
# define GPIO_C	((void *) 0x40020800)
# define GPIO_D	((void *) 0X40020C00)
# define GPIO_E	((void *) 0x40021000)
# define GPIO_F	((void *) 0x40021400)
# define GPIO_G	((void *) 0x40021800)
# define GPIO_H	((void *) 0x40021C00)

# define GPIO_OFFSET_MODE	0x0
// TODO
# define GPIO_OFFSET_OUTPUT	0x14

void set_GPIO_mode(void *gpio_addr, int io_id, int mode);
void set_GPIO_out(void *gpio_addr, int io_id, int val);

#endif
