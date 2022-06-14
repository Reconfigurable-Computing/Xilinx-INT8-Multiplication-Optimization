`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/06/06 12:49:11
// Design Name: 
// Module Name: int8_mult
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


module int8_mult(
input logic clk,
input logic signed [7:0] a,
input logic signed [7:0] b,
input logic signed [7:0] c,
output logic signed [15:0] ac,
output logic signed [15:0] bc
    );
//计算a*c和b*c
//(a*2^16+b)*c
logic signed [23:0] tmp;
logic signed [31:0] result;
//tmp
assign tmp={a,16'd0}+{{16{b[7]}},b};
//result
always@(posedge clk)
   result<=$signed(tmp)*$signed(c);
//ac,bc
assign ac=result[31:16]+result[15];
assign bc=result[15:0];
endmodule
