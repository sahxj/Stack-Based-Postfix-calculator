# Stack-Based Postfix calculator
This calculator was developed using C++ and Stack management logic.

I developed this project to practice implementing stack-based logic in C++, a clean terminal based UI, and effective error handling.

# Features:
-  Postfix (RPN) Evaluation:
  Evaluates expressions where operators follow operands, eliminating the need for parentheses and complex precedence rules.

- Dynamic Stack Architecture:
  Utilizes a C++ STL stack-based logic to manage intermediate computational results with \(O(n)\) time complexity.
  
- Comprehensive Operator Support:
  Binary: Standard arithmetic operations (+, -, *, /).
  Unary: Advanced stack manipulation and math functions (abs, dup, drop).
  Commands: Interactive session management (clear, print, help).
  
- Strict Lexical Tokenization:
 Processes space-delimited input strings to accurately differentiate between multi-digit numbers, floating points, and operators.

- Robust Error Handling (Detects and reports common postfix errors)
  Stack underflow (insufficient operands for an operator).
  Invalid token detection.
  Division by zero.
  

