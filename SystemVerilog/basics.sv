//FlipFlop
module flipFlop(clk, data_in, data_out);
    input clk, data_in;
    output data_out;
    logic q;
    always_ff @(posedge clk) begin
        q<=data_in;
    end
    assign data_out=q;
endmodule

/*
//Mux
module mux(data0_i,data1_i,select_i,data_o);
    input data0_i, data1_i,select_i;
    output data_o;
    always_comb begin
        data_o=select_i?data0_i:data1_i;
    end

endmodule
*/
`timescale 10ps/1ps
module top;
    reg clk,in,out;
    always begin
        #10 clk=1;
        #10 clk=0;
    end
    
    flipFlop ff(.clk(clk),.data_in(in),.data_out(out));

    initial begin 
        // $dumpfile("hmm.vcd");
        // $dumpvars(0,top);
        $monitor("at clk=0x%h, for in=0x%h out=0x%h",clk,in,out);
    
        in=0;
        #20 in=1;
        #20 in=0;
        #20 in=1;       
        $finish;
    end    
endmodule