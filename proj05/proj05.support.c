#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"


//Return Infinity
float get_infinity()
{
  union sp_object num;
  num.irep = 0x7F800000;
  return num.frep;
};

//Return not-a-number
float get_nan()
{
  union sp_object num;
  num.irep = 0xFFFFFFFF;
  return num.frep;
};

//Return largest normal
float get_max_normal()
{
  union sp_object num;
  num.irep = 0x7f7fffff;
  return num.frep;
};

//Return smallest normal
float get_min_normal()
{
  union sp_object num;
  num.irep = 0x00ffffff;
  return num.frep;
};

//Return largest denormal
float get_max_denormal()
{
  union sp_object num;
  num.irep = 0x007fffff;
  return num.frep;
};

//Return smallest denormal
float get_min_denormal()
{
  union sp_object num;
  num.irep = 0x00000001;
  return num.frep;
};

//Test if argument is negative
int is_negative( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;
  int count = 0;

  for (i=0; i<23; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count++;
    }
    B.irep = B.irep >> 1;
  }
  
  int count_exp = 0;
  
  for (i=23; i<31; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count_exp++;
    }
    B.irep = B.irep >> 1;
  }
  
  int sign = 0;
  
  for(i=31; i<32; i++){
	if ((B.irep & 0x00000001) == 0x00000001)
    {
      sign++;
    }
    B.irep = B.irep >> 1;
  }

  if(sign == 1){
	  return 1;
  }else{
	  return 0;
  }
};

//Test if argument is infinity
int is_infinity( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;
  int count = 0;

  for (i=0; i<23; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count++;
    }
    B.irep = B.irep >> 1;
  }
  
  int count_exp = 0;
  
  for (i=23; i<31; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count_exp++;
    }
    B.irep = B.irep >> 1;
  }

  if(count == 0){
	if(  count_exp == 8 ){
		return 1;
	}
  }else{
	return 0;  
  }
  
};

//Test if argument is not-a-number
int is_nan( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;
  int count = 0;

  for (i=0; i<23; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count++;
    }
    B.irep = B.irep >> 1;
  }
  
  int count_exp = 0;
  
  for (i=23; i<31; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count_exp++;
    }
    B.irep = B.irep >> 1;
  }
  
  if(count > 0){
	  if(count_exp == 8){
		  return 1;
	  }
  }
  return 0;
  
};

//Test if argument is zero
int is_zero( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;
  int count = 0;

  for (i=0; i<23; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count++;
    }
    B.irep = B.irep >> 1;
  }
  
  int count_exp = 0;
  
  for (i=23; i<31; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count_exp++;
    }
    B.irep = B.irep >> 1;
  }
  
  if( count == 0 ){
	  if( count_exp == 0){
		  return 1;
	  }
  }
  return 0;
};

//Test if argument is denormal
int is_denormal( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;
  int count = 0;

  for (i=0; i<23; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count++;
    }
    B.irep = B.irep >> 1;
  }
  
  int count_exp = 0;
  
  for (i=23; i<31; i++)
  {
    if ((B.irep & 0x00000001) == 0x00000001)
    {
      count_exp++;
    }
    B.irep = B.irep >> 1;
  }

  int sign;
  for(i=31; i<32; i++){
	if ((B.irep & 0x00000001) == 0x00000001)
    {
      sign++;
    }
    B.irep = B.irep >> 1;
  }
  
  if( count > 1 ){
	  if( count_exp == 0){
		  return 1;
	  }
  }
  return 0;
};

//Return negation of argument
float negate( float n )
{
  union sp_object B;
  B.frep = n;
  
  B.irep = ~B.irep;
  B.irep = (B.irep + 0x000000001);
  return B.frep;
};

//Return absoulute value of argument
float absolute( float n )
{
  union sp_object B;
  B.frep = n;
  
  int i;

  for (i=0; i<23; i++)
  {
    B.irep = B.irep >> 1;
  }
  
  for (i=23; i<31; i++)
  {
    B.irep = B.irep >> 1;
  }

  int sign;
  
  for(i=31; i<32; i++){
	if ((B.irep & 0x00000001) == 0x00000001)
    {
	  sign = 1;
    }
    B.irep = B.irep >> 1;
  }
  
  if(sign == 1){
	  B.irep = B.irep & 0x41400000;
  }
  return B.frep;
  
  
  
  
};
