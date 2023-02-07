//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Random number definition
#define RND1 ((double)((double)rand()/(double)RAND_MAX))

int main(){

  //RANDOM NUMBERS WITH TIME SEED
  time_t t;
  srand((unsigned) time(&t));	        //Random number generator with time seed

  //CONSTANTS DECLARATION
  const int     n_ene = 2;              //Number of enemies on the simulation
  const int     n_step = 100;         //Steps the enemies move in the simulation

  const int     vel_freq = 5;           //Frequency for updating velocities

  const float   x_size = 60.0;          //Length; x
  const float   y_size = 40.0;          //Length; y

  const float   vel_x = 1.0;            //Velocity; x
  const float   vel_y = 1.0;            //Velocity; y

  const float   dt = 0.5;               //Integration step; time interval

  float x_ene[n_ene],y_ene[n_ene];      //Enemies postion; x y vectors
  float vx_ene[n_ene],vy_ene[n_ene];    //Enemies velocities; x y vectors

  //OPENING MOVIE FILE
  FILE *movie_file = fopen("./output/movie.xyz","w");
  fprintf(movie_file,"\t%d\nFRAME\n",n_ene);

  //POSITIONS AND VELOCITIES INITIALIZATION
  for(int i=0; i<n_ene; i++){
    x_ene[i] = RND1*x_size;
    y_ene[i] = RND1*y_size;

    vx_ene[i] = RND1*vel_x;
    vy_ene[i] = RND1*vel_y;

    //PRINTING FIRST CONFIGURATION
    fprintf(movie_file,"C\t%f\t%f\t0.0\n",x_ene[i],y_ene[i]);
  }

  //Loop over number of steps
  for(int j=1; j<=n_step; j++){
    fprintf(movie_file,"\t%d\nFRAME\n",n_ene);
    //Loop over enemies
    for(int i=0; i<n_ene; i++){

      //Moving particles ballistically
      x_ene[i] += vx_ene[i]*dt;
      y_ene[i] += vy_ene[i]*dt;

      //Re-assigning velocities
/*
      vx_ene[i] = RND1*vel_x;
      vy_ene[i] = RND1*vel_y;
*/

      //Re-assigning velocities with frequency
/*
      if(j%vel_freq == 0)  vx_ene[i] = RND1*vel_x;
      if(j%vel_freq == 0)  vy_ene[i] = RND1*vel_y;
*/

      //Periodic boundary conditions
/*
      x_ene[i] -= floor(x_ene[i]/x_size)*x_size;	//PBC x-direction
      y_ene[i] -= floor(y_ene[i]/y_size)*y_size;	//PBC y-direction
*/

      //Non slip boundary conditions (x)
/*
      if (x_ene[i] < 0){
        const float time_in_wall = x_ene[i] / vx_ene[i];
        x_ene[i] -= 2.0 * vx_ene[i] * time_in_wall;
        y_ene[i] -= 2.0 * vy_ene[i] * time_in_wall;
        vx_ene[i] *= -1.0;
        vy_ene[i] *= -1.0;
      }
      if (x_ene[i] > x_size){
        const float time_in_wall = (x_ene[i]-x_size) / vx_ene[i];
        x_ene[i] -= 2.0 * vx_ene[i] * time_in_wall;
        y_ene[i] -= 2.0 * vy_ene[i] * time_in_wall;
        vx_ene[i] *= -1.0;
        vy_ene[i] *= -1.0;
      }
      //Non slip boundary conditions (y)
      if (y_ene[i] < 0){
        const float time_in_wall = y_ene[i] / vy_ene[i];
        x_ene[i] -= 2.0 * vx_ene[i] * time_in_wall;
        y_ene[i] -= 2.0 * vy_ene[i] * time_in_wall;
        vx_ene[i] *= -1.0;
        vy_ene[i] *= -1.0;
      }
      if (y_ene[i] > y_size){
        const float time_in_wall = (y_ene[i]-y_size) / vy_ene[i];
        x_ene[i] -= 2.0 * vx_ene[i] * time_in_wall;
        y_ene[i] -= 2.0 * vy_ene[i] * time_in_wall;
        vx_ene[i] *= -1.0;
        vy_ene[i] *= -1.0;
      }
*/
      //Printing positions
      fprintf(movie_file,"C\t%f\t%f\t0.0\n",x_ene[i],y_ene[i]);
    }
  }
  
  //CLOSING MOVIE FILE
  fclose(movie_file);

  return 0;
}//End main
