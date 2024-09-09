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

/*
		Ler o Arquio Bitmap
*/

	inputFile = fopen(inputFilename, "rb");
	if (inputFile == NULL){
		return 1;
	}

	// Cabeçalho

	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);

	if(fileHeader.bfType != 0x4D42){
		return 1;
	}

	// Informações

	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

	if(infoHeader.biBitCount != 24){
		return 1;
	}

/*
		Preencher arquivo de saída
*/

	outputFile = fopen(outputFilename, "wb");

	if (outputFile == NULL){
		return 1;
	}

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

/*
		Começar leitura no início da imagem
*/

	fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);

	// alocar memória para linha

	rowSize = ((infoHeader.biWidth * 3 + 3) / 4) * 4;

	row = (uint8_t *)malloc(rowSize);

	if (row == NULL){
		return 1;
	}

/*
		Inverter imagem
*/

	for(int i=0; i<infoHeader.biHeight; i++){
		fread(row, rowSize, 1, inputFile);

		for (int j=0; j<infoHeader.biWidth / 2; j++){
			int lpixelIndex = j*3;
			int rpixelIndex = (infoHeader.biWidth - 1 - j) * 3;

			for(int k=0; k<3; k++){
				uint8_t temp = row[lpixelIndex + k];
				row[lpixelIndex + k] = row[rpixelIndex + k];
				row[rpixelIndex + k] = temp;
			}
		}

		fwrite(row, rowSize, 1, outputFile);
	}

	// fechar arquivo

	fclose(inputFile);
	fclose(outputFile);

	printf("Imagem invertida: %s\n", outputFilename);
	return 0;
	
}

