#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
	Estrutura de cabeçalho bitmap padrão
*/

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

/*
	Estrutura de informações bitmap
*/


typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

int main(){

/*
		Declarações
*/

	const char *inputFilename = "carinha.bmp";
    const char *outputFilename = "carinvertida.bmp";

	FILE *inputFile;
	FILE *outputFile;

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	int rowSize;

	uint8_t *row;







	
}

