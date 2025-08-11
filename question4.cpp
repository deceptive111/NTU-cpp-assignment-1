/*
This is the solution for question4
*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//struct a loan from GPT along with some of my updates
struct Loan {
    string loan_name;
    double principal;
    int term_years; // I update it since the term years may not be an integer in reality
    double annual_rate;
    double interest_due;
    double residual_years;// remaining years of the loan
};

//struct a deposite from GPT along with my updates
struct Deposit{
    string deposit_name;
    double principal;
    int term_years; //The same as struct Loan
    double annual_rate;
    double interest_earned;
    double residual_years;//remaining years of the deposit
};

//define a function to calculate the accumulated interest for both deposit and loan. Then returns a new loan or deposit

//this is for loan
//remind that void should never return a value. Here I need to update my loan and return a new loan. So I should use Loan instead 
Loan CalculateInterestDue(const Loan & l, int years_passed){
    Loan updated_loan = l;
    double interestdue = 0;
    interestdue = l.principal*pow((1+l.annual_rate),years_passed)-l.principal;
    updated_loan.interest_due=interestdue;
    updated_loan.residual_years=l.residual_years-years_passed;
    updated_loan.loan_name=l.loan_name+"."+"updated";
    return updated_loan;
};

//this is for deposit similar to what is for Loan
Deposit CalculateInterestEarned(const Deposit & d, int years_passed){
    Deposit updated_deposit = d;
    double interestearned = 0;
    interestearned = d.principal*pow((1+d.annual_rate),years_passed)-d.principal;
    updated_deposit.interest_earned = interestearned;
    updated_deposit.residual_years = d.residual_years-years_passed;
    updated_deposit.deposit_name = d.deposit_name+"."+"updated";
    return updated_deposit;
};

//define a function to print the status of the and deposit
void PrintL(const Loan & l){
    cout<<l.loan_name<<"status"<<"\n";
    cout<<"Loan principal: "<<l.principal<<"\n";
    cout<<"Loan initial term: "<<l.term_years<<"\n";
    cout<<"Loan annual interest rate: "<<l.annual_rate<<"\n";
    cout<<"Loan residual term: "<<l.residual_years<<"\n";
    cout<<"Interest due: "<<l.interest_due<<"\n"<<"\n";
};

//Similarly, define the print function for deposit
void PrintD(const Deposit & d){
    cout<<d.deposit_name<<"status"<<"\n";
    cout<<"Loan principal: "<<d.principal<<"\n";
    cout<<"Loan initial term: "<<d.term_years<<"\n";
    cout<<"Loan annual interest rate: "<<d.annual_rate<<"\n";
    cout<<"Loan residual term: "<<d.residual_years<<"\n";
    cout<<"Interest earned: "<<d.interest_earned<<"\n"<<"\n";
};


// The main program
int main(){
    //initial those two financial instrument
    Loan loan{
        "Loan 1",
        300000,//principal
        20,//term
        0.031,//annual rate
    };
    Deposit deposit{
        "deposit 1",
        100000,
        5,
        0.021,
    };
    loan.residual_years = loan.term_years;
    deposit.residual_years = deposit.term_years;

    //output the initial status of loan and deposit

    PrintL(loan);
    PrintD(deposit);

    // 4 years later
    Loan new_loan = CalculateInterestDue(loan,4);
    Deposit new_deposit = CalculateInterestEarned(deposit,4);

    //print all the informations about the new loan and new deposit
    //the answer to sub-question 3 and 4 are inside those outputs
    PrintL(new_loan);
    PrintD(new_deposit);
    
    return 0;

}