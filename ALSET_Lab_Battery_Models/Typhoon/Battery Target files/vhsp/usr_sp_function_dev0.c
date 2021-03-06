// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------

// x86 libraries:
#include "../include/sp_functions_dev0.h"

// H files from Advanced C Function components
//#include "example_dll.h"

// Header files from additional sources (Advanced C Function)
// ----------------------------------------------------------------------------------------
// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: common_consts.template----------------------------------------100};

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines
//@cmp.def.end

//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables

//@cmp.var.start
// variables
double _nominal_voltage__out;
double _battery_constant7__out = 3.25;
double _battery_voc_calculation_constant14__out = 0.3201;
double _battery_voc_calculation_constant13__out = 3.0;
double _battery_voc_calculation_constant12__out = 0.1178;
double _battery_voc_calculation_constant11__out = 2.0;
double _battery_voc_calculation_constant10__out = 0.2156;
double _battery_voc_calculation_constant9__out = 3.6;
double _battery_voc_calculation_constant8__out = -35.0;
double _battery_voc_calculation_constant7__out = -1.031;
double _battery_constant6__out = 100.0;
double _battery_rs_value__out = 0.005;
double _battery_constant5__out = 100.0;
double _battery_constant4__out = 1.0;
double _battery_constant3__out = 3600.0;
double _rated_capacity__out;
double _battery_constant2__out = 100.0;
double _soc0__out;
double _battery_product1__out;
double _battery_constant1__out = 1.0;
double _battery_sub1__out;
double _battery_product2__out;
double _battery_product3__out;
double _battery_integrator1__out;
double _battery_gain1__out;
double _battery_limit1__out;
double _battery_product4__out;
double _battery_sub2__out;
double _battery_product5__out;
double _battery_limit2__out;
double _ia2_ia1__out;
double _battery_current_filiter__out;
double _battery_current_filiter__b_coeff[1] = {0.0004998750000000385};
double _battery_current_filiter__a_coeff[2] = {1.0, -0.999500125};
double _battery_current_filiter__a_sum;
double _battery_current_filiter__b_sum;
double _battery_current_filiter__delay_line_in;
unsigned int _battery_current_filiter__i;
double _battery_vs__out;
double _battery_product6__out;
double _battery_voc_calculation_product8__out;
double _battery_voc_calculation_mathematical_function1__out;
double _battery_voc_calculation_product7__out;
double _battery_voc_calculation_product9__out;
double _battery_voc_calculation_mathematical_function2__out;
double _battery_voc_calculation_product10__out;
double _battery_voc_calculation_mathematical_function3__out;
double _battery_voc_calculation_product11__out;
double _battery_voc_calculation_sum1__out;
double _battery_sub3__out;
double _battery_limit3__out;
double _battery_product7__out;
double _battery_product8__out;
//@cmp.var.end

//@cmp.svar.start
// state variables
double _battery_integrator1__state;
double _battery_current_filiter__states[1];
//@cmp.svar.end
// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_user_sp_cpu_dev0() {

#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif

    //@cmp.init.block.start























    _battery_integrator1__state =  _battery_product3__out;








    for (_battery_current_filiter__i = 0; _battery_current_filiter__i < 1; _battery_current_filiter__i++) {
        _battery_current_filiter__states[_battery_current_filiter__i] = 0.0;
    }

















    HIL_OutFloat(137101312, 0.0);

    HIL_OutAO(0x4000, 0.0f);

    //@cmp.init.block.end
}
// generated using template: common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_user_sp_cpu_dev0() {

