#include<stdio.h>
int main()
{
    int N, T;
    int grid[6][6];
    int i,j;
    int rowtotal, columntotal;
    int rowmax = 0, columnmax = 0;
    int maxRisk = -1;
    int count = 0;
    int maindiagonal= 0, secdiagonal= 0;
    int boundary = 0;
    int hotspots = 0;
    
    printf("Enter the size of the grid between (3 to 6): ");
    scanf("%d", &N);
    while (N < 3 || N > 6)
    {
        printf("this is an invalid,enter again: ");
        scanf("%d", &N);
    }
    printf("\nEnter the risk scores:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Enter row %d column %d: ", i + 1, j + 1);
            scanf("%d", &grid[i][j]);

            while (grid[i][j] < 0 || grid[i][j] > 100)
            {
                printf("The score is invalid.Enter again: ");
                scanf("%d", &grid[i][j]);
            }
        }
    }
    printf("\nEnter threshold T (1 to 100): ");
    scanf("%d", &T);
    while (T < 1 || T > 100)
    {
        printf("Invalid threshold  value.  Enter again: ");
        scanf("%d", &T);
    }
     printf("\n----- Gridwatch -----\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%4d", grid[i][j]);

        printf("\n");
    }
    printf("\n-----row totals-----\n");
    for (i = 0; i < N; i++)
    {
        rowtotal = 0;

        for (j = 0; j < N; j++)
            rowtotal += grid[i][j];

        printf("Row %d = %d\n", i + 1, rowtotal);

        if (rowtotal > rowmax)
            rowmax = rowtotal;
    }

    printf("Highest row total = %d\n", rowmax);
    printf("Highest row(s): ");

    for (i = 0; i < N; i++)
    {
        rowtotal= 0;

        for (j = 0; j < N; j++)
            rowtotal += grid[i][j];

        if (rowtotal == rowmax)
            printf("%d ", i + 1);
    }

    printf("\n\n-----column totals-----\n");
    for (j = 0; j < N; j++)
    {
        columntotal = 0;

        for (i = 0; i < N; i++)
            columntotal += grid[i][j];

        printf("Column %d = %d\n", j + 1, columntotal);

        if (columntotal > columnmax)
            columnmax = columntotal;
    }
    printf("Highest column total = %d\n", columnmax);
    printf("Highest column(s): ");
    for (j = 0; j < N; j++)
    {
        columntotal = 0;

        for (i = 0; i < N; i++)
            columntotal += grid[i][j];

        if (columntotal == columnmax)
            printf("%d ", j + 1);
    }
    printf("\n\n-----full grid analysis -----\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] > maxRisk)
                maxRisk = grid[i][j];

            if (grid[i][j] >= T)
                count++;
        }
    }
    printf("Highest risk score = %d\n", maxRisk);
    printf("Position(s) of highest risk:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == maxRisk)
                printf("Row %d Column %d\n", i + 1, j + 1);
        }
    }

    printf("Cells >= T = %d\n", count);
    printf("\n----- Diagonal Analysis-----\n");
    for (i = 0; i < N; i++)
    {
        maindiagonal += grid[i][i];
        secdiagonal+= grid[i][N - 1 - i];
    }

    printf("Main diagonal sum = %d\n", maindiagonal);
    printf("Secondary diagonal sum = %d\n", secdiagonal);

    if (maindiagonal == secdiagonal)
        printf("Both the diagonals are balanced.\n");
    else
        printf("The diagonals are not balanced.\n");
        
    printf("\n----- Boundary Analysis -----\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 ||
                j == 0 || j == N - 1)
            {
                boundary += grid[i][j];
            }
        }
    }

    printf("Boundary total = %d\n", boundary);
    printf("\n----- Local Hotspots-----\n");
     for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j < N - 1; j++)
        {
            if (grid[i][j] >= T &&
                grid[i][j] > grid[i - 1][j] &&
                grid[i][j] > grid[i + 1][j] &&
                grid[i][j] > grid[i][j - 1] &&
                grid[i][j] > grid[i][j + 1])
            {
                printf("Hotspot at Row %d Column %d\n",
                       i + 1, j + 1);
                hotspots++;
            }
        }
    }
    if (hotspots == 0)
        printf("No local hotspots found.\n");
    printf("\n-----Final Decision -----\n");

    if (hotspots > 0)
        printf("Status: Critical\n");
    else if (count >= N)
        printf("Status: Warning \n");
    else
        printf("Status: Normal\n");

    printf("\nGridwatch Analysis completed.\n");

    return 0;
}
