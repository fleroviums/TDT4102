#include "task2.h"


double sum(vector<double>& x){
    double total = 0;
    for(auto n : x){
        total+=n;
    }
    return total;
}
double mean(vector<double>& x){
    return sum(x)/x.size();
}

void read_csv(string filename, vector<double>& x, vector<double>& y){
    ifstream ist{filename};
    //ist.open(filename);
    if(!ist) error("Couldn't read file " + filename);
    string currline;
    while(getline(ist, currline)){
        auto it = currline.find(' ');
        string xcoord = currline.substr(0,it);
        string ycoord = currline.substr(it);
        x.push_back(stoi(xcoord));
        y.push_back(stoi(ycoord));
    }
    ist.close();
}

pair<double, double> linreg(vector<double>& x, vector<double>& y){
    double var = 0;
    double cov = 0;
    for(auto i : x){
        var += (i-mean(x))*(i-mean(x));
    }
    var = var/x.size();
    for(int i=0;i<x.size();++i){
        cov += (x[i]-mean(x))*(y[i]-mean(y));
    }
    double a = cov/var;
    pair<double, double> vals = {a, mean(y)-a*mean(x)};
    return vals;
}
 vector<double> linpred(vector<double>& x, double a, double b){
     vector<double> y;
     for(auto i : x){
         y.push_back(a*i+b);
     }
     return y;    
 }
 double r2(vector<double>& y, vector<double>& y_pred){
     double numerator = 0;
     double denominator = 0;
     for(int i=0;i<y.size();++i){
         numerator += (y[i]-y_pred[i])*(y[i]-y_pred[i]);
         denominator += (y[i]-mean(y))*(y[i]-mean(y));
     }
     return 1-numerator/denominator;
 }

 void fakeMain(){
     vector<double> x_values;
     vector<double> y_values;
     read_csv("data.csv", x_values, y_values);
     pair<double, double> coeff = linreg(x_values, y_values);
     vector<double> y_pred = linpred(x_values, coeff.first, coeff.second);
     double r_squared = r2(y_values, y_pred);
     cout << "Best fit: y=" << coeff.first << "x + " << coeff.second << endl;
     cout << "R^2     : " << r_squared << endl; 
 }