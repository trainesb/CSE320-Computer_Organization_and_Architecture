
float get_infinity();       /* Return infinity                   */
float get_nan();            /* Return not-a-number               */
float get_max_normal();     /* Return largest normal             */
float get_min_normal();     /* Return smallest normal            */
float get_max_denormal();   /* Return largest denormal           */
float get_min_denormal();   /* Return smallest denormal          */

int is_negative( float );   /* Test if argument is negative      */
int is_infinity( float );   /* Test if argument is infinity      */
int is_nan( float );        /* Test if argument is not-a-number  */
int is_zero( float );       /* Test if argument is zero          */
int is_denormal( float );   /* Test if argument is denormal      */

float negate( float );      /* Return negation of argument       */
float absolute( float );    /* Return absolute value of argument */

union sp_object
{
  float frep;
  unsigned int irep;
};

