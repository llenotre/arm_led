#ifndef _ASSERT_H
# define _ASSERT_H

# define assert(expr)	if(!(expr)) halt()

__attribute__((noreturn))
extern void halt(void);

#endif
