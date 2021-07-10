#include<bits/stdc++.h>
#include<chrono> //function to calculate wall time.
//This one uses the clock with the highest resolution available, so it is probably adequate for most people.

using namespace std;
using namespace std::chrono;

string passwordCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";//62 digits. So there have 62^(62) Permutation.
long long int attempts = 0, passlength = 1;
int length = passwordCharacters.length();

void before(){

    cout<<"\n\n--->It is not "<<passlength<<" length password"<<endl;
    passlength++;
    cout<<"--->Looking for "<<passlength<<" length password\n~~~~~~~~~>"<<endl;
}

int bruteForce(string password)
{

    //for 1 length pass
    for(int i = 0 ; i<length ; i++){
        string tempPass = "";
        attempts++;

        tempPass += passwordCharacters[i];
        if( tempPass == password) return 1;
    }//Attempts done = 62

    before();

    //LENGTH 2
    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            string tempPass = "";
            attempts++;

            tempPass += passwordCharacters[i];
            tempPass += passwordCharacters[j];
            if( tempPass == password) return 1;
        }
    }//Attempts done = 62 + 62^2 = 3906

    before();

    //LENGTH 3
    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            for(int k=0 ; k<length ; k++){
                string tempPass = "";
                attempts++;

                tempPass += passwordCharacters[i];
                tempPass += passwordCharacters[j];
                tempPass += passwordCharacters[k];

                if( tempPass == password) return 1;
            }
        }
    }//Attempts done = 3906 + 62^3 = 242234

    before();

    //LENGTH 4
    /*Math-> permutation:
    total Combination = 62*62*62*62 = 62^4 = 14776336
    */

    double percentage = 0;

    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            for(int k=0 ; k<length ; k++){
                for(int l=0 ; l<length ; l++){
                        string tempPass = "";
                        attempts++;
                        if(attempts % 250000 == 0){ cout << '.'; }
                        if(attempts % (15018570/10) == 0){
                           percentage += 10;
                           cout << " " << percentage << "% ";
                           }

                        tempPass += passwordCharacters[i];
                        tempPass += passwordCharacters[j];
                        tempPass += passwordCharacters[k];
                        tempPass += passwordCharacters[l];

                        if( tempPass == password) return 1;
                }
            }
        }
    }//Attempts Done = 242234 + 62^4 =

    before();

    //LENGTH 5
    percentage = 0;
    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            for(int k=0 ; k<length ; k++){
                for(int l=0 ; l<length ; l++){
                    for(int m=0 ; m<length ; m++){
                        string tempPass = "";
                        attempts++;
                        if(attempts % 2500000 == 0) { cout << '.';}
                        if(attempts % (931151402/50) == 0){
                            percentage += 2;
                            cout << " " << percentage << "% ";
                          }
                        tempPass += passwordCharacters[i];
                        tempPass += passwordCharacters[j];
                        tempPass += passwordCharacters[k];
                        tempPass += passwordCharacters[l];
                        tempPass += passwordCharacters[m];

                        if( tempPass == password) return 1;


                    }
                }
            }
        }
    }

    before();

    //LENGTH 6
    percentage = 0;
    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            for(int k=0 ; k<length ; k++){
                for(int l=0 ; l<length ; l++){
                    for(int m=0 ; m<length ; m++){
                        for(int n=0 ; n<length ; n++){
                            string tempPass = "";
                            attempts++;
                            if(attempts % 2500000 == 0) { cout << '.';}
                            if(attempts % ((long long int)57731386986/1000) == 0){
                                percentage += 0.1;
                                cout << " " << percentage << "% ";
                                }
                            tempPass += passwordCharacters[i];
                            tempPass += passwordCharacters[j];
                            tempPass += passwordCharacters[k];
                            tempPass += passwordCharacters[l];
                            tempPass += passwordCharacters[m];
                            tempPass += passwordCharacters[n];

                            if(tempPass == password) return 1;
                        }
                    }
                }
            }
        }
    }

    before();

    //LENGTH 7
    percentage = 0;
    for (int i=0 ; i<length ; i++){
        for(int j=0 ; j<length ; j++){
            for(int k=0 ; k<length ; k++){
                for(int l=0 ; l<length ; l++){
                    for(int m=0 ; m<length ; m++){
                        for(int n=0 ; n<length ; n++){
                            for(int o=0 ; o<length ; o++){
                                string tempPass = "";
                                attempts++;
                                if(attempts % 2500000 == 0){cout << '.';}
                                if(attempts % ((long long int)3579345993194/10000) == 0){
                                    percentage += 0.01;
                                    cout << " " << percentage << "% ";
                                    }
                                tempPass += passwordCharacters[i];
                                tempPass += passwordCharacters[j];
                                tempPass += passwordCharacters[k];
                                tempPass += passwordCharacters[l];
                                tempPass += passwordCharacters[m];
                                tempPass += passwordCharacters[n];
                                tempPass += passwordCharacters[o];

                                if(tempPass == password) return 1;
                            }
                        }
                    }
                }
            }
        }
    }


}

int main()
{
    cout<<"\n\n\t\t\t\t\t\t\t-PICK-BEE-\t\t\t\t\n\n\n";
    cout<<"Give a Password at most 7 words : ";
    string password;
    cin>>password;

    auto start = high_resolution_clock::now();

    int check = bruteForce(password);

    auto stop = high_resolution_clock::now();

    if (check == 1) cout<<"password checked"<<endl;
    else cout<<"\n\n!!!!!!!!!-> PASSWORD COULD NOT FOUND <-!!!!!!!!!"<<endl;

    auto duration = duration_cast<milliseconds>(stop - start);

    cout<<"Password            : "<<password<<endl;
    cout<<"Attempts            : "<<attempts<<endl;
    cout<<"Total Execution time: "<<(double)duration.count()/1000<<" seconds. \n";

}

/* ~ S ~ B ~ R ~
 Date: 26-11-20
 Time: 1201
*/
