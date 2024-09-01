#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Estruturas para o cabeçalho e informações do bitmap
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

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

int main() {
    const char *inputFilename = "carinha.bmp";
    const char *outputFilename = "output_inverted.bmp";

    // Abrir o arquivo BMP original
    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Ler o cabeçalho do arquivo BMP
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);

    // Verificar se é um arquivo BMP válido
    if (fileHeader.bfType != 0x4D42) {
        printf("Erro: o arquivo não é um BMP válido.\n");
        fclose(inputFile);
        return 1;
    }

    // Ler o cabeçalho de informações do BMP
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Verificar se o BMP é de 24 bits (sem paleta de cores)
    if (infoHeader.biBitCount != 24) {
        printf("Erro: apenas BMPs de 24 bits são suportados.\n");
        fclose(inputFile);
        return 1;
    }

    // Mover o ponteiro do arquivo para o início dos dados de pixel
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);

    // Calcular o tamanho da linha em bytes (incluindo padding)
    int rowSize = (infoHeader.biWidth * 3 + 3) & (~3);

    // Alocar memória para uma linha de pixels
    uint8_t *row = (uint8_t *)malloc(rowSize);
    if (row == NULL) {
        perror("Erro ao alocar memória");
        fclose(inputFile);
        return 1;
    }

    // Criar o arquivo de saída para a imagem invertida
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        free(row);
        fclose(inputFile);
        return 1;
    }

    // Escrever o cabeçalho do arquivo BMP no arquivo de saída
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // Inverter a imagem horizontalmente linha por linha
    for (int y = 0; y < infoHeader.biHeight; y++) {
        // Ler uma linha de pixels do arquivo original
        fread(row, rowSize, 1, inputFile);

        // Inverter a linha de pixels
        for (int x = 0; x < infoHeader.biWidth / 2; x++) {
            // Calcular o offset dos pixels para trocar
            int leftPixelIndex = x * 3;
            int rightPixelIndex = (infoHeader.biWidth - 1 - x) * 3;

            // Trocar os pixels
            for (int i = 0; i < 3; i++) {
                uint8_t temp = row[leftPixelIndex + i];
                row[leftPixelIndex + i] = row[rightPixelIndex + i];
                row[rightPixelIndex + i] = temp;
            }
        }

        // Escrever a linha invertida no arquivo de saída
        fwrite(row, rowSize, 1, outputFile);
    }

    // Limpar e fechar arquivos
    free(row);
    fclose(inputFile);
    fclose(outputFile);

    printf("Imagem invertida salva como '%s'.\n", outputFilename);
    return 0;
}
