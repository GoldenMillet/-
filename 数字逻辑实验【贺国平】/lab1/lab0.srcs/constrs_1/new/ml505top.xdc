set_property PACKAGE_PIN T18 [get_ports {BUTTONS[3]}]
set_property PACKAGE_PIN N15 [get_ports {BUTTONS[2]}]
set_property PACKAGE_PIN P16 [get_ports {BUTTONS[1]}]
set_property PACKAGE_PIN R18 [get_ports {BUTTONS[0]}]
set_property PACKAGE_PIN T22 [get_ports {LEDS[0]}]
set_property PACKAGE_PIN T21 [get_ports {LEDS[1]}]
set_property PACKAGE_PIN U22 [get_ports {LEDS[2]}]
set_property PACKAGE_PIN U21 [get_ports {LEDS[3]}]
set_property PACKAGE_PIN V22 [get_ports {LEDS[4]}]
set_property PACKAGE_PIN W22 [get_ports {LEDS[5]}]
set_property PACKAGE_PIN F22 [get_ports {SWITCHES[0]}]
set_property PACKAGE_PIN G22 [get_ports {SWITCHES[1]}]
set_property -dict { PACKAGE_PIN AB12   IOSTANDARD LVCMOS33 } [get_ports { CLK_125MHZ_FPGA}]; #IO_L13P_T2_MRCC_35 Sch=sysclk
create_clock -add -name sys_clk_pin -period 8.00 -waveform {0 4} [get_ports { CLK_125MHZ_FPGA }];
set_property IOSTANDARD LVCMOS33 [get_ports {BUTTONS[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {BUTTONS[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {BUTTONS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {BUTTONS[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LEDS[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SWITCHES[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SWITCHES[1]}]

## A neat way to assign both the pin signal name and the I/O standard at the same time:
# set_property -dict { PACKAGE_PIN L19   IOSTANDARD LVCMOS33 } [get_ports { BUTTONS[3] }];
