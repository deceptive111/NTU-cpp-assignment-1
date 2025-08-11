#include<iostream>
#include<vector>
#include<string>
using namespace std;
//declare and define VoucherV3 type, HouseholdVouchersV2 type again

//VoucherV3 type with the help of enum
enum class VoucherValue{
    ONE=1, TWO=2, FIVE=5, TEN=10
};
struct VoucherV3{
    VoucherValue value;
    bool spent = false;
};


//with enum, data types of the elements in those two structs above, especially value, are locked by enum(I guess) 

//HouseholdVouchersV2 
using HouseholdID = long ; //Therefore HouseholdID becomes a type that absolutely equals to long. just another name of long 
struct HouseholdVoucherV2{
    HouseholdID ID;
    string name;
    string address;
    vector<VoucherV3> vouchers;//this is for all issued vouchers
    bool issued = false;
    int issuedamount;
    vector<VoucherV3> spentvouchers;//this vector contains all spent vouchers
};

//this is going to be update for functions like----balance, remained vouchers

//declare a print function to help me check the whether the output is feasible
//and also, it need to do some accumulation about issued amount

/*(this comment is my guess, I might find them wrong in future studies)
we can notice that when we define a function, we have to use some "positional marks"
like the h in PrintHousehold to indicate the object is HouseholdV2 type.
const means the input is const, will not change in any cases.
*/

void PrintHousehold(HouseholdVoucherV2& h){//this
    cout<<"ID: "<<h.ID<<"\n";
    cout<<"Name: "<<h.name<<"\n";
    cout<<"Address: "<<h.address<<"\n";
    cout<<"Vouchers:";
    if (h.issued==true){
        for(const auto&v : h.vouchers){
            cout<<static_cast<int>(v.value)<<"("<<(v.spent ? "spent":"not spent")<<")"<<" ";
        };
        /*(also a guess)
        here inside the for loop, is the same.
        auto judge the type of v, which comes from h.vouchers.
        then the v plays a role as positional mark to indicate the h.vouchers(with : connections)
        */
       cout<<"\nIssued?"<<(h.issued ? "Yes":"No")<<"\n";//change bool type to yes or no.
       h.issuedamount = 0;//initialized as 0. However, may result in more time to process
       for(const auto& v : h.vouchers){
            h.issuedamount += static_cast<int>(v.value);
       }
       cout<<"Issued Amount: "<<h.issuedamount<<"\n";
    }
    else {
        cout << "No vouchers issued.\n"<<"\n";
    };// reminder, if else forms a statement or "if" only.

    if (h.spentvouchers.empty()){
        cout<<"Haven't spend any Vouchers"<<"\n"<<"\n";
    }
    else{
        cout<<"Spent Vouchers are:";
        for(auto&sv : h.spentvouchers){
            cout<<static_cast<int>(sv.value)<<" ";
        }
        cout<<"\n";
    };
};

//this above is going to be updated as long as householdvouchers type has been updated



int main(){
    //those are the three households
    HouseholdVoucherV2 h1{
        123,//ID
        "Jack",//name
        "Nanyang Hill",
    };
    HouseholdVoucherV2 h2{
        456,
        "Alice",
        "BoonLay",
    };
    HouseholdVoucherV2 h3{
        789,
        "John",
        "Lakeside"
    };
    //instantiation Vouchers with different face value
    VoucherV3 twodvoucher{
        VoucherValue::TWO,
    };
    VoucherV3 fivedvoucher{
        VoucherValue::FIVE,
    };
    VoucherV3 tendvoucher{
        VoucherValue::TEN,
    };

    //issued them with require times loop
    for(int i = 0;i<5; i++){
        h1.vouchers.push_back(twodvoucher);
        h2.vouchers.push_back(twodvoucher);
        h3.vouchers.push_back(twodvoucher);
    };
    for(int i = 0; i<4; i++){
        h1.vouchers.push_back(fivedvoucher);
        h2.vouchers.push_back(fivedvoucher);
        h3.vouchers.push_back(fivedvoucher);
    };
    for(int i = 0; i<2; i++){
        h1.vouchers.push_back(tendvoucher);
        h2.vouchers.push_back(tendvoucher);
        h3.vouchers.push_back(tendvoucher);
    };
    h1.issued=true;
    h2.issued=true;
    h3.issued=true;
    //check whether successfully issued
    cout<<"Household 1"<<"\n";
    PrintHousehold(h1);
    cout<<"Household 2"<<"\n";
    PrintHousehold(h2);
    cout<<"Household 3"<<"\n";
    PrintHousehold(h3);

    //for h1 to spent a total number of 20 dollars (with two 10 dollars voucher)
    int spentamount = 0;
    for(int i = 0; i < h1.vouchers.size(); i++){
        if(static_cast<int>(h1.vouchers[i].value) == 10 && h1.vouchers[i].spent == false && spentamount<20){ 
            // multiple condition to meet is done by &&
            /*
            the reason why we need to use static_cast here is because enum locks the type
            we have to use static_cast to convert the element we need in the program
            */
            h1.vouchers[i].spent = true;
            h1.spentvouchers.push_back(tendvoucher);
            spentamount+=static_cast<int>(h1.vouchers[i].value);
        }
        else{
            continue;
        }
    };
    PrintHousehold(h1);
    return 0;
}