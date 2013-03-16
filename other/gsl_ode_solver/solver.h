{% load kdev_filters %}
/*

 {{ license|lines_prepend:" * " }}
 */


#ifndef {% include "include_guard_cpp.txt" %}
#define {% include "include_guard_cpp.txt" %}


#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>


#include <iostream>


/**
 * Computes the derivatives of the equation
 * 
 * @param t current time, or independent variable
 * @param y current values of the dependent variables
 * @param dydt computed derivatives of dependent variables
 * @param params additional parameters
 * 
 * @returns GSL_SUCCESS on success, or any GSL error code on failure
 */
int ydot(double t, const double y[], double dydt[], void* params)
{
    // TODO: Write derivatives to dydt
    // like dydt[0] = 1 - y[0]*y[0];
    
    
    return GSL_SUCCESS;
}


/**
 * @brief Solves the ordinary differential equation
 * 
 * This function solves the differential equation defined by ydot
 *
 * @param h initial step size
 * @param epsabs required absolute precision
 * @param epsrel required relative precision
 * @param T length of the time interval in which to solve
 * 
 **/
void solve(double h, double epsabs, double epsrel, double T)
{
    const int d = {{ dimension }}; // Number of dimensions
    void* params = 0; // Extra parameters, passed to ydot
    
    
    gsl_odeiv2_system system = {ydot, 0, d, params};
    gsl_odeiv2_driver* driver = gsl_odeiv2_driver_alloc_y_new(&system, gsl_odeiv2_step_rk4, h, epsabs, epsrel);
    
    
    double y[d]; // Initial condition
    
    
    double t = 0;
    while (t < T)
    {
        // Propagate the solution for one h
        // The actual integrator step size is adjusted by the solver
        gsl_odeiv2_driver_apply(driver, &t, t+h, y);
        
        
        // Print out the current values
        std::cout << t;
        for (int c = 0; c < d; ++c)
        {
            std::cout << " " << y[c];
        }
        std::cout << std::endl;
    }
}


#endif // {% include "include_guard_cpp.txt" %}