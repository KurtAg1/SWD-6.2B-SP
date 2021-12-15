#include "lo1.h"

int main(int argc, char *argv[])
{
    char buffer[100] = {'\0'};

#ifdef EXTENDED
    while (true)
    {
#endif
        printf("Enter text: ");
        fgets(buffer, 100, stdin);

        int words = 0;
        int characters = 0;
        bool spaceBefore = false;

        for (int i = 0; i < 100; i++)
        {
            if (buffer[i] == '\0')
            {
                break;
            }
            else if (is_space(buffer[i]))
            {
                if (!spaceBefore)
                {
                    words++;
                    spaceBefore = true;
                }
            }
            else
            {
                if (i == 0)
                {
                    words++;
                }
                characters++;
                spaceBefore = false;
            }
        }

        if (should_count_chars(argc, argv))
        {
            printf("%d words (%d characters)\n", words, characters);
        }
        else
        {
            printf("%d words\n", words);
        }
#ifdef EXTENDED
    }
#endif

    return 0;
}