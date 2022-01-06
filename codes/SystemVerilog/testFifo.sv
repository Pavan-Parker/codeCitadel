/*Testbench for testing FIFO designed for AXI4-Stream*/
/*
    Working:
        This is a simple testbench, where on reset, variable temp will be initialized to 'DEPTH', and
            Mode 1 - driver will keep on writing temp and decrementing the temp, until FIFO says it's full (isFull) , then  
            Mode 0 - driver will keep on reading FIFO, until FIFO says it's empty (isEmpty)
        The above two cycles will keep repeating endlessly, but the simulaiton stops after a fixed time. 
*/



`timescale 1ns/1ps
module tb_fifo ();
    
    parameter DEPTH=8,
              WIDTH=8;

/*AXI-Stream Interfaces*/
    
    logic  CLK;        // CLOCK SIGNAL

    /*Slave ports of driver*/
    logic [0:WIDTH-1] M_TData;    // Transmission Data
    logic             M_TValid;   // Master ready
    logic             M_TLast;    // Last byte of packet
    logic             M_TReady;   // Slave ready

    /*Master ports of driver*/
    logic [0:WIDTH-1] S_TData;    // Transmission Data
    logic             S_TValid;   // Master ready
    logic             S_TLast;    // Last byte of packet
    logic             S_TReady;   // Slave ready

/*Signals for Debugging purposes*/

    logic isEmpty;  // check if buffer is Empty
    logic isFull;   // check if buffer is full

/*Reset and Flush the fifo*/
    
    logic Reset;

/*temp variable (Data to write)*/
    logic [0:$clog2(DEPTH)-1]temp=DEPTH;

/*Mode:
        1 = Driver writes to Buffer
        0 = Driver reads from Buffer
*/
    logic mode=1;


fifo 
#(
    .depth(DEPTH),
    .width(WIDTH)
)
test_fifo
(

/*Connecting Clock Signal*/
    .CLK(CLK),

/*Connecting "WriteToFIFO" ports*/
    .S_TData(M_TData),
    .S_TValid(M_TValid),
    .S_TLast(M_TLast),
    .S_TReady(M_TReady),

/*Connecting "ReadFromFIFO" ports*/    
    .M_TData(S_TData),
    .M_TValid(S_TValid),
    .M_TLast(S_TLast),
    .M_TReady(S_TReady),

/*Connecting Flag Signals*/
    .isEmpty(isEmpty),  // check if buffer is Empty
    .isFull(isFull),   // check if buffer is full

/*Connecting Reset*/
    .Reset(Reset)
    
);


localparam CLK_PERIOD = 10; //setting clock period

/*CLOCK GENERATOR*/
always begin : clockGenerator
    #(CLK_PERIOD/2) CLK=~CLK;
end

/*INITIALIZATION*/
initial begin

    CLK<=0;                 //Clock singal initialize to 0
    Reset<=1;               //Asset Reset FIFO on start
    #(CLK_PERIOD) Reset<=0; //Release after a one clock period

end



/*Asserting Handshake singals depending on the mode*/
always_ff @(mode) begin

    if(mode) begin : WriteHandshake
        M_TValid<=1;
        S_TReady<=0;
    end : WriteHandshake

    else begin : ReadHandshake
        M_TValid<=0;
        S_TReady<=1;
    end : ReadHandshake

end

always_ff @(posedge CLK) begin

    /*if FIFO is full, switch to read mode*/
  	if(isFull) begin : WriteCompletionCheck
        mode<=0;
    end : WriteCompletionCheck

    /*if FIFO is empty, switch to write mode*/	
  	if(isEmpty) begin : ReadCompletionCheck
        mode<=1;
    end : ReadCompletionCheck

  	if(!Reset) begin
    
      /*Mode1=Writing temp and decrementing temp*/
      if(mode) begin : SENDING
          M_TData<=temp;
          temp<=temp-1'b1;
      end : SENDING

      /*Mode0=Reading temp*/      
      else begin : RECEIVING
          temp<=S_TData;
      end : RECEIVING
      
    end
    
end

// Terminate simulation after a fixed time
initial begin : TerminateSimulation
    #300 $finish();
end : TerminateSimulation


    /*VCD dump for debugging*/
// initial begin
//     $dumpfile("tb_fifo.vcd");
//     $dumpvars(0, tb_fifo);
// end



endmodule
