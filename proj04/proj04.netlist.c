
/******************************************************************************
  Project #4 skeleton
  Ben Traines
  05/25/2018
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  Pulser ((SD("1a"), "i - Init"), Init, 'i', 1000);
  Pulser ((SD("1a"), "c - Clock"), Clock, 'c', 1000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  
  Probe ((SD("1e"), "w"), w);
  Probe ((SD("1e"), "x"), x);
  Probe ((SD("1e"), "y"), y);
  Probe ((SD("1e"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8;
  Signal W, X, Y, Z;

  // Replace with code for your DFFs
  Dff ((SD("1b"), "Dff3"), (Init, W, Clock, Zero), w);
  Dff ((SD("1b"), "Dff2"), (Zero, X, Clock, Init), x);
  Dff ((SD("1b"), "Dff1"), (Init, Y, Clock, Zero), y);
  Dff ((SD("1b"), "Dff0"), (Zero, Z, Clock, Init), z); 

  // Replace with circuit implementation (Not, And, Or gates)

  Not( SD(sd, "1a"), w, notw );
  Not( SD(sd, "2a"), x, notx );
  Not( SD(sd, "3a"), y, noty );
  Not( SD(sd, "4a"), z, notz );

  And( SD(sd, "2d"), (notw, x, y, notz), and1);
  And( SD(sd, "3d"), (w, notx, noty), and2);
  And( SD(sd, "4d"), (notw, notx, noty, z), and3);
  And( SD(sd, "2e"), (notw, x, noty, notz), and4);
  And( SD(sd, "3e"), (w, notx, y, notz), and5);
  And( SD(sd, "4e"), (w, notx, noty, z), and6);
  And( SD(sd, "2f"), (notx, notz), and7);
  And( SD(sd, "3f"), (x, z), and8);

  Or( SD(sd, "1b"), (and1, and2), W);
  Or( SD(sd, "2b"), (and3, and4, and5), X);
  Or( SD(sd, "3b"), (and4, and6), Y);
  Or( SD(sd, "4b"), (and7, and8), Z); 
}

