#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<size_t> tarif= {73,31,45,90,56,12,67,89,37,11};
    //tarif = {1,2,3,4,5,6,7,8,9,10};

    size_t number_of_days = tarif.size();
    if(number_of_days == 0){
        cout << "ERROR: Number of Days is Zero!" << endl;
        return 1;
    }
    vector<size_t> len_to_sell(number_of_days);
    size_t max_el = 0;
    size_t new_max_el = 0;
    len_to_sell[0] = 1;
    while(max_el < number_of_days){
        for(size_t i = max_el;i < number_of_days; i++){
            if(tarif[i] >= tarif[max_el]){
                len_to_sell[max_el] = 0;
                len_to_sell[i] = i+1-new_max_el;
                max_el = i;
            }
        }
        max_el++;
        new_max_el = max_el;
    }
    size_t result = 0;
    for(size_t i = 0; i < number_of_days; i++)
        result += tarif[i]*len_to_sell[i];

    cout << "Man can earn " << result << "$ maximally!" << endl;
    cout << "EXPLAINING!" << endl << "We have " << number_of_days << " day";

    if(((number_of_days % 10) != 1) || ((number_of_days % 100) == 11))
        cout << "s";
    cout << ":" << endl;
    for(size_t i = 0; i < number_of_days; i++){
        cout << "Day " << i + 1 << " : Tarif = " << tarif[i] << "$,\t Length to sell = " << len_to_sell[i] << "cm" << endl;
    }
    return 0;
}
