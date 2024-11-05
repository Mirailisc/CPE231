module counter_4bit(
    input clk,      // Clock signal
    input rst,      // Reset signal
    output reg [3:0] count  // 4-bit output count
);

    // Initialize count to 0 on reset
    always @(posedge clk or posedge rst) begin
        if (rst) 
            count <= 4'b0000;  // Reset count to 0
        else
            count <= count + 1;  // Increment count
    end

endmodule

module counter_4bit_tb;
    reg clk;
    reg rst;
    wire [3:0] count;

    // Instantiate the counter module
    counter_4bit uut (
        .clk(clk),
        .rst(rst),
        .count(count)
    );

    // Clock generation (period of 10 time units)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Test sequence
    initial begin
        rst = 1;  // Reset the counter
        #10 rst = 0;  // Release reset
        #100;  // Wait for 100 time units

        $stop;  // End simulation
    end

    // Monitor output
    initial begin
        $monitor("At time %0t, count = %b", $time, count);
    end
endmodule
