#include "task1.h"

void printIt(vector<string> vStr){
    for(vector<string>::iterator it = vStr.begin(); it!=vStr.end(); ++it){
    cout << *it << " ";
    }
}
void printItSet(set<string> sStr){
    for(set<string>::iterator it = sStr.begin(); it!=sStr.end();++it){
        cout << *it << " ";
    }
}

void task1(){
	vector<string> lipsumStr{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
	//a
    printIt(lipsumStr); //Made printIt-function so I can reuse it:)
    cout << endl;
	//b
	for(vector<string>::reverse_iterator it = lipsumStr.rbegin(); it!=lipsumStr.rend();++it){
		cout << *it << " ";
		//SPM: Hvorfor må man bruke rbegin og ikke kan bruke begin?
	}
    //c
    cout << "\nBefore calling replace function:\n";
    vector<string> newLipsum{"Lorem", "Ipsum", "Dolor", "Lorem"};
    printIt(newLipsum);
    replace(newLipsum, "Lorem", "Latin");
    cout << "\nAfter calling replace:\n";
    printIt(newLipsum);

    //d
    cout << "\n===Deloppgave D===\n";
    set<string> setStr = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    printItSet(setStr); //set sorterer så kommer ikke ut på samme måte som vector da
    cout << endl;
    for(set<string>::reverse_iterator it = setStr.rbegin(); it!=setStr.rend();++it){
    cout << *it << " ";
    }
    cout << endl;
    cout << "\nBefore calling replace function:\n";
    set<string> newNewLipsum{"Lorem", "Ipsum", "Dolor", "Lorem"}; //Set fjerner dupes => bare én Lorem
    printItSet(newNewLipsum);
    replaceSet(newNewLipsum, "Lorem", "Latin"); 
    cout << "\nAfter calling replace:\n";
    printItSet(newNewLipsum); //Variabelnavn on point (dette er hvorfor templates er viktig)


}

void replace(vector<string> &sVec, string old, string replacement){
    //Prøvde find men var enklere å gjøre følgende
    for(vector<string>::iterator it = sVec.begin(); it!=sVec.end(); ++it){
        if(*it==old){
            it = sVec.erase(it);
            it = sVec.insert(it, replacement);
        }
    }
} //Vet at templates er mye bedre men det implementerers sikkert senere i øvingen:))
void replaceSet(set<string> &sSet, string old, string replacement){
    for(set<string>::iterator it = sSet.begin(); it!=sSet.end(); ++it){
        if(*it==old){
            it = sSet.erase(it);
            it = sSet.insert(it, replacement);
        }
    }
}