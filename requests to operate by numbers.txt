#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double cos( double arg );

double add( double l, double r )
{
    return l + r;
}

double mult( double a, double b )
{
    return a * b;
}

double division( double a, double b )
{
    return a / b;
}

int ApplicateOp( double (*op) (double l, double r), int argc, char **argv, int curr_arg )
{
    if( curr_arg + 2 >= argc )
    {
        printf( "error, not enough args\n" );
        return 1;
    }
    else
    {
        double arg1, arg2;
        int code1 = sscanf( argv[curr_arg+1], "%lf", &arg1 );
        int code2 = sscanf( argv[curr_arg+2], "%lf", &arg2 );
        if( code1 != 1 || code2 != 1 )
        {
            printf( "error, incorrect args\n" );
            return 1;
        }
        
        print( "%lf\n", op( arg1, arg2 ) );
        return 0;
    }
}


// Implement command-line calculator with following operations:
// Addition:      -a ARG1 ARG2
// Multiplicaton: -m ARG1 ARG2
// Division:      -d ARG1 ARG2
// Help:          -h
int main( int argc, char **argv )
{
    int curr_arg = 1;
    while( curr_arg < argc )
    {
        if( 0 == strcmp( "-a", argv[curr_arg] ) )
        {
            int res = ApplicateOp( add, argc, argv, curr_arg );
            if( res != 0 )
                return res;
            else
                curr_arg += 3;
        }
        else if( 0 == strcmp( "-m", argv[curr_arg] ) )
        {
            int res = ApplicateOp( mult, argc, argv, curr_arg );
            if( res != 0 )
                return res;
            else
                curr_arg += 3;
        }
        else if( 0 == strcmp( "-d", argv[curr_arg] ) )
        {
            int res = ApplicateOp( division, argc, argv, curr_arg );
            if( res != 0 )
                return res;
            else
                curr_arg += 3;
        }
                else if( 0 == stcmp( "-cos", argv[curr_arg] ) )
        {
            double arg;
            sscanf(argv[curr_arg+1], "%lf", &arg);
            
            printf("%lf\n", cos(arg));
            curr_arg += 2;
        }
        else if( 0 == strcmp( "-h", argv[curr_arg] ) )
        {
            printf( "Usage: %s CMD [ARG1] [ARG2]\n", argv[0] );
            printf( "Commands:\n" );
            printf( "Addition:      -a ARG1 ARG2\n");
            printf( "Multiplicaton: -m ARG1 ARG2\n");
            printf( "Division:      -d ARG1 ARG2\n");
            printf( "Help:          -h\n");
            curr_arg += 1;
        }    
    }
    return 0;
}
