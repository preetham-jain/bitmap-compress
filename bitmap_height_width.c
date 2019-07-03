#include<stdio.h>

int main()
{
    unsigned char imagedata[54];
    int index=0, i, bytevalue;
    char filename[50];

    FILE *file;

    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "rb");

    if (file){
        do{
            bytevalue = fgetc(file);
            imagedata[index] = bytevalue;
            index++;
            if (index == 54) break;
        }while (bytevalue != EOF);
    }

    else{
        for (i = 0; i<29; i++){
            imagedata[i] = '\0';
        }
    }

    fclose(file);

    int image_width = imagedata[19]*256 + imagedata[18];
    int image_height = imagedata[23]*256 + imagedata[22];
    
    printf("Image height = %d\n",image_height);
    printf("Image width = %d\n", image_width);

    return 0;
}

