`timescale 1ns/1ps

module tb_fifo ();
    
    parameter DEPTH=8,
          WIDTH=8;

/*AXI-Stream Interfaces*/
    
    logic  CLK;        // CLOCK SIGNAL

    /*Slave ports of tb*/
    logic [0:WIDTH-1] M_TData;    // Transmission Data
    logic             M_TValid;   // Master ready
    logic             M_TLast;    // Last byte of packet
    logic             M_TReady;   // Slave ready

    /*Master ports of tb*/
    logic [0:WIDTH-1] S_TData;    // Transmission Data
    logic             S_TValid;   // Master ready
    logic             S_TLast;    // Last byte of packet
    logic             S_TReady;   // Slave ready

/*Signals for Debugging purposes*/

    logic isEmpty;  // check if buffer is Empty
    logic isFull;   // check if buffer is full

/*Reset and Flush the fifo*/
    
    logic Reset;
  logic [0:$clog2(DEPTH)-1]temp=DEPTH;
    logic START=0;


fifo 
#(
    .depth(DEPTH),
    .width(WIDTH)
)
test_fifo
(

    .CLK(CLK),
    
    .S_TData(M_TData),
    .S_TValid(M_TValid),
    .S_TLast(M_TLast),
    .S_TReady(M_TReady),

    
    .M_TData(S_TData),
    .M_TValid(S_TValid),
    .M_TLast(S_TLast),
    .M_TReady(S_TReady),


    .isEmpty(isEmpty),  // check if buffer is Empty
    .isFull(isFull),   // check if buffer is full

/*Reset and Flush the fifo*/
    
    .Reset(Reset)
    
);


localparam CLK_PERIOD = 10;

always begin : clockGenerator
    #(CLK_PERIOD/2) CLK=~CLK;
end

// initial begin
//     $dumpfile("tb_fifo.vcd");
//     $dumpvars(0, tb_fifo);
// end

initial begin
    CLK<=0;
    Reset<=1;
    M_TValid<=1;
//     M_TData<=temp;
    #(CLK_PERIOD) Reset<=0;
    // START<=1;
end
//  initial begin
//    #100 $finish();
//  end

always_ff @(posedge CLK) begin

    if(isFull) begin : CompletionCheck
        $finish;
    end : CompletionCheck

  	if(!Reset) begin : SENDING
        M_TData<=temp;
        temp<=temp-1'b1;
    end : SENDING
    
    // if(!Reset&&temp) begin : RECEPTION
    //     M_TData<=temp;
    //     temp<=temp-1;
    // end : RECEPTION
    
end



endmodule
