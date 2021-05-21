#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Geometry;

void initRectangle(struct Geometry **object);
void initSquare(struct Geometry **object);
void initCircle(struct Geometry **object);
void initLine(struct Geometry **object);

void printGeometry(struct Geometry* object);

void freeGeometry(struct Geometry* object);

#define SCANF_FMT_CIRCLE    "%f %f %f"
#define SCANF_FMT_RECTANGLE "%f %f %f %f"
#define SCANF_FMT_SQUARE    "%f %f %f"
#define SCANF_FMT_LINE      "%f %f %f %f"


#define PRINTF_FMT_CIRCLE    "Circle with center at %f, %f and radius %f\n"
#define PRINTF_FMT_RECTANGLE "Rectangle with corner at (%f, %f) with width %f and height %f\n"
#define PRINTF_FMT_SQUARE    "Square with corner at (%f, %f) and side %f\n"
#define PRINTF_FMT_LINE      "Line from (%f, %f) to (%f, %f)\n"

struct Geometry
{
    int type;
    float arg[4];
};

void initRectangle(struct Geometry **object)
{
    strcpy((*object)->type,"Rectangle");
    scanf(SCANF_FMT_RECTANGLE,&((*object)->arg[0]),&((*object)->arg[1]),&((*object)->arg[2]),&((*object)->arg[3]));
    printf(PRINTF_FMT_RECTANGLE,(*object)->arg[0],(*object)->arg[1],(*object)->arg[2],(*object)->arg[3]);
}


void initSquare(struct Geometry **object)
{
    strcpy((*object)->type,"Square");
    scanf(SCANF_FMT_SQUARE,&((*object)->arg[0]),&((*object)->arg[1]),&((*object)->arg[2]));
}


void initCircle(struct Geometry **object)
{
    strcpy((*object)->type,"Circle");
    scanf(SCANF_FMT_CIRCLE,&((*object)->arg[0]),&((*object)->arg[1]),&((*object)->arg[2]));
}


void initLine(struct Geometry **object)
{
    strcpy((*object)->type,"Line");
    scanf(SCANF_FMT_LINE,&((*object)->arg[0]),&((*object)->arg[1]),&((*object)->arg[2]),&((*object)->arg[3]));
}


void printGeometry(struct Geometry* object)
{
    if(!strcmp(object->type,"Rectangle"))
    {
        printf(PRINTF_FMT_RECTANGLE,object->arg[0],object->arg[1],object->arg[2],object->arg[3]);
    }
    else if(!strcmp(object->type,"Square"))
    {
        printf(PRINTF_FMT_SQUARE,object->arg[0],object->arg[1],object->arg[2]);

    }
    else if(!strcmp(object->type,"Circle"))
    {
       printf(PRINTF_FMT_CIRCLE,object->arg[0],object->arg[1],object->arg[2]);
    }
    else if(!strcmp(object->type,"Line"))
    {
    printf(PRINTF_FMT_LINE,object->arg[0],object->arg[1],object->arg[2],object->arg[3]);
    }
    else{printf("wut");}
}

void freeGeometry(struct Geometry* object)
{
    free(object);
}

int main()
{
  int n;
  struct Geometry **object;
  scanf("%d", &n);
  printf("%d geometric items\n", n);

  object = malloc(sizeof(struct Geometry*)*n);

  for(int i = 0; i < n; i++)
  {
    char objectType[40];
    scanf("%s", objectType);

    if(!strcmp(objectType, "Rectangle"))
    {
      initRectangle(&object[i]);
    }
    else if (!strcmp(objectType, "Square"))
    {
      initSquare(&object[i]);
    }
    else if(!strcmp(objectType, "Circle"))
    {
      initCircle(&object[i]);
    }
    else if(!strcmp(objectType, "Line"))
    {
      initLine(&object[i]);
    }
    else
    {
      printf("Unknown geometric type %s\n", objectType);
      exit(1);
    }

  }
  
  for(int i = 0; i < n; i++)
  {
    printGeometry(object[i]);
  }
  
  for(int i = 0; i < n; i++)
  {
    freeGeometry(object[i]);
  }

  free(object);
}



