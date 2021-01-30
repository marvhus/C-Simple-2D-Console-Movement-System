#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)

int printMap(px, py, GameMap, mapSx, mapSy)
{
    system("clear");
    char output;

    for (int x = 0; x < mapSx; i++)
    {
        for (int y = 0; y < mapSy; i++)
        {
            if (px == x && py = y)
            {
                output += "p";
            }
            else if (GameMap[x][y] == 1)
            {
                output += "x";
            }
            else if (GameMap[x][y] == 1)
            {
                output += " ";
            }
        }
        printf("%d\n", output);
        output = "";
    }
}

int checkInput(px, py, GameMap)
{ 
    int speed = 1, ammount, cordinates;
    char userInput, command;
    printf("Movement commands: W,A,S,D for movement. Q to exit.\nyou can also add a number between 1 and 9 in front of the movement commands.\nExample: 4w\n");
    
    printf(">  ");
    scanf("%d", &userInput);

    try
    {
        ammount = ( (int) userInput[0] ) * speed;
        command = (char) userInput[1]; 
    }
    catch(...)
    {
        ammount = speed;
        command = userInput;
    }
    // Thing to make the command lowercase START
    command = tolower(command);
    // Thing to make the command lowercase END

    cordinates = commands(px, py, ammount, command, GameMap);
    return cordinates;
}

int commands(px, py, ammount, command, GameMap)
{
    if (command == "q")
    {
        exit(0);
    }
    // Movement if statements
    // ##### Move UP ########################################
    
    else if (command == "w")
    {
        int x = px-ammount, y = py;
        if ( !colission )
        {
            px -= ammount;
        }
    }

    // ##### Move DOWN ######################################
    
    else if (command == "s")
    {
        int x = px+ammount, y = py;
        if ( GameMap[x][y] != 1 )
        {
            px += ammount;
        }
    }

    // ##### Move LEFT ######################################
    
    else if (command == "a")
    {
        int x = px, y = py-ammount;
        if ( GameMap[x][y] != 1 )
        {
            py -= ammount;
        }
    }

    // ##### Move RIGHT #####################################
    
    else if (command == "d")
    {
        int x = px, y = py+ammount;
        if ( GameMap[x][y] != 1 )
        {
            py += ammount;
        }
    }

    // ######################################################
    // Atempt on patching the out of bounds glitch
    //#######################
    if ( px < 0 )       // w
    {                   // w
        px = 1;         // w
    }                   // w
    //#######################
    if ( px > 8 )       // s
    {                   // s
        px = 7;         // s
    }                   // s
    //#######################
    if ( py < 0 )       // a
    {                   // a
        py = 1;         // a
    }                   // a
    //#######################
    if ( py >  15 )     // d
    {                   // d
        py = 14;        // d
    }                   // d
    //#######################

    int cordinates[2] = {px, py};
    return cordinates[2];
}

int main()
{
    int mapSx = 8, mapSy = 15;
    int px = 3, py = 3;
    int cordinates[2];
    int GameMap[8][15] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    // Walls = 1 = x    Floor = 0 = (space)     Player = P

    while (true)
    {
        printMap(px, py, GameMap, mapSx, mapSy);
        printf("PlayerX: %d\nPlayerY: %d\n", px, py);
        cordinates[2] = checkInput(px, py, GameMap);
        px = cordinates[0];
        py = cordinates[1];
    }
}
