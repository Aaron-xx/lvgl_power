/**
 * @file lv_power_conf.h
 * Configuration file for v8.1.0
 *
 */
/*
 * COPY THIS FILE AS lv_power_conf.h
 */

/* clang-format off */
#if 1 /*Set it to "1" to enable the content*/

#ifndef LV_POWER_CONF_H
#define LV_POWER_CONF_H


/*******************
 * GENERAL SETTING
 *******************/
#define LV_EX_PRINTF       0       /*Enable printf-ing data in poweres and examples*/
#define LV_EX_KEYBOARD     0       /*Add PC keyboard support to some examples (`lv_drivers` repository is required)*/
#define LV_EX_MOUSEWHEEL   0       /*Add 'encoder' (mouse wheel) support to some examples (`lv_drivers` repository is required)*/

/*********************
 * POWER USAGE
 *********************/

/*Show some widget*/
#define LV_USE_POWER_WIDGETS        1
#if LV_USE_POWER_WIDGETS
#define LV_POWER_WIDGETS_SLIDESHOW  0
#endif

/*Printer power, optimized for 800x480*/
#define LV_USE_POWER_PRINTER     0

/*Demonstrate the usage of encoder and keyboard*/
#define LV_USE_POWER_KEYPAD_AND_ENCODER     1

/*Benchmark your system*/
#define LV_USE_POWER_BENCHMARK   0

/*Stress test for LVGL*/
#define LV_USE_POWER_STRESS      0

#endif /*LV_POWER_CONF_H*/

#endif /*End of "Content enable"*/