#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif

    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Nominal_Voltage
    _nominal_voltage__out = XIo_InFloat(0x55000100);

    // Generated from the component: Battery.Constant7

    // Generated from the component: Battery.VOC_calculation.Constant14

    // Generated from the component: Battery.VOC_calculation.Constant13

    // Generated from the component: Battery.VOC_calculation.Constant12

    // Generated from the component: Battery.VOC_calculation.Constant11

    // Generated from the component: Battery.VOC_calculation.Constant10

    // Generated from the component: Battery.VOC_calculation.Constant9

    // Generated from the component: Battery.VOC_calculation.Constant8

    // Generated from the component: Battery.VOC_calculation.Constant7

    // Generated from the component: Battery.Constant6

    // Generated from the component: Battery.Rs_value

    // Generated from the component: Battery.Constant5

    // Generated from the component: Battery.Constant4

    // Generated from the component: Battery.Constant3

    // Generated from the component: Rated_Capacity
    _rated_capacity__out = XIo_InFloat(0x55000108);

    // Generated from the component: Battery.Constant2

    // Generated from the component: SOC0
    _soc0__out = XIo_InFloat(0x55000104);

    // Generated from the component: Battery.Product1
    _battery_product1__out = (_soc0__out) * 1.0 / (_battery_constant2__out);

    // Generated from the component: Battery.Constant1

    // Generated from the component: Battery.Sub1
    _battery_sub1__out = _battery_constant1__out - _battery_product1__out;

    // Generated from the component: Battery.Product2
    _battery_product2__out = (_battery_sub1__out * _rated_capacity__out);

    // Generated from the component: Battery.Product3
    _battery_product3__out = (_battery_product2__out * _battery_constant3__out);

    // Generated from the component: Battery.Integrator1
    _battery_integrator1__out = _battery_integrator1__state;

    // Generated from the component: Battery.Gain1
    _battery_gain1__out = 0.0002777777777777778 * _battery_integrator1__out;

    // Generated from the component: Battery.Limit1
    if (_battery_gain1__out > 9.999) {
        _battery_limit1__out = 9.999;
    } else if (_battery_gain1__out < 0.0) {
        _battery_limit1__out = 0.0;
    } else {
        _battery_limit1__out = _battery_gain1__out;
    }

    // Generated from the component: Battery.Product4
    _battery_product4__out = (_battery_limit1__out) * 1.0 / (_rated_capacity__out);

    // Generated from the component: Battery.Sub2
    _battery_sub2__out = _battery_constant4__out - _battery_product4__out;

    // Generated from the component: Battery.Product5
    _battery_product5__out = (_battery_constant5__out * _battery_sub2__out);

    // Generated from the component: Battery.Limit2
    if (_battery_product5__out > 100.0) {
        _battery_limit2__out = 100.0;
    } else if (_battery_product5__out < 0.0) {
        _battery_limit2__out = 0.0;
    } else {
        _battery_limit2__out = _battery_product5__out;
    }

    // Generated from the component: Ia2.Ia1
    _ia2_ia1__out = HIL_InAO(0x2);

    // Generated from the component: Battery.Current filiter
    _battery_current_filiter__a_sum = 0.0f;
    _battery_current_filiter__b_sum = 0.0f;
    _battery_current_filiter__delay_line_in = 0.0f;
    for (_battery_current_filiter__i = 0; _battery_current_filiter__i < 1; _battery_current_filiter__i++) {
        _battery_current_filiter__b_sum += _battery_current_filiter__b_coeff[_battery_current_filiter__i] * _battery_current_filiter__states[_battery_current_filiter__i + 0];
    }
    _battery_current_filiter__a_sum += _battery_current_filiter__states[0] * _battery_current_filiter__a_coeff[1];
    _battery_current_filiter__delay_line_in = _ia2_ia1__out - _battery_current_filiter__a_sum;
    _battery_current_filiter__out = _battery_current_filiter__b_sum;


    // Generated from the component: Battery.Vs
    _battery_vs__out = (_battery_rs_value__out * _battery_current_filiter__out);

    // Generated from the component: Battery.Product6
    _battery_product6__out = (_battery_limit2__out) * 1.0 / (_battery_constant6__out);

    // Generated from the component: Battery.VOC_calculation.Product8
    _battery_voc_calculation_product8__out = (_battery_voc_calculation_constant8__out * _battery_product6__out);

    // Generated from the component: Battery.VOC_calculation.Mathematical function1
    _battery_voc_calculation_mathematical_function1__out = pow(M_E, _battery_voc_calculation_product8__out);

    // Generated from the component: Battery.VOC_calculation.Product7
    _battery_voc_calculation_product7__out = (_battery_voc_calculation_constant7__out * _battery_voc_calculation_mathematical_function1__out);

    // Generated from the component: Battery.VOC_calculation.Product9
    _battery_voc_calculation_product9__out = (_battery_product6__out * _battery_voc_calculation_constant10__out);

    // Generated from the component: Battery.VOC_calculation.Mathematical function2
    _battery_voc_calculation_mathematical_function2__out = pow(_battery_product6__out, _battery_voc_calculation_constant11__out);

    // Generated from the component: Battery.VOC_calculation.Product10
    _battery_voc_calculation_product10__out = (_battery_voc_calculation_constant12__out * _battery_voc_calculation_mathematical_function2__out);

    // Generated from the component: Battery.VOC_calculation.Mathematical function3
    _battery_voc_calculation_mathematical_function3__out = pow(_battery_product6__out, _battery_voc_calculation_constant13__out);

    // Generated from the component: Battery.VOC_calculation.Product11
    _battery_voc_calculation_product11__out = (_battery_voc_calculation_constant14__out * _battery_voc_calculation_mathematical_function3__out);

    // Generated from the component: Battery.VOC_calculation.Sum1
    _battery_voc_calculation_sum1__out = _battery_voc_calculation_product7__out + _battery_voc_calculation_constant9__out + _battery_voc_calculation_product9__out - _battery_voc_calculation_product10__out + _battery_voc_calculation_product11__out;

    // Generated from the component: Battery.Sub3
    _battery_sub3__out = _battery_voc_calculation_sum1__out - _battery_vs__out;

    // Generated from the component: Battery.Limit3
    if (_battery_sub3__out > 10.0) {
        _battery_limit3__out = 10.0;
    } else if (_battery_sub3__out < 0.0) {
        _battery_limit3__out = 0.0;
    } else {
        _battery_limit3__out = _battery_sub3__out;
    }

    // Generated from the component: Battery.Product7
    _battery_product7__out = (_battery_limit3__out) * 1.0 / (_battery_constant7__out);

    // Generated from the component: Battery.Product8
    _battery_product8__out = (_battery_product7__out * _nominal_voltage__out);

    // Generated from the component: Vsp1.Vs1

    HIL_OutFloat(137101312, (float) _battery_product8__out);

    // Generated from the component: SOC
    HIL_OutAO(0x4000, (float)_battery_limit2__out);
    //@cmp.out.block.end


    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Battery.Integrator1
    _battery_integrator1__state += _ia2_ia1__out * 5e-05;


    // Generated from the component: Battery.Current filiter
    _battery_current_filiter__states[0] = _battery_current_filiter__delay_line_in;


    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------  //-----------------------------------------------------------------------------------------