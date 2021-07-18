
module fifo #
(
parameter depth      = 8,  //FIFO depth
parameter width = 8  //FIFO width
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

    logic receptionComplete=0;

    assign S_TReady=( S_TValid && !isFull);
    assign M_TValid=(!S_TReady && !isEmpty);

    logic [(width-1):0]memory [(depth-1):0],
            readPointer,
            writePointer,
            count;

    assign isEmpty=(count==0);
    assign isFull=(count==depth);

    always_ff @(posedge CLK) begin : MONITOR
      	$display("@CLK=0x%0h",CLK);
        $display($sformatf("%p", memory));
    end : MONITOR

    always_ff @(posedge CLK) begin
            if(Reset) begin : RESET
                writePointer<='0;
                readPointer<='0;
                count<=0;
            end : RESET
            else if(S_TReady) begin : WriteToBuffer
                memory[writePointer]<=S_TData;
                writePointer<=(writePointer+1)%depth;
                count<=count+1;
            end : WriteToBuffer
    
            else if(M_TValid) begin  : ReadFromBuffer
                M_TData<=memory[readPointer];
                readPointer<=(readPointer+1)%depth;
                count<=count-1;
            end : ReadFromBuffer

    end

endmodule