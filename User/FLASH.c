#include "main.h"

uint32_t DATA[32] = {0x01010101, 0x23456789, 0x3456789A, 0x456789AB, 0x56789ABC, 0x6789ABCD, 0x789ABCDE, 0x89ABCDEF,
                     0x9ABCDEF0, 0xABCDEF01, 0xBCDEF012, 0xCDEF0123, 0xDEF01234, 0xEF012345, 0xF0123456, 0x01234567,
                     0x01010101, 0x23456789, 0x3456789A, 0x456789AB, 0x56789ABC, 0x6789ABCD, 0x789ABCDE, 0x89ABCDEF,
                     0x9ABCDEF0, 0xABCDEF01, 0xBCDEF012, 0xCDEF0123, 0xDEF01234, 0xEF012345, 0xF0123456, 0x01234567,  
                    };
//擦除
void flash_erase()
{
	HAL_FLASH_Unlock();

	uint32_t PAGEError = 0;
  FLASH_EraseInitTypeDef EraseInitStruct={0};

  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGEERASE;                                     /* Macro FLASH_TYPEERASE_PAGEERASE means Page erase , Macro FLASH_TYPEERASE_SECTORERASE means Sector erase */
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;                                         /* Start address of erase area */
  EraseInitStruct.NbPages  = sizeof(DATA) / FLASH_PAGE_SIZE;                                   /* Number of pages to be erased */
  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)                               /* Perform page erase,PAGEError save faulty page in case of error(0xFFFFFFFF means that all the pages have been correctly erased) */
  {
   
  }
}
//查空
void flash_blank(void)
{
  uint32_t addr = 0;

  while (addr < sizeof(DATA))
  {
    if (0xFFFFFFFF != HW32_REG(FLASH_USER_START_ADDR + addr))
    {
      flash_erase();
    }
    addr += 4;
  }
}
//写
void flash_program(void)
{
	uint32_t flash_program_start = FLASH_USER_START_ADDR ;                                /* Start address of user write flash */
  uint32_t flash_program_end = (FLASH_USER_START_ADDR + sizeof(DATA));                  /* End address of user write flash */
  uint32_t *src = (uint32_t *)DATA;                                                     /* Pointer to array */

  while (flash_program_start < flash_program_end)
  {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_PAGE, flash_program_start, src) == HAL_OK)  /* Perform Program */
    {
      flash_program_start += FLASH_PAGE_SIZE;                                           /* Point to the start address of the next page to be written */
      src += FLASH_PAGE_SIZE / 4;                                                       /* Point to the next data to be written */
    }
  }
	HAL_FLASH_Lock();
}

//校验
void flash_verity(void)
{
	 uint32_t addr = 0;

  while (addr < sizeof(DATA))
  {
    if (DATA[addr / 4] != HW32_REG(FLASH_USER_START_ADDR + addr))
    {
      APP_ErrorHandler();
    }
    addr += 4;
  }
}

void flash_test(void)
{
	flash_erase();
	flash_blank();
	flash_program();
	flash_verity();
}
