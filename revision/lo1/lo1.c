#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char buffer[100] = {'\0'};
    bool showChars = false;
    if (argc > 1)
    {
        // check for flag
        showChars = (argv[1][0] == '-' && argv[1][1] == 'c');
    }

    printf("Enter text: ");
    fgets(buffer, 100, stdin);

    int words = 0;
    int characters = 0;

    for(int i = 0; i < 100; i++){
        if(buffer[i] == '\0'){
            break;
        }
        else if(buffer[i] == ' '){
            words++;
        }
        else{
            characters++;
        }
    }

    if(showChars){
        printf("%d words (%d characters)\n", words, characters);
    }
    else{
        printf("%d words\n", words);
    }
    
    return 0;
}