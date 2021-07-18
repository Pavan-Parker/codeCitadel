
module fifo #
(
    parameter depth      = 8,  //FIFO depth
    parameter width      = 8  //FIFO width
)
(
/*AXI-Stream Interfaces*/
    
    input logic  CLK,        // CLOCK SIGNAL

    /*AXIS INPUT FIFO*/
    input logic  [width-1:0] S_TData,    // Transmission Data
    input logic              S_TValid,   // Master ready
    input logic              S_TLast,    // Last byte of packet
    output logic             S_TReady,   // Slave ready

    /*AXIS OUTPUT FIFO*/
    output logic  [width-1:0] M_TData,    // Transmission Data
    output logic            M_TValid,   // Master ready
    output logic            M_TLast,    // Last byte of packet
    input  logic            M_TReady,   // Slave ready

/*Signals for Debugging purposes*/

    output logic isEmpty,  // check if buffer is Empty
    output logic isFull,   // check if buffer is full

/*Reset and Flush the fifo*/
    
    input Reset
);

    // logic receptionComplete=0;

    /*
    *                           FIFO
                ----------->[S------------M]---------------------
                |                                                 |
                |                                                 |
                |                                                 |
                -------------[M------------S]---------------------
                                DRIVER
    */

    assign S_TReady=( S_TValid && !isFull);

    assign M_TValid=(!S_TReady && !isEmpty);

  logic [0:(width-1)] memory [0:(depth-1)];
  logic [0:($clog2(depth)-1)] readPointer='0;
  logic [0:($clog2(depth)-1)] writePointer='0;
  logic [0:($clog2(depth))] count='0;

    assign isEmpty=(!count);
    assign isFull=(count==depth);

//     always_ff @(posedge CLK) begin : MONITOR
//         $display("@CLK=0x%0t",$time/10);
//         $display($sformatf("%p", memory));
//     end : MONITOR

    initial begin
        $dumpfile("tb_fifo.vcd");
        $dumpvars(0, tb_fifo);
    end
    always_ff @(posedge CLK) begin
            if(Reset) begin : RESET
                writePointer<='0;
                readPointer<='0;
                count<='0;
            end : RESET
        
            else if(S_TReady) begin : Reception
                memory[writePointer]<=S_TData;
                writePointer<=(writePointer+1);
                count<=count+1'b1;
            end : Reception
    
            else if(M_TValid) begin  : Sending
                M_TData<=memory[readPointer];
                readPointer<=(readPointer+1);
                count<=count-1'b1;
            end : Sending

    end

endmodule