`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/11/02 14:39:16
// Design Name: 
// Module Name: add_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


`timescale 1ns / 1ps 
module add_tb(); 
reg [1:0] CLK_50MHZ_FPGA; 
reg [3:0] BUTTONS;
reg [1:0] SWITCHES; 
wire[5:0]  LEDS; 
 
// 调用被仿真模块模块 
ml505top uut (
.CLK_50MHZ_FPGA(CLK_50MHZ_FPGA), 
.BUTTONS(BUTTONS),
.SWITCHES(SWITCHES),
. LEDS(LEDS)); 
 
initial 
     begin    // initial 是仿真用的初始化关键词 
       BUTTONS = 2 ;  // 必须初始化输入信号 
       SWITCHES = 2 ;
      end 
endmodule 
        
