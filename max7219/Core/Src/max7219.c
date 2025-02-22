#include "max7219.h"

extern SPI_HandleTypeDef hspi1;

void MAX7219_Write(uint8_t addr, uint8_t data)
{
	uint8_t buff[2] = {addr, data};
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); //chipselect
	HAL_SPI_Transmit(&hspi1, buff, sizeof(buff)/sizeof(buff[0]), HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

}

void MAX7219_Init(void)
{
	MAX7219_Write(DECODE_MODE, 0x00);
	MAX7219_Write(INTENSITY, 0x0F);
	MAX7219_Write(SCAN_LIMIT, 0x07);
	MAX7219_Write(SHUTDOWN, 0x01);
	MAX7219_Write(DISP_TEST, 0x01);  //matrix test
	HAL_Delay(200); //visible delay
	MAX7219_Write(DISP_TEST, 0x00); //stop test

}

void MAX7219_Shutdown(void)
{
	MAX7219_Write(SHUTDOWN, 0x00);  //shutdown matrix
}

