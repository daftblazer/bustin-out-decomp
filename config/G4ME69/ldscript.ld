/*
 * Linker script for ngcld (SN Systems ProDG linker, GNU ld syntax).
 *
 * Section order and alignment reproduce the retail DOL. Note that .bss sits
 * before the small-data sections, and that .sdata2 is addressed through r13
 * (_SDA_BASE_) like .sdata/.sbss; r2 is set up by __start but never used.
 */
ENTRY(__start)

SECTIONS
{
	. = 0x80003100;
	.init : { *(.init) }
	.text : { *(.text) }
	.ctors : { *(.ctors) }
	. = ALIGN(8);
	.rodata : { *(.rodata) }
	. = ALIGN(8);
	.data : { *(.data) }
	. = ALIGN(8);
	.bss : { *(.bss) }
	. = ALIGN(32);
	.sdata : { *(.sdata) }
	.sbss : { *(.sbss) }
	. = ALIGN(32);
	.sdata2 : { *(.sdata2) }

	/* __CTOR_LIST__: -1, constructors..., 0 (walked by __do_global_ctors) */
	_ctors = ADDR(.ctors);
	_SDA_BASE_ = ADDR(.sdata) + 0x8000;
	_SDA2_BASE_ = _SDA_BASE_ + 0x10000;
}
