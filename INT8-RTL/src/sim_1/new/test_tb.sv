`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/06/06 12:55:17
// Design Name: 
// Module Name: test_tb
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


module test_tb(

    );
logic clk;
logic signed [7:0] a;
logic signed [7:0] b;
logic signed [7:0] c;
logic signed [15:0] ac;
logic signed [15:0] bc;
logic signed [15:0] ac_ref;
logic signed [15:0] bc_ref;
//
always@(posedge clk)
begin
   ac_ref<=a*c;
   bc_ref<=b*c;
end
//
initial
begin
   clk=0;
   forever
      #5 clk=~clk;
end
//
always@(posedge clk)
begin
    a<=(-127+$urandom%255);
	b<=(-127+$urandom%255);
	c<=(-127+$urandom%255);
end
//
always@(posedge clk)
if(ac!=ac_ref||bc_ref!=bc)
begin
    $display("test failed");
	$finish;
end	
//
int8_mult
U
(.*);
endmodule
