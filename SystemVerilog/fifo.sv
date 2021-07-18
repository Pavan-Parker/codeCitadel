/*Basic FIFO designed for AXI4-Stream*/

/*
*     
*    WORKING:                    
*                ----------->[S----FIFO-----M]-------------
*                |                                         |
*        (Write  |                                         | (Read
*        to      |                                         | from
*        FIFO)   |                                         | FIFO)
*                |                                         |
*                -------------[M---DRIVER---S]--------------
*                                DRIVER
*
*        - To Write into FIFO,
*            Driver will use it's MASTER ports (M_*) to send the data and
*            FIFO will use it's SLAVE ports (S_*) to receive the data
*        - To Read from FIFO,
*            FIFO will use it's MASTER ports (M_*) to send the data and
*            Driver will use it's SLAVE ports (S_*) to receive the data
*        
*        - To avoid race condition,
*            "Write into FIFO" operation is prioritized over "Read from FIFO" operation,
*            Which means "Read from FIFO" will be operational only when there's no data "Writing into FIFO" 
*    NOTE: 
*        In the current state, there is no packing of the data,
*        So, TLast signal is not used as it is not relavant anymore. 
*/
module fifo #
(
    parameter depth      = 8,  //FIFO depth
    parameter width      = 8  //FIFO width
)
(
/*AXI-Stream Interfaces*/

    input logic  CLK,        // CLOCK SIGNAL

    /*AXIS WRITE INTO FIFO*/
    input logic  [width-1:0] S_TData,    // Transmission Data
    input logic              S_TValid,   // Master ready
    input logic              S_TLast,    // Last byte of packet, NOT USED AS OF NOW
    output logic             S_TReady,   // Slave ready

    /*AXIS READ FROM FIFO*/
    output logic  [width-1:0] M_TData,   // Transmission Data
    output logic            M_TValid,    // Master ready
    output logic            M_TLast,     // Last byte of packet, NOT USED AS OF NOW
    input  logic            M_TReady,    // Slave ready

/*Signals for Debugging purposes*/

    output logic isEmpty,  // check if buffer is Empty
    output logic isFull,   // check if buffer is full

/*Reset and Flush the fifo*/
    
    input Reset
);

    /*Assert WriteInto_Ready signal if Writer is ready and Buffer isn't full*/
    assign S_TReady=( S_TValid && !isFull);

    /*Assert ReadFrom_Ready signal if there's no writing Operation going on and Buffer isn't empty*/
    assign M_TValid=(!S_TReady && !isEmpty);

    /*Storage of (Depth)*(Width)*/
    logic [0:(width-1)] memory [0:(depth-1)];

    /*Pointers for tracking*/    
    logic [0:($clog2(depth)-1)] readPointer='0;
    logic [0:($clog2(depth)-1)] writePointer='0;
    logic [0:($clog2(depth))] count='0;

    /*Flags for underflow and Overflow*/    
    assign isEmpty=(!count);
    assign isFull=(count==depth);

    always_ff @(posedge CLK) begin

            /*Reset the FIFO*/
            if(Reset) begin : RESET
                writePointer<='0;
                readPointer<='0;
                count<='0;
            end : RESET
        
            /*Reception*/
            else if(S_TReady) begin : Reception
                memory[writePointer]<=S_TData;      //Write to storage
                writePointer<=(writePointer+1);     //Increment the write pointer
                count<=count+1'b1;                  //Increment the counter
            end : Reception
    
            /*Sender*/
            else if(M_TValid) begin  : Sending
                M_TData<=memory[readPointer];       //Read from storage
                readPointer<=(readPointer+1);       //Increment the read pointer
                count<=count-1'b1;                  //Decrement the counter
            end : Sending
    end

    /*VCD dump for debugging*/
    initial begin
        $dumpfile("tb_fifo.vcd");
        $dumpvars(0, tb_fifo);
    end

endmodule