/*============================================================================================
	헤더파일 선언 및 선행처리 지시구문 정의
============================================================================================*/
#include "DSP2833x_Device.h"		/* DSP2833x Headerfile Include File */
#include "DSP2833x_Examples.h"		/* DSP2833x Examples Include File */
#include "DSP28x_Project.h"
#define usec_delay 100000

//2021-01-20

Uint16 SW1, SW2;
Uint16 ADC_value;

void main(void)
{
    Uint16 i = 0; // if 조건
    DINT;
    InitSysCtrl();
    EALLOW;     // 여기까지는 항상 적어준다 생각

    SysCtrlRegs.HISPCP.bit.HSPCLK = 1;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;
    GpioCtrlRegs.GPADIR.all = 0x0000003F;
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO27 = 0;

    EDIS;


    GpioDataRegs.GPADAT.all=0x0000003F;
    EINT;
    ERTM;
    while(1)
    {
        SW1 = GpioDataRegs.GPADAT.bit.GPIO12;
        SW2 = GpioDataRegs.GPADAT.bit.GPIO27;


        if(SW1==1)
        {
            i++;
            if(i==1)
            {
                GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
                        GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1;
                        GpioDataRegs.GPATOGGLE.bit.GPIO2 = 1;
                        GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
                        GpioDataRegs.GPATOGGLE.bit.GPIO4 = 1;
                        GpioDataRegs.GPATOGGLE.bit.GPIO5 = 1;
                        DELAY_US(usec_delay);
            }
            if(i==2)
            {
                GpioDataRegs.GPATOGGLE.bit.GPIO0 = 0;
                                        GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1;
                                        GpioDataRegs.GPATOGGLE.bit.GPIO2 = 0;
                                        GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
                                        GpioDataRegs.GPATOGGLE.bit.GPIO4 = 0;
                                        GpioDataRegs.GPATOGGLE.bit.GPIO5 = 1;
                                        DELAY_US(usec_delay);
                                        i==0;
            }

        }
        if(SW2==1)
        {
            GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
            DELAY_US(usec_delay);
                    GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1;
                    DELAY_US(usec_delay);
                    GpioDataRegs.GPATOGGLE.bit.GPIO2 = 1;
                    DELAY_US(usec_delay);
                    GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
                    DELAY_US(usec_delay);
                    GpioDataRegs.GPATOGGLE.bit.GPIO4 = 1;
                    DELAY_US(usec_delay);
                    GpioDataRegs.GPATOGGLE.bit.GPIO5 = 1;

                    DELAY_US(usec_delay);
        }
    }
}
