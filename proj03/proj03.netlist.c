
/******************************************************************************
  Project #3 skeleton
  Ben Traines
  5/22/2018
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  // Replace with code to generate four input signals
  
  Switch( SD("1a"), w, 'w' );	//Switch w controlled by 'w' key
  Switch( SD("2a"), x, 'x' );	//Switch x controlled by 'x' key
  Switch( SD("3a"), y, 'y' );
  Switch( SD("4a"), z, 'z' );  

  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);

  // Replace with code to display eight output signals
  
  Probe ( (SD("1e-1f"), "Present"), Present );
  Probe ( (SD("2e-2f"), "a"), a );
  Probe ( (SD("2f-3f"), "b"), b );
  Probe ( (SD("3f-4f"), "c"), c );
  Probe ( (SD("4e-4f"), "d"), d );
  Probe ( (SD("3e-4e"), "e"), e );
  Probe ( (SD("2e-3e"), "f"), f );
  Probe ( (SD("3e-3f"), "g"), g );

}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Replace with declarations for any auxiliary Signals

  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9;

  // Replace with circuit implementation (Not, And, Or gates)

  Not( SD(sd, "1a"), w, notw );
  Not( SD(sd, "2a"), x, notx );
  Not( SD(sd, "3a"), y, noty );
  Not( SD(sd, "4a"), z, notz ); 

  And ( SD(sd,"2d"), (noty, z, notx), and1 );
  And ( SD(sd,"3d"), (notw,noty,x), and2 );
  And ( SD(sd,"4d"), (w,notx,notz), and3 );
  And ( SD(sd,"1e"), (w, notx), and4);
  And ( SD(sd,"2e"), (x, noty, z), and5);
  And ( SD(sd,"4e"), (notw, x, noty, z), and7);
  And ( SD(sd,"5e"), (w, notx, noty), and8);
  And ( SD(sd,"6e"), (w, notx, notz), and9);

  Or ( SD(sd,"1f"), (and1, and2, and3), Present);
  Or ( SD(sd,"2f"), (and4, and5), a);
  Or ( SD(sd,"3f"), (notx, notz), b);
  Or ( SD(sd,"3f"), (w,x,y,z), c);
  Or ( SD(sd,"5f"), (and7, and8), d);
  Or ( SD(sd,"6f"), (and9), e);
  Or ( SD(sd,"7f"), (and2, and4), f);
  Or ( SD(sd,"8f"), (and2, and4), g);

 
}

