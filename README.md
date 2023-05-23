# MACD_Stock_Index

## General Info
This program analyzes stock data from a CSV file and calculates the Moving Average Convergence Divergence (MACD) and its signal line.
It then performs a basic buy/sell strategy based on the crossover of the MACD and its signal line.

## Perequisites
- C++ compiler
- Matlab
- Input file: `apple.csv` (you can replace it with other stock data files like `cdr.csv` or `msft.csv`)

## Getting Started
1. Clone the repository or download the source code files.
2. Compile the code using a C++ compiler.
3. Ensure that the input file (`apple.csv`) is in the same directory as the compiled program.
4. Run the compiled program.

## How It Works
1. The program reads the stock data from the input file (apple.csv) and extracts the necessary information.
2. It calculates the MACD by subtracting the Exponential Moving Average (EMA) of the stock prices over a shorter period (13 days) from the EMA over a longer period (27 days).
3. The MACD values are stored in a vector (MACD).
4. The program calculates the signal line by taking the EMA of the MACD values over a certain period (10 days).
5. The MACD and signal line values are written to an output file (MACDiSignal.csv).
6. Based on the crossover of the MACD and the signal line, the program determines whether to buy or sell stocks.
7. The program keeps track of the budget, the number of stocks owned, and calculates the income and percentage gain/loss.

## Constants
- `START_UP_CAPITAL`: The initial capital available for trading (set to 1000)

## Functions
### `float EMA_value(vector<float> temp_data, int N, int Now)`
- Calculates the Exponential Moving Average (EMA) based on the given data, number of periods, and current position.
- `temp_data`: Vector of stock prices.
- `N`: Number of periods for the EMA calculation.
- `Now`: Current position in the vector.

## Output

The program generates an output file (`MACDiSignal.csv`) with the following columns:

1. Date: The date corresponding to the stock data.
2. MACD: The calculated MACD values.
3. Signal: The calculated signal line values.
At the end of the program, it prints the following information:

- Profit/Loss: The net income gained or lost from the trading strategy.
- Percentage Gain/Loss: The percentage gain or loss relative to the initial capital.

## License
This project is licensed under the **MIT License**.

**Note:** This program is for educational purposes only and should not be used for real trading without thorough testing and understanding of the risks involved.





