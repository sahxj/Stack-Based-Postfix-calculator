// a1.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name         : Sahaj Bhangu   
// Student ID # : 301649137      
// SFU Email    : sba286@sfu.ca  
// Platform     : macOS, using clang++
// Editor/IDE   : VS Code        
// Known Bugs   : <describe any bugs or issues you're aware of>
// Missing      : Trig. functions calculate in degrees, not radians
// Challenges   : Learning to implement <vector>, and using the concept of stacks in this assignment
// // Help      :    1. To learn about vectors 
//                      https://cppreference.com/w/cpp/container/vector/clear.html
//                   2. To figure out how to use stacks in general although implemnted through vector
//                      https://www.w3schools.com/cpp/cpp_stacks.asp
//                   3. To understand stringstreams used for split helper fxn 
//                      https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
//                   4. Split helper function taken from and then modified myself
//                      https://share.google/aimode/1FPCj9ls7J45hEiqT
//                   5. Other C++ syntax that I did not learn in class including cmath
//                      https://www.w3schools.com/cpp/default.asp
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations above and in the comments with
// enough detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <cmath>

using namespace std;

vector<string> split(const string& line) {
    vector<string> tokens; // this is the full string with the tokens
    string token; //initializes the string as token
    stringstream ss(line); //extracts the token

    while (ss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}


int main(){
    cout << "Welcome to RPN Calculator! \n (type 'h' or '?' for help, 'q' to quit) \n";
    

    vector<double> postfixSt; // using this for my stack

    while (true) {
        cout << "--> ";

        string line;
        getline(cin, line);

        vector<string> tokens = split(line); // calling the input as the original string to split it 

            for (const string& token : tokens) { 
                // HELP TOKEN //

                if (token == "h" || token =="?" || token == "help") { 
                    cout << "This is a postfix calculator, so operators appear after operands \n";
                    cout << "e.g. 2 4 * 1 + gives 9, same as 2 * 4 + 1\n"; 
                }

                // QUIT TOKEN //

                else if (token == "q" || token == "quit" || token == "exit"){ 
                    cout << "The calculation has ended\n";
                    break;
                }

                // CLEAR TOKEN //

                else if (token == "c" || token == "clear"){
                    postfixSt.clear();
                }

                // PRINT TOKEN //

                else if (token == "p" || token == "print"){ 
                    if (postfixSt.empty()) {
                        cout << "The stack is empty\n";
                    }
                    else {
                        for (double x : postfixSt) {
                            cout << x << " ";
                        }
                    }
                }

                // DUP TOKEN //

                else if (token == "dup"){
                    if (postfixSt.empty()){
                        cout << "error: can't duplicate from empty stack\n";
                        continue;
                    }
                    postfixSt.push_back(postfixSt.back());
                }

                // DROP TOKEN //
                else if (token == "drop"){
                    if (postfixSt.empty()){
                        cout << "error: can't drop from empty stack\n";
                        continue;
                    }
                    postfixSt.pop_back();
                }
                // in the next two there will be nested "if"s for each operation
                // using cmath for the operations

                // UNARY TOKENS //

                else if(token == "abs" || token == "sin" || token == "cos" || token == "sqrt"){ 

                    if (postfixSt.empty()) {
                        cout << "Error: stack is empty\n";
                        break;
                    }

                    double x = postfixSt.back();
                    postfixSt.pop_back();

                    if (token == "abs"){
                        // for the abs 
                        postfixSt.push_back(abs(x));
                    }
                    else if (token == "sin") {
                        // for sin 
                        postfixSt.push_back(sin(x));
                    }
                    else if (token == "cos"){
                        // for cos 
                        postfixSt.push_back(cos(x));
                    }
                    else if (token == "sqrt"){
                        // for sqrt 
                        if (x < 0) {
                            cout << "Error: x < 0, no solution\n";
                            break;
                        }
                        postfixSt.push_back(sqrt(x));
                    }

                }

                // BINARY TOKENS //

                else if(token == "+" || token == "-" || token == "*" || token == "/") { 

                    if (postfixSt.size() < 2) {
                        // checking for error
                        cout << "Error: not enough operands\n";
                        break;
                    }

                    double b = postfixSt.back(); 
                    postfixSt.pop_back();

                    double a = postfixSt.back();
                    postfixSt.pop_back();

                    if (token == "+"){
                        // for add 
                        postfixSt.push_back(a + b);
                    }
                    else if (token == "-"){
                        postfixSt.push_back(a - b);
                    }
                    else if (token == "*"){
                        // for multiply
                        postfixSt.push_back(a * b);
                    }
                    else if (token == "/"){
                        // for divide
                        if (b == 0){
                            cout << "Error: division by zero, no solution\n";
                            break;
                        }
                        postfixSt.push_back(a / b);
                    }
                }

                // FOR THE NUMBER //
                else {
                    try {
                        double num = stod(token);
                        postfixSt.push_back(num);
                    }
                    catch(...) {
                        cout << "Error: this is an invalid token: " << token << "\n";
                        break;
                    }
                }
        }  
        
        //PRINTING THE STACK IF NOT EMPTY//
        if (!postfixSt.empty()) {
            cout << postfixSt.back() << endl;
        }
        else {
            cout << "The stack is empty, can't print\n";
        }
   }
}
