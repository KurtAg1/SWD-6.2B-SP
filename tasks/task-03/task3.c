#include <stdio.h>
#include <string.h>  /* strlen */
#include <stdlib.h>  /* atoi, rand, srand */
#include <stdbool.h> /* bools */
#include <time.h>

#define COORD_MAX 100 // maximum x & y coord.
#define POINTS_MAX 1000 // no. of points to generate
#define POINT_NAME_BUFFER 10 // characters to store point name

struct Rectangle
{
    unsigned short xCoord;
    unsigned short yCoord;
    unsigned short width;
    unsigned short height;
};

struct Point
{
    unsigned short xCoord;
    unsigned short yCoord;
    char *name;
};

bool equals_point(struct Point point1, struct Point point2)
{
    return (point1.xCoord == point2.xCoord && point1.yCoord == point2.yCoord);
}

bool equals_rect(struct Rectangle rect1, struct Rectangle rect2)
{
    return memcmp(&rect1, &rect2, sizeof(struct Rectangle)) == 0;
}

bool contains(struct Rectangle rect, struct Point point)
{
    for (int x = rect.xCoord; x < (rect.xCoord + rect.width); x++)
    {
        for (int y = rect.yCoord; y < (rect.yCoord + rect.height); y++)
        {
            if (x == point.xCoord && y == point.yCoord)
            {
                return true;
            }
        }
    }
    return false;
}

unsigned short generateCoord(int max){
    return rand() % (max + 1);
}

int main()
{
    // Use current time as seed for random generator
    srand(time(0));

    // generate a rectangle of 50x50 at a random location
    struct Rectangle rect;
    rect.height = 50;
    rect.width = 50;

    // generate x coord from 0 to max (inclusive)
    rect.xCoord = generateCoord(COORD_MAX - rect.width);

    // generate y coord from 0 to max (inclusive)
    rect.yCoord = generateCoord(COORD_MAX - rect.height);

    printf("Rectangle generated at X: %d | Y: %d\n", rect.xCoord, rect.yCoord);

    // generate 1000 unique points
    // TODO: check if unique
    struct Point point;
    point.name = malloc(POINT_NAME_BUFFER);
    int hits = 0;

    bool xCoordsUsed[COORD_MAX + 1] = {false};
    bool yCoordsUsed[COORD_MAX + 1] = {false};

    for (int i = 0; i < POINTS_MAX; i++)
    {
        snprintf(point.name, POINT_NAME_BUFFER, "Point%d", (i+1));
        bool numGenerated = false;
        while(numGenerated == false){
            // infinite loop happens here
            point.xCoord = generateCoord(COORD_MAX);
            point.yCoord = generateCoord(COORD_MAX);
            if(!(xCoordsUsed[point.xCoord] && yCoordsUsed[point.yCoord])){
                // point is available
                xCoordsUsed[point.xCoord] = true;
                yCoordsUsed[point.yCoord] = true;
                numGenerated = true;
            }
        }
        
        // printf("Point generated at X: %d | Y: %d\n", point.xCoord, point.yCoord);
        if (contains(rect, point))
        {
            hits++;
        }
    }
    double percentageHit = (double)hits / (double)POINTS_MAX * 100;
    printf("TOTAL HITS: %d | PERCENTAGE HIT: %.2f%%\n", hits, percentageHit);

    return 0;
}