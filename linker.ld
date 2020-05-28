SECTIONS
{
	. = 0K;

	.init :
	{
		*(.init)
	}

	.text :
	{
		*(.text)
	}

	.rodata :
	{
		*(.rodata)
	}

	.data :
	{
		*(.data)
	}

	.bss :
	{
		*(.bss)
	}
}
